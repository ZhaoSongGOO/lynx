// Copyright 2023 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.
package com.lynx.tasm;

import android.content.Context;
import android.net.Uri;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.annotation.RestrictTo;
import com.lynx.tasm.base.TraceEvent;
import com.lynx.tasm.base.trace.TraceEventDef;
import com.lynx.tasm.behavior.BehaviorRegistry;
import com.lynx.tasm.behavior.ILynxUIRenderer;
import com.lynx.tasm.component.DynamicComponentFetcher;
import com.lynx.tasm.group.ILynxViewConfigProvider;
import com.lynx.tasm.group.ILynxViewGroup;
import com.lynx.tasm.group.LynxBaseConfigurator;
import com.lynx.tasm.image.model.LynxImageFetcher;
import com.lynx.tasm.loader.LynxFontFaceLoader;
import com.lynx.tasm.provider.AbsTemplateProvider;
import com.lynx.tasm.provider.LynxResourceFetcher;
import com.lynx.tasm.resourceprovider.generic.LynxGenericResourceFetcher;
import com.lynx.tasm.resourceprovider.media.LynxMediaResourceFetcher;
import com.lynx.tasm.resourceprovider.template.LynxTemplateResourceFetcher;
import com.lynx.tasm.service.ILynxTrailService;
import com.lynx.tasm.service.LynxServiceCenter;
import java.util.HashMap;
import java.util.Map;

public class LynxViewBuilder
    extends LynxBaseConfigurator<LynxViewBuilder> implements ILynxViewConfigProvider {
  AbsTemplateProvider templateProvider;
  Object lynxModuleExtraData;
  Float densityOverride;
  DynamicComponentFetcher fetcher;
  LynxResourceFetcher resourceFetcher;
  LynxFontFaceLoader.Loader fontLoader;
  LynxImageFetcher imageFetcher;

  TemplateBundle templateBundle;
  static Float defaultDensity = null;
  boolean enableLayoutOnly = LynxEnv.inst().isLayoutOnlyEnabled();
  Map<String, String> mImageCustomParam;
  Map<String, String> lynxViewConfig;
  LynxBackgroundRuntime lynxBackgroundRuntime;
  Uri uri = null;
  ILynxViewGroup lynxViewGroup;

  public LynxViewBuilder() {
    LynxEnv.inst().lazyInitIfNeeded();
    templateProvider = LynxEnv.inst().getTemplateProvider();
    densityOverride = null;
    if (defaultDensity != null) {
      densityOverride = defaultDensity;
    }
  }

  @Deprecated
  public LynxViewBuilder(Context context) {
    this();
  }

  /**
   * Experimental API.
   *
   * Set a default overriding density which will be applied to all LynxView constructed after it is
   * set. Will use screen density if default density is not set.
   * @param density overriding density by default, set it to null to reset the default density.
   */
  public static void setDefaultDensity(Float density) {
    defaultDensity = density;
  }

  public LynxViewBuilder setTemplateProvider(@Nullable AbsTemplateProvider provider) {
    templateProvider = provider;
    return this;
  }

  /**
   * @brief create a UIRenderer for UIBodyView and refactor the thread strategy.
   * @return UIRenderer
   */
  @RestrictTo(RestrictTo.Scope.LIBRARY)
  public ILynxUIRenderer createLynxUIRenderer() {
    ILynxUIRenderer uiRenderer = getUIRendererCreator().createLynxUIRender();
    setThreadStrategyForRendering(uiRenderer.getSupportedThreadStrategy(getThreadStrategy()));
    return uiRenderer;
  }

  /**
   * @brief set the uri for LynxView, which will be parsed by ILynxTrailService in building
   * LynxView.
   * @param uri uri for LynxView
   * @return this
   */
  public LynxViewBuilder setUri(@Nullable Uri uri) {
    this.uri = uri;
    return this;
  }

  /**
   * @brief get the uri of LynxView
   * @return uri of LynxView
   */
  public Uri getUri() {
    return uri;
  }

  /**
   * insert a key-value pair into lynxViewConfig if the key does not exist, otherwise ignored.
   * @param key
   * @param value
   * @return
   */
  public LynxViewBuilder insertLynxViewConfig(String key, String value) {
    if (lynxViewConfig == null) {
      lynxViewConfig = new HashMap<>();
    }
    lynxViewConfig.putIfAbsent(key, value);
    return this;
  }

  public LynxViewBuilder setLynxViewGroup(ILynxViewGroup group) {
    this.lynxViewGroup = group;
    return this;
  }

  /**
   * Pass extra data to LynxModule, the usage of data depends on module's implementation
   *
   * @param data Data passed to LynxModule
   */
  public LynxViewBuilder setLynxModuleExtraData(Object data) {
    lynxModuleExtraData = data;
    return this;
  }

  /**
   * @param resourceFetcher need to implement the request interface and requestSync interface in
   *     LynxResourceFetcher.
   */
  public LynxViewBuilder setResourceFetcher(LynxResourceFetcher resourceFetcher) {
    this.resourceFetcher = resourceFetcher;
    return this;
  }

  public LynxViewBuilder setFontLoader(LynxFontFaceLoader.Loader fontLoader) {
    this.fontLoader = fontLoader;
    return this;
  }

  @Deprecated
  public LynxViewBuilder setEnableRadonCompatible(boolean enableRadonCompatible) {
    return this;
  }

  @Deprecated
  public LynxViewBuilder setEnableLayoutOnly(boolean enableLayoutOnly) {
    return this;
  }

  public LynxViewBuilder setDynamicComponentFetcher(DynamicComponentFetcher fetcher) {
    this.fetcher = fetcher;
    return this;
  }

  @Deprecated
  public LynxViewBuilder setEnableCreateViewAsync(boolean enable) {
    return this;
  }

  public LynxViewBuilder setImageFetcher(LynxImageFetcher imageFetcher) {
    this.imageFetcher = imageFetcher;
    return this;
  }

  /**
   * Supports passing custom parameters to image network requests,
   * currently only used in image compliance scenarios.
   * @param imageCustomParams default is null
   */
  public LynxViewBuilder setImageCustomParam(Map<String, String> imageCustomParams) {
    mImageCustomParam = imageCustomParams;
    return this;
  }

  /**
   * Support container to pass in LynxViewConfig for direct parsing and processing within Lynx.
   * @param map schema map
   */
  public LynxViewBuilder setLynxViewConfig(Map<String, String> map) {
    lynxViewConfig = map;
    return this;
  }

  public Map<String, String> getLynxViewConfig() {
    return lynxViewConfig;
  }

  /**
   * Build a LynxView using a pre-created LynxBackgroundRuntime, if the runtime is
   * non-null, LynxView will use this runtime.
   *
   * @important Once the builder is used to create a LynxView, this runtime is
   * consumed and set to null
   *
   * @param runtime LynxBackgroundRuntime will be used by LynxView
   */
  public LynxViewBuilder setLynxBackgroundRuntime(LynxBackgroundRuntime runtime) {
    lynxBackgroundRuntime = runtime;
    return this;
  }

  public TemplateBundle getTemplateBundle() {
    return templateBundle;
  }

  public LynxViewBuilder setTemplateBundle(TemplateBundle templateBundle) {
    this.templateBundle = templateBundle;
    return this;
  }

  @Override
  public BehaviorRegistry getBehaviorRegistry() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.getBehaviorRegistry();
    }
    return this.behaviorRegistry;
  }

  @Override
  public boolean isEnableAutoExpose() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.isEnableAutoExpose();
    }
    return this.enableAutoExpose;
  }

  @Override
  public Float getDensity() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.getDensity();
    }
    return this.densityOverride;
  }

  @Override
  public ThreadStrategyForRendering getThreadStrategy() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.getThreadStrategy();
    }
    return this.threadStrategy;
  }

  @Override
  public boolean isEnableLayoutSafepoint() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.isEnableLayoutSafepoint();
    }
    return this.enableLayoutSafepoint;
  }

  @Override
  public boolean isEnableUnifiedPipeline() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.isEnableUnifiedPipeline();
    }
    return this.enableUnifiedPipeline;
  }

  @Override
  public Map<String, Object> getContextData() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.getContextData();
    }
    return this.mContextData;
  }

  @Override
  public LynxBackgroundRuntimeOptions getLynxRuntimeOptions() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.getLynxRuntimeOptions();
    }
    return this.lynxRuntimeOptions;
  }

  LynxViewBuilder mergeLynxRuntimeOptions(LynxBackgroundRuntimeOptions other) {
    LynxBackgroundRuntimeOptions options = getLynxRuntimeOptions();
    if (options != null) {
      options.merge(other);
    }
    return this;
  }

  @Override
  public int getScreenWidth() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.getScreenWidth();
    }
    return this.screenWidth;
  }

  @Override
  public int getScreenHeight() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.getScreenHeight();
    }
    return this.screenHeight;
  }

  @Override
  public boolean getForceDarkAllowed() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.getForceDarkAllowed();
    }
    return this.forceDarkAllowed;
  }

  @Override
  public boolean isEnableMultiAsyncThread() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.isEnableMultiAsyncThread();
    }
    return this.enableMultiAsyncThread;
  }

  @Override
  public boolean isEnableSyncFlush() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.isEnableSyncFlush();
    }
    return this.enableSyncFlush;
  }

  @Override
  public boolean isEnableAutoConcurrency() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.isEnableAutoConcurrency();
    }
    return this.enableAutoConcurrency;
  }

  @Override
  public boolean isEnableVSyncAlignedMessageLoop() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.isEnableVSyncAlignedMessageLoop();
    }
    return this.enableVSyncAlignedMessageLoop;
  }

  @Override
  public boolean isEnablePendingJsTask() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.isEnablePendingJsTask();
    }
    return this.enablePendingJsTask;
  }

  @Override
  public boolean isEnableAsyncHydration() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.isEnableAsyncHydration();
    }
    return this.enableAsyncHydration;
  }

  @Override
  public boolean isEnableJSRuntime() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.isEnableJSRuntime();
    }

    if (enableAirStrictMode) {
      return false;
    } else {
      return enableJSRuntime;
    }
  }

  @Override
  public boolean isEnableAirStrictMode() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.isEnableAirStrictMode();
    }
    return this.enableAirStrictMode;
  }

  @Override
  public boolean isDebuggable() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.isDebuggable();
    }
    return this.debuggable;
  }

  @Override
  public int getPresetWidthMeasureSpec() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.getPresetWidthMeasureSpec();
    }
    return this.presetWidthMeasureSpec;
  }

  @Override
  public int getPresetHeightMeasureSpec() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.getPresetHeightMeasureSpec();
    }
    return this.presetHeightMeasureSpec;
  }

  @Override
  public float getFontScale() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.getFontScale();
    }
    return this.fontScale;
  }

  @Override
  public boolean isEnablePreUpdateData() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.isEnablePreUpdateData();
    }
    return this.enablePreUpdateData;
  }

  @Override
  public IUIRendererCreator getUIRendererCreator() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.getUIRendererCreator();
    }
    return this.uiRendererCreator;
  }

  @Override
  public int getEmbeddedMode() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.getEmbeddedMode();
    }
    return this.embeddedMode;
  }

  @Override
  public LynxBooleanOption isEnableGenericResourceFetcher() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.isEnableGenericResourceFetcher();
    }
    return lynxRuntimeOptions.isEnableGenericResourceFetcher();
  }

  @Override
  public LynxGenericResourceFetcher getLynxGenericResourceFetcher() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.getLynxGenericResourceFetcher();
    }
    return lynxRuntimeOptions.getGenericResourceFetcher();
  }

  @Override
  public LynxMediaResourceFetcher getLynxMediaResourceFetcher() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.getLynxMediaResourceFetcher();
    }
    return lynxRuntimeOptions.getMediaResourceFetcher();
  }

  @Override
  public LynxTemplateResourceFetcher getLynxTemplateResourceFetcher() {
    if (lynxViewGroup != null) {
      return lynxViewGroup.getLynxTemplateResourceFetcher();
    }
    return lynxRuntimeOptions.getTemplateResourceFetcher();
  }

  public LynxView build(@NonNull Context context) {
    TraceEvent.beginSection(TraceEventDef.LYNXVIEW_BUILDER_BUILD);
    ILynxTrailService trailService = LynxServiceCenter.inst().getService(ILynxTrailService.class);
    if (trailService != null) {
      trailService.parseLynxViewBuilder(this);
    }

    LynxView lynxView = new LynxView(context, this);
    if (TraceEvent.enableTrace()) {
      HashMap<String, String> args = new HashMap<>();
      if (lynxView.getLynxContext() != null) {
        args.put(
            TraceEventDef.INSTANCE_ID, String.valueOf(lynxView.getLynxContext().getInstanceId()));
      }
      TraceEvent.endSection(
          TraceEvent.CATEGORY_DEFAULT, TraceEventDef.LYNXVIEW_BUILDER_BUILD, args);
    }
    return lynxView;
  }
}

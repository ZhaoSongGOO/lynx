// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

package com.lynx.tasm.behavior.ui.frame;

import android.content.Context;
import android.graphics.Rect;
import androidx.annotation.NonNull;
import androidx.annotation.RestrictTo;
import com.lynx.react.bridge.JavaOnlyMap;
import com.lynx.react.bridge.ReadableMap;
import com.lynx.tasm.LynxUpdateMeta;
import com.lynx.tasm.TemplateBundle;
import com.lynx.tasm.TemplateData;
import com.lynx.tasm.base.LLog;
import com.lynx.tasm.behavior.LynxContext;
import com.lynx.tasm.behavior.LynxProp;
import com.lynx.tasm.behavior.ui.LynxBaseUI;
import com.lynx.tasm.behavior.ui.LynxUI;
import com.lynx.tasm.behavior.ui.UIBody;
import java.lang.ref.WeakReference;
import java.util.HashMap;

@RestrictTo(RestrictTo.Scope.LIBRARY)
public final class UIFrame extends LynxUI<LynxFrameView> {
  private static final String TAG = "UIFrame";

  public UIFrame(LynxContext context) {
    this(context, null);
  }

  public UIFrame(LynxContext context, Object params) {
    super(context, params);
  }

  @Override
  protected LynxFrameView createView(Context context) {
    return new LynxFrameView(mContext);
  }

  @Override
  public void updateExtraData(Object data) {
    if (data instanceof TemplateBundle) {
      LynxFrameView view = getView();
      if (view != null) {
        view.loadBundle((TemplateBundle) data);
      }
    }
  }

  @Override
  public void onNodeReady() {
    super.onNodeReady();
    LynxFrameView view = getView();
    if (view == null) {
      return;
    }
    // TODO(hexionghui): remove callback on uibody
    view.setAttachLynxPageUICallback(new UIBody.UIBodyView.attachLynxPageUICallback() {
      final private WeakReference<LynxBaseUI> mPageUI = new WeakReference<>(UIFrame.this);
      @Override
      public void attachLynxPageUI(@NonNull WeakReference<Object> ui) {
        if (!(ui.get() instanceof UIBody)) {
          return;
        }
        UIBody rootUI = (UIBody) ui.get();
        if (rootUI.getLynxContext() == null) {
          return;
        }
        rootUI.getLynxContext().EnsureEventDispatcher();
        LynxBaseUI pageUI = mPageUI.get();
        if (pageUI == null) {
          return;
        }
        if (pageUI.getChildrenLynxPageUI() == null) {
          pageUI.setChildrenLynxPageUI(new HashMap<>());
        }
        pageUI.getChildrenLynxPageUI().put(String.valueOf(System.identityHashCode(pageUI)), rootUI);
        if (pageUI.getLynxContext() != null && pageUI.getLynxContext().getLynxUIOwner() != null
            && pageUI.getLynxContext().getLynxUIOwner().getRootUI() != null) {
          rootUI.setParentLynxPageUI(pageUI.getLynxContext().getLynxUIOwner().getRootUI());
        }
        if (rootUI.getView() != null) {
          rootUI.getView().setIsChildLynxPageUI(true);
        }
      }
    });
  }

  @Override
  public void onNodeRemoved() {
    super.onNodeRemoved();
    LynxFrameView view = getView();
    if (view != null) {
      view.destroy();
    }
  }

  @Override
  public void updateLayout(int left, int top, int width, int height, int paddingLeft,
      int paddingTop, int paddingRight, int paddingBottom, int marginLeft, int marginTop,
      int marginRight, int marginBottom, int borderLeftWidth, int borderTopWidth,
      int borderRightWidth, int borderBottomWidth, Rect bound) {
    super.updateLayout(left, top, width, height, paddingLeft, paddingTop, paddingRight,
        paddingBottom, marginLeft, marginTop, marginRight, marginBottom, borderLeftWidth,
        borderTopWidth, borderRightWidth, borderBottomWidth, bound);

    LynxFrameView view = getView();
    if (view != null) {
      view.updateViewport(width, height);
    }
  }

  // TODO(zhoupeng): do not convet LepusValue to ReadableMap
  @LynxProp(name = "data")
  public void setData(ReadableMap value) {
    if (!(value instanceof JavaOnlyMap)) {
      LLog.e(TAG, "prop date is not a JavaOnlyMap");
      return;
    }
    LynxFrameView view = getView();
    if (view == null) {
      return;
    }
    LynxUpdateMeta meta = new LynxUpdateMeta.Builder()
                              .setUpdatedData(TemplateData.fromMap((JavaOnlyMap) value))
                              .build();
    view.updateMetaData(meta);
  }

  @LynxProp(name = "src")
  public void setSrc(String value) {
    LynxFrameView view = getView();
    if (view == null) {
      return;
    }
    view.setUrl(value);
  }
}

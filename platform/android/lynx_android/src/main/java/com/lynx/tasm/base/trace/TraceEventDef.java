// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.
package com.lynx.tasm.base.trace;

import androidx.annotation.RestrictTo;

@RestrictTo(RestrictTo.Scope.LIBRARY)
public class TraceEventDef {
  /**
   * @trace_description: Draw LynxView and its children on Android.
   */
  public static final String LYNX_TEMPLATE_RENDER_DRAW = "LynxTemplateRender.Draw";

  /**
   * @trace_description: Layout LynxView and its children on Android.
   */
  public static final String LYNX_TEMPLATE_RENDER_LAYOUT = "LynxTemplateRender.Layout";

  /**
   * @trace_description: Measure LynxView and its children on Android, which may trigger starlight
   * re-layout if MeasureSpec changes.
   */
  public static final String LYNX_TEMPLATE_RENDER_MEASURE = "LynxTemplateRender.Measure";

  /**
   * @trace_description: Layout of <text> element's platform layout node, where the element's
   * characters are @args{characters} or the first 50 characters are @args{first_fifty_characters}.
   * @history_name{text.TextShadowNode.measure}
   */
  public static final String TEXT_SHADOW_NODE_MEASURE = "TextShadowNode.measure";

  /**
   * @trace_description: Redirect the image URL.
   * @link{https://lynxjs.org/api/lynx-native-api/resource-fetcher/mediaresourcefetcher#shouldredirecturl}
   */
  public static final String IMAGE_SHOULD_REDIRECT_IMAGE_URL = "Interceptor.shouldRedirectImageUrl";
}

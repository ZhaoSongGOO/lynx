// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.
NS_ASSUME_NONNULL_BEGIN

#if ENABLE_TRACE_PERFETTO

/**
 * @trace_description: Check the exposure and disexposure states of LynxUIs and send disexposure
 * and exposure events to trigger custom exposure listeners. link:
 * @link{https://lynxjs.org/guide/interaction/visibility-detection/exposure-ability.html}
 */
static NSString* const UI_EXPOSURE_HANDLER = @"LynxUIExposure.exposureHandler";
/**
 * @trace_description:  Layout of <text> element's platform layout node, where the element's
 * characters are @args{characters} or the first 50 characters are @args{first_fifty_characters}.
 * @history_name{text.TextShadowNode.measure}
 */
static NSString* const TEXT_SHADOW_NODE_MEASURE = @"TextShadowNode.measure";

#endif

NS_ASSUME_NONNULL_END

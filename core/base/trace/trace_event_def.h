// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#ifndef CORE_BASE_TRACE_TRACE_EVENT_DEF_H_
#define CORE_BASE_TRACE_TRACE_EVENT_DEF_H_
#if ENABLE_TRACE_PERFETTO || ENABLE_TRACE_SYSTRACE

namespace lynx {

/**
 * @trace_description: Load the Lynx bundle.
 */
static constexpr const char* const LYNX_ENGINE_LOAD_TEMPLATE =
    "LynxEngine::LoadTemplate";
/**
 * @trace_description: Load the Lynx bundle with templateBundle. Reference:
 * @link{https://lynxjs.org/api/lynx-native-api/template-bundle.html}
 */
static constexpr const char* const LYNX_ENGINE_LOAD_TEMPLATE_BUNDLE =
    "LynxEngine::LoadTemplateBundle";
/**
 * @trace_description: Load, parse, and execute @args{url}.
 */
static constexpr const char* const APP_LOAD_SCRIPT = "App::loadScript";
/**
 * @trace_description: Load, parse and execute background scripts @args{url}.
 */
static constexpr const char* const LOAD_JS_APP = "LoadJSApp";
/**
 * @trace_description: Execute @args{name} on background scripting
 * thread(historically known as "JS Thread").
 */
static constexpr const char* const RUNNING_IN_JS = "RunningInJS";
/**
 * @trace_description: Execute the @args{module_name}.@args{method} method on
 * the background scripting thread (historically known as "JS Thread").
 */
static constexpr const char* const CALL_JS_FUNCTION = "CallJSFunction";
/**
 * @trace_description: Execute the callbacks for the @args{type} event on
 * background scripting thread (historically known as "JS Thread").
 */
static constexpr const char* const CALL_JS_CLOSURE_EVENT = "CallJSClosureEvent";
/**
 * @trace_description: Get and call the main script's global function:
 * @args{name}.
 */
static constexpr const char* const QUICK_CONTEXT_GET_AND_CALL =
    "QuickContext::GetAndCall";
/**
 * @trace_description: Call @args{name} on Engine thread (historically known as
 * "Tasm Thread").
 */
static constexpr const char* const QUICK_CONTEXT_CALL = "QuickContext::Call";
/**
 * @trace_description: Create a <wrapper/> element, a special
 * element provided by the FiberElement API designed to serve as a low-cost
 * container.
 */
static constexpr const char* const FIBER_ELEMENT_CREATE_WRAPPER_ELEMENT =
    "FiberCreateWrapperElement";
/**
 * @trace_description: Update the component's info, such as path, id, and the
 * compiled render function.
 */
static constexpr const char* const RADON_DIFF_UPDATE_COMPONENT_INFO =
    "UpdateComponentInfo";
/*
 * @trace_description: Convert the updated value into LepusValue. Then send this
 * value to the Engine thread to trigger the component's update process.
 */
static constexpr const char* const BATCHED_UPDATE_DATA = "batchedUpdateData";

/**
 * @trace_description: Create virtual Component on Engine thread (historically
 * known as "TASM Thread"). Component's name is @args{componentName}. One or
 * more components form a virtual node tree, which is used for subsequent render
 * and dispatch processes.
 */
static constexpr const char* const CREATE_VIRTUAL_COMPONENT =
    "CreateVirtualComponent";
/**
 * @trace_description: Invoke the NativeModule method with module name
 * @args{module}, method name @args(method} and first_args @args{first_arg}.
 * @history_name{CallJSB}
 */
static constexpr const char* const INVOKE_NATIVE_MODULE = "InvokeNativeModule";
/**
 * @trace_description: Start a pipeline. Pipeline trigger is
 * @args{pipeline_origin}. About Lynx pipeline:
 * @link{https://lynxjs.org/api/lynx-api/performance-api/performance-entry/pipeline-entry.html}
 */
static constexpr const char* const TIMING_PIPELINE_START =
    "Timing::OnPipelineStart";
/**
 * @trace_description: Send reporting tasks, such as Timing reports and
 * LongTask detection reports, to the asynchronous thread.
 */
static constexpr const char* const EVENT_TRACKER_FLUSH = "EventTracker::Flush";

/**
 * @trace_description: Send a request of LazyBundle on Background Thread
 * Script(BTS). It only occurs when rendering LazyBundle on ReactLynx3.
 */
static constexpr const char* const APP_QUERY_COMPONENT = "App::QueryComponent";

/**
 * @trace_description: Synchronously execute UI operations, such as creating
 * platform ui.
 */
static constexpr const char* const UI_OPERATION_QUEUE_FLUSH =
    "LynxUIOperationQueue.Flush";

/**
 * @trace_description: Execute the platform ui operations, such as creating,
 * inserting, updating, and deleting platform ui.
 */
static constexpr const char* const UI_OPERATION_QUEUE_EXECUTE =
    "LynxUIOperationQueue::ExecuteOperation";

/**
 * @trace_description: Execute UI operations, such as creating
 * platform ui.
 */
static constexpr const char* const UI_OPERATION_ASYNC_QUEUE_FLUSH =
    "LynxUIOperationAsyncQueue::FlushInterval";

}  // namespace lynx

#endif  // #if ENABLE_TRACE_PERFETTO || ENABLE_TRACE_SYSTRACE

#endif  // CORE_BASE_TRACE_TRACE_EVENT_DEF_H_

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
 * @trace_description: Load the Lynx bundle, which includes four parts: load,
 * parse, framework rendering, and pixel pipeline.
 * 1. Load: request the bundle;
 * 2. Parse: parse bundle for subsequent pipeline process;
 * 3. Framework rendering: create and synchronize its internal representation of
 * the UI with the actual element tree in the engine through element
 * manipulation.
 * @link{https://lynxjs.org/guide/spec.html#frameworkrendering-framework-rendering};
 * 4. Pixel pipeline: processes element tree into pixels that are displayed on
 * the users' screen.
 * @link{https://lynxjs.org/guide/spec.html#enginepixeling-pixel-pipeline};
 */
static constexpr const char* const LYNX_LOAD_TEMPLATE = "LynxLoadTemplate";
/**
 * @trace_description: At this stage, based on the attribute of the element, the
 * computed style and prop bundle of the element are generated and synchronized
 * to the layout node. This stage will also create and modify layout node tree.
 * At the same time, it will also generate platform UI operations.
 */
static constexpr const char* const FIBER_ELEMENT_FLUSH_ACTIONS =
    "FiberElement::FlushActions";
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
 * @trace_description: Update component Data. Component name is
 * @args{componentName}. Updated Keys is @args{Keys}. `Keys` represent the state
 * keys updated in this update.
 */
static constexpr const char* const RADON_DIFF_UPDATE_COMPONENT_DARA =
    "UpdateComponentData";
/**
 * @trace_description: Update the component's info, such as path, id, and the
 * compiled render function.
 */
static constexpr const char* const RADON_DIFF_UPDATE_COMPONENT_INFO =
    "UpdateComponentInfo";
/**
 * @trace_description: RootComponent update triggered by background scripting
 * thread(historically known as "JS Thread").
 */
static constexpr const char* const LYNX_UPDATE_DATA_BY_JS =
    "LynxUpdateDataByJS";
/*
 * @trace_description: Convert the updated value into LepusValue. Then send this
 * value to the Engine thread to trigger the component's update process.
 */
static constexpr const char* const BATCHED_UPDATE_DATA = "batchedUpdateData";
/**
 * @trace_description: Batch update for component on Engine Thread(historically
 * known as "Tasm Thread").
 */
static constexpr const char* const LYNX_BATCHED_UPDATE_DATA =
    "LynxBatchedUpdateData";
/**
 * @trace_description: Root Component update. Updated Keys is @args{Keys}. Keys
 * represent the keys of the state that were updated in this update. defaultData
 * represents the current state keys of the root component.
 */
static constexpr const char* const LYNX_UPDATE_DATA = "LynxUpdateData";
/**
 * @trace_description: Component update triggered by background scripting thread
 * (historically known as "JS Thread"). A component update can be triggered for
 * multiple reasons.
 */
static constexpr const char* const LYNX_UPDATE_COMPONENT_DATA_BY_JS =
    "LynxUpdateComponentDataByJS";
/**
 * @trace_description: Update the attributes of the RadonNode and recursively
 * execute DispatchChildrenForDiff process of its child.
 */
static constexpr const char* const RADON_DIFF_DISPATCH_CHILDREN =
    "DispatchChildrenForDiff";
/**
 * @trace_description: Update the data of the @args{componentName} component.
 */
static constexpr const char* const RADON_COMPONENT_UPDATE_COMPONENT =
    "RadonComponent::UpdateRadonComponent";
/**
 * @trace_description: Create virtual Component on Engine thread (historically
 * known as "TASM Thread"). Component's name is @args{componentName}. One or
 * more components form a virtual node tree, which is used for subsequent render
 * and dispatch processes.
 */
static constexpr const char* const CREATE_VIRTUAL_COMPONENT =
    "CreateVirtualComponent";
/**
 * @trace_description: Create child nodes and update component attributes, then
 * execute DispatchForDiff process for child nodes. Finally, send the
 * "__OnReactComponentDidUpdate" to trigger the component's componentDidUpdate
 * lifecycle method.
 */
static constexpr const char* const RADON_COMPONENT_DISPATCH_FOR_DIFF =
    "RadonComponent::DispatchForDiff";
/**
 * @trace_description: Diff process of the virtual node tree in Lynx using the
 * MyersDiff algorithm.
 */
static constexpr const char* const RADON_MYERS_DIFF =
    "RadonBase::RadonMyersDiff";
/**
 * @trace_description: Create element and update attributes of the node if
 * needed.
 */
static constexpr const char* const RADON_DISPATCH_SELF = "RadonDispatchSelf";
/**
 * @trace_description: No changes happened in the update pipeline; it is
 * considered a useless update.
 */
static constexpr const char* const ELEMENT_MANAGER_ON_PATCH_FINISH_NO_PATCH =
    "ElementManager::OnPatchFinishNoPatch";
/**
 * @trace_description: Execute tasks such as the layout of elements and the
 * creation of platform UI views after the virtual nodes diff process is
 * completed.
 */
static constexpr const char* const ELEMENT_MANAGER_ON_PATCH_FINISH =
    "ElementManager::OnPatchFinish";

/**
 * @trace_description: Execute the platform ui operations, such as creating,
 * inserting, updating, and deleting platform ui.
 */
static constexpr const char* const UI_OPERATION_QUEUE_EXECUTE =
    "LynxUIOperationQueue::ExecuteOperation";
/**
 * @trace_description: Synchronously execute UI operations, such as creating
 * platform ui.
 */
static constexpr const char* const UI_OPERATION_QUEUE_FLUSH =
    "LynxUIOperationQueue.Flush";
/**
 * @trace_description: Execute UI operations, such as creating
 * platform ui.
 */
static constexpr const char* const UI_OPERATION_ASYNC_QUEUE_FLUSH =
    "LynxUIOperationAsyncQueue::FlushInterval";
/**
 * @trace_description: Layout stage. This stage is based on layout node tree to
 * complete the layout stage, and finally synchronize the layout results to
 * element. Element adjusts the layout results and generates UI layout op.
 */
static constexpr const char* const LAYOUT_CONTEXT_LAYOUT =
    "LayoutContext.Layout";
/**
 * @trace_description: Request to trigger the Layout stage when layout related
 * computed styles, such as width, height, are updated.
 */
static constexpr const char* const LAYOUT_CONTEXT_REQUEST_LAYOUT =
    "LayoutContext.RequestLayout";
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
 * @trace_description: Update content size and offset and flush content size and
 * scroll info to platform ListContainerView.
 */
static constexpr const char* const FLUSH_CONTENT_SIZE_AND_OFFSET_TO_PLATFORM =
    "FlushContentSizeAndOffsetToPlatform";

/**
 * @trace_description: Prerender of off-screen upper elements in the <list>
 * component.
 */
static constexpr const char* const LIST_PRE_RENDER_OFF_SCREEN_UPPER_ELEMENT =
    "LinearLayoutManager::PreloadToStart";

/**
 * @trace_description: Pre-render off-screen list child components for c++ list.
 * @history_name{Preload}
 */
static constexpr const char* const LIST_PRELOAD =
    "LinearLayoutManager::Preload";
/**
 * @trace_description: Render one list child component in ReactLynx2 or
 * TTMLRadonDiff.
 * @history_name{List::RenderComponent}
 */
static constexpr const char* const RADON_LIST_RENDER_COMPONENT =
    "RadonDiffListNode2::ComponentAtIndex";

/**
 * @trace_description: Render one list child component in ReactLynx3 or
 * TTMLNoDiff.
 */
static constexpr const char* const LIST_ELEMENT_RENDER_COMPONENT =
    "ListElement::ComponentAtIndex";

/**
 * @trace_description: Parse diff result and list child component info in
 * ReactLynx2 or TTMLRadonDiff for c++ list.
 */
static constexpr const char* const LIST_ADAPTER_UPDATE_DATA_SOURCE =
    "ListAdapter::UpdateDataSource";

/**
 * @trace_description:  Parse diff result and list child component info in
 * ReactLynx3 or TTMLNoDiff for c++ list.
 */
static constexpr const char* const LIST_ADAPTER_UPDATE_FIVER_DATA_SOURCE =
    "ListAdapter::UpdateFiberDataSource";

/**
 * @trace_description: Send a request of LazyBundle on Main Thread Script(MTS).
 * It is a necessary step to render a LazyBundle. However, it only occurs when
 * rendering LazyBundle on IFR in ReactLynx3.
 * @link{https://lynxjs.org/guide/interaction/ifr.html}
 */
static constexpr const char* const LAZY_BUNDLE_REQUIRE_TEMPLATE =
    "LazyBundle::RequireTemplateEntry";

/**
 * @trace_description: Send a request of LazyBundle on Background Thread
 * Script(BTS). It only occurs when rendering LazyBundle on ReactLynx3.
 */
static constexpr const char* const APP_QUERY_COMPONENT = "App::QueryComponent";

}  // namespace lynx

#endif  // #if ENABLE_TRACE_PERFETTO || ENABLE_TRACE_SYSTRACE

#endif  // CORE_BASE_TRACE_TRACE_EVENT_DEF_H_

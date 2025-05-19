// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#import <Lynx/LynxFrameView.h>

#import <Lynx/LynxFrameRender.h>

#pragma mark - LynxFrameView

@implementation LynxFrameView {
  LynxFrameRender *_render;
}

// TODO(zhoupeng.z): implement following methods, some of them are useless for LynxFrameView.
// Optimize it later

#pragma mark - LUIErrorHandling

- (void)didReceiveResourceError:(LynxError *_Nullable)error
                     withSource:(NSString *_Nullable)resourceUrl
                           type:(NSString *_Nullable)type {
}

- (void)reportError:(nonnull NSError *)error {
}

- (void)reportLynxError:(LynxError *_Nullable)error {
}

#pragma mark - LUIBodyView

- (BOOL)enableAsyncDisplay {
  return NO;
}

- (void)setEnableAsyncDisplay:(BOOL)enableAsyncDisplay {
}

- (NSString *)url {
  return nil;
}

- (int32_t)instanceId {
  return -1;
}

- (void)sendGlobalEvent:(nonnull NSString *)name withParams:(nullable NSArray *)params {
}

- (void)setIntrinsicContentSize:(CGSize)size {
}

- (BOOL)enableTextNonContiguousLayout {
  return YES;
}

- (void)runOnTasmThread:(dispatch_block_t)task {
}

// TODO(zhoupeng.z):implement it by frame render
- (LynxThreadStrategyForRender)getThreadStrategyForRender {
  return LynxThreadStrategyForRenderAllOnUI;
}

@end

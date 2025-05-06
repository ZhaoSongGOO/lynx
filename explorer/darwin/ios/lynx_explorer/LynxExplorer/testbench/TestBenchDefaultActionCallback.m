// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#import "TestBenchDefaultActionCallback.h"
#import <Lynx/LynxProviderRegistry.h>
#import <Lynx/LynxRawTextShadowNode.h>
#import <Lynx/LynxTextShadowNode.h>
#import <Lynx/LynxUIText.h>
#import <Lynx/LynxUIView.h>
#import <Lynx/LynxView.h>
#import "ExplorerModule.h"

static const int kVirtual = 1 << 2;

@interface TestBenchDefaultActionCallback ()
@end

@implementation TestBenchDefaultActionCallback

- (void)onLynxViewWillBuild:(TestBenchActionManager *)manager builder:(LynxViewBuilder *)builder {
  [builder.config registerModule:[ExplorerModule class]];
}
- (void)onLynxViewDidBuild:(LynxView *)lynxView {
}
@end

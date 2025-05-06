// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#import <TestBenchReplay/TestBenchActionManager.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TestBenchDefaultActionCallback : NSObject <TestBenchActionCallback>

- (void)onLynxViewWillBuild:(TestBenchActionManager *)manager builder:(LynxViewBuilder *)builder;
- (void)onLynxViewDidBuild:(LynxView *)lynxView;

@end

NS_ASSUME_NONNULL_END

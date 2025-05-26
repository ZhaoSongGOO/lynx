// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

package com.lynx.explorer.shell;

import com.lynx.tasm.LynxGroup;
import com.lynx.tasm.LynxGroup.LynxGroupBuilder;
import com.lynx.tasm.LynxViewBuilder;
import com.lynx.testbench.TestBenchActionCallback;
import com.lynx.testbench.TestBenchActionManager;

public class TestBenchDefaultActionCallback implements TestBenchActionCallback {
  @Override
  public void onLynxViewWillBuild(TestBenchActionManager manager, LynxViewBuilder builder) {
    String[] paths = manager.getTestBenchPreloadScripts();

    LynxGroup lynxGroup = manager.getLynxGroup();
    if (lynxGroup == null) {
      lynxGroup = new LynxGroupBuilder().setGroupName("testbench").setPreloadJSPaths(paths).build();
      manager.setLynxGroup(lynxGroup);
    }
    builder.setLynxGroup((LynxGroup) lynxGroup);
  }
}

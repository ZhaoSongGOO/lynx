// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

package com.lynx.testbench;

import org.json.JSONArray;
import org.json.JSONObject;

public interface TestBenchReplayDataProvider {
  JSONArray getFunctionCall();
  JSONObject getCallbackData();
  JSONArray getJsbIgnoredInfo();
  JSONObject getJsbSettings();
}

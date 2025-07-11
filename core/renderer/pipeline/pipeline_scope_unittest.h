// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#ifndef CORE_RENDERER_PIPELINE_PIPELINE_SCOPE_UNITTEST_H_
#define CORE_RENDERER_PIPELINE_PIPELINE_SCOPE_UNITTEST_H_

#include <memory>

#include "core/renderer/template_assembler.h"
#include "core/shell/testing/mock_tasm_delegate.h"
#include "third_party/googletest/googletest/include/gtest/gtest.h"

namespace lynx {
namespace tasm {
namespace test {
class PipelineScopeTest : public testing::Test {
 public:
  PipelineScopeTest();
  ~PipelineScopeTest() override = default;
  void SetUp() override{};
  void TearDown() override{};

 private:
  std::unique_ptr<TemplateAssembler> tasm_{nullptr};
  std::unique_ptr<MockTasmDelegate> delegate_{nullptr};
};
}  // namespace test
}  // namespace tasm
}  // namespace lynx

#endif  // CORE_RENDERER_PIPELINE_PIPELINE_SCOPE_UNITTEST_H_

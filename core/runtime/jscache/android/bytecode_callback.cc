// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#include "core/runtime/jscache/android/bytecode_callback.h"

#include "platform/android/lynx_android/src/main/jni/gen/LynxBytecodeCallback_jni.h"

namespace lynx {
namespace jni {

bool RegisterJNIForLynxBytecodeCallback(JNIEnv* env) {
  return RegisterNativesImpl(env);
}

}  // namespace jni
}  // namespace lynx

namespace lynx {
namespace piper {
namespace cache {

void OnBytecodeResponse(JNIEnv* env,
                        base::android::ScopedGlobalJavaRef<jobject> obj,
                        base::android::ScopedLocalJavaRef<jstring> error_msg,
                        jobject& byte_buffer) {
  Java_LynxBytecodeCallback_onResponse(
      env, obj.Get(), error_msg.IsNull() ? nullptr : error_msg.Get(),
      byte_buffer);
}

}  // namespace cache
}  // namespace piper
}  // namespace lynx

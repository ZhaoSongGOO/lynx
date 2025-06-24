// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#ifndef CORE_RUNTIME_JSCACHE_ANDROID_BYTECODE_CALLBACK_H_
#define CORE_RUNTIME_JSCACHE_ANDROID_BYTECODE_CALLBACK_H_

#include <jni.h>

#include "core/base/android/android_jni.h"

namespace lynx {
namespace piper {
namespace cache {

void OnBytecodeResponse(JNIEnv* env,
                        base::android::ScopedGlobalJavaRef<jobject> obj,
                        base::android::ScopedLocalJavaRef<jstring> error_msg,
                        jobject& byte_buffer);

}  // namespace cache
}  // namespace piper
}  // namespace lynx

#endif  // CORE_RUNTIME_JSCACHE_ANDROID_BYTECODE_CALLBACK_H_

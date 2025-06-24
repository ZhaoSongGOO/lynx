/**
 * Copyright (c) 2015-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

package com.lynx.jsbridge;

import androidx.annotation.Keep;
import com.lynx.tasm.base.CalledByNative;
import java.nio.ByteBuffer;

/**
 * Interface that represents a bytecode generate result.
 */
@Keep
public interface LynxBytecodeCallback {
  /**
   * response when bytecode generate finish.
   * @param errorMsg when success, errorMsg will be null, otherwise is error.
   * @param buffer when success, this will be bytecode result.
   */
  @Keep @CalledByNative void onResponse(String errorMsg, ByteBuffer buffer);
}

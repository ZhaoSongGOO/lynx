// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#ifndef CORE_RUNTIME_VM_LEPUS_LYNX_VALUE_EXTENDED_H_
#define CORE_RUNTIME_VM_LEPUS_LYNX_VALUE_EXTENDED_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "base/include/value/lynx_value_types.h"
#include "quickjs/include/quickjs.h"

#define MAKE_LYNX_VALUE(val, tag)                                            \
  {                                                                          \
    .val_ptr = reinterpret_cast<lynx_value_ptr>(LEPUS_VALUE_GET_INT64(val)), \
    .type = lynx_value_extended, .tag = tag                                  \
  }

// TODO(frendy): move this to single file
lynx_api_env lynx_value_api_new_env(LEPUSContext* ctx);
void lynx_value_api_delete_env(lynx_api_env env);
LEPUSContext* lynx_value_api_get_context_from_env(lynx_api_env env);

lynx_api_status lynx_value_get_bool(lynx_api_env env, lynx_value value,
                                    bool* result);
lynx_api_status lynx_value_is_integer(lynx_api_env env, lynx_value value,
                                      bool* result);
lynx_api_status lynx_value_get_integer(lynx_api_env env, lynx_value value,
                                       int64_t* result);
lynx_api_status lynx_value_get_number(lynx_api_env env, lynx_value value,
                                      double* result);
lynx_api_status lynx_value_get_string_ref(lynx_api_env env, lynx_value value,
                                          void** result);
lynx_api_status lynx_value_get_external(lynx_api_env env, lynx_value value,
                                        void** result);
lynx_api_status lynx_value_get_length(lynx_api_env env, lynx_value value,
                                      uint32_t* result);
lynx_api_status lynx_value_is_array(lynx_api_env env, lynx_value value,
                                    bool* result);
lynx_api_status lynx_value_set_element(lynx_api_env env, lynx_value object,
                                       uint32_t index, lynx_value value);
lynx_api_status lynx_value_get_element(lynx_api_env env, lynx_value object,
                                       uint32_t index, lynx_value* result);
lynx_api_status lynx_value_is_map(lynx_api_env env, lynx_value value,
                                  bool* result);
lynx_api_status lynx_value_set_named_property(lynx_api_env env,
                                              lynx_value object,
                                              const char* utf8name,
                                              lynx_value value);
lynx_api_status lynx_value_has_named_property(lynx_api_env env,
                                              lynx_value object,
                                              const char* utf8name,
                                              bool* result);
lynx_api_status lynx_value_get_named_property(lynx_api_env env,
                                              lynx_value object,
                                              const char* utf8name,
                                              lynx_value* result);
lynx_api_status lynx_value_is_function(lynx_api_env env, lynx_value value,
                                       bool* result);
lynx_api_status lynx_value_to_string_utf8(lynx_api_env env, lynx_value value,
                                          void* result);
lynx_api_status lynx_value_typeof(lynx_api_env env, lynx_value value,
                                  lynx_value_type* result);

#ifdef __cplusplus
}
#endif

#endif  // CORE_RUNTIME_VM_LEPUS_LYNX_VALUE_EXTENDED_H_

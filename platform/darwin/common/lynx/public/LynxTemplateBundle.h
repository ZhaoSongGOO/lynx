// Copyright 2022 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#ifndef DARWIN_COMMON_LYNX_LYNX_TEMPLATE_BUNDLE_H_
#define DARWIN_COMMON_LYNX_LYNX_TEMPLATE_BUNDLE_H_

#import <Lynx/LynxTemplateBundleOption.h>

/**
 * block that represents a bytecode generate result callback.
 * @param errorMsg when success, errorMsg will be null, otherwise is error.
 * @param buffer when success, this will be bytecode result. Note: Please note that the current
 * NSData is constructed using dataWithBytesNoCopy. If you need to use it, please make a copy
 * yourself and do not store this object directly.
 */
typedef void (^LynxBytecodeResponseBlock)(NSString* _Nullable errorMsg, NSData* _Nullable buffer);

@interface LynxTemplateBundle : NSObject

@property(nonatomic, readonly, nullable) NSString* url;

- (instancetype _Nullable)initWithTemplate:(nonnull NSData*)tem;
- (instancetype _Nullable)initWithTemplate:(nonnull NSData*)tem
                                    option:(nullable LynxTemplateBundleOption*)option;
- (NSString* _Nullable)errorMsg;

/**
 * get ExtraInfo of a `template.js`
 *
 * @return ExtraInfo of LynxTemplate
 */
- (NSDictionary* _Nullable)extraInfo;

/**
 * Whether the TemplateBundle contains a Valid ElementBundle.
 */
- (BOOL)isElementBundleValid;

/**
 * Post a task to generate bytecode for a given template bundle.
 * The task will be executed in a background thread.
 * @param bytecodeSourceUrl The source url of the template.
 */
- (void)postJsCacheGenerationTask:(nonnull NSString*)bytecodeSourceUrl;

/**
 * Post a task to generate bytecode for a given template bundle.
 * The task will be executed in a background thread.
 * @param bytecodeSourceUrl The source url of the template.
 * @param callback When generate finished, this will response the result.
 */
- (void)postJsCacheGenerationTask:(nonnull NSString*)bytecodeSourceUrl
                         callback:(nullable LynxBytecodeResponseBlock)callback;

@end

#endif  // DARWIN_COMMON_LYNX_LYNX_TEMPLATE_BUNDLE_H_

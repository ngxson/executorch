/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>

#ifdef __cplusplus
 #import <executorch/extension/module/module.h>
 #import <executorch/runtime/core/evalue.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@interface ExecutorchRuntimeTensorValue : NSObject

@property (nonatomic, readonly) NSArray<NSNumber *> *shape;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithFloatArray:(NSArray<NSNumber *> *)floatArray shape:(NSArray<NSNumber *> *)sizes NS_SWIFT_NAME(init(floatArray:shape:));

#ifdef __cplusplus
- (nullable instancetype)initWithTensor:(torch::executor::Tensor)tensor error:(NSError * _Nullable * _Nullable)error;
- (instancetype)initWithData:(std::vector<float>)floatData
                       shape:(std::vector<int32_t>)shape NS_DESIGNATED_INITIALIZER;
- (torch::executor::Tensor)backedValue;
#endif

#pragma mark - 
- (NSArray<NSNumber *> * _Nullable)floatArrayAndReturnError:(NSError * _Nullable * _Nullable)error;

@end

NS_ASSUME_NONNULL_END

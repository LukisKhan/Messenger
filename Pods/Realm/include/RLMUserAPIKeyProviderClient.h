////////////////////////////////////////////////////////////////////////////
//
// Copyright 2020 Realm Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
////////////////////////////////////////////////////////////////////////////

#import <Realm/RLMProviderClient.h>

@class RLMUserAPIKey, RLMObjectId;

NS_ASSUME_NONNULL_BEGIN

/// Provider client for user API keys.
@interface RLMUserAPIKeyProviderClient : RLMProviderClient

/// A block type used to report an error
typedef void(^RLMUserAPIKeyProviderClientOptionalErrorBlock)(NSError * _Nullable);

/// A block type used to return an `RLMUserAPIKey` on success, or an `NSError` on failure
typedef void(^RLMOptionalUserAPIKeyBlock)(RLMUserAPIKey * _Nullable, NSError * _Nullable);

/// A block type used to return an array of `RLMUserAPIKey` on success, or an `NSError` on failure
typedef void(^RLMUserAPIKeysBlock)(NSArray<RLMUserAPIKey *> *  _Nullable, NSError * _Nullable);

/**
  Creates a user API key that can be used to authenticate as the current user.
 
  @param name The name of the API key to be created.
  @param completion A callback to be invoked once the call is complete.
*/
- (void)createApiKeyWithName:(NSString *)name
                  completion:(RLMOptionalUserAPIKeyBlock)completion;

/**
  Fetches a user API key associated with the current user.
 
  @param objectId The ObjectId of the API key to fetch.
  @param completion A callback to be invoked once the call is complete.
 */
- (void)fetchApiKey:(RLMObjectId *)objectId
         completion:(RLMOptionalUserAPIKeyBlock)completion;

/**
  Fetches the user API keys associated with the current user.
 
  @param completion A callback to be invoked once the call is complete.
 */
- (void)fetchApiKeysWithCompletion:(RLMUserAPIKeysBlock)completion;

/**
  Deletes a user API key associated with the current user.
 
  @param objectId The ObjectId of the API key to delete.
  @param completion A callback to be invoked once the call is complete.
 */
- (void)deleteApiKey:(RLMObjectId *)objectId
          completion:(RLMUserAPIKeyProviderClientOptionalErrorBlock)completion;

/**
  Enables a user API key associated with the current user.
 
  @param objectId The ObjectId of the  API key to enable.
  @param completion A callback to be invoked once the call is complete.
 */
- (void)enableApiKey:(RLMObjectId *)objectId
          completion:(RLMUserAPIKeyProviderClientOptionalErrorBlock)completion;

/**
  Disables a user API key associated with the current user.
 
  @param objectId The ObjectId of the API key to disable.
  @param completion A callback to be invoked once the call is complete.
 */
- (void)disableApiKey:(RLMObjectId *)objectId
           completion:(RLMUserAPIKeyProviderClientOptionalErrorBlock)completion;

@end

NS_ASSUME_NONNULL_END

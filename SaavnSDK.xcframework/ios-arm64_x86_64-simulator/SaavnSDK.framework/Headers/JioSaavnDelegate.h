//
//  JioSaavnDelegate.h
//  SaavnSDK
//
//  Created by Rishabh Tiwari on 30/09/21.
//  Copyright © 2021 Saavn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol JioSaavnDelegate <NSObject>

/**
   @brief Called when back button on last vc on stack is clicked or close button to dismiss the entire stack.

   @param viewController is the reference of ViewController on which the backButton or closeButton is pressed
   @remark Should be used for toggling tab bar visibility and popping/dismissal for ViewController
*/

- (void)dismissFromJioSaavn:(id)viewController isClose:(BOOL)isClose;

/**
   @brief This method will be called when refreshed session token dict is required.
     Pass the appropriate refresh token dict
*/

- (NSDictionary *)refreshSessionTokenDict;

/**
    @brief This will be called on launch of JioTune controller,
    MyJio should hit the current subscription api, parse the data and return it as a JioTuneData object through
    given doorway method:
 
 - (void) handleCurrentJioTuneData: (NSDictionary *)data;
 */

- (void)getCurrentJioTuneData;

/**
   @brief This will be called for deactivating current jio tune
   MyJio should call the deactivate api and pass the response as a boolean(api success, failure) and errorMsg whether the deactivation was successful or not.
   given doorway method:

- (void) deactiveJioTuneResponse:(BOOL)isSuccess errorMsg:(NSString *)errorMsg;
*/

- (void)deactivateJioTune:(NSString *)vcode digitalServiceId:(NSString *)digitalServiceId;

@end

NS_ASSUME_NONNULL_END

//
//  DataCounters.h
//  Saavn
//
//  Created by Ramesh Sudini on 4/26/17.
//  Copyright © 2017 Saavn. All rights reserved.
//

#ifndef DataCounters_h
#define DataCounters_h
typedef NS_ENUM(NSInteger, AFNetworkReachabilityStatus);
@interface DataCounters : NSObject {
    NSTimeInterval last_event_post_time;
}
@property (nonatomic, assign) NSTimeInterval last_event_post_time;

+ (instancetype) sharedManager;
// Setters
- (void) setApiDataSent:(double)value;
- (void) setApiDataReceived:(double)value;
- (void) setStreamingData:(double)value;
// Getters
-(double) getApiDataSent;
-(double) getApiDataReceived;
-(double) getStreamingData;
- (void) resetData;

+ (NSDictionary *) getDataCounters;
+ (void) addMeasurement:(double) measurement;
+ (double) getAverageBitRate;
+ (void) internetChanged:(AFNetworkReachabilityStatus)status;
+ (void) addSampling;

@end
#endif /* DataCounters_h */

#import <Foundation/Foundation.h>
#import <CoreVideo/CoreVideo.h>

@class Landmark;
@class PoseTracker;

@protocol PoseTrackerDelegate <NSObject>
- (void)poseTracker: (PoseTracker *)tracker didOutputLandmarks: (NSArray<Landmark *> *)landmarks;
- (void)poseTracker: (PoseTracker *)tracker didOutputPixelBuffer: (CVPixelBufferRef)pixelBuffer;
@end

@interface PoseTracker : NSObject
- (instancetype)init;
- (void)startGraph;
- (void)sendPixelBuffer:(CVPixelBufferRef)pixelBuffer;
@property (weak, nonatomic) id <PoseTrackerDelegate> delegate;
@end

@interface Landmark: NSObject
@property(nonatomic, readonly) float x;
@property(nonatomic, readonly) float y;
@property(nonatomic, readonly) float z;
@end

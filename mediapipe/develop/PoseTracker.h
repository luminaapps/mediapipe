#import <Foundation/Foundation.h>
#import <CoreVideo/CoreVideo.h>

@class Landmark;
@class PoseTracker;

@protocol PoseTrackerDelegate <NSObject>
- (void)poseTracker: (nonnull PoseTracker *)tracker didOutputLandmarks: (nonnull NSArray<Landmark *> *)landmarks;
- (void)poseTracker: (nonnull PoseTracker *)tracker didOutputPixelBuffer: (nonnull CVPixelBufferRef)pixelBuffer;
@end

@interface PoseTracker : NSObject
- (nonnull instancetype)init;
- (void)startGraph;
- (void)sendPixelBuffer:(nonnull CVPixelBufferRef)pixelBuffer;
@property (weak, nonatomic) id <PoseTrackerDelegate> delegate;
@end

@interface Landmark: NSObject
@property(nonatomic, readonly) CGFloat x;
@property(nonatomic, readonly) CGFloat y;
@property(nonatomic, readonly) CGFloat z;
@property(nonatomic, readonly) CGFloat visibility;
@end

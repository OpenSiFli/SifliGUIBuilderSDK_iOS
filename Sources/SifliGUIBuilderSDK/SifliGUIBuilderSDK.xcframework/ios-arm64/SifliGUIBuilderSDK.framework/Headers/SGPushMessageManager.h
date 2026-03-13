//
//  SGPushMessageManager.h
//  SiFliGUIBuilderSDK
//
//  Created by Sean on 2026/3/7.
//

#import <Foundation/Foundation.h>
#import <SifliOCore/SifliOCore.h>

NS_ASSUME_NONNULL_BEGIN

@class SGPushMessageManager;
@protocol SGPushMessageManagerDelegate <NSObject>

- (void)pushMessageManager:(SGPushMessageManager *)manager updateBleState:(SFBleCoreManagerState)state;
- (void)pushMessageManager:(SGPushMessageManager *)manager success:(BOOL)success errror:(nullable SFCoreError *)error;
- (void)pushMessageManager:(SGPushMessageManager *)manager updateManagerState:(SFBleShellStatus)state;

@end

@interface SGPushMessageManager : NSObject
@property (nonatomic,weak) id<SGPushMessageManagerDelegate> delegate;
+ (SGPushMessageManager *)shared;
- (void)sendSwitchThemeCmdWithIdentifier:(NSString *)identifier appId:(NSString *)appId themeId:(NSString *)themeId;
- (void)sendDeletePatchCmdWithIdentifier:(NSString *)identifier appId:(NSString *)appId patchFileName:(NSString *)patchFileName;
- (void)sendDeleteAppCmdWithIdentifier:(NSString *)identifier appId:(NSString *)appId;
@end

NS_ASSUME_NONNULL_END

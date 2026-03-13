//
//  SGAppResUserContext.h
//  SiFliGUIBuilderSDK
//
//  Created by Sean on 2026/3/5.
//

#import <Foundation/Foundation.h>
#import <SiFliGUIBuilderSDK/SGWorkSpaceManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface SGAppResUserContext : NSObject

/// ezipColor color type as below: rgb565, rgb565A, rbg888, rgb888A
@property (nonatomic, copy, readonly) NSString *ezipColor;

/// 0 keep original alpha channel  1 no alpha channel
@property (nonatomic, assign, readonly) NSInteger ezipNoAlpha;

/// set 0 to support rotation  set 1 for no rotation
@property (nonatomic, assign, readonly) NSInteger ezipNoRotation;

/// 板子芯片类型     * 0: 55x 1: 56x 2: 52x
@property (nonatomic, assign, readonly) NSInteger ezipBoardType;

/// 拓展资源在设备上的制作路径模版，如
/// dyn/dynamic_app/tool_wf/{app_id}/{uid}.bin
/// 其中的app_id 为SiFliGUIBuilder中工程的ID
/// uid 为拓展资源的UID,SiFliGUIBuilder 生成表盘时为每一个资源编码确定
@property (nonatomic, copy, readonly) NSString *watchPathTemp;

/// 表盘/应用工程的ID
@property (nonatomic, copy, readonly) NSString *appId;
@property (nonatomic,strong,readonly) SGWorkSpaceManager *workSpaceManager;

- (instancetype)initWithAppId:(NSString *)appId
                watchPathTemp:(NSString *)watchPathTemp
             workSpaceManager:(SGWorkSpaceManager *)manager;

- (void)setEZIPParameterWithColor:(NSString *)ezipColor
                        noAlpha:(NSInteger)ezipNoAlpha
                     noRotation:(NSInteger)ezipNoRotation
                      boardType:(NSInteger)ezipBoardType;
@end

NS_ASSUME_NONNULL_END

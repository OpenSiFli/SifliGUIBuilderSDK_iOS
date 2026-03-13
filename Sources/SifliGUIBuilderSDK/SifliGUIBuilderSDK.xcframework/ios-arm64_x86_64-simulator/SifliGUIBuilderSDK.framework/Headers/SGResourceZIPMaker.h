//
//  SGResourceZIPMaker.h
//  SiFliGUIBuilderSDK
//
//  Created by Sean on 2026/3/3.
//

#import <Foundation/Foundation.h>
#import <SiFliGUIBuilderSDK/SGAppResUserContext.h>
#import <SiFliGUIBuilderSDK/SGImageEditItem.h>
#import <SifliOCore/SFCoreError.h>

NS_ASSUME_NONNULL_BEGIN

@class SGResourceZIPMaker;

@protocol SGResourceZIPMakerDelegate <NSObject>

/// SGResourceZIPMaker  生成patchZip完成后回调
/// - Parameters:
///   - maker:
///   - success: YES 成功,NO 失败
///   - path: patch Zip 文件路径
///   - error: 错误信息，参见SGErrorCode
- (void)sgResourceZIPMaker:(SGResourceZIPMaker *)maker
                onComplete:(BOOL)success
              patchZipPath:(nullable NSString *)path
                     error:(nullable SFCoreError *)error;

- (void)sgResourceZIPMaker:(SGResourceZIPMaker *)maker
    onProgressWithCurrent:(NSInteger)current
                    total:(NSInteger)total;
@end

@interface SGResourceZIPMaker : NSObject

/// 单例
+ (instancetype)sharedInstance;

/// 代理（弱引用）
@property (nonatomic, weak, nullable) id<SGResourceZIPMakerDelegate> delegate;

/**
 将表盘修改清单制作为拓展资源补丁 zip
 @param userContext 制作上下文
 @param editItem 已编辑并需要打包的资源编辑项
 */
- (void)startMakePatchZipWithContext:(SGAppResUserContext *)userContext
                            editItem:(SGImageEditItem *)editItem;

/**
 清理资源
 */
- (void)clear;

@end

NS_ASSUME_NONNULL_END

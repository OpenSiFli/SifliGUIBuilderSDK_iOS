//
//  SGImageEditItem.h
//  SiFliGUIBuilderSDK
//
//  Created by Sean on 2026/2/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <SiFliGUIBuilderSDK/SGWatchfaceEditItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface SGImageEditItem : SGWatchfaceEditItem

/// 原始图像名称
@property (nonatomic, copy) NSString *originImageName;
/// 原始图像数据
@property (nonatomic, strong, nullable) UIImage *originImage;
/// 补丁图像名称
@property (nonatomic, copy, nullable) NSString *patchImageName;
/// 补丁图像数据
@property (nonatomic, strong, nullable) UIImage *patchImage;
/// 是否是表盘背景
@property (nonatomic, assign, getter=isBackground) BOOL background;

/**
 初始化方法
 @param controlId 控件ID
 @param originImageName 原始图像名称
 @return 实例对象
 */
- (instancetype)initWithControlId:(NSString *)controlId
                 originImageName:(NSString *)originImageName;

/**
 是否有补丁图像
 @return 如果补丁图像存在返回 YES，否则 NO
 */
- (BOOL)hasPatch;

/**
 设置补丁图像（校验尺寸是否与原始图像一致）
 @param patchImage 补丁图像
 @return 设置成功返回 YES，尺寸不一致则返回 NO
 */
- (BOOL)updatePatchImage:(UIImage *)patchImage;

/**
 删除补丁图像
 */
- (void)deletePatch;

@end

NS_ASSUME_NONNULL_END

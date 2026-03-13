//
//  SGWorkSpaceManager.h
//  SiFliGUIBuilderSDK
//
//  Created by Sean on 2026/2/24.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>


#import <SifliOCore/SFOLog.h>
#import <SifliOCore/SFResult.h>
#import <SiFliGUIBuilderSDK/SGWatchfaceEditItemListResult.h>
#import <SiFliGUIBuilderSDK/SGImageEditItem.h>
#import <SiFliGUIBuilderSDK/LanguageItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface SGWorkSpaceManager : NSObject




/**
 初始化方法（替代 Android 的 init）
 */
- (instancetype)init;

/**
 打开工程
 @param projectPath 工程文件路径（.sif）
 @return SFResult，成功时 success 为 YES
 */
- (SFResult *)openProject:(NSString *)projectPath;

/**
 绘制预览图片
 @return 预览 UIImage，失败返回 nil
 */
- (nullable UIImage *)drawPreviewImage;

/**
 切换主题
 @param themeId 主题 ID
 */
- (void)switchTheme:(NSString *)themeId;

/**
 清理资源
 */
- (void)clear;

/**
 获取当前页面可修改项目
 @return SGWatchfaceEditItemListResult，包含可编辑项数组
 */
- (SGWatchfaceEditItemListResult *)getEditItems;

/**
 制作图像补丁
 @param imageEditItem 图像编辑项
 @return SFResult，成功返回 YES
 */
- (SFResult *)makeImagePatch:(SGImageEditItem *)imageEditItem;

/**
 删除补丁文件
 @param originImageName 原始图像名称
 @return 删除成功返回 YES，否则 NO
 */
- (BOOL)deletePatchWithOriginImageName:(NSString *)originImageName;

- (nullable NSString *)getProjectId;

- (NSArray<LanguageItem *> *)getLanguageItems;

- (NSString *)getCurrentThemeId;

- (nullable LanguageItem * )getCurrentLanguageItem;

- (NSArray<NSString *> *)themeIdList;

- (void)switchLanguageItemById:(NSString *)languageItemId;

/// 是否加载了表盘编辑项目
- (BOOL)hasLoadProject;

@end

NS_ASSUME_NONNULL_END

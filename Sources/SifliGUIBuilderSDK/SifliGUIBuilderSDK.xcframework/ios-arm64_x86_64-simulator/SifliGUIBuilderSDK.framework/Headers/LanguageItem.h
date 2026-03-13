//
//  LanguageItem.h
//  SiFliGUIBuilderSDK
//
//  Created by Sean on 2026/2/12.
//

#import <SiFliGUIBuilderSDK/BaseModel.h>
#import <SiFliGUIBuilderSDK/LanguageKey.h>

NS_ASSUME_NONNULL_BEGIN

/**
 语言选项项
 */
@interface LanguageItem : BaseModel

/// 语言键值
@property (nonatomic, assign) LanguageKey languageKey;

/// 语言名称
@property (nonatomic, copy) NSString *name;

/// 是否选中
@property (nonatomic, assign) BOOL isSelected;

/**
 初始化方法
 @param languageKey 语言键值
 @param name 语言名称
 @return 语言选项实例
 */
- (instancetype)initWithLanguageKey:(LanguageKey)languageKey name:(NSString *)name;

/**
 获取ID（对应C#的Id属性）
 @return 语言键值的字符串表示
 */
- (NSString *)itemId;

/**
 获取描述（对应C#的Description属性）
 @return 格式化的描述字符串
 */
- (NSString *)itemDescription;

@end

NS_ASSUME_NONNULL_END

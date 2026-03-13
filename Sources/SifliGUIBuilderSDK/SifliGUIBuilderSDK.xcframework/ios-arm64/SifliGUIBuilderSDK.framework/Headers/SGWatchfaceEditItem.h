//
//  SGWatchfaceEditItem.h
//  SiFliGUIBuilderSDK
//
//  Created by Sean on 2026/2/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SGWatchfaceEditItem : NSObject

/// 修改的控件ID
@property (nonatomic, copy) NSString *controlId;

/// 资源UID（十六进制字符串）
@property (nonatomic, copy, nullable) NSString *hexUID;

/// 控件UID（十六进制字符串）
@property (nonatomic, copy, nullable) NSString *controlUID;

/**
 初始化方法
 @param controlId 控件ID
 @return 实例对象
 */
- (instancetype)initWithControlId:(NSString *)controlId;

@end

NS_ASSUME_NONNULL_END

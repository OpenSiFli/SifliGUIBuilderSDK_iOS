//
//  SGWatchfaceEditItemListResult.h
//  SiFliGUIBuilderSDK
//
//  Created by Sean on 2026/2/24.
//

#import <SifliOCore/SifliOCore.h>
#import <SiFliGUIBuilderSDK/SGWatchfaceEditItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface SGWatchfaceEditItemListResult : SFResult
@property (nonatomic,strong,nullable)NSArray<SGWatchfaceEditItem *> *EditItems;
@end

NS_ASSUME_NONNULL_END

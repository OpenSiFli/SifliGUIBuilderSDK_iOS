//
//  LanguageKey.h
//  SiFliGUIBuilderSDK
//
//  Created by Sean on 2026/2/11.
//
#import <Foundation/Foundation.h>
#ifndef LanguageKey_h
#define LanguageKey_h

/**
 语言键位枚举 (支持位运算)
 */
typedef NS_OPTIONS(NSUInteger, LanguageKey) {
    /**
     * 默认语言
     */
    LanguageKeyDefault = 1 << 0,
    
    /**
     * 简体中文
     */
    LanguageKeyChineseSimplified = 1 << 1,
    
    /**
     * 英语
     */
    LanguageKeyEnglish = 1 << 2,
    
    /**
     * 韩语
     */
    LanguageKeyKorean = 1 << 3,
    
    /**
     * 德语
     */
    LanguageKeyGerman = 1 << 4,
    
    /**
     * 法语
     */
    LanguageKeyFrench = 1 << 5,
    
    /**
     * 意大利语
     */
    LanguageKeyItalian = 1 << 6,
    
    /**
     * 日语
     * 注意：C#原注释为"西班牙"，但根据枚举项名称`JAPANESE`，此处译为日语
     */
    LanguageKeyJapanese = 1 << 7,
    
    /**
     * 葡萄牙语
     */
    LanguageKeyPortuguese = 1 << 8,
    
    /**
     * 俄语
     */
    LanguageKeyRussian = 1 << 9,
    
    /**
     * 荷兰语
     */
    LanguageKeyDutch = 1 << 10,
    
    /**
     * 瑞典语
     */
    LanguageKeySwedish = 1 << 11,
    
    /**
     * 挪威语
     * 注意：C#枚举项为`NORWEGIANc`，推测为`NORWEGIAN`的笔误
     */
    LanguageKeyNorwegian = 1 << 12,
    
    /**
     * 丹麦语
     */
    LanguageKeyDanish = 1 << 13,
    
    /**
     * 芬兰语
     */
    LanguageKeyFinnish = 1 << 14,
    
    /**
     * 泰语
     */
    LanguageKeyThai = 1 << 15,
    
    /**
     * 越南语
     */
    LanguageKeyVietnamese = 1 << 16,
    
    /**
     * 印度语
     */
    LanguageKeyIndian = 1 << 17,
    
    /**
     * 巴西葡萄牙语
     */
    LanguageKeyBrazilian = 1 << 18,
    
    /**
     * 墨西哥西班牙语
     */
    LanguageKeyMexican = 1 << 19,
    
    /**
     * 阿拉伯语
     */
    LanguageKeyArabic = 1 << 20,
    
    /**
     * 土耳其语
     */
    LanguageKeyTurkish = 1 << 21,
    
    /**
     * 希腊语
     */
    LanguageKeyGreek = 1 << 22,
    
    /**
     * 希伯来语 (以色列)
     */
    LanguageKeyHebrew = 1 << 23,
    
    /**
     * 波斯语 (伊朗)
     */
    LanguageKeyPersian = 1 << 24,
    
    /**
     * 印度尼西亚语
     */
    LanguageKeyIndonesian = 1 << 25,
    
    /**
     * 马来西亚语
     */
    LanguageKeyMalaysian = 1 << 26,
    
    /**
     * 西班牙语
     * 注意：此项目与`LanguageKeyMexican`有所区别，通常指欧洲西班牙语
     */
    LanguageKeySpanish = 1 << 27,
    
    /**
     * 繁体中文
     */
    LanguageKeyChineseTraditional = 1 << 28
};
#endif /* LanguageKey_h */

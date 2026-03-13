# SifliGUIBuilderSDK

## 1. 概述
SifliGUIBuilderSDK 是思澈表盘工具SifliGUIBuilder的移动端配套组件，客户App可以基于它对SifliGUIBuilder编辑产生的表盘包.sif
文件进行编辑。目前它可以对表盘中设定为允许编辑的图片控件进行编辑，实现在手机App上更换表盘背景。
使用请参照[Demo](https://github.com/OpenSiFli/SiFli_OTA_APP_iOS)

## 2.集成
SifliGUIBuilderSDK 依赖库 SifliOCore,eZIPSDK，可选组件SFSSZipArchivePlugin
### 2.1 Swift Package
```
https://github.com/OpenSiFli/SifliGUIBuilderSDK_iOS.git
```

### 2.2 Cocoapod
```
pod 'SifliGUIBuilderSDK','1.0.1'
```

### 2.3 初始化
```
import SiFliGUIBuilderSDK
import SFSSZipArchivePlugin

private let workspaceManager:SGWorkSpaceManager = SGWorkSpaceManager.init()
private let resourceZIPMaker:SGResourceZIPMaker = SGResourceZIPMaker.sharedInstance()
private let pushMessageManager:SGPushMessageManager = SGPushMessageManager.shared()

SFZipHelper.shared().zipDelegate = SFSSZipArchiver.shared()
self.resourceZIPMaker.delegate = self;
self.pushMessageManager.delegate = self;
```

## 3.接口调用
### 3.1 打开表盘
通过`SGWorkSpaceManager`来打开.sif表盘包，绘制预览图、查询可编辑项目、制作图像补丁、删除图像补丁、切换页面(样式)、切换语言

```objective-c
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
```

### 3.2 生成拓展资源zip
通过`SGResourceZIPMaker`对表盘编辑产生的图像补丁生成拓展资源zip文件，用于传输到设备上显示.

```objective-c
/**
 将表盘修改清单制作为拓展资源补丁 zip
 @param userContext 制作上下文
 @param editItem 已编辑并需要打包的资源编辑项
 */
- (void)startMakePatchZipWithContext:(SGAppResUserContext *)userContext
                            editItem:(SGImageEditItem *)editItem;
```
调用`SGResourceZIPMaker`的startMakePatchZipWithContext需要构建SGAppResUserContext对象，它需要输入appId,watchPathTemp,`SGWorkSpaceManager`,ezip参数来构建。

- appId 表盘工程中设定的ID
- watchPathTemp 一个文件路径模版，它指定了拓展资源文件zip的内部层级，这决定了它被传输到设备后的存放位置
- ezip参数 参照`eZIPSDK`

### 3.3 消息发送
通过`SGPushMessageManager`来发送切换页面，删除拓展资源补丁，删除表盘命令

```objective-c
/// 发送切换页面(样式)命令
/// - Parameters:
///   - identifier: 蓝牙地址
///   - appId: 表盘/应用ID
///   - themeId: 页面(样式)ID
- (void)sendSwitchThemeCmdWithIdentifier:(NSString *)identifier appId:(NSString *)appId themeId:(NSString *)themeId;

/// 发送删除拓展资源补丁
/// - Parameters:
///   - identifier: 蓝牙地址
///   - appId: 应用/表盘id
///   - patchFileName: 补丁文件名称
- (void)sendDeletePatchCmdWithIdentifier:(NSString *)identifier appId:(NSString *)appId patchFileName:(NSString *)patchFileName;

/// 删除表盘/应用ID
/// - Parameters:
///   - identifier: 蓝牙地址
///   - appId: 表盘/应用ID
- (void)sendDeleteAppCmdWithIdentifier:(NSString *)identifier appId:(NSString *)appId;`

```
## 4.错误码
查看SDK中的`SGErrorCode.h`定义
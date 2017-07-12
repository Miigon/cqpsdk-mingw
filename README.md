**注意：本SDK只支持MinGW64（MinGW32未测试），VC++编译器请使用 https://github.com/CoolQ/cqsdk-vc/**  

# cqsdk-mingw

使用 C/C++(MinGW) 开发[酷Q](cqp.cc)插件的SDK，适用于API版本9的酷Q和MinGW64编译器  
使用`build.bat`构建测试插件`com.example.democ`和`com.example.democpp`  

# 注意事项

本SDK的方法名称大多同 https://github.com/CoolQ/cqsdk-vc/，但是使用方法有少许不同：
* `EVENT_BLOCK` 被更名为 `EVENT_INTERCEPT`
* 事件函数定义方法不同
* 编译时需将酷Q目录下bin文件夹中的CQP.dll复制到本目录下（即：需动态链接CQP.dll）
# NickPhalanx

## 项目说明
NickPhalanx 是一个[玩家自行编辑逻辑，进行数字博弈游戏]的项目。
目前完成了模型的静态构架
基础元素 Power， Type， Position， Step  用于反映模型的状态
单元 Cell， AliveCell 模型的最小单位
环境类 Phalanx 储存模型主体
工具类 View 实现控制台输出
控制类 Control 向模型导入逻辑（构建中）

模型动态的机能尚处于设计阶段，在环境类（Palanx）中声明相关函数（move，plunder...），

## 主要特性
- [特性 1] 支持跨平台运行
- [特性 2] 
- [特性 3]

## 安装方法

 - 下载Github仓库
git clone https://github.com/QQDDTT/NickPhalanx.git

## 注意，若未安装 Virtual Studio ， 请自行下载 MinGW 和 CMake

 - 本地安装MinGW
 Windows : https://github.com/niXman/mingw-builds-binaries/releases
 Linux : sudo apt install mingw-w64

 - 本地安装CMake
 Windows : https://cmake.org/download/
 Linux : sudo apt install cmake

 - 配置环境变量
 在环境变量中添加 MinGW 和 CMake 文件夹下的 bin 文件夹的路径


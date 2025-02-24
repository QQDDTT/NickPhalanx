# NickPhalanx

## 项目说明
NickPhalanx 是一个[玩家自行编辑逻辑，进行数字博弈游戏]的项目。
 - 静态构架
 基础元素 Power， Type， Position， Step  用于反映模型的状态
 单元 Cell， AliveCell 模型的最小单位
 环境类 Phalanx 储存模型主体
 工具类 View 实现控制台输出
 控制类 Control 向模型导入逻辑,[目前随机动作，无逻辑]

 - 动态机能
 能量类（Power）中定义重载（>>）,函数（half）
 回合类（Step）中定义函数 （nextStep）
 时间戳脚本 (TimeDate) 中定义函数 （Time, Data, DateTime）
 环境类（Palanx）中声明函数（move，plunder，dedicate, copy）
 控制类 （Control）中定义重载 （<< Phalanx）

 - 扩展(逻辑注入模块)
 逻辑解析模块[用于解释或编译用户脚本]，设计中...
 流程 1[调查并选择合适的脚本语言（JavaScript...）]
 流程 2[根据选择的脚本语言设计接口]
 流程 3[根据设计的接口，制作简单的测试脚本]
 流程 4[根据设计的接口，设计和制作脚本文件的解释器]
 流程 5[测试解释器，并添加必要的提示信息]
 流程 6[在现有框架，完善该模块]

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


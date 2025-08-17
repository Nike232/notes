**什么是CMake?**
CMake是一个**自动生成编译工程文件的工具**，能根据写的配置文件在不同平台上生成对应的编译方式，从而让项目更加容易管理和移植。

所以它本身并不是建构工具，而是生成建构系统的工具。

---
### CMake基础
`CMakeLists.txt`文件是CMake的配置文件，用于定义项目的构建规则、依赖关系、编译选项等等

该文件是用一系列的CMake指令来描述构建过程，常见的指令有：

1.指定CMake的最低版本要求：
`cmake_minimum_required(VERSION <version>)`
比如
`cmake_minimum_required(VERSION 3.10)`

2.定义项目名称和使用的编程语言
`project(<projecct_name> [<language>...])`
例如
`project(Myproj CXX)`

3.指定要生成的可执行文件和其源文件
`add_executable(<target> <source_files>...)`
例如
`add_executable(MyExecutable main.cpp other_file.cpp)`

4.创建一个库（静态库或动态库）及其源文件
`add_library(<target> <source_files>...)`
例如
`add_library(MyLibrary STATIC library.cpp)`

STATIC 静态库
SHARED 动态库
不写就是让他自动决定

**Ps：”静态库和动态库的区别**
```
静态库：像复制粘贴一样直接贴进程序里
动态库：像“引用连接”,运行时再使用
```
静态库(`.lib`(windows)):在编译时被直接编进可执行文件，从而导致程序体积比较大，但是可以不依赖外部库文件，更新要重新编译

动态库（.dll(windows)）:独立存在，在运行时才加载，程序体积会比较小，更新直接换库就行，但是必须带着库文件运行

---
5.链接目标文件与其他库
就是将程序或库与其他库链接起来，包含自己写的静态/动态库，也可以是外部库
`target_link_libraries(<target> [PUBLIC | PRIVATE | INTERFACE ]<libraries>...)`
比如
```
add_library(GameCore STATIC GameEngine.cpp)
add_library(GraphicsLib STATIC Map.cpp)

add_executable(TankBattleClient main.cpp)
target_link_libraries(TankBattleClient PRIVATE GameCore GraphicsLib)
```
分析：创建了两个静态库，然后指定了生成的可执行文件，然后将可执行文件与两个静态库进行链接

---
6.添加头文件搜索路径
`target_include_directories(<target> [PUBLIC | PRIVATE | INTERFACE ] <路径...>)`
例如:
`target_include_directories(MyGame PRIVATE ${CMAKE_SOURCE_DIR}/Core`

| 关键字         | 含义                            |
| ----------- | ----------------------------- |
| `PRIVATE`   | 只当前 target 用这个路径（不会传给别的）      |
| `PUBLIC`    | 当前 target 用，同时依赖它的也能用         |
| `INTERFACE` | 自己不用，用它的才用（常用于 header-only 库） |

> 一般主程序用 `PRIVATE`，库文件用 `PUBLIC`

一次性可以添加多个路径

其中`${CMAKE_SOURCE_DIR}` 是 **CMake 中的一个内置变量**表示CMake项目的**顶层目录**

比如：
```
TankBattleClient/
├── CMakeLists.txt         ← 顶层 CMake 文件
├── main.cpp
├── Core/
│   └── GameEngine.h/.cpp

```
常用于拼接路径，避免硬编码绝对路径。

|变量名|含义|
|---|---|
|`${CMAKE_SOURCE_DIR}`|顶层源文件目录|
|`${CMAKE_CURRENT_SOURCE_DIR}`|当前 `CMakeLists.txt` 所在目录|
|`${CMAKE_BINARY_DIR}`|顶层构建目录（通常是 build/）|
|`${CMAKE_CURRENT_BINARY_DIR}`|当前 CMakeLists 生成的 build 子目录|

---
7.设置一个变量的值
`set (<变量名> <值>)`
比如
`set(SOURCE_DIR ${CMAKE_SOURCE_DIR}}/src`

使用变量 用$即可
比如
`add_executable(Myapp ${SOURCE_DIR}/main.cpp)`

8.条件语句
```
if(expression)
  # Commands
elseif(expression)
  # Commands
else()
  # Commands
endif()
```
比如
```
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  message("Debug build")
endif()
```
意思是如果选择"Debug"模式编译的时候打印消息

---
9.查找库和包
CMake可以通过`find_package()`指令自动检测和配置外部库和包
**常用于查找系统安装的库或第三方库**

`find_package(<包名> [版本] [REQUIRED] [COMPONENTS <组件>...])
`

| 参数           | 说明                                              |
| ------------ | ----------------------------------------------- |
| `<包名>`       | 要查找的库，比如 Qt6、SFML、Boost                         |
| `[版本]`       | 指定最小版本（可选）                                      |
| `REQUIRED`   | 如果找不到就停止生成（必须存在）                                |
| `COMPONENTS` | 指定要用这个库的哪些部分（例如 Qt6::Widgets、Boost::filesystem） |
例如:
```
find_package(Qt6 REQUIRED COMPONENTS Widgets)
target_link_libraries(Myapp PRIVATE Qt6::Widgets)
```
第一条指令去找Qt6的Widgets模块，然后链接到可执行文件

如果找不到库怎么办？（因为是自动找的，效果难说）
1.在cmake的时候指定查找路径
`cmake -DCMAKE_PREFIX_PATH="xxx" ..`
2.直接在CMakeLists.txt中写
```
set(CMAKE_PREFIX_PATH "xxx")
find_package(Qt6 REQUIRED COMPONENTS Widgets)
```

---
10.多功能文件处理命令
`file()`是CMake的多功能文件处理命令，支持查找、读写、目录操作、路径转换等等操作，下面介绍最常用的GLOB/GLOB_RECURSE
```
file(GLOB MY_SRC "*.cpp" "*.h")
file(GLOB_RECURSE ALL_SRC "${CMAKE_SOURCE_DIR}/src/*.cpp")
```
GLOB是非递归查找，也就是只查找当前目录下的，不管子目录
GLOB_RECURSE是递归查找，查找当前目录下所有满足条件的
`MY_SRC`和`ALL_SRC`都是自定义的变量名，用于存放查找到的文件路径列表

---
### CMakeLists.txt书写的基本流程
其实是与C++编译流程一一对应的

设置项目环境(最小版本、项目名称)->选择源文件->找头文件路径->如果使用了第三方库找第三方库->链接库->设置编译选项(可选)->安装/打包(可选)

基本框架案例:
```
cmake_minimum_required(VERSION 3.16)
project(TankBattleClient LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# vcpkg 路径设置
set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-mingw-dynamic")

# 查找库
find_package(Qt6 REQUIRED COMPONENTS Widgets Gui)
find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

# 添加源文件
#这里就是递归查找，然后存放到SRC_FILES这个变量中
file(GLOB_RECURSE SRC_FILES
    ${CMAKE_SOURCE_DIR}/Core/*.cpp
    ${CMAKE_SOURCE_DIR}/GameObjects/*.cpp
    ${CMAKE_SOURCE_DIR}/Systems/*.cpp
    ${CMAKE_SOURCE_DIR}/Graphics/*.cpp
    ${CMAKE_SOURCE_DIR}/UI/*.cpp
    ${CMAKE_SOURCE_DIR}/Network/*.cpp
    ${CMAKE_SOURCE_DIR}/main.cpp
)

# 创建可执行程序
add_executable(TankBattleClient ${SRC_FILES})

# 添加头文件路径
target_include_directories(TankBattleClient PRIVATE
    ${CMAKE_SOURCE_DIR}/Core
    ${CMAKE_SOURCE_DIR}/GameObjects
    ${CMAKE_SOURCE_DIR}/Systems
    ${CMAKE_SOURCE_DIR}/Graphics
    ${CMAKE_SOURCE_DIR}/UI
    ${CMAKE_SOURCE_DIR}/Network
)

# 链接库
target_link_libraries(TankBattleClient PRIVATE
    Qt6::Widgets
    Qt6::Gui
    sfml-graphics
    sfml-window
    sfml-system
)

```

---
### CMake构建流程
1. **创建构建目录**：保持源代码目录整洁。
2. **使用 CMake 生成构建文件**：配置项目并生成适合平台的构建文件。
3. **编译和构建**：使用生成的构建文件执行编译和构建。
4. **清理构建文件**：删除中间文件和目标文件。
5. **重新配置和构建**：处理项目设置的更改。

1.创建构建目录
CMake推荐`Out-of-source`的构建方式，即将构建文件放在源代码目录之外的独立目录中

<1>创建构建目录
`mkdir build`
<2>进入构建目录
`cd build`

2.使用CＭake生成构建文件
在构建目录中运行 CMake，以生成适合当前平台的构建系统文件（例如 Makefile、Ninja 构建文件、Visual Studio 工程文件等）。

**运行 CMake 配置：在构建目录中运行 CMake 命令，指定源代码目录。源代码目录是包含 CMakeLists.txt 文件的目录。

`cmake ..`
这里的`..`是上级目录，也就是我这里`CMakeLists.txt`文件的目录

如果需要指定生成器（如 Ninja、Visual Studio），可以使用 -G 选项。例如：
`cmake -G "Ninja" ..` 

如果需要指定构建类型（如 Debug 或 Release），可以使用 -DCMAKE_BUILD_TYPE 选项。例如：
`cmake -DCMAKE_BUILD_TYPE=Release ..`

**检查配置结果：**CMake 会输出配置过程中的详细信息，包括找到的库、定义的选项等，如果没有错误，构建系统文件将被生成到构建目录中。

3.编译和构建
使用生成的构建文件进行编译和构建
不同的构建系统使用不同的命令(具体命令参照自己的构建系统，图Makefile Ninja vs...)

4.清理构建文件
构建过程中生成的中间文件和目标文件可以通过清理操作清楚
命令清除：参照自己的构建系统的命令
手动清除：直接`rm -r build`

5.重新配置和构建
按照上面的操作就可以了

---
### 实例----以实训任务一为例
以下是提供的CMakeLists.txt文件（为方便分析，已手动标号）
```
1.cmake_minimum_required(VERSION 3.10) 

2.list(APPEND CMAKE_PREFIX_PATH "./vcpkg_installed/x64-mingw-dynamic") # 替换为你的实际路径 

3.project(HelloWorld) 

4.find_package(fmt CONFIG REQUIRED) 

5.add_executable(HelloWorld main.cpp) 

6.target_link_libraries(HelloWorld PRIVATE fmt::fmt)
```
第一行代码是确定CMake可用的最低版本

第二行代码`list(APPEND ...)`是CMake中向列表变量也就是这里的`CMAKE_PREFIX_PATH`添加元素的语法

根据之前的讲解，其实就是添加寻找第三方库的路径，所以也能替换成上面讲解的两种解决方式

第三行代码是指定项目名称为HelloWorld

第四行代码是去查找fmt库，`REQUIRED`是如果没有找到就退出

其中`CONFIG`是查找模式，一共有`MODULE`和`CONFIG`模式，下面简要比较，了解即可

| 模式                         | 一句话说明                                    |                                        |
| -------------------------- | ---------------------------------------- | -------------------------------------- |
| **MODULE 模式**              | 使用 CMake 自带的 `FindXXX.cmake` 文件          |                                        |
| **CONFIG 模式**              | 使用库作者自己提供的 `xxx-config.cmake` 文件 ✅（现代推荐） |                                        |
| 特性                         | MODULE 模式                                | CONFIG 模式 ✅                            |
| 查找文件                       | `FindXXX.cmake`                          | `xxx-config.cmake` 或 `XXXConfig.cmake` |
| 文件来源                       | CMake 官方 or 用户编写                         | 库作者提供                                  |
| 使用方式                       | 设置变量（INCLUDE_DIRS 等）                     | 使用 target（如 `fmt::fmt`）                |
| 推荐程度                       | 较老（部分库还在用）                               | ✅ 现代推荐方式                               |
| 支持 vcpkg                   | 一般不支持                                    | ✅ 原生支持                                 |
| 支持 `target_link_libraries` | 部分支持或需手动写路径                              | ✅ 全面支持                                 |
**结论：CMake 会自动优先用 CONFIG 模式（现代方式），找不到时才回退到 MODULE。并且推荐使用CONFIG模式，写上就好**

同时实验文档中给了一个提示:`如果提示find_package找不到fmt-config.cmake，追加 CMAKE_PREFIX_PATH 的配置`现在应该也可以理解了。

第五行代码就是将main.cpp作为源码，然后编译后的可执行文件名字定为HelloWorld

第六行代码就是将fmt库链接到可执行文件中

---
三个问题：

1.**为什么是`fmt::fmt`而不是`fmt`**
这是由CMake的命名空间机制决定的，避免不同的库中有重复的名称，产生多义性
`库名::库提供的 target 名`

2.**为什么动态链接需要把.dll复制到可执行文件目录？**
首先根据之前对静态链接和动态链接的了解可以知道，动态链接的代码是没有被打包进exe中的，所以exe运行的使用需要加载.dll

因此系统就会去找.dll文件

系统是如何找的呢？
- EXE 所在目录 ✅（最常见做法）
    
- 系统目录（`C:\Windows\System32` 等）
    
- 环境变量 `PATH` 指定的目录
    
- 注册表路径（更高级）

所以很明显，我们一般也不会把.dll专门放在系统目录下，也不会专门为此去配置环境变量，所以最简单的方式就是直接把.dll文件放在可执行文件的目录下，这也是采用动态链接需要注意的一点

3.为什么已经有了CMakeLists.txt但是却还要写一个`CMakePresets.json`文件，作用是什么？**

如果仔细注意到前文一些cmake命令的话，可以发现很多cmake命令在使用的时候是带有`options`的

事实上，像git、cmake这样的命令行工具，带有很多参数（options)，**每次手动输入非常繁琐，容易错处，所以就引入`.json`或者配置文件来保存预设(preset)或者默认配置**，方便复用和协作

下面针对给出的案例做简要分析（了解即可）
```json
{ 
	"version": 8, 
	"configurePresets": [ 
	{ 
		"name": "TDM-GCC-64", 
		"displayName": "GCC 10.3.0 x86_64-w64-mingw32", 
		"description": "使用编译器: C = D:\\Dev\\TDM-GCC-64\\bin\\gcc.exe, CXX = D:\\Dev\\TDM-GCC-64\\bin\\g++.exe", 
		"binaryDir": "${sourceDir}/out/build/${presetName}", 
		"generator": "MinGW Makefiles", 
		"cacheVariables": { 
			"CMAKE_INSTALL_PREFIX": "${sourceDir}/out/install/${presetName}",  
			 "CMAKE_C_COMPILER": "D:/Dev/TDM-GCC-64/bin/gcc.exe", 
			"CMAKE_CXX_COMPILER": "D:/Dev/TDM-GCC-64/bin/g++.exe", 
			"CMAKE_BUILD_TYPE": "Debug" }, 
		"environment": { 
				"VCPKG_ROOT": "D:\\Dev\\vcpkg\\" 
			} 
		} 
	] 
}
```
`"version": 8`  表示使用的 **CMake Preset 文件格式版本**
` "configurePresets": [ ... ]`是一个数组，里面可以定义多个构建预设

- `"name"` 是你在命令行用的 preset 名字（用于：`cmake --preset TDM-GCC-64`）。
    
- `"displayName"` 是 IDE（比如 VSCode）中显示给用户看的名字。
    
- `"description"` 是 preset 的说明，主要是你自己看用的。

`"binaryDir"` 指明 **构建产物输出的目录**
`"generator"` 表示你使用的构建工具是 `MinGW Makefiles`（即用 `mingw32-make`）

接下来是CMake缓存变量设置

|键|含义说明|
|---|---|
|`CMAKE_INSTALL_PREFIX`|`cmake --install` 安装的目标路径，按 preset 分类|
|`CMAKE_C_COMPILER`|指定 C 语言编译器的路径|
|`CMAKE_CXX_COMPILER`|指定 C++ 编译器的路径|
|`CMAKE_BUILD_TYPE`|构建类型为 Debug（用于调试）|

最后是环境变量设置
设置一个名为 `VCPKG_ROOT` 的环境变量，告诉 CMake 或工具链：  
vcpkg 安装在哪（一般用于自动找到 toolchain 或包管理路径）。

该文件可以使得构建命令变得非常简洁，只需要`cmake --preset TDM-GCC-64`
相当于
``` bash
cmake -S . -B out/build/TDM-GCC-64 -G "MinGW Makefiles" ^
  -DCMAKE_INSTALL_PREFIX=out/install/TDM-GCC-64 ^
  -DCMAKE_C_COMPILER=D:/Dev/TDM-GCC-64/bin/gcc.exe ^
  -DCMAKE_CXX_COMPILER=D:/Dev/TDM-GCC-64/bin/g++.exe ^
  -DCMAKE_BUILD_TYPE=Debug
```

以上仅是对CMake的简要介绍，需要完全掌握CMake，需要在项目开发中不断练习，积累经验。但辅以上面的介绍，现阶段应该能基本看懂CMakeLists.txt，能基本了解CMake的构建流程，并具有一定的修正Bug的能力。

资料来源：菜鸟教程、chatgpt回答、《cpp脚手架搭建》
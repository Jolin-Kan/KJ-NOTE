# macOS下的OpenGL开发使用

#### 

### 开发思路

- 用任意工具编写主体程序

- 利用`CMake`中创建项目（GUI 或 终端机）

- 在终端机中编译运行文件



### 项目创建的结构

```
Project_Name
    |
    -----> main.c
    -----> CMakelists.txt //关键！
    -----> build (folder) 
```



### CMakelists.txt 简要

#### 引入project

```
cmake_minimum_required(VERSION 3.5)
project(Project_Name)
```

#### 查找库

```
# 查找 GLEW 库
find_package(GLEW REQUIRED)

# 查找 GLFW 库
find_package(glfw3 REQUIRED)

# 查找 FreeType 库
find_package(Freetype REQUIRED)

```

#### 添加可执行文件（一个文件只能添加一次！）

```
add_executable(Project_Name File_Name)
```

#### 处理头文件和库（安装好库并验证路径！）

```
# 包含 FreeType 头文件路径
target_include_directories(hello PRIVATE ${FREETYPE_INCLUDE_DIRS})

# 链接 GLEW、GLFW 和 FreeType 库
target_link_libraries(hello PRIVATE GLEW::GLEW glfw Freetype::Freetype)
```



### 终端机指令

> 项目路径：/Users/jolin/hello

```
cd /Users/jolin/hello

cmake . --->注意空格； .. 指的是上一级文件

make 
#[respond:[100%] Built target Name

./Name ----->即可执行
```

#### 清理构建文件

- 重复编译或文件混乱时，在项目根目录执行

```
rm -rf build
```

#### 验证库 路径

```
brew list XXX
```



# ANSI控制字符头文件(ansi.h)

版权声明(中英)：

Copyright (c) 2023 wumingdaxian. All rights reserved

Use of this source code is governed by a BSD-style license that can be

found in the LICENSE file



特此免费授予任何获得本头文件和相关软件文件副本的人无限制的处理本软件的权限

包括但不限于使用、复制、修改、合并、发布、分发、在许可和/或销售软件的副本

并允许接受该软件的人这样做，但必须注明出处并开源。



上述版权声明和本许可声明应包含在头文件的所有副本或主要部分中



Hereby grant to anyone who obtains a copy of this header file and related software files, free of charge, unrestricted permission to process this software

Including but not limited to using, copying, modifying, merging, publishing, distributing, licensing and/or selling copies of software

And allow those who accept the software to do so, but must indicate the source and open source.

The above copyright statement and this license statement should be included in all copies or main parts of the header file



![头文件URL](http://github.com/wumingdaxian)



## 目录

##### 原理

##### 内置宏定义与意义

##### 内置函数、参数、用法




* * *

# 原理

ANSI（American National Standards Institute）字符编码的原理涉及多个方面，主要包括字符集的定义、编码方式以及在不同系统中的应用。以下是其核心原理和关键点的详细解释：



---



### 1. **ANSI字符集与编码的基本概念**

- **ANSI字符集**：最初指ASCII（American Standard Code for Information Interchange）字符集，包含128个字符（7位），包括英文字母、数字、标点符号和控制字符（如换行、制表符等）。

- **扩展ASCII**：后来扩展到8位（256个字符），称为“扩展ASCII”，新增了特殊符号（如©、®）、欧洲字母（如é、ñ）等。但这一扩展并非由ANSI统一制定，导致不同厂商/地区有不同版本（如ISO-8859系列）。



---



### 2. **编码原理**

- **单字节编码**：每个字符用1个字节（8位）表示，范围`0x00`-`0xFF`。前128字符（`0x00`-`0x7F`）与ASCII一致，后128字符（`0x80`-`0xFF`）因地区而异。

- **代码页（Code Page）**：Windows系统通过“代码页”实现ANSI扩展字符的适配。例如：

  - **代码页1252**：西欧语言（含€符号）。

  - **代码页936**：简体中文（GB2312）。

  - 不同代码页下，相同的字节可能对应不同字符。



---



### 3. **ANSI在Windows系统中的特殊性**

- **术语混淆**：在Windows语境中，“ANSI”常被误指为系统默认的代码页编码（如Windows-1252），而非严格的ANSI标准。

- **多字节编码支持**：对于非拉丁语系（如中文、日文），Windows的“ANSI”实际使用多字节编码（如GBK、Shift-JIS），部分字符仍用单字节，部分用双字节。



---



### 4. **与Unicode的区别**

- **Unicode**：统一字符集，涵盖全球语言，采用多字节编码（如UTF-8、UTF-16）。与ANSI的关键差异：

  - **兼容性**：UTF-8兼容ASCII（前128字符相同），但不兼容扩展ANSI。

  - **灵活性**：Unicode支持更多字符，无需代码页切换。



---



### 5. **实际应用中的问题**

- **乱码根源**：ANSI编码文件在不同代码页的系统打开时，可能显示乱码（如中文GBK文件在日文系统打开）。

- **解决方案**：现代系统优先使用Unicode（如UTF-8），避免ANSI的局限性。



---



### 6. **技术示例**

- **字符“A”**：ASCII编码为`0x41`（所有ANSI兼容）。

- **字符“€”**：在代码页1252中为`0x80`，但在其他代码页中可能无效。

- **中文字符“你”**：在GBK编码（ANSI扩展）中占2字节（如`0xC4 0xE3`），但无法在非中文代码页正确显示。



* * *



# 内置宏定义与意义

RESET 重置



TEXT_BOLD 文字加粗/高亮

TEXT_DIM  暗淡（降低亮度）

TEXT_ITALIC 斜体

TEXT_UNDERLINE 下划线

TEXT_SLOWFLICKER 闪烁（慢）

TEXT_FASTFLICKER 闪烁（快）

TEXT_REVER 反向显示

TEXT_HIDE 隐藏文字

TEXT_DELETELINE 删除线



TEXT_BLACK 黑色文字

TEXT_RED 红色文字

TEXT_GREEN 绿色文字

TEXT_YELLOW 黄色文字

TEXT_BLUE 蓝色文字

TEXT_MAGENTA 品红文字

TEXT_CYAN 青色文字

TEXT_WHITE 白色文字

TEXT_DEFAULT 默认前景色文字

BACKGROUND_BLACK 黑色背景

BACKGROUND_RED 红色背景

BACKGROUND_GREEN 绿色背景

BACKGROUND_YELLOW 黄色背景

BACKGROUND_BLUE 蓝色背景

BACKGROUND_MAGENTA 品红背景

BACKGROUND_CYAN 青色背景

BACKGROUND_WHITE 白色背景

BACKGROUND_DEFAULT 默认背景色



CURSOR_MOVE11 光标移至(1,1)

CLEAR_SCREEN 清除屏幕

CLEAR_LINE 清除本行文字

SAVE_CURSOR 保存光标位置

RESTORE_CURSOR 恢复光标位置

HIDE_CURSOR 隐藏光标

DISPLAY_CURSOR 显示光标



ENABLE_BACKUP_SCREEN_BUFFER 启用备用屏幕缓冲区

EXIT_THE_BACKUP_SCREEN_BUFFER 退出备用屏幕缓冲区

DISABLE_AUTOMATIC_LINE_WRAPPING 禁用自动换行

ENABLE_AUTOMATIC_LINE_WRAPPING 启用自动换行

QUERY_CURSOR_TYPE 查询光标位置（返回{y};{x}R）

QUERY_TERMINAL_TYPE 查询终端类型（返回?{n}c）

QUERY_TERMINAL_CAPABILITY 查询终端能力

* * *
# 内置函数、参数、用法
##### EnableANSI()
参数：无参数
参数意义：无
参数类型：无
返回类型：void
作用：在Windows平台上启用ANSI字符功能
使用方法：直接调用

##### ANSI256()
参数：n,backgroundcolor
参数意义：n：256色参数 ; backgroundcolor：是否为背景颜色(true为背景颜色，false为文字颜色)
参数类型：n：uint8_t ; backgroundcolor：bool,默认值为false
返回类型：std::string
作用：返回256色文字或背景所使用的ANSI字符
使用方法：填入函数参数之后作为字符串打印后使用

##### ANSIrgb()
参数：r,g,b,backgroundcolor
参数意义：r:红，g：绿，b：蓝 ，backgroundcolor：是否为背景颜色(true为背景颜色，false为文字颜色)
参数类型：r：uint8_t;g：uint8_t;b：uint8_t ; backgroundcolor：bool,默认值为false
返回类型：std::string
作用：返回24bit颜色文字或背景所使用的ANSI字符
使用方法：填入函数参数之后作为字符串打印后使用

##### SetWindowTitle()
参数：title
参数意义：title：字符串标题
参数类型：title : std::string
返回类型：std::string
作用：设置窗口标题
使用方法：填入函数参数之后作为字符串打印后使用

##### CursorMove()
参数：mode, step
参数意义：mode : 模式（'A'表示上移，'B'表示下移，'C'表示右移，'D'表示左移）；step:移动步数
参数类型：mode : char ; step : int
返回类型：std::string
作用：移动光标
使用方法：填入函数参数之后作为字符串打印后使用

##### MoveCursorTo()
参数：x,y
参数意义：x:光标x坐标，y:光标y坐标
参数类型：x:int , y:int
返回类型：std::string
作用：移动光标到指定坐标
使用方法：填入函数参数之后作为字符串打印后使用


备注：若不再使用此功能，请在使用完后打印 RESET 宏

## Table of Contents

##### Principles

##### Built-in Macro Definitions and Meanings

##### Built-in Functions, Parameters, and Usage




* * *

# Principles

The principles of ANSI (American National Standards Institute) character encoding involve multiple aspects, primarily including the definition of character sets, encoding methods, and applications in different systems. The following is a detailed explanation of its core principles and key points:


### 1. **Basic Concepts of ANSI Character Set and Encoding**

- **ANSI Character Set**: Initially referred to the ASCII (American Standard Code for Information Interchange) character set, which contains 128 characters (7 bits), including English letters, numbers, punctuation marks, and control characters (such as line breaks and tab characters).

- **Extended ASCII**: Later extended to 8 bits (256 characters), known as "Extended ASCII," which added special symbols (such as ©, ®) and European letters (such as é, ñ). However, this extension was not uniformly defined by ANSI, leading to different versions among different manufacturers/regions (such as the ISO-8859 series).


### 2. **Encoding Principles**

- **Single-Byte Encoding**: Each character is represented by 1 byte (8 bits), ranging from `0x00` to `0xFF`. The first 128 characters (`0x00` to `0x7F`) are consistent with ASCII, while the latter 128 characters (`0x80` to `0xFF`) vary by region.

- **Code Page**: Windows systems implement adaptation for ANSI extended characters through "code pages." For example:

  - **Code Page 1252**: Western European languages (including the € symbol).

  - **Code Page 936**: Simplified Chinese (GB2312).

  - Under different code pages, the same byte may correspond to different characters.


### 3. **Particularities of ANSI in Windows Systems**

- **Terminology Confusion**: In the Windows context, "ANSI" is often mistakenly referred to as the system's default code page encoding (such as Windows-1252), rather than the strict ANSI standard.

- **Multi-byte Encoding Support**: For non-Latin scripts (such as Chinese and Japanese), Windows' "ANSI" actually uses multi-byte encoding (such as GBK, Shift-JIS), with some characters still using single bytes and others using double bytes.


### 4. **Differences from Unicode**

- **Unicode**: A unified character set covering languages worldwide, using multi-byte encoding (such as UTF-8, UTF-16). Key differences from ANSI:

  - **Compatibility**: UTF-8 is compatible with ASCII (the first 128 characters are the same) but not with extended ANSI.

  - **Flexibility**: Unicode supports more characters and does not require code page switching.


### 5. **Problems in Practical Applications**

- **Root Cause of Garbled Text**: When an ANSI-encoded file is opened on a system with a different code page, garbled text may appear (for example, a Chinese GBK file opened on a Japanese system).

- **Solution**: Modern systems prefer to use Unicode (such as UTF-8) to avoid the limitations of ANSI.


### 6. **Technical Examples**

- **Character "A"**: ASCII encoding is `0x41` (compatible with all ANSI).

- **Character "€"**: `0x80` in Code Page 1252, but may be invalid in other code pages.

- **Chinese Character "你"**: Occupies 2 bytes in GBK encoding (ANSI extension) (such as `0xC4 0xE3`), but cannot be correctly displayed in non-Chinese code pages.


* * *

# Built-in Macro Definitions and Meanings

RESET Reset

TEXT_BOLD Bold/Highlight Text

TEXT_DIM Dim (Reduce Brightness)

TEXT_ITALIC Italic

TEXT_UNDERLINE Underline

TEXT_SLOWFLICKER Slow Blink

TEXT_FASTFLICKER Fast Blink

TEXT_REVER Reverse Display

TEXT_HIDE Hide Text

TEXT_DELETELINE Strikethrough

TEXT_BLACK Black Text

TEXT_RED Red Text

TEXT_GREEN Green Text

TEXT_YELLOW Yellow Text

TEXT_BLUE Blue Text

TEXT_MAGENTA Magenta Text

TEXT_CYAN Cyan Text

TEXT_WHITE White Text

TEXT_DEFAULT Default Foreground Color Text

BACKGROUND_BLACK Black Background

BACKGROUND_RED Red Background

BACKGROUND_GREEN Green Background

BACKGROUND_YELLOW Yellow Background

BACKGROUND_BLUE Blue Background

BACKGROUND_MAGENTA Magenta Background

BACKGROUND_CYAN Cyan Background

BACKGROUND_WHITE White Background

BACKGROUND_DEFAULT Default Background Color

CURSOR_MOVE11 Move Cursor to (1,1)

CLEAR_SCREEN Clear Screen

CLEAR_LINE Clear Current Line

SAVE_CURSOR Save Cursor Position

RESTORE_CURSOR Restore Cursor Position

HIDE_CURSOR Hide Cursor

DISPLAY_CURSOR Display Cursor

ENABLE_BACKUP_SCREEN_BUFFER Enable Alternate Screen Buffer

EXIT_THE_BACKUP_SCREEN_BUFFER Exit Alternate Screen Buffer

DISABLE_AUTOMATIC_LINE_WRAPPING Disable Automatic Line Wrapping

ENABLE_AUTOMATIC_LINE_WRAPPING Enable Automatic Line Wrapping

QUERY_CURSOR_TYPE Query Cursor Position (Returns {y};{x}R)

QUERY_TERMINAL_TYPE Query Terminal Type (Returns ?{n}c)

QUERY_TERMINAL_CAPABILITY Query Terminal Capabilities


* * *

# Built-in Functions, Parameters, and Usage

##### EnableANSI()
**Parameters**: None
**Parameter Meaning**: None
**Parameter Type**: None
**Return Type**: void
**Function**: Enables ANSI character functionality on Windows platforms
**Usage**: Call directly

##### ANSI256()
**Parameters**: n, backgroundcolor
**Parameter Meaning**: n: 256-color parameter; backgroundcolor: Whether it is a background color (true for background color, false for text color)
**Parameter Type**: n: uint8_t; backgroundcolor: bool, default value is false
**Return Type**: std::string
**Function**: Returns the ANSI characters used for 256-color text or background
**Usage**: Use as a string after filling in the function parameters

##### ANSIrgb()
**Parameters**: r, g, b, backgroundcolor
**Parameter Meaning**: r: Red, g: Green, b: Blue; backgroundcolor: Whether it is a background color (true for background color, false for text color)
**Parameter Type**: r: uint8_t; g: uint8_t; b: uint8_t; backgroundcolor: bool, default value is false
**Return Type**: std::string
**Function**: Returns the ANSI characters used for 24-bit color text or background
**Usage**: Use as a string after filling in the function parameters

##### SetWindowTitle()
**Parameters**: title
**Parameter Meaning**: title: String title
**Parameter Type**: title: std::string
**Return Type**: std::string
**Function**: Sets the window title
**Usage**: Use as a string after filling in the function parameters

##### CursorMove()
**Parameters**: mode, step
**Parameter Meaning**: mode: Mode ('A' for up, 'B' for down, 'C' for right, 'D' for left); step: Number of steps to move
**Parameter Type**: mode: char; step: int
**Return Type**: std::string
**Function**: Moves the cursor
**Usage**: Use as a string after filling in the function parameters

##### MoveCursorTo()
**Parameters**: x, y
**Parameter Meaning**: x: Cursor x-coordinate, y: Cursor y-coordinate
**Parameter Type**: x: int, y: int
**Return Type**: std::string
**Function**: Moves the cursor to the specified coordinates
**Usage**: Use as a string after filling in the function parameters

**Note**: If you no longer need this functionality, print the RESET macro after use to reset.
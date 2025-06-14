/*
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
*/

#pragma once

#include <Windows.h>
#include <iostream>
#include <sstream>
#include <cstdlib>

//文字效果
#define RESET "\033[0m" //重置

#define TEXT_BOLD "\033[1m"//文字加粗/高亮
#define TEXT_DIM "\033[2m"//暗淡（降低亮度）
#define TEXT_ITALIC "\033[3m"//斜体
#define TEXT_UNDERLINE "\033[4m"//下划线
#define TEXT_SLOWFLICKER "\033[5m"//闪烁（慢）
#define TEXT_FASTFLICKER "\033[6m"//闪烁（快）
#define TEXT_REVER "\033[7m"//反向显示
#define TEXT_HIDE "\033[8m"//隐藏文字
#define TEXT_DELETELINE "\033[9m"//删除线

//16色模式
#define TEXT_BLACK "\033[30m"//黑色文字
#define TEXT_RED "\033[31m"//红色文字
#define TEXT_GREEN "\033[32m"//绿色文字
#define TEXT_YELLOW "\033[33m"//黄色文字
#define TEXT_BLUE "\033[34m"//蓝色文字
#define TEXT_MAGENTA "\033[35m"//品红文字
#define TEXT_CYAN "\033[36m"//青色文字
#define TEXT_WHITE "\033[37m"//白色文字
#define TEXT_DEFAULT "\033[39m"//默认前景色文字
#define BACKGROUND_BLACK "\033[40m"//黑色背景
#define BACKGROUND_RED "\033[41m"//红色背景
#define BACKGROUND_GREEN "\033[42m"//绿色背景
#define BACKGROUND_YELLOW "\033[43m"//黄色背景
#define BACKGROUND_BLUE "\033[44m"//蓝色背景
#define BACKGROUND_MAGENTA "\033[45m"//品红背景
#define BACKGROUND_CYAN "\033[46m"//青色背景
#define BACKGROUND_WHITE "\033[47m"//白色背景
#define BACKGROUND_DEFAULT "\033[49m"//默认背景色

//光标
#define CURSOR_MOVE11 "\033[H"//光标移至(1,1)
#define CLEAR_SCREEN "\033[2J"//清除屏幕
#define CLEAR_LINE "\033[K"//清除本行文字
#define SAVE_CURSOR "\033[s"//保存光标位置
#define RESTORE_CURSOR "\033[u"//恢复光标位置
#define HIDE_CURSOR "\033[?25l"//隐藏光标
#define DISPLAY_CURSOR "\033[?25h"//显示光标

//控制
#define ENABLE_BACKUP_SCREEN_BUFFER "\033[?1049h"//启用备用屏幕缓冲区
#define EXIT_THE_BACKUP_SCREEN_BUFFER "\033[?1049l"//退出备用屏幕缓冲区
#define DISABLE_AUTOMATIC_LINE_WRAPPING "\033[?7l"//禁用自动换行
#define ENABLE_AUTOMATIC_LINE_WRAPPING "\033[?7h"//启用自动换行
#define QUERY_CURSOR_TYPE "\033[6n"//查询光标位置（返回\033[{y};{x}R）
#define QUERY_TERMINAL_TYPE "\033[c"//查询终端类型（返回\033[?{n}c）
#define QUERY_TERMINAL_CAPABILITY "\033[>c"//查询终端能力

void EnableANSI() {//启用ANSI功能
#ifdef _WIN32
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	GetConsoleMode(hOut, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);
#endif
}

//256色模式
std::string ANSI256(uint8_t n, bool backgroundcolor = false) {
	std::ostringstream oss;
	oss << "\033[" << (backgroundcolor ? "48" : "38") << ";5;{" << n << "}m";
	return oss.str();
}

//ANSI 24bit 色彩控制
std::string ANSIrgb(uint8_t r, uint8_t g, uint8_t b, bool backgroundcolor = false) {
	std::ostringstream oss;
	oss << "\033[" << (backgroundcolor ? "48" : "38") << ";2;" << r << ";" << g << ";" << b << "m";
	return oss.str();
}

//设置窗口标题
std::string SetWindowTitle(std::string title) {
	std::ostringstream oss;
	oss << "\033]0;{" << title << "}\a";
	return oss.str();
}

//移动鼠标光标
std::string CursorMove(char mode = 'A', int step) {//'A'表示上移，'B'表示下移，'C'表示右移，'D'表示左移
	std::ostringstream oss;
	switch (mode) {
	case 'A':oss << "\033[{" << step << "}A"; break;
	case 'B':oss << "\033[{" << step << "}B"; break;
	case 'C':oss << "\033[{" << step << "}C"; break;
	case 'D':oss << "\033[{" << step << "}D"; break;
	}
	return oss.str();
}

//移动鼠标至（y,x）
std::string MoveCursorTo(int x, int y) {
	std::ostringstream oss;
	oss << "\033[{" << y << "};{" << x << "}H";
	return oss.str();
}
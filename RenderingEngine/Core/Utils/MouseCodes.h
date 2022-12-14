#pragma once
/* Start Header -------------------------------------------------------
Copyright (C) 2022 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior written
consent of DigiPen Institute of Technology is prohibited.
File Name: MouseCodes.h
Purpose: for easy use i made my engine it converts glfw api to mine.
Language: C++ MSVC(2022)
Platform: MSVC(2022), GPU needs to support OpenGL 4.6.0, Windows11(x64)
Project: junwoo.seo_cs300_1
Author: Junwoo Seo, junwoo.seo, 0055213
Creation date: Sep 05 2022
End Header --------------------------------------------------------*/
#include <ostream>
//enums From glfw3.h however for easy use i made my engine one that converts glfw api to mine

typedef enum class MouseCode : unsigned short
{
	Button0 = 0,
	Button1 = 1,
	Button2 = 2,
	Button3 = 3,
	Button4 = 4,
	Button5 = 5,
	Button6 = 6,
	Button7 = 7,

	ButtonLast = Button7,
	ButtonLeft = Button0,
	ButtonRight = Button1,
	ButtonMiddle = Button2
} Mouse;

inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
{
	os << static_cast<int>(mouseCode);
	return os;
}


#define MOUSE_BUTTON_0      Mouse::Button0
#define MOUSE_BUTTON_1      Mouse::Button1
#define MOUSE_BUTTON_2      Mouse::Button2
#define MOUSE_BUTTON_3      Mouse::Button3
#define MOUSE_BUTTON_4      Mouse::Button4
#define MOUSE_BUTTON_5      Mouse::Button5
#define MOUSE_BUTTON_6      Mouse::Button6
#define MOUSE_BUTTON_7      Mouse::Button7
#define MOUSE_BUTTON_LAST   Mouse::ButtonLast
#define MOUSE_BUTTON_LEFT   Mouse::ButtonLeft
#define MOUSE_BUTTON_RIGHT  Mouse::ButtonRight
#define MOUSE_BUTTON_MIDDLE Mouse::ButtonMiddle

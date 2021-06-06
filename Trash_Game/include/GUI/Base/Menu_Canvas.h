#pragma once
#include <SEngine/Core/GUI/GUI_Canvas.h>
#include <string>

#include "S/S.h"

class Menu_Canvas : public GUI_Canvas {
public:

	Menu_Canvas() {};
	virtual ~Menu_Canvas() {};

	virtual void Menu_Button_Pressed(std::string name) = 0;

};

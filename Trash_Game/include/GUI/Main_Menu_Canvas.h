#pragma once

#include "GUI/Base/Menu_Canvas.h"

class Main_Menu_Canvas : public Menu_Canvas {
public:
	Main_Menu_Canvas() {};
	virtual ~Main_Menu_Canvas() {};

private:

protected:
	virtual bool On_Init() override;

	virtual void Menu_Button_Pressed(std::string name) override;

};
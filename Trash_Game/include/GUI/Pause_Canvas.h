#pragma once

#include "GUI/Base/Menu_Canvas.h"

class Pause_Canvas : public Menu_Canvas {
public:

	Pause_Canvas();
	virtual ~Pause_Canvas();

protected:
	virtual bool On_Init() override;



	virtual void Menu_Button_Pressed(std::string name) override;






};


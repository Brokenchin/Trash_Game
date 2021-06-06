#pragma once

#include <SEngine/Core/GUI/Base_Parts/GUI_Button.h>

class Menu_Button : public GUI_Button {
public:

	Menu_Button() : GUI_Button() {}
	virtual ~Menu_Button() {}
	void Set_Button_Name(std::string name);
protected:

	virtual bool On_Init() override;



	virtual void On_Mouse_Button_Up(const MOUSE_KEY & key) override;

private: 

	std::string m_button_name;

};

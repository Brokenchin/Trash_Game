#include "Trash_Game/include/GUI/Menu_Button.h"

#include "Trash_Game/include/GUI/Base/Menu_Canvas.h"

bool Menu_Button::On_Init() {
	return GUI_Button::On_Init();
}

void Menu_Button::Set_Button_Name(std::string name) { m_button_name = name; }

void Menu_Button::On_Mouse_Button_Up(const MOUSE_KEY & key) {

	if (key == MOUSE_KEY::LEFT) {

		auto c = static_cast<Menu_Canvas*>(d_parent_canvas);

		if (c)
			c->Menu_Button_Pressed(m_button_name);

	}

}

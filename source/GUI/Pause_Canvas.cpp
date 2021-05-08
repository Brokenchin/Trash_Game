#include "Trash_Game/include/GUI/Pause_Canvas.h"
#include "Trash_Game/include/GUI/Menu_Button.h"

#include "Core/GUI/Base_Parts/GUI_Text.h"
#include "Runtime/Libraries/Statix.h"

Pause_Canvas::Pause_Canvas() {}

Pause_Canvas::~Pause_Canvas() {}

bool Pause_Canvas::On_Init() {

	Menu_Button * m_b_1 = nullptr;
	Menu_Button * m_b_2 = nullptr;

	for (size_t i = 0; i < 2; i++) {

		auto a = Create_New_Widget<Menu_Button>();
		a->Set_Size(256.f, 64.f);
		a->Set_Pos(d_transform.size.x / 2 - a->Get_Transform().size.x / 2, 250.f + (64.f * i + (10.f * i)));
		a->Get_Button_Text();

		if (i == 0)
			m_b_1 = a;
		else
			m_b_2 = a;

	}




	auto b = Create_New_Widget<GUI_Object>({ d_transform.size.x / 2 - 460.f / 2 , 50.f }, { 460.f, 76.f });
	auto t = b->Create_New_Widget<GUI_Text>();
	t->Set_Text("Pause", 86, S::font_title);
	t->Set_Color_Font_Outline(sf::Color::Yellow);

	m_b_1->Get_Button_Text().Set_Text("Restart", 32 , S::font);
	m_b_2->Get_Button_Text().Set_Text("Quit", 32, S::font);

	m_b_1->Set_Button_Name("Restart");
	m_b_1->Set_Color_Area(sf::Color::Green, WIDGET_MOUSE_STATE::HOVER);
	m_b_2->Set_Color_Area(sf::Color(0, 100, 0), WIDGET_MOUSE_STATE::CLICKED);
	m_b_2->Set_Button_Name("Quit");
	m_b_2->Set_Color_Area(sf::Color::Red, WIDGET_MOUSE_STATE::HOVER);
	m_b_2->Set_Color_Area(sf::Color(139, 0, 0), WIDGET_MOUSE_STATE::CLICKED);

	return true;
}

void Pause_Canvas::Menu_Button_Pressed(std::string name) {
	//std::cout << name << std::endl;

	if (name == "Restart") {
		Statix::Open_World(S::S_trash_game_world_name, d_contr);
	}
	else {
		Statix::Open_World(S::S_trash_menu_world_name, d_contr);
	}

}

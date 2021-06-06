#include "GUI/Main_Menu_Canvas.h"
#include "GUI/Menu_Button.h"

#include <SEngine/Core/GUI/Base_Parts/GUI_Text.h>

#include <SEngine/Runtime/Libraries/Statix.h>

#include "Game_State/Trash_Game_State.h"


bool Main_Menu_Canvas::On_Init() {

	Menu_Button * m_b_1 = nullptr, * m_b_2 = nullptr;

	//CALL TEXT LOCATION SET RECTANGLE FIRST AND SET THE TEXT INSDE or just GUI OBJECT...
	//d_transform.size.x / 2 - a->Get_Transform().size.x / 2

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
	t->Set_Text("Trash Sorter", 86, S::font_title);
	t->Set_Color_Font_Outline(sf::Color::Yellow);
	t->Rotate(10.f);


	m_b_1->Get_Button_Text().Set_Text("Start Game", 32, S::font);
	m_b_1->Set_Button_Name("Start Game");
	m_b_1->Set_Color_Area(sf::Color::Green, WIDGET_MOUSE_STATE::HOVER);
	m_b_2->Get_Button_Text().Set_Text("Quit Game", 32, S::font);
	m_b_2->Set_Button_Name("Quit Game");
	m_b_2->Set_Color_Area(sf::Color::Red, WIDGET_MOUSE_STATE::HOVER);
	m_b_2->Set_Color_Area(sf::Color(139, 0, 0), WIDGET_MOUSE_STATE::CLICKED);

	auto c = Create_New_Widget<GUI_Object>({ d_transform.size.x - 275.f , d_transform.size.y - 50.f }, { 350.f, 76.f });
	auto t2 = c->Create_New_Widget<GUI_Text>();
	t2->Set_Text("Music by freesounds.org: \n ShadyDave - CC BY-NC 3.0 \n Migfus20   - CC BY 3.0", 16, S::font_num);
	t2->Set_Color_Font(sf::Color::White);
	//Music by - Migfus20 freesound.org - CC BY 3.0
	return true;
}

void Main_Menu_Canvas::Menu_Button_Pressed(std::string name) {
	std::cout << name << std::endl;

	if (name == "Start Game") {
		Statix::Open_World(S::S_trash_game_world_name, d_contr);
	}
	else if ("Quit Game") {
		Statix::Quit_Game();
	}

}

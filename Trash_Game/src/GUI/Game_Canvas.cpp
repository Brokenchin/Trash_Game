#include "GUI/Game_Canvas.h"

#include <SEngine/Core/GUI/Base_Parts/GUI_Rectangle.h>
#include <SEngine/Core/GUI/Base_Parts/GUI_Text.h>

#include "GUI/Menu_Button.h"

#include <SEngine/Runtime/Libraries/Statix.h>

#include "Game_State/Trash_Game_State.h"

Game_Canvas::Game_Canvas() {
	m_rect = nullptr;
}

Game_Canvas::~Game_Canvas() {}

bool Game_Canvas::On_Init() {

	//Setting both of the Text widgets...
	m_rect = Create_New_Widget<GUI_Object>();

	m_rect->Set_Size(250.f, 96.f);
	m_rect->Set_Pos(d_transform.size.x / 2.f - m_rect->Get_Transform().size.x / 2.f , 0.f );

	auto a = m_rect->Create_New_Widget<GUI_Object>();
	a->Set_Size(96.f, 96.f);

	auto b = m_rect->Create_New_Widget<GUI_Object>();
	b->Set_Size(96.f , 96.f);
	b->Set_Pos(m_rect->Get_Transform().size.x - b->Get_Transform().size.x , 0.f);

	m_wrong = a->Create_New_Widget<GUI_Text>();
	m_right = b->Create_New_Widget<GUI_Text>();

	m_wrong->Set_Text("0", 72, S::font_num);
	m_right->Set_Text("0", 72, S::font_num);

	m_wrong->Set_Color_Font(sf::Color::Black);
	m_right->Set_Color_Font(sf::Color::Green);

	m_wrong->Set_Color_Font_Outline(sf::Color::White);
	m_right->Set_Color_Font_Outline(sf::Color::Black);


	/* HELP BUTTON...*/
	auto help = Create_New_Widget<Menu_Button>();
	help->Set_Size(64.f, 64.f);
	help->Set_Pos(d_transform.size.x - help->Get_Transform().size.x , d_transform.size.y - help->Get_Transform().size.y);
	help->Set_Color_Area(sf::Color(255, 182, 193, 255));
	help->Set_Color_Area(sf::Color(255, 105, 180, 255), WIDGET_MOUSE_STATE::HOVER);
	help->Set_Color_Area(sf::Color(255, 20, 147), WIDGET_MOUSE_STATE::CLICKED);

	help->Set_Button_Name("Help");
	help->Get_Button_Text().Set_Text("?", 32, "Arialbd");

	return true;
}

void Game_Canvas::Menu_Button_Pressed(std::string name) {

	if (name == "Help") {

		//TODO make help overlay that explains what you need to do.

	}

}

void Game_Canvas::Update_Score() {

	auto sc = Statix::Get_Game_State<Trash_Game_State>()->Get_Score();

	m_wrong->Update_Text(std::to_string(sc.wrong));
	m_right->Update_Text(std::to_string(sc.correct));

}

void Game_Canvas::Reset() {
	m_wrong->Update_Text(std::to_string(0));
	m_right->Update_Text(std::to_string(0));
}

#include "Trash_Game/include/GUI/Congratulations_Canvas.h"

#include "Trash_Game/include/GUI/Pause_Canvas.h"
#include "Trash_Game/include/GUI/Menu_Button.h"

#include "Core/GUI/Base_Parts/GUI_Text.h"
#include "Runtime/Libraries/Statix.h"

#include "Trash_Game/include/Game_State/Trash_Game_State.h"

Congratulations_Canvas::Congratulations_Canvas() {}

Congratulations_Canvas::~Congratulations_Canvas() {}

bool Congratulations_Canvas::On_Init() {

	Menu_Button * m_b_1 = nullptr;
	Menu_Button * m_b_2 = nullptr;

	for (size_t i = 0; i < 2; i++) {

		auto a = Create_New_Widget<Menu_Button>();
		a->Set_Size(256.f, 64.f);
		a->Set_Pos(d_transform.size.x / 2 - a->Get_Transform().size.x / 2, 350.f + (64.f * i + (10.f * i)));
		a->Get_Button_Text();

		if (i == 0)
			m_b_1 = a;
		else
			m_b_2 = a;

	}

	auto b = Create_New_Widget<GUI_Object>({ d_transform.size.x / 2 - 460.f / 2 , 50.f }, { 460.f, 76.f });
	auto t = b->Create_New_Widget<GUI_Text>();
	t->Set_Text("Congratulations!", 86, S::font_title);
	t->Set_Color_Font_Outline(sf::Color::Yellow);



	m_b_1->Get_Button_Text().Set_Text("Restart", 32, S::font);
	m_b_2->Get_Button_Text().Set_Text("Quit", 32, S::font);

	m_b_1->Set_Button_Name("Restart");
	m_b_1->Set_Color_Area(sf::Color::Green, WIDGET_MOUSE_STATE::HOVER);
	m_b_2->Set_Color_Area(sf::Color(0, 100, 0), WIDGET_MOUSE_STATE::CLICKED);
	m_b_2->Set_Button_Name("Quit");
	m_b_2->Set_Color_Area(sf::Color::Red, WIDGET_MOUSE_STATE::HOVER);
	m_b_2->Set_Color_Area(sf::Color(139, 0, 0), WIDGET_MOUSE_STATE::CLICKED);

	Create_Results();

	return true;
}

void Congratulations_Canvas::On_Update(double ticks) {

	if (b_m_active) {

		m_elapsed_anim += (float)ticks;

		if (m_elapsed_anim > 3.f) {
			m_results_Title->Toggle_Visible_State(WIDGET_SHOWN_STATE::SHOWN);

			auto p = Statix::Get_Game_State<Trash_Game_State>()->Get_Percent();
			if (p > 75.f) {
				m_results_Title->Update_Text("Trash Master");
			}
			else if (p > 50.f) {
				m_results_Title->Update_Text("Trash Knowhow");
			}
			else if (p > 25.f) {
				m_results_Title->Update_Text("Trash Newb");
			}
			else if (p < 25) {
				m_results_Title->Update_Text("Garbage");
			}
		}
		else if (m_elapsed_anim > 2.f) {
			m_results_percent->Toggle_Visible_State(WIDGET_SHOWN_STATE::SHOWN);
			m_results_percent->Update_Text("Score: " + std::to_string(Statix::Get_Game_State<Trash_Game_State>()->Get_Percent()) + "%");
		}
		else if (m_elapsed_anim > 1.5f) {
			m_results_right->Toggle_Visible_State(WIDGET_SHOWN_STATE::SHOWN);
			auto sc = Statix::Get_Game_State<Trash_Game_State>()->Get_Score();
			m_results_right->Update_Text(std::to_string(sc.correct));
		}
		else if (m_elapsed_anim > 1.f) {
			m_results_wrong->Toggle_Visible_State(WIDGET_SHOWN_STATE::SHOWN);
			auto sc = Statix::Get_Game_State<Trash_Game_State>()->Get_Score();
			m_results_wrong->Update_Text(std::to_string(sc.wrong));
		}

	}
}

void Congratulations_Canvas::Activate() {

	b_m_active = true;
}

void Congratulations_Canvas::Deactivate() {
	m_elapsed_anim = 0.f;
	b_m_active = false;
	m_results_percent->Toggle_Visible_State(WIDGET_SHOWN_STATE::HIDDEN);
	m_results_wrong->Toggle_Visible_State(WIDGET_SHOWN_STATE::HIDDEN);
	m_results_right->Toggle_Visible_State(WIDGET_SHOWN_STATE::HIDDEN);
	m_results_Title->Toggle_Visible_State(WIDGET_SHOWN_STATE::HIDDEN);
}

void Congratulations_Canvas::Menu_Button_Pressed(std::string name) {
	//std::cout << name << std::endl;

	if (name == "Restart") {
		this->Deactivate();
		this->Toggle_Visible_State(WIDGET_SHOWN_STATE::HIDDEN);
		Statix::Open_World(S::S_trash_game_world_name, d_contr);
	}
	else {
		Statix::Open_World(S::S_trash_menu_world_name, d_contr);
	}

}

void Congratulations_Canvas::Create_Results() {
	//Setting both of the Text widgets...
	auto m_rect = Create_New_Widget<GUI_Object>();

	m_rect->Set_Size(250.f, 96.f);
	m_rect->Set_Pos(d_transform.size.x / 2.f - m_rect->Get_Transform().size.x / 2.f, 75.f);

	auto a = m_rect->Create_New_Widget<GUI_Object>();
	a->Set_Size(96.f, 96.f);

	auto b = m_rect->Create_New_Widget<GUI_Object>();
	b->Set_Size(96.f, 96.f);
	b->Set_Pos(m_rect->Get_Transform().size.x - b->Get_Transform().size.x, 0.f);

	m_results_wrong = a->Create_New_Widget<GUI_Text>();
	m_results_right = b->Create_New_Widget<GUI_Text>();

	m_results_wrong->Set_Text("0", 72, S::font_num);
	m_results_right->Set_Text("0", 72, S::font_num);

	m_results_wrong->Set_Color_Font(sf::Color::Black);
	m_results_right->Set_Color_Font(sf::Color::Green);

	m_results_wrong->Set_Color_Font_Outline(sf::Color::White);
	m_results_right->Set_Color_Font_Outline(sf::Color::Black);

	auto rect2 = Create_New_Widget<GUI_Object>();
	rect2->Set_Size(250.f, 96.f);
	rect2->Set_Pos(d_transform.size.x / 2.f - rect2->Get_Transform().size.x / 2.f, 130.f);

	m_results_percent = rect2->Create_New_Widget<GUI_Text>();
	m_results_percent->Set_Text("% got right:   0", 72, S::font_num);

	auto rect3 = Create_New_Widget<GUI_Object>();
	rect3->Set_Size(250.f, 96.f);
	rect3->Set_Pos(d_transform.size.x / 2.f - rect3->Get_Transform().size.x / 2.f + 100.f, 250.f);

	m_results_Title = rect3->Create_New_Widget<GUI_Text>();
	m_results_Title->Set_Text("Trash Master!", 72, S::font_title);
	m_results_Title->Rotate(15.f);
	Deactivate();
}

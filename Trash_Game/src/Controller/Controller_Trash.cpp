#include "Controller/Controller_Trash.h"

#include <SEngine/Runtime/Libraries/Statix.h>

#include <SEngine/Core/GUI/GUI.h>

#include "GUI/Game_Canvas.h"
#include "GUI/Pause_Canvas.h"
#include "GUI/Main_Menu_Canvas.h"
#include "GUI/Congratulations_Canvas.h"

#include "Game_State/Trash_Game_State.h"
#include "Objects/Trash.h"
#include "Objects/Bin.h"

#include <SEngine/Runtime/Libraries/Resourcex.h>


Trash_Controller::Trash_Controller(G_Object * obj) : Controller(obj) {
	m_gui_pause_screen = nullptr;
	m_gui_game_screen = nullptr;
	m_gui_main_menu = nullptr;

}

void Trash_Controller::Setup_Input() {

	auto bind2 = Bind_Input<Trash_Controller, &Trash_Controller::Left_Click>("Left_Click_Press", INPUT_STATE::PRESSED, this);
	bind2->Add_Key(MOUSE_KEY::LEFT);
	bind2->b_execute_when_paused = true;

	auto bind4 = Bind_Input<Trash_Controller, &Trash_Controller::Left_Click_R>("Left_Click_Release", INPUT_STATE::RELEASED, this);
	bind4->Add_Key(MOUSE_KEY::LEFT);
	bind4->b_execute_when_paused = true;

	auto bind3 = Bind_Input<Trash_Controller, &Trash_Controller::Pause_Menu>("Pause_Menu_Toggle", INPUT_STATE::PRESSED, this);
	bind3->Add_Key(KEYBOARD_KEY::P);
	bind3->b_execute_when_paused = true;

}

void Trash_Controller::Handle_Input(double ticks) {

	if (!m_held_obj)
		return;

	auto pos = m_held_obj->Get_Pos();
	auto size = m_held_obj->Get_Size();
	auto window = Statix::Get_Window_Size() - (m_held_obj->Get_Pos() + m_held_obj->Get_Size() / 2.f);


	//std::cout << "W  x: " << Get_Mouse_Event()->last_world_pos.x << " | y: " << Get_Mouse_Event()->last_world_pos.y << std::endl;
	//std::cout << "L  x: " << Get_Mouse_Event()->last_pos.x << " | y: " << Get_Mouse_Event()->last_pos.y << std::endl;

	auto mouse_vec = Mathix::Vector_Clamp(Get_Mouse_Event()->last_world_pos, sf::Vector2f(0.f, 0.f), Statix::Get_Window_Size());

	//if (0.f > pos.x) {
	//	std::cout << "LEFT" << std::endl;
	//	m_held_obj->Move(sf::Vector2f(50.f * ticks,0.f));
	//	//check the object pos + its movement and compare to screen.. hell lets just make function calle is within screen.. ifx,y1 < pos && x,y3 > pos.. and do not call the move at all just stop..
	//	//better idea lets just make collision for it...

	//	
	//}
	//else {



		m_held_obj->Move({
			(mouse_vec.x - (m_held_obj->Get_Pos().x + m_held_obj->Get_Size().x / 2.f)) * (float)ticks * 10 ,
			(mouse_vec.y - (m_held_obj->Get_Pos().y + m_held_obj->Get_Size().y / 2.f)) * (float)ticks * 10
			});

		auto test = m_held_obj->Get_Pos() - Get_Mouse_Event()->last_world_pos;
		//std::cout << "x: " <<test.x<< " y: " << test.y << std::endl;

	//}

}

bool Trash_Controller::On_Init() {

	//lets create here some shit..
	m_gui_game_screen = d_gui->Create_New_Canvas<Game_Canvas>("game");
	m_gui_pause_screen = d_gui->Create_New_Canvas<Pause_Canvas>("pause");
	m_gui_main_menu = d_gui->Create_New_Canvas<Main_Menu_Canvas>("menu");
	m_gui_congratulations_screen = d_gui->Create_New_Canvas<Congratulations_Canvas>("gratz");
	Main_Menu();
	return true;
}

void Trash_Controller::Main_Menu() {

	//LOAD WORLD MAIN MENU

	d_gui->Toggle_Canvases(WIDGET_SHOWN_STATE::HIDDEN, "menu");
	Play_Menu_Music();

}

void Trash_Controller::Trash_World() {
	d_gui->Toggle_Canvases(WIDGET_SHOWN_STATE::HIDDEN, "game");
	m_gui_game_screen->Reset();
	Play_Game_Music();
}

void Trash_Controller::Pause_Menu() {

	if (m_gui_main_menu->is_Shown() || m_gui_congratulations_screen->is_Shown())
		return;

	if (!m_gui_pause_screen->is_Shown()) {
		stored_offset = m_sf_music.getPlayingOffset();
		Play_Menu_Music();
		d_gui->Toggle_Canvases(WIDGET_SHOWN_STATE::HIDDEN, "pause");
		m_held_obj = nullptr;

	}
	else {
		d_gui->Toggle_Canvases(WIDGET_SHOWN_STATE::HIDDEN, "game");
		Play_Game_Music();
	}
}

void Trash_Controller::Test() {}

void Trash_Controller::Left_Click() {

	if (m_gui_pause_screen->is_Shown() || m_gui_main_menu->is_Shown())
		return;

	auto temp = Statix::Trace_Point(TRA_TRASH, this->Get_Mouse_Event()->last_world_pos);
	//DEBUG CODE
	//std::cout << "Mouse Word X = " << this->Get_Mouse_Event()->last_world_pos.x << "|| Y = " << this->Get_Mouse_Event()->last_world_pos.y << std::endl;
	//std::cout << "Mouse Pixel X = " << this->Get_Mouse_Event()->last_pos.x << "|| Y = " << this->Get_Mouse_Event()->last_pos.y << std::endl;

	if (temp.b_is_hit) {
		std::cout << temp.Get_First()->Get_ID() << std::endl;

		m_held_obj = temp.Get_First();
	}


}

void Trash_Controller::Left_Click_R() {

	if (m_held_obj) {
		Cast<Trash>(m_held_obj);
		m_held_obj = nullptr;

		if (m_gui_pause_screen->is_Shown() || m_gui_main_menu->is_Shown())
			return;

		auto temp = Statix::Trace_Point(TRA_BIN, this->Get_Mouse_Event()->last_world_pos);
		//DEBUG CODE
		//std::cout << "Mouse Word X = " << this->Get_Mouse_Event()->last_world_pos.x << "|| Y = " << this->Get_Mouse_Event()->last_world_pos.y << std::endl;
		//std::cout << "Mouse Pixel X = " << this->Get_Mouse_Event()->last_pos.x << "|| Y = " << this->Get_Mouse_Event()->last_pos.y << std::endl;

		if (temp.b_is_hit) {
			std::cout << temp.Get_First()->Get_ID() << std::endl;

			Cast<Bin>(temp.Get_First())->Handle_Trash();

			m_gui_game_screen->Update_Score();
			//m_held_obj = temp.Get_First();
		}

		if (Statix::Get_Game_State<Trash_Game_State>()->Is_Game_Complete()) {
			d_gui->Toggle_Canvases(WIDGET_SHOWN_STATE::HIDDEN, "gratz");
			m_gui_congratulations_screen->Activate();
			Play_Menu_Music();
		}

	}
}

void Trash_Controller::On_Game() {
	Trash_World();

}

void Trash_Controller::On_Main_Menu() {
	Main_Menu();
}

void Trash_Controller::Play_Menu_Music() {
	m_sf_music.stop();
	m_sf_music.setBuffer(Resourcex::Get_Soundbuffer(S::audio_menu_music));
	m_sf_music.setLoop(true);

	m_sf_music.setVolume(50.f);
	m_sf_music.play();

}

void Trash_Controller::Play_Game_Music() {

	if (m_gui_game_screen)
		m_sf_music.getPlayingOffset();

	m_sf_music.stop();
	m_sf_music.setBuffer(Resourcex::Get_Soundbuffer(S::audio_game_music));
	m_sf_music.setLoop(true);

	m_sf_music.setVolume(25.f);
	m_sf_music.setPlayingOffset(stored_offset);
	m_sf_music.play();
}

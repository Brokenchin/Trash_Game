#pragma once

#include <SEngine/Core/Controllers/Controller.h>
#include <SFML/Audio/Sound.hpp>

class Trash_Controller : public Controller {
public:

	Trash_Controller(G_Object * obj);
	virtual ~Trash_Controller() {};

	virtual void Setup_Input() override;
	virtual void Handle_Input(double ticks) override;

	virtual bool On_Init();


	void Main_Menu();
	void Trash_World();

	void Pause_Menu();

	void Test();

	void Left_Click();
	void Left_Click_R();

	void On_Game();
	void On_Main_Menu();

private:

	sf::Sound m_sf_music;
	sf::Time stored_offset = sf::Time();
	class Pause_Canvas * m_gui_pause_screen;
	class Game_Canvas * m_gui_game_screen;
	class Main_Menu_Canvas * m_gui_main_menu;
	class Congratulations_Canvas * m_gui_congratulations_screen;


	void Play_Menu_Music();
	void Play_Game_Music();
};

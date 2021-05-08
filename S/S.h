#pragma once
#include "Runtime/Objects/G_Object.h"
#include <string>

#define COL_TRASH Collision_Channel::Chan1
#define COL_BIN Collision_Channel::Chan2

#define TRA_TRASH Trace_Channel::Chan1
#define TRA_BIN Trace_Channel::Chan2
namespace S {

	const std::string S_trash_game_world_name("Trash_Game_World");
	const std::string S_trash_menu_world_name("Menu_World");
	const std::string font("StrangerThings-Regular");
	const std::string font_title("WC_RoughTrad");
	const std::string font_num("TwinMarker");


	const std::string tex_bg_MENU("yard");
	const std::string tex_bg_GAME("Box");
	const std::string tex_bins("bins");
	const std::string tex_trash("trash");
	const std::string tex_trash_big("trash_big");

	//AUDIO
	const std::string audio_menu_music("music/560446__migfus20__happy-background-music");
	const std::string audio_game_music("music/325647__shadydave__expressions-of-the-mind-piano-loop");

	const std::string audio_sfx_wrong("sfx/331912__kevinvg207__wrong-buzzer");
	const std::string audio_sfx_right("sfx/546081__stavsounds__correct3");
	//WILL BE USED BY BOTH BIN AND TRASH

	enum class TRASH_TYPE : int {
		GENERAL = 0,
		PLASTIC = 1,
		CARDBOARD = 2,
		PAPER = 3,
		METAL = 4,
		SER = 5,
		BIO = 6,
		JUNKYARD = 7,
		HAZARD = 8
	};

	//Some type of func struct to get the type and all shit..like the texture name...


}
#include "Trash_Game/include/Game/Trash_Game.h"
#include "Trash_Game/include/World/Trash_Game_World.h"
#include "Trash_Game/include/World/Main_Menu_World.h"

#include "Runtime/Libraries/Resourcex.h"

#include "Trash_Game/include/Controller/Controller_Trash.h"
#include "Trash_Game/include/Game_State/Trash_Game_State.h"

#include "Runtime/Libraries/Statix.h"



void Trash_Game::On_Init() {

	Create_Game_State<Trash_Game_State>();


	Create_New_World<Trash_Game_World>(false, S::S_trash_game_world_name);
	Create_New_World<Main_Menu_World>(true, S::S_trash_menu_world_name);

	Statix::Create_New_Controller<Trash_Controller>();


}

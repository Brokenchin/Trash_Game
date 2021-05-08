#include "Trash_Game/include/World/Main_Menu_World.h"
#include "Trash_Game/include/Objects/BG.h"
#include "Runtime/Libraries/Statix.h"

#include "Trash_Game/S/S.h"
#include "Trash_Game/include/Controller/Controller_Trash.h"

bool Main_Menu_World::On_Init() {

	Statix::Create_New_Object<BG>();


	return true;
}

void Main_Menu_World::On_Update(double ticks) {}

void Main_Menu_World::On_Kill() {}

void Main_Menu_World::On_Activate(class Controller * contr) {
	auto c = static_cast<Trash_Controller *>(contr);
	c->On_Main_Menu();



}

void Main_Menu_World::On_Deactivate(class Controller * contr) {


}

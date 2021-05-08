#include "Trash_Game/include/World/Trash_Game_World.h"
#include "Runtime/Libraries/Statix.h"
#include "Runtime/Libraries/Mathix.h"

#include "Trash_Game/include/Controller/Controller_Trash.h"

#include "Trash_Game/include/Objects/BG.h"

#include "Trash_Game/include/Game_State/Trash_Game_State.h"

#include "Trash_Game/include/Objects/Bin.h"

#include "Runtime/Libraries/Resourcex.h"

void Trash_Game_World::On_Update(double ticks) {}

void Trash_Game_World::On_Kill() {}

bool Trash_Game_World::On_Init() {

	Statix::Create_New_Object<BG>(sf::Vector2f(),0, this)->Setup(BG_TYPE::GAME);

	const float offset = 145.f;

	for (size_t i = 0; i < 5; i++) {

		auto bin = Statix::Create_New_Object<Bin>({ ((float)i * offset) + offset / 2, 100.f }, 0.f, this);
		bin->Setup(static_cast<S::TRASH_TYPE>(i));
	}

	for (size_t i = 5; i < 7; i++) {

		auto bin = Statix::Create_New_Object<Bin>({ (((float)i - 5.f) * offset) + offset / 2, 200.f }, 0.f, this);
		bin->Setup(static_cast<S::TRASH_TYPE>(i));
	}

	for (size_t i = 8; i < 9; i++) {

		auto bin = Statix::Create_New_Object<Bin>({ (((float)i - 6.f) * offset) + offset / 2, 200.f }, 0.f, this);
		bin->Setup(static_cast<S::TRASH_TYPE>(i));
	}

	for (size_t i = 6; i < 7; i++) {

		auto bin = Statix::Create_New_Object<Bin>({ ((float)i - 2.f) * offset -50.f, 200.f }, 0.f, this);
		bin->Setup(S::TRASH_TYPE::JUNKYARD);
	}

	//Garbaga 
	//Trash Sorter
	//Sort and Recycle

	//I nmeed logo for main menu and pause text for the pause screen..

	//TODO Lets makr some trash..

	return true;
}

void Trash_Game_World::On_Activate(class Controller * contr) {
	auto c = static_cast<Trash_Controller *>(contr);
	c->On_Game();

	Statix::Get_Game_State<Trash_Game_State>()->Reset(100);


	for (size_t i = 0; i < 95; i++) { 

	
		auto trash = Statix::Create_New_Object<Trash>({ Mathix::Random(100.f, 750.f), Mathix::Random(300.f,500.f) });
		trash->Setup_Trash(false, static_cast<S::TRASH_TYPE>(Mathix::Random(static_cast<int>(S::TRASH_TYPE::GENERAL), static_cast<int>(S::TRASH_TYPE::HAZARD))));
		//trash->Setup_Trash(false, S::TRASH_TYPE::JUNKYARD);

		m_trash.push_back(trash);


	}

	for (size_t i = 0; i < 5; i++) {


		auto trash = Statix::Create_New_Object<Trash>({ Mathix::Random(100.f, 650.f), Mathix::Random(300.f,500.f) });
		trash->Setup_Trash(true, S::TRASH_TYPE::JUNKYARD);

		m_trash.push_back(trash);


	}

}

void Trash_Game_World::On_Deactivate(class Controller * contr) {

	for (size_t i = 0; i < m_trash.size(); i++)	{
		if (m_trash[i])
			m_trash[i]->Kill();
	}

	m_trash.clear();
}

void Trash_Game_World::Remove_Trashes(Trash * to_remove) {
	for (size_t i = 0; i < m_trash.size(); i++) {
		if (m_trash[i] == to_remove) {
			m_trash[i]->Kill();
			m_trash[i] = nullptr;
		}

	}

}

#pragma once

#include "Runtime/World/World.h"

#include "Trash_Game/include/Objects/Trash.h"

#include <SFML/Audio/Sound.hpp>

class Trash_Game_World : public World {

public:

	Trash_Game_World() {};
	virtual ~Trash_Game_World() {};
	void Remove_Trashes(Trash * to_remove);
protected:

	virtual void On_Update(double ticks);
	virtual void On_Kill() override;

	virtual bool On_Init() override;

	virtual void On_Activate(class Controller * contr) override;
	virtual void On_Deactivate(class Controller * contr) override;



	std::vector<Trash*> m_trash{};

private:



};
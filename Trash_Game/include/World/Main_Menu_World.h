#pragma once


#include <SEngine/Runtime/World/World.h>

#include <SFML/Audio/Sound.hpp>

class Main_Menu_World : public World {
public:

	Main_Menu_World() {};
	virtual ~Main_Menu_World() {};

protected:

	virtual bool On_Init() override;
	virtual void On_Update(double ticks);
	virtual void On_Kill() override;

	virtual void On_Activate(class Controller * contr) override;
	virtual void On_Deactivate(class Controller * contr) override;

};

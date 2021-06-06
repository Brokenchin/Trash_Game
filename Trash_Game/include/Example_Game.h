#pragma once

#include <SEngine/Core/Engine/Small_Game_Engine.h>

/* Simple Example how game engine expects the game to be made.*/
class Example_Game : public S_Game_Engine {


public:
	Example_Game() {};
	virtual ~Example_Game() {};

protected:

	/* Create your Initial stuff for the game in here.*/
	virtual void On_Init() override;

private:











};



#pragma once


#include "Core/Engine/Small_Game_Engine.h"
#include "Trash_Game/S/S.h"

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>

class Trash_Game : public S_Game_Engine {
public:
	Trash_Game() {};
	virtual ~Trash_Game() {};

protected:

	virtual void On_Init();

private:



};
#pragma once

#include <SEngine/Runtime/Objects/Sprite.h>

enum class BG_TYPE {
	MENU,
	GAME
};

class BG : public Sprite {
public:

	BG(World * world) : Sprite(world) { m_type = BG_TYPE::MENU; };
	BG(World * w, sf::Vector2f loc) : Sprite(w, loc) 	{ m_type = BG_TYPE::MENU; };
	virtual ~BG() {}
	void Setup(BG_TYPE type) { m_type = type; };


protected:
	virtual bool On_Init();
	//virtual void On_Kill();

	


	BG_TYPE m_type;
};

#pragma once

#include <SEngine/Runtime/Objects/Sprite.h>

#include "S/S.h"

class Trash : public Sprite {
public:
	Trash(World * wc) :Sprite(wc) {};
	Trash(World * w, sf::Vector2f loc) :Sprite(w, loc) {};
	virtual ~Trash() {};

	S::TRASH_TYPE Get_Type() { return m_type; }	
	void Setup_Trash(bool is_it_big, S::TRASH_TYPE type);
	void On_Dump();
protected:


	virtual bool On_Init() override;

	

private:

	S::TRASH_TYPE m_type = S::TRASH_TYPE::GENERAL;


	bool b_is_big = false;

};
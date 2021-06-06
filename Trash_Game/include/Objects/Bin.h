#pragma once


#include <SEngine/Runtime/Objects/Sprite.h>

#include "S/S.h"

#include <SFML/Audio/Sound.hpp>

class Bin : public Sprite {
public:

	Bin(World * w) :Sprite(w) {  }
	Bin(World * w, sf::Vector2f loc) :Sprite(w, loc) {  }
	
	virtual ~Bin() {}

	inline void Setup(S::TRASH_TYPE type) { m_type = type; };

	void Handle_Trash();
protected:

	bool Has_Trash() { return m_held_trash; };

	virtual bool On_Init() override;

	virtual void On_Handle_Overlap_Begin(G_Object * object) override;
	virtual void On_Handle_Overlap_End(G_Object * object) override;



private:
	class Trash * m_held_trash = nullptr;

	S::TRASH_TYPE m_type = S::TRASH_TYPE::GENERAL;

	sf::Sound m_sfx;


};

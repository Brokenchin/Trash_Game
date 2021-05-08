#include "Trash_Game/include/Objects/Bin.h"
#include "Trash_Game/include/Objects/Trash.h"

#include "Trash_Game/include/Game_State/Trash_Game_State.h"

#include "Core/Helpers/Casts.h"
#include "Runtime/Libraries/Resourcex.h"
#include "Runtime/Libraries/Statix.h"

#include <iostream>

bool Bin::On_Init() {


	Set_Collision_Channel(COL_BIN);
	Set_Collision_Channel_Response(COL_TRASH, Collision_Type::OVERLAP);
	Set_Collision_Channel_Response(COL_BIN, Collision_Type::IGNORED);

	Set_Trace_Channel(TRA_BIN);
	Set_Trace_Channel_Response(TRA_BIN, Trace_Type::COLLIDE);

	if (m_type == S::TRASH_TYPE::JUNKYARD)
		Set_Collision_Size({ 128.f,128.f });
	else
		Set_Collision_Size({ 64.f,64.f });

	d_sf_sprite.setTexture(Resourcex::Get_Texture(S::tex_bins));
	auto rect = sf::IntRect({ static_cast<int>(m_type) * 64, 0 }, { 64,64 });
	d_sf_sprite.setTextureRect(rect);

	if (m_type == S::TRASH_TYPE::JUNKYARD) {
		d_sf_sprite.setScale(2.f, 2.f);
	}

	return true;
}

void Bin::On_Handle_Overlap_Begin(G_Object * object) {

	std::cout << object->Get_ID() << " started " << std::endl;

	auto trash = Cast<Trash>(object);

	m_held_trash = trash;

}

void Bin::On_Handle_Overlap_End(G_Object * object) {

	std::cout << object->Get_ID() << " ended" << std::endl;
}

void Bin::Handle_Trash() {
	if (m_held_trash) {

		if (m_held_trash->Get_Type() == m_type) {
			Statix::Get_Game_State<Trash_Game_State>()->Update_Score(true);
			m_sfx.setBuffer(Resourcex::Get_Soundbuffer(S::audio_sfx_right));
			m_sfx.setVolume(50.f);
			m_sfx.play();
		}
		else {
			m_sfx.stop();
			Statix::Get_Game_State<Trash_Game_State>()->Update_Score(false);
			m_sfx.setBuffer(Resourcex::Get_Soundbuffer(S::audio_sfx_wrong));
			m_sfx.setVolume(25.f);
			m_sfx.play();
		}
		m_held_trash->On_Dump();
		m_held_trash = nullptr;
	}

}

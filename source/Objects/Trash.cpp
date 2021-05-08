#include "Trash_Game/include/Objects/Trash.h"

#include "Core/Helpers/Casts.h"

#include "Runtime/Libraries/Mathix.h"
#include "Runtime/Libraries/Resourcex.h"
#include "Trash_Game/include/World/Trash_Game_World.h"
bool Trash::On_Init() {
	Set_Collision_Channel(COL_TRASH);
	Set_Trace_Channel(TRA_TRASH);
	Set_Trace_Channel_Response(TRA_TRASH, Trace_Type::COLLIDE);
	Set_Collision_Channel_Response(COL_BIN, Collision_Type::OVERLAP);
	//Set_Collision_Channel_Response(COL_TRASH, Collision_Type::COLLIDE);
	if (b_is_big)
		Set_Collision_Size({ 128.f, 128.f });
	else
		Set_Collision_Size({ 32.f,32.f });
	return true;
}

void Trash::On_Dump() {
	Cast<Trash_Game_World>(d_world)->Remove_Trashes(this);

}


void Trash::Setup_Trash(bool is_it_big, S::TRASH_TYPE type) {

	m_type = type;
	b_is_big = is_it_big;

	if (is_it_big) {
		auto i = Mathix::Random(0, 3);
		d_sf_sprite.setTexture(Resourcex::Get_Texture(S::tex_trash_big));
		auto rect = sf::IntRect({ i * 128, 0 }, { 128,128 });
		d_sf_sprite.setTextureRect(rect);

		if (i > 1) {
			m_type = S::TRASH_TYPE::SER;
		}
		else {
			m_type = S::TRASH_TYPE::JUNKYARD;
		}
	}
	else {
		if (type == S::TRASH_TYPE::JUNKYARD)
			m_type = S::TRASH_TYPE::BIO;

		auto i = Mathix::Random(0, 4);
		d_sf_sprite.setTexture(Resourcex::Get_Texture(S::tex_trash));
		auto rect = sf::IntRect({ i * 32, static_cast<int>(m_type) * 32 }, { 32,32 });
		d_sf_sprite.setTextureRect(rect);

	}

}

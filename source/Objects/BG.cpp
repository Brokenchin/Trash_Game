#include "Trash_Game/include/Objects/BG.h"

#include "Runtime/Libraries/Statix.h"
#include "Runtime/Libraries/Resourcex.h"

//SFML
#include <SFML/Graphics/Sprite.hpp>

#include "Trash_Game/S/S.h"

bool BG::On_Init() {

	auto wind_size = Statix::Get_Window_Size();

	//problem with this is that this has no way to set direct size...
	if (m_type == BG_TYPE::GAME)
		d_sf_sprite.setTexture(Resourcex::Get_Texture(S::tex_bg_GAME));
	else
		d_sf_sprite.setTexture(Resourcex::Get_Texture(S::tex_bg_MENU));
	return true;
}

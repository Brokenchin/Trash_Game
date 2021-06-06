#pragma once

#include "GUI/Base/Menu_Canvas.h"

class Game_Canvas : public Menu_Canvas {
public:


	Game_Canvas(); 
	virtual ~Game_Canvas();

	virtual bool On_Init() override;

	void Update_Score();
	void Reset();
protected:

	virtual void Menu_Button_Pressed(std::string name) override;





private:


	GUI_Object * m_rect;
	class GUI_Text * m_wrong = nullptr, * m_right = nullptr;



};

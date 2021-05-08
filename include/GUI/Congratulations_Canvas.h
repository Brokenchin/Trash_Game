#pragma once

#include "Trash_Game/include/GUI/Base/Menu_Canvas.h"
#include "Core/GUI/Base_Parts/GUI_Text.h"
class Congratulations_Canvas : public Menu_Canvas {
public:

	Congratulations_Canvas();
	virtual ~Congratulations_Canvas();
	void Activate();
	void Deactivate();
protected:
	virtual bool On_Init() override;

	virtual void On_Update(double ticks) override;


	virtual void Menu_Button_Pressed(std::string name) override;

	void Create_Results();

	GUI_Text * m_results_wrong =nullptr;
	GUI_Text * m_results_right = nullptr;
	GUI_Text * m_results_percent = nullptr;
	GUI_Text * m_results_Title = nullptr;


	bool b_m_active = false;
	float m_elapsed_anim = 0.f;
};
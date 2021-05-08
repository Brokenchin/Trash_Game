#pragma once

#include "Runtime/Game_State/Game_State.h"

//couls also use struct called Score..

struct Score {

	unsigned int wrong = 0, correct = 0;

	void Reset() {
		wrong = 0;
		correct = 0;
	};
};

class Trash_Game_State : public Game_State {
public:
	Trash_Game_State();
	~Trash_Game_State();


	void Update_Score(bool correct) const {

		if (correct)
			m_score.correct++;
		else
			m_score.wrong++;

		m_count++;
	}

	const Score & Get_Score() const {

		return m_score;
	}

	const bool Is_Game_Complete() const {

		return m_count == m_trashes;

	}

	const int & Get_Trash_Count() const {

		return m_trashes;
	}

	const float Get_Percent() const {

		return (float(m_score.correct) / float(m_trashes)) * 100;
	}

	

	void Reset(int number_of_trashes) const {
		m_score.Reset();
		m_trashes = number_of_trashes;
		m_count = 0;
	}

private:
	mutable int m_count;
	mutable int m_trashes = 0;
	mutable Score m_score;

};
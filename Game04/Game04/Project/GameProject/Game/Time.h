#pragma once
#include "../Base/Base.h"

class TIME :public Base
{
	//�����\���I�u�W�F�N�g
	CFont m_time_text;
	int time;
public:
	TIME();
	void Update();
	void Draw();
};
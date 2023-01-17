#pragma once
#include "../Base/Base.h"

class TIME :public Base
{
	//文字表示オブジェクト
	CFont m_time_text;
	int time;
public:
	TIME();
	void Update();
	void Draw();
};
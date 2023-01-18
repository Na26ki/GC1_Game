#include "Time.h"

TIME::TIME() :Base(eType_Scene),
m_time_text("C://Windows//Fonts//msgothic.ttc", 64)
{
	time = 10 * 80;
}

void TIME::Update()
{
	time--;

	if (time < 0) {
		Base::KillAll();
	};
}

void TIME::Draw()
{
	//•¶Žš•\Ž¦
	//m_time_text.Draw(64, 256, 0, 0, 0, "[%d]Time", time);
	m_time_text.Draw(575, 70, 0, 0, 0, "[%d]",time/101);
}
#include "Gameover.h"

Gameover::Gameover() :Base(eType_Scene)
{
	//�摜�̕���
	m_Gameover = COPY_RESOURCE("Gameover", CImage);
}

void Gameover::Draw()
{
	m_Gameover.Draw();
}
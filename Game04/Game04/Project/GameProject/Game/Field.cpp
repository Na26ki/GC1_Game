#include "Field.h"

Field::Field() :Base(eType_Field)
{
	//�摜�̕���
	m_sand = COPY_RESOURCE("sand", CImage);
}

void Field::Draw()
{
	m_sand.Draw();
}
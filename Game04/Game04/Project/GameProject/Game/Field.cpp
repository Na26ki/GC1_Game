#include "Field.h"

Field::Field() :Base(eType_Field)
{
	//‰æ‘œ‚Ì•¡»
	m_sand = COPY_RESOURCE("sand", CImage);
}

void Field::Draw()
{
	m_sand.Draw();
}
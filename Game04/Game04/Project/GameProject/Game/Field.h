#pragma once
#include "../Base/Base.h"

class Field : public Base {
private:
	//�摜�I�u�W�F�N�g
	CImage m_sand;
public:
	//�R���X�g���N�g
	Field();
	//�`��
	void Draw();
};

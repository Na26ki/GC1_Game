#pragma once
#include "../Base/Base.h"

//m_speed : �ړ��̑���
class Bullet : public Base {
	CImage m_img;
	float m_speed;
public:
	//type : �e�̎�ށi�v���C���[�̒e�A�G�̒e�j
		//pos : �ʒu
		//ang : �p�x
		//speed : ����
	Bullet(int type, int player_id, const CVector2D& pos, float ang, float speed);
	void Update();
	void Draw();
	void Collision(Base* b);
};
#pragma once
#include "../Base/Base.h"

//m_speed : 移動の速さ
class Bullet : public Base {
	CImage m_img;
	float m_speed;
public:
	//type : 弾の種類（プレイヤーの弾、敵の弾）
		//pos : 位置
		//ang : 角度
		//speed : 速さ
	Bullet(int type, int player_id, const CVector2D& pos, float ang, float speed);
	void Update();
	void Draw();
	void Collision(Base* b);
};
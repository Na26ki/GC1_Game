#pragma once
#include "../Base/Base.h"

class Gauge;
class Player : public Base {
	CImage m_img;
	int m_player_id;

private:
	int m_hp;
	int m_max_hp;
	Gauge* m_gauge;

public:
	Player(const CVector2D& pos, int player_id);
	~Player();
	void Update();
	void Draw();
	void Collision(Base* b);
};
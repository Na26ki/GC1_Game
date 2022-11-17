/*
#include "Enemy.h"
#include "Bullet.h"

Enemy::Enemy(const CVector2D& pos)
	:Base(eType_Enemy)
{
	//画像を読み込んで複製
	m_img = COPY_RESOURCE("Enemy", CImage);
	m_pos = pos;
	m_img.SetCenter(16, 16);
}

void Enemy::Update()
{
//ゲーム内から指定したTypeのオブジェクトを探します
	//カウントアップ
	m_cnt++;
	//プレイヤーを取得
	Base* b = Base::FindObject(eType_Player);
	//プレイヤーが居れば
	if (b) {
		//ターゲットへのベクトル
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
//120F = 2秒
//プレイヤーに向かって
//弾を撃ちます
		if (m_cnt >= 120) {
			Base::Add(new Bullet(eType_Enemy_Bullet, m_pos, m_ang, 4));
			m_cnt = 0;
		}
	}

}

void Enemy::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Enemy::Collision(Base* b)
{
}
*/
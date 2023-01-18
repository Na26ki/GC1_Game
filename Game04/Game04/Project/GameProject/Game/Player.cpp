#include "Player.h"
#include "Bullet.h"
#include "Gauge.h"
#include "Map.h"

Player::Player(const CVector2D& pos,int player_id)
	:Base(eType_Player){
	//画像を読み込んで複製
	m_img = COPY_RESOURCE("Player2", CImage);
	m_pos = pos;
	//中心を設定
	m_img.SetCenter(16, 16);
	//表示サイズ
	m_img.SetSize(45, 45);
	//短形を設定  //左 //上 //右 //下
	m_rect = CRect(-16, -16, 16, 16);
	//半径
	m_rad = 16;
	m_player_id = player_id;

	//ゲージ生成
	Base::Add(m_gauge = new Gauge(0));
	//HP設定
	m_hp = m_max_hp = 200;


}

Player::~Player()
{
	//ゲージ削除
	if (m_gauge)
		m_gauge->SetKill();
}
void Player::Update()
{
	m_pos_old = m_pos;
	const float speed = 4;

	//アナログスティックはx,yそれぞれ-1～1の値を返却
	//左スティック
	CVector2D axis_l = CInput::GetLStick(m_player_id);
	//右スティック
	CVector2D axis_r = CInput::GetRStick(m_player_id);

	//左スティックは移動
	//0.2は遊び領域
	if (axis_l.Length() > 0.2f) {
		//正規化
		CVector2D dir = axis_l.GetNormalize();
		//倒し具合でスピード調整
		m_pos += dir * axis_l.Length() * speed;
	}
	//右スティックは照準
	if (axis_r.Length() > 0.2f) {
		m_ang = atan2(axis_r.x, axis_r.y);
	}
	//十字キーは方向キーと同じ
	//if (HOLD_PAD(m_player_id, CInput::eLeft)) {
	//}

	//複数のゲームパッドを使用する場合は
	//PUSH_PAD,HOLD_PADを使用。第一引数にパッドのID(0,1,2,3など)を指定する
	// 
	//コントローラーによるが右トリガーボタン
	if (PUSH_PAD(m_player_id, CInput::eButton6)) {
		Base::Add(new Bullet(eType_Player_Bullet, m_player_id,m_pos, m_ang, 4));
	}

}

void Player::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Enemy:
		if (Base::CollisionRect(this, b)) {
			m_hp -= 1;
			if (m_hp < 0) {
				m_hp = 0;
				SetKill();
			}
		}
		break;

	case eType_Player_Bullet:
		if (m_player_id != b->m_player_id && Base::CollisionCircle(this, b)) {

			m_hp -= 20;
			if (m_hp <= 0)
			SetKill();
			b->SetKill();
		}
		break;

	case eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y));
			if (t != 0)
				m_pos.x = m_pos_old.x;
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y));
			if (t != 0)
				m_pos.y = m_pos_old.y;
		}
		break;
	}
}

void Player::Draw() 
{
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();

	//Gauge位置
	CVector2D gp[] = {
		//{0,0},
		//{1280 - 256,0},
		{3,0},
		{1280 - 560,0},
	};
	m_gauge->m_pos = gp[m_player_id];
	m_gauge->SetValue((float)m_hp / m_max_hp);
}

#include "Player.h"
#include "Bullet.h"
#include "Map.h"
#include "Gauge.h"

Player::Player(const CVector2D& pos,int player_id)
	:Base(eType_Player){
	//�摜��ǂݍ���ŕ���
	m_img = COPY_RESOURCE("Player", CImage);
	m_pos = pos;
	//���S��ݒ�
	m_img.SetCenter(16, 16);
	//�Z�`��ݒ�
	m_rect = CRect(-16, -16, 16, 16);
	//���a
	m_rad = 16;
	m_player_id = player_id;

	//�Q�[�W����
	Base::Add(m_gauge = new Gauge(0));
	//HP�ݒ�
	m_hp = m_max_hp = 200;


}
Player::~Player()
{
	//�Q�[�W�폜
	if (m_gauge)
		m_gauge->SetKill();
}
void Player::Update()
{
	const float speed = 4;

	//�A�i���O�X�e�B�b�N��x,y���ꂼ��-1�`1�̒l��ԋp
	//���X�e�B�b�N
	CVector2D axis_l = CInput::GetLStick(m_player_id);
	//�E�X�e�B�b�N
	CVector2D axis_r = CInput::GetRStick(m_player_id);

	//���X�e�B�b�N�͈ړ�
	//0.2�͗V�ї̈�
	if (axis_l.Length() > 0.2f) {
		//���K��
		CVector2D dir = axis_l.GetNormalize();
		//�|����ŃX�s�[�h����
		m_pos += dir * axis_l.Length() * speed;
	}
	//�E�X�e�B�b�N�͏Ə�
	if (axis_r.Length() > 0.2f) {
		m_ang = atan2(axis_r.x, axis_r.y);
	}
	//�\���L�[�͕����L�[�Ɠ���
	//if (HOLD_PAD(m_player_id, CInput::eLeft)) {
	//}

	//�����̃Q�[���p�b�h���g�p����ꍇ��
	//PUSH_PAD,HOLD_PAD���g�p�B�������Ƀp�b�h��ID(0,1,2,3�Ȃ�)���w�肷��
	// 
	//�R���g���[���[�ɂ�邪�E�g���K�[�{�^��
	if (PUSH_PAD(m_player_id, CInput::eButton6)) {
		Base::Add(new Bullet(eType_Player_Bullet, m_pos, m_ang, 4));
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
	}
}
void Player::Draw() 
{
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();
}
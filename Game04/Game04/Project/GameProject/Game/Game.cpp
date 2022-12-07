#include "Game.h"
#include "Map.h"
//#include "Field.h"
#include "Player.h"
#include "Enemy.h"
#include "Gauge.h"
#include "../Title/Title.h"

Game::Game() :Base(eType_Scene)
{
	Base::Add(new Map());
	Base::Add(new Gauge(0));
	Base::Add(new Player(CVector2D(200,200),false));
	Base::Add(new Player(CVector2D(800, 800), false));
}

Game::~Game()
{
	//�S�ẴI�u�W�F�N�g��j��
	Base::KillAll();
	//�^�C�g���V�[����
	Base::Add(new Title());
}

void Game::Update()
{
	//�v���C���[���S�@�{�^���P�ŃQ�[���V�[���I��
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
	}
}
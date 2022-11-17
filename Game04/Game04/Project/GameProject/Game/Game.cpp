#include "Game.h"
#include "Map.h"
//#include "Field.h"
#include "Player.h"
#include "Enemy.h"
#include "Gauge.h"
#include "../Title/Title.h"

Game::Game() :Base(eType_Scene)
{
	//Map
	Base::Add(new Map());
	//Player
	//Base::Add();
	//Gauge
	//Base::Add(new Gauge());

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
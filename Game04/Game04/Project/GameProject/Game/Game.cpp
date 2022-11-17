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
	//全てのオブジェクトを破棄
	Base::KillAll();
	//タイトルシーンへ
	Base::Add(new Title());
}

void Game::Update()
{
	//プレイヤー死亡　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
	}
}
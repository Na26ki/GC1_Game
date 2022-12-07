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
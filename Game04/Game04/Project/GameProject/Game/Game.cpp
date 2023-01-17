#include "Game.h"
#include "Field.h"
#include "Map.h"
//#include "Field.h"
#include "Player.h"
#include "Enemy.h"
#include "Gauge.h"
#include "Time.h"
#include "Gameover.h"
#include "../Title/Title.h"

Game::Game() :Base(eType_Scene)
{
	Base::Add(new Field());
	Base::Add(new Map());
	Base::Add(new TIME());
	//[ 0 1 ]でプレイヤーの区別をしている
	Base::Add(new Player(CVector2D(200,330),0));
	Base::Add(new Player(CVector2D(1050, 330), 1));
}

Game::~Game()
{
	//全てのオブジェクトを破棄
	Base::KillAll();
	//タイトルシーンへ
	Base::Add(new Gameover2());
}

void Game::Update()
{
	//プレイヤー死亡　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
	}
}
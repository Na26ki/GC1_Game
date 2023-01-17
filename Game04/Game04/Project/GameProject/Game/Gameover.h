#pragma once
#include "../Base/Base.h"

class Gameover : public Base {
private:
	//画像オブジェクト
	CImage m_Gameover;
public:
	//コンストラクト
	Gameover();
	//描画
	void Draw();
};

#pragma once
#include "../Base/Base.h"

class Field : public Base {
private:
	//画像オブジェクト
	CImage m_sand;
public:
	//コンストラクト
	Field();
	//描画
	void Draw();
};

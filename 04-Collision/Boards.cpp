#include "Boards.h"

string Board::FillNumber(string s, UINT MaxNumber)
{
	while (s.size() < MaxNumber)
		s = "0" + s;
	return s;
}

Board::Board(float X, float Y)
{
	_texture = TextureManager::GetInstance()->GetTexture(eType::BOARD);
	_sprite = new GSprite(_texture, 0);

	_spriteIconDoubleShot = new GSprite(TextureManager::GetInstance()->GetTexture(eType::ITEMDOUBLESHOT), 0);

	x = X;
	y = Y;

	_boardHealth = new BoardHealth(x + 110, y + 30);
}


Board::~Board()
{
	SAFE_DELETE(_sprite);
}

void Board::SetTexture(GTexture* tex)
{
	_texture = tex;
	_sprite->texture = tex;
}

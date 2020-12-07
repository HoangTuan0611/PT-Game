#include "Brick.h"




Brick::Brick(float X, float Y, int W, int H, int Model)
{
	model = Model;
	switch (Model)
	{
	case BRICK_MODEL_1:
		texture = TextureManager::GetInstance()->GetTexture(eType::TEX_BRICK_MODEL_1); // loại màn 1
		break;
	case BRICK_MODEL_2:
		texture = TextureManager::GetInstance()->GetTexture(eType::TEX_BRICK_MODEL_2); // loại màn 2
		break;
	case BRICK_MODEL_3:
		texture = TextureManager::GetInstance()->GetTexture(eType::TEX_BRICK_MODEL_3); // loại nhỏ 16px
		break;
	case BRICK_MODEL_TRANSPARENT:
		texture = TextureManager::GetInstance()->GetTexture(eType::TEX_BRICK_TRANSPARENT);// loại trong suốt 
		break;
	case BRICK_MODEL_3_3_32:
		texture = TextureManager::GetInstance()->GetTexture(eType::TEX_BRICK_MODEL_3_3_32);// loại 3 ô nhỏ - 32px 
		break;
	case BRICK_MODEL_3_4_32:
		texture = TextureManager::GetInstance()->GetTexture(eType::TEX_BRICK_MODEL_3_4_32);// loại đủ 4 ô nhỏ - 32px
		break;
	default:
		DebugOut(L"[BRICK] Get Texture that bai! Ko nhan dang duoc Model!\n");
		break;
	}

	type = eType::BRICK;
	sprite = new GSprite(texture, 1000);
	this->x = X;
	this->y = Y;
	this->width = W;
	this->height = H;
}


void Brick::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + (float)ceil(width / texture->GetFrameWidth()) * texture->GetFrameWidth();
	b = y + (float)ceil(height / texture->GetFrameHeight()) * texture->GetFrameHeight();
}

int Brick::GetModel()
{
	return model;
}

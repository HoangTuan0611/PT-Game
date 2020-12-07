#pragma once

#include <Windows.h>
#include <d3dx9.h>
#include <vector>

#include "Sprites.h"
#include "Contands.h"


#include "Define.h"
#include "GSprite.h"
#include "GTexture.h"
#include "TextureManager.h"

// Tuan code
#include "Camera.h" 


using namespace std;

class CGameObject; 
typedef CGameObject * LPGAMEOBJECT;

struct CCollisionEvent;
typedef CCollisionEvent * LPCOLLISIONEVENT;
struct CCollisionEvent
{
	LPGAMEOBJECT obj;
	float t, nx, ny;
	CCollisionEvent(float t, float nx, float ny, LPGAMEOBJECT obj = NULL) { this->t = t; this->nx = nx; this->ny = ny; this->obj = obj; }

	static bool compare(const LPCOLLISIONEVENT &a, LPCOLLISIONEVENT &b)
	{
		return a->t < b->t;
	}
};



class CGameObject
{
public:

	float x; 
	float y;

	float dx;	// dx = vx*dt
	float dy;	// dy = vy*dt

	float vx;
	float vy;

	int nx;	 

	int state;
	int nextState;
	bool isHidden;
	bool renderBBox;
	bool isStop;
	bool isActive;
	DWORD dt;
	DWORD stop_time;

	// Tuan define intro
	GTexture* texture;
	GSprite* sprite;
	eType type; // Loại Object
	int Health;
	HWND hWnd;
	int direction;	// hướng -1 : trái, 1: phải

	vector<LPANIMATION> animations;
	int hp;
public: 
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	void SetSpeed(float vx, float vy) { this->vx = vx, this->vy = vy; }
	void GetPosition(float &x, float &y) { x = this->x; y = this->y; }
	void GetSpeed(float &vx, float &vy) { vx = this->vx; vy = this->vy; }

	int GetState() { return this->state; }
	int GetNextState() { return this->nextState; }
	bool get_isHidden() { return isHidden; }
	void set_isHidden(bool hidden) { isHidden = hidden; }

	void RenderBoundingBox();
	void RenderBoundingBox(Camera* camera);
	void toggleRenderBBox() { renderBBox = !renderBBox; }

	LPCOLLISIONEVENT SweptAABBEx(LPGAMEOBJECT coO);
	void CalcPotentialCollisions(vector<LPGAMEOBJECT> *coObjects, vector<LPCOLLISIONEVENT> &coEvents); // Tính toán những TH có thể va chạm
	void FilterCollision(
		vector<LPCOLLISIONEVENT> &coEvents, 
		vector<LPCOLLISIONEVENT> &coEventsResult, 
		float &min_tx, 
		float &min_ty, 
		float &nx, 
		float &ny);

	void AddAnimation(int aniId);

	bool isOverlapping(CGameObject* other);
	void basicCollision(float &min_tx, float &min_ty,float& nx, float& ny);

	CGameObject();

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom) = 0;
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render() = 0;
	//virtual void Render(Camera* camera) = 0;
	virtual void SetState(int state) { this->state = state; }
	virtual void SetNextState(int nextState) { this->nextState = nextState; }
	virtual void BeDestroy();
	void SetDirection(int d);

	// Tuan define
	float GetX();
	GSprite* GetSprite();

	// end Tuan

	~CGameObject();
};


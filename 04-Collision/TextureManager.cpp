#include "TextureManager.h"

TextureManager* TextureManager::__Instance = NULL;

TextureManager* TextureManager::GetInstance()
{
	if (__Instance == NULL)
		__Instance = new TextureManager();
	return __Instance;
}

void TextureManager::AddTexture(eType type, GTexture* texture)
{
	_ArrTextures[type] = texture;
}

GTexture* TextureManager::GetTexture(eType type)
{
	return _ArrTextures[type];
}

void TextureManager::LoadResource()
{
	// Intro
	AddTexture(eType::MAINMENU, new GTexture("Resources/mainmenu.png"));
	AddTexture(eType::INTRO_BAT, new GTexture("Resources/intro_bat.png", 2, 1, 2));
	AddTexture(eType::INTRO_BAT_MENU, new GTexture("Resources/IntroBatMenu.png", 5, 3, 15));
	AddTexture(eType::INTRO_GO_SCENE1, new GTexture("Resources/intro_go_scene_1.png"));
	AddTexture(eType::HELICOPTER, new GTexture("Resources/helicopter.png"));
}

TextureManager::TextureManager()
{
	LoadResource();
}


TextureManager::~TextureManager()
{
	SAFE_DELETE(__Instance);
}

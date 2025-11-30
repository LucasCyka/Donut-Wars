#ifndef SCENE_H
#define SCENE_H

#include "raylib.h" 

typedef enum GameScene  {
	LOGO,
	MENU,
	GAMEPLAY,
	GAMEOVER
	
}scene;

extern scene CurrentScene;


void UpdateGameplayScene(Vector2 mousePos);
void DrawGameplayScene();
int  IsStateOver();

#endif

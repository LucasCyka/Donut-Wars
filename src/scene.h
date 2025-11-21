#ifndef SCENE_H
#define SCENE_H

typedef enum GameScene  {
	LOGO,
	MENU,
	GAMEPLAY,
	GAMEOVER
	
}scene;

extern scene CurrentScene;


void UpdateGameplayScene();
void DrawGameplayScene();
int  IsStateOver();

#endif

#include "scene.h"
#include "assets.h"

#define PLAYER_ANIM_SPEED 15

static int playerAnimFrame = 0;
static Vector2 playerPosition = {0.0f, 0.0f};
static Rectangle playerAnimRec = {0.0f,0.0f,0.0f,0.0f};
static float frameCounter  = 0.0f; 
static float playerSpeed = 10.0f;

void UpdateGameplayScene(Vector2 mousePos){
	frameCounter++;
	playerAnimRec = (Rectangle) {playerAnimFrame*jetTextMoving.width/10.0f,0.0f,jetTextMoving.width/10.0f,jetTextMoving.height};
	if(frameCounter >= (30/PLAYER_ANIM_SPEED)){
		 
		playerAnimFrame++;
		frameCounter = 0;
	}
	
	if(IsKeyDown(KEY_RIGHT)){
		//playerPosition.x += playerSpeed;
	}
	
	playerPosition.x += IsKeyDown(KEY_RIGHT) * playerSpeed; 	
	playerPosition.x -= IsKeyDown(KEY_LEFT) * playerSpeed; 	
	playerPosition.y += IsKeyDown(KEY_DOWN) * playerSpeed; 	
	playerPosition.y -= IsKeyDown(KEY_UP) * playerSpeed; 	
	
	
	//playerPosition = (Vector2){mousePos.x - (jetTextMoving.width/10.0f) / 2.0f, mousePos.y - jetTextMoving.height /2.0f };

}

void DrawGameplayScene(){

	
	DrawTextureRec(jetTextMoving,playerAnimRec,playerPosition, WHITE);
	//DrawTexture(jetTextMoving,0,0,WHITE);	
	
}

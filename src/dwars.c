#include <raylib.h>
#include "scene.h"
#include "assets.h"

static int gameWidth = 1280;
static int gameHeight = 720;

scene CurrentScene = GAMEPLAY; 

int main(){

    SetTargetFPS(30);
    InitWindow(gameWidth,gameHeight,"War of Donuts");
	
	LoadSprites(); //TODO: check for errors

    while(!WindowShouldClose()){
    	 
		BeginDrawing();
			DrawGameplayScene();	
            ClearBackground(PURPLE);
		//	DrawTexture(jetText,GetMouseX()-128,GetMouseY()-128,WHITE);	
				
        EndDrawing();


    }
	//TODO: Unloading
    CloseWindow();

    return 0;
}

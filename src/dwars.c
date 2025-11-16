#include <raylib.h>

static int gameWidth = 1280;
static int gameHeight = 720;

Texture2D jetText;

int main(){

    SetTargetFPS(30);
    InitWindow(gameWidth,gameHeight,"yooo");
	jetText = LoadTexture("../assets/newTileset.png");
	
    while(!WindowShouldClose()){
    	 
		BeginDrawing();
			
            ClearBackground(BLACK);
			DrawTexture(jetText,GetMouseX()-128,GetMouseY()-128,WHITE);	
				
        EndDrawing();


    }

    CloseWindow();

    return 0;
	//test
}

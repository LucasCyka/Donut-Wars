#include <raylib.h>
#include "scene.h"
#include "assets.h"

static int gameWidth  = 1280;
static int gameHeight = 720;
static float screenScale = 1;
static RenderTexture2D framebufferRender;

scene CurrentScene = GAMEPLAY; 

void UpdateFrame();
void DrawFrame();

Vector2 GetVirtualMousePosition();

int main(){

    SetTargetFPS(30);
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(gameWidth,gameHeight,"War of Donuts");
	framebufferRender = LoadRenderTexture(gameWidth,gameHeight);
	SetTextureFilter(framebufferRender.texture,TEXTURE_FILTER_BILINEAR);

	LoadSprites(); //TODO: check for errors

    while(!WindowShouldClose()){
 		   	 
		float widthScale  = (float)GetScreenWidth() / gameWidth;
		float heightScale = (float)GetScreenHeight() / gameHeight;
		screenScale = (widthScale < heightScale) ? widthScale : heightScale; 
		//screenScale = heightScale;		

		UpdateFrame();
		DrawFrame();

    }
	//TODO: Unloading
	UnloadRenderTexture(framebufferRender);
    CloseWindow();

    return 0;
}

void UpdateFrame(){
	UpdateGameplayScene(GetVirtualMousePosition());
}

void DrawFrame(){
	BeginTextureMode(framebufferRender);
		ClearBackground(BLACK);
		DrawGameplayScene();
		/*for(int y = 0; y < 10;y++){
			DrawRectangle(0,y*100+100,1280,20,RED);
		}*/	
	
	DrawText(TextFormat("%f , %f",GetVirtualMousePosition().x, GetVirtualMousePosition().y), 0,0,100,WHITE);		

	EndTextureMode();	
	
	BeginDrawing();
		
		ClearBackground(BLACK);

		Rectangle sourceRect = {
			0.0f,
			0.0f,
			framebufferRender.texture.width,
			-framebufferRender.texture.height};

		Rectangle destRect = {
			(float)(GetScreenWidth()  - (float)screenScale  * gameWidth)/2.0,
			(float)(GetScreenHeight() - (float)screenScale  * gameHeight)/2.0,
			(float) gameWidth  * screenScale,
			(float) gameHeight * screenScale};

		DrawTexturePro(framebufferRender.texture,sourceRect,destRect,(Vector2) {0.0f,0.0f},0.0f,WHITE);

	EndDrawing();
	

}

Vector2 GetVirtualMousePosition(){
	Vector2 mousePos = GetMousePosition();
    mousePos.x = (mousePos.x  - (float) (GetScreenWidth() - gameWidth * screenScale) / 2.0f) / screenScale;
	//clamp x
	mousePos.x = (mousePos.x > gameWidth) ? gameWidth : mousePos.x; 
	mousePos.x = (mousePos.x < 0) ? 0 : mousePos.x; 
	
	mousePos.y = (mousePos.y - (float)(GetScreenHeight() - gameHeight * screenScale) / 2.0f ) / screenScale;
	//clamp y
	mousePos.y = (mousePos.y > gameHeight) ? gameHeight : mousePos.y;
	mousePos.y = (mousePos.y < 0) ? 0 : mousePos.y;
	

	return mousePos;
}

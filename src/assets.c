#include "assets.h"

Texture2D jetTextMoving;

int LoadSprites(){
	jetTextMoving = LoadTexture("../assets/newTileset.png");
	
	//TODO: error handling
	return 0;
}

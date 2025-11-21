#include "assets.h"

Texture2D jetText;

int LoadSprites(){
	jetText = LoadTexture("../assets/newTileset.png");
	
	//TODO: error handling
	return 0;
}

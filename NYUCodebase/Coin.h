#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

extern int coinAnimation[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

class Coin{
public:
	Coin();
	Coin(int textureID, float x, float y);
	~Coin();

	void Draw();
	void DrawSpriteSheetSpriteCoin(int spriteTexture, float x, float y, float rotation, float scale, int index, int spriteCountX, int spriteCountY, float width, float height);


	int textureID;
	float x;
	float y;

	float width = .12f;
	float height = .16f;

	//animation variables
	int currentIndex = 0;
	float animationElapsed = 0.f;
	int numFrames = 21;
	float framesPerSecond = 20.0f;

};

Coin::~Coin(){}
Coin::Coin(){}
Coin::Coin(int textureID, float x, float y)
{
	Coin::textureID = textureID;
	Coin::x = x;
	Coin::y = y;
}


void Coin::Draw()
{
	DrawSpriteSheetSpriteCoin(textureID, x, y, 0, 1, coinAnimation[currentIndex], 16, 2, width, height);
}

void Coin::DrawSpriteSheetSpriteCoin(int spriteTexture, float x, float y, float rotation, float scale, int index, int spriteCountX, int spriteCountY, float width, float height) {
	GLfloat vertices[] = { -width / 2.f, height / 2.f,
		-width / 2.f, -height / 2.f,
		width / 2.f, -height / 2.f,
		width / 2.f, height / 2.f };
	glVertexPointer(2, GL_FLOAT, 0, vertices);
	glEnableClientState(GL_VERTEX_ARRAY);

	float u = (float)(((int)index) % spriteCountX) / (float)spriteCountX;
	float v = (float)(((int)index) / spriteCountX) / (float)spriteCountY;
	float spriteWidth = 1.0f / (float)spriteCountX;
	float spriteHeight = 1.0f / (float)spriteCountY;

	GLfloat quadUVs[] = { u, v,
		u, v + spriteHeight,
		u + spriteWidth, v + spriteHeight,
		u + spriteWidth, v
	};

	glTexCoordPointer(2, GL_FLOAT, 0, quadUVs);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, spriteTexture); // so gltexture_2d knows what textureid to draw
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	//glLoadIdentity();
	glTranslatef(x, y, 0.0);
	glRotatef(rotation, 0.0, 0.0, 1.0);
	glScalef(scale, scale, scale);

	glEnable(GL_BLEND);//enables blend
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDrawArrays(GL_QUADS, 0, 4);

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glPopMatrix();
}
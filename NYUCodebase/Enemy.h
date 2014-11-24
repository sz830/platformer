#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

int rightEnemyAnimation[] = { 8, 7, 6, 5, 4, 3, 2 };
int leftEnemyAnimation[] = { 9, 10, 11, 12, 13, 14, 15 };

class Enemy{
public:
	Enemy();
	Enemy(int textureID, float x, float y);
	~Enemy();

	void Draw();
	void DrawSpriteSheetSpriteEnemy(int spriteTexture, float x, float y, float rotation, float scale, int index, int spriteCountX, int spriteCountY, float width, float height);
	int textureID;
	float x;
	float y;
	float width = .07f; // in a 1.6 total width world. slightly less than width of tile
	float height = .11f; // slightly more than width of tile, tile is .08

	float velocity_x = 0.3;
	float velocity_y = .0f;// subject to change

	int spritesheet_x = 9;
	int spritesheet_y = 8;
	int currentIndex = 0;
	float animationElapsed = 0;
	float framesPerSecond = 20.f;
	int numFrames = 7;
	int standingIndex = 19; // this is the index in spritesheet


	int flagDirection = 1; // 1=right 0=neighter -1=left


};

Enemy::~Enemy(){}
Enemy::Enemy(){}
Enemy::Enemy(int textureID, float x, float y)
{
	Enemy::textureID = textureID;
	Enemy::x = x;
	Enemy::y = y;
}

void Enemy::Draw()
{
	if (flagDirection == 0)
	{
		DrawSpriteSheetSpriteEnemy(textureID, x, y, 0, 1.0f, standingIndex, spritesheet_x, spritesheet_y, width, height);
	}
	else if (flagDirection == 1)
	{
		DrawSpriteSheetSpriteEnemy(textureID, x, y, 0, 1.0f, rightEnemyAnimation[currentIndex], spritesheet_x, spritesheet_y, width, height);
	}
	else
	{
		DrawSpriteSheetSpriteEnemy(textureID, x, y, 0, 1.0f, leftEnemyAnimation[currentIndex], spritesheet_x, spritesheet_y, width, height);
	}
}

void Enemy::DrawSpriteSheetSpriteEnemy(int spriteTexture, float x, float y, float rotation, float scale, int index, int spriteCountX, int spriteCountY, float width, float height) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, spriteTexture); // so gltexture_2d knows what textureid to draw
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	//glLoadIdentity();
	glTranslatef(x, y, 0.0);
	glRotatef(rotation, 0.0, 0.0, 1.0);
	glScalef(scale, scale, scale);

	//GLfloat quad[] = { -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f };
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

	glEnable(GL_BLEND);//enables blend
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDrawArrays(GL_QUADS, 0, 4);

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glPopMatrix();
}


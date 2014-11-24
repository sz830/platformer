#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

extern int rightPlayerAnimation[] = { 8, 7, 6, 5, 4, 3, 2 };
extern int leftPlayerAnimation[] = { 9,10,11,12,13,14,15 };
extern int rightPlayerAnimationInvincibility[] = { 0, 7, 0, 5, 0, 3, 2 };
extern int leftPlayerAnimationInvincibility[] = { 9, 0, 11, 0, 13, 0, 15 };
extern int standingInvincibility[] = { 19, 0, 19, 0, 19, 0, 19 };


class Player{
public:
	Player();
	Player(int textureID, float x, float y);
	~Player();

	void Draw();
	void DrawSpriteSheetSpritePlayer(int spriteTexture, float x, float y, float rotation, float scale, int index, int spriteCountX, int spriteCountY, float width, float height);
	int textureID;
	float x;
	float y;
	float width=.05f; // in a 1.6 total width world. slightly less than width of tile
	float height=.07f; // slightly more than width of tile, tile is .08

	float velocity_x=0.5;
	float velocity_y=0.0;// subject to change

	int spritesheet_x = 9;
	int spritesheet_y = 8;

	int currentIndex = 0; 
	int standingIndex = 19; // this is the index in spritesheet
	float animationElapsed = 0;
	float framesPerSecond = 20.f;
	int numFrames = 7;
	int lastflagDirec = 1;
	int flagDirection = 1; // 1=right 0=neighter -1=left

	int health = 5;
	float invincibility = 0.f;
};

Player::~Player(){}
Player::Player(){}
Player::Player(int textureID, float x, float y)
{
	Player::textureID = textureID;
	Player::x = x;
	Player::y = y;
}

void Player::Draw()
{
	if (flagDirection == 0 && invincibility <= 0)
	{
		DrawSpriteSheetSpritePlayer(textureID, x, y, 0, 1.0f, standingIndex, spritesheet_x, spritesheet_y,width,height);
	}
	else if (flagDirection == 0 && invincibility > 0)
	{
		DrawSpriteSheetSpritePlayer(textureID, x, y, 0, 1.0f, standingInvincibility[currentIndex], spritesheet_x, spritesheet_y, width, height);
	}
	else if (flagDirection == 1 && invincibility <= 0)
	{
		DrawSpriteSheetSpritePlayer(textureID, x, y, 0, 1.0f, leftPlayerAnimation[currentIndex], spritesheet_x, spritesheet_y, width, height);
	}
	else if (flagDirection == -1 && invincibility <= 0)
	{
		DrawSpriteSheetSpritePlayer(textureID, x, y, 0, 1.0f, rightPlayerAnimation[currentIndex], spritesheet_x, spritesheet_y, width, height);
	}
	else if (flagDirection == 1 && invincibility > 0)
	{
		DrawSpriteSheetSpritePlayer(textureID, x, y, 0, 1.0f, leftPlayerAnimationInvincibility[currentIndex], spritesheet_x, spritesheet_y, width, height);
	}
	else if (flagDirection == -1 && invincibility > 0)
	{
		DrawSpriteSheetSpritePlayer(textureID, x, y, 0, 1.0f, rightPlayerAnimationInvincibility[currentIndex], spritesheet_x, spritesheet_y, width, height);
	}
}

void Player::DrawSpriteSheetSpritePlayer(int spriteTexture, float x, float y, float rotation, float scale, int index, int spriteCountX, int spriteCountY, float width, float height) {
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


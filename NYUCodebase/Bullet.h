#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

class Bullet{
public:
	Bullet();
	~Bullet();
	Bullet(int textureID, float x, float y, float velocity_x, float velocity_y);

	int textureID;
	float x;
	float y;
	float velocity_x;
	float velocity_y;
	float width = .02f;
	float height = .02f;

	void Draw();
};

Bullet::Bullet(){}
Bullet::~Bullet(){}
Bullet::Bullet(int textureID, float x, float y, float velocity_x, float velocity_y)
{
	Bullet::textureID = textureID;
	Bullet::x = x;
	Bullet::y = y;
	Bullet::velocity_x = velocity_x;
	Bullet::velocity_y = velocity_y;
}

void Bullet::Draw()
{
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	//glLoadIdentity();
	glTranslatef(x, y, 0.0);

	GLfloat vertices[] = { -width / 2.f, height / 2.f,
		-width / 2.f, -height / 2.f,
		width / 2.f, -height / 2.f,
		width / 2.f, height / 2.f };

	glVertexPointer(2, GL_FLOAT, 0, vertices);
	glEnableClientState(GL_VERTEX_ARRAY);


	GLfloat quadUVs[] = { 0, 0,
		0, 1,
		1, 1,
		1, 0
	};

	glTexCoordPointer(2, GL_FLOAT, 0, quadUVs);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glDrawArrays(GL_QUADS, 0, 4);

	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_BLEND);
	glPopMatrix();
}
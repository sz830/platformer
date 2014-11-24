#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

class Cloud{
public:
	Cloud();
	Cloud(int textureID, float x, float y, float velocity_x, float width, float height);
	~Cloud();

	void Draw();

	int textureID;
	float x;
	float y;
	float width = 0; 
	float height = 0;

	float velocity_x = 0.0;
};

Cloud::~Cloud(){}
Cloud::Cloud(){}
Cloud::Cloud(int textureID, float x, float y, float velocity_x,float width, float height)
{
	Cloud::textureID = textureID;
	Cloud::x = x;
	Cloud::y = y;
	Cloud::velocity_x = velocity_x;
	Cloud::width = width;
	Cloud::height = height;
}

void Cloud::Draw()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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



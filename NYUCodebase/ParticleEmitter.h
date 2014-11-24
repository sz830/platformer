#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <string>
#include <time.h>
#include "Vector.h"
#include "Particle.h"

#define MAXIMUM_PARTICLE_LIFE 1.
#define MAXIMUM_PARTICLE_VELOCITY .5

class ParticleEmitter {
public:
	ParticleEmitter(float x, float y);
	~ParticleEmitter();
	Vector position;
	std::vector<Particle> particles;
	
	void Draw();
	bool Update(float elapsed,float gravity);
};
ParticleEmitter::ParticleEmitter(float x, float y){
	ParticleEmitter::position = Vector(x, y, 0.f);
	for (int i = 0; i < 5; i++){
		float vx = MAXIMUM_PARTICLE_VELOCITY*((2 * ((float)rand() / (float)RAND_MAX)) - 1.);
		float vy = MAXIMUM_PARTICLE_VELOCITY*((2 * ((float)rand() / (float)RAND_MAX)) - 1.);
		float lifetime = (MAXIMUM_PARTICLE_LIFE *((float)rand() / (float)RAND_MAX)) + 1.;
		Particle p = Particle(position.x, position.y, position.z,vx,vy,0.,lifetime);
		particles.push_back(p);
	}
}
ParticleEmitter::~ParticleEmitter(){}

void ParticleEmitter::Draw(){
	std::vector<float> particleVertices;
	std::vector<float> particleColors;
	for (int i = 0; i < particles.size(); i++){
		if (particles[i].timealive < particles[i].lifetime){
			particleVertices.push_back(particles[i].position.x);
			particleVertices.push_back(particles[i].position.y);
			particleColors.push_back(1.);
			particleColors.push_back(0.);
			particleColors.push_back(0.);
			particleColors.push_back(1.);
		}
	}
	glVertexPointer(2, GL_FLOAT, 0, particleVertices.data());
	glEnableClientState(GL_VERTEX_ARRAY);

	glColorPointer(4, GL_FLOAT, 0, particleColors.data());
	glEnableClientState(GL_COLOR_ARRAY);
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPointSize(4.0);
	glDrawArrays(GL_POINTS, 0, particleVertices.size() / 2);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisable(GL_BLEND);
	glPopMatrix();
}
bool ParticleEmitter::Update(float elapsed,float gravity){
	bool done = true;
	for (int i = 0; i < particles.size(); i++){
		bool tf = particles[i].Update(elapsed,gravity);
		if (!tf)
		{
			done = false; 
		}
	}
	return done;
}
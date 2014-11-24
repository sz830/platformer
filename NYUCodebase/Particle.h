#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

class Particle {
public:
	Particle(float x, float y, float z, float vx, float vy, float vz, float lifetime);
	~Particle();
	Vector position;
	Vector velocity;
	float lifetime;
	float timealive = 0;
	bool Update(float elapsed, float gravity);
};
Particle::Particle(float x, float y, float z, float vx, float vy, float vz, float lifetime)
{
	Particle::position = Vector(x, y, z);
	Particle::velocity = Vector(vx, vy, vz);
	Particle::lifetime = lifetime;
}
Particle::~Particle(){}

bool Particle::Update(float elapsed, float gravity)
{
	timealive += elapsed;
	if (timealive <= lifetime){
		velocity.y -= gravity*elapsed;
		position.x += velocity.x*elapsed;
		position.y += velocity.y*elapsed;
		return false;
	}
	else{
		return true;
	}
}
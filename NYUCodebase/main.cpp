#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <string>
#include <time.h>
#include "Player.h"
#include "Cloud.h"
#include "Coin.h"
#include "Enemy.h"
#include "Bullet.h"
#include "ParticleEmitter.h"
#include "AppDelegate.h"

/*
Notes on this game
the jump power is insufficient to reach the coin and win. level data can be adjusted to allow this.

no health system has been implemented so it is impossible to lose.
would be easy though, add health in to player.h. in appdelegate update player, check for collision with each of the enemies, if collision true and invincibility<=0
health --, invincibility = .4 (recover/get away time), at every update(elapsed) invincibility-=elapsed
a you lose game state needs to be created too for this to happen

next steps include, adding sound
making it a multi screen scrolling game, and implementing camera following, and that sorta shit
also screen culling

Next game will be multi side asteroids!
*/
using namespace std;

int main(int argc, char *argv[])
{
	srand(time(NULL));
	AppDelegate app = AppDelegate();
	while (!app.UpdateAndRender())
	{ }
	return 0;
}
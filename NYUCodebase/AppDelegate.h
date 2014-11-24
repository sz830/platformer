#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

extern float gravity = 2.5f; // gravity acceleration
extern unsigned char levelData[50][20] = {
		{ 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41 },
		{ 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 12, 13, 14, 11, 30 },
		{ 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 21, 22, 23, 21, 30 },
		{ 27, 0, 11, 12, 13, 14, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 20, 21, 22, 23, 23, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 11, 12, 13, 14, 0, 0, 30 },
		{ 27, 12, 13, 14, 0, 0, 0, 0, 0, 14, 0, 0, 41, 20, 21, 22, 23, 0, 0, 30 },
		{ 27, 21, 22, 23, 0, 0, 11, 12, 13, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 0, 0, 20, 21, 22, 41, 0, 13, 14, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 0, 0, 11, 12, 13, 0, 0, 22, 23, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 0, 0, 20, 21, 22, 0, 0, 0, 0, 0, 0, 11, 12, 13, 14, 30 },
		{ 27, 11, 12, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 21, 22, 23, 30 },
		{ 27, 20, 21, 22, 0, 0, 0, 0, 0, 0, 11, 12, 13, 14, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 11, 12, 13, 0, 0, 0, 20, 21, 22, 23, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 20, 21, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 14, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 0, 11, 12, 13, 14, 0, 0, 0, 22, 23, 0, 11, 12, 13, 14, 30 },
		{ 27, 0, 0, 0, 0, 20, 21, 22, 23, 0, 0, 0, 0, 0, 0, 20, 21, 22, 23, 30 },
		{ 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 6, 6, 0, 0, 30 },
		{ 41, 0, 0, 0, 41, 41, 0, 0, 0, 41, 41, 41, 0, 0, 41, 41, 41, 0, 0, 41 },
		{ 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 41 },
		{ 27, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 12, 13, 14, 11, 30 },
		{ 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 21, 22, 23, 21, 30 },
		{ 27, 0, 11, 12, 13, 14, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 20, 21, 22, 23, 23, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 11, 12, 13, 14, 0, 0, 30 },
		{ 27, 12, 13, 14, 0, 0, 0, 0, 0, 14, 0, 0, 41, 20, 21, 22, 23, 0, 0, 30 },
		{ 27, 21, 22, 23, 0, 0, 11, 12, 13, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 0, 0, 20, 21, 22, 41, 0, 13, 14, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 0, 0, 11, 12, 13, 0, 0, 22, 23, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 0, 0, 20, 21, 22, 0, 0, 0, 0, 0, 0, 11, 12, 13, 14, 30 },
		{ 27, 11, 12, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 21, 22, 23, 30 },
		{ 27, 20, 21, 22, 0, 0, 0, 0, 0, 0, 11, 12, 13, 14, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 11, 12, 13, 0, 0, 0, 20, 21, 22, 23, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 20, 21, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 0, 0, 0, 11, 12, 13, 14, 0, 0, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 0, 0, 0, 20, 21, 22, 23, 0, 0, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 14, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 0, 0, 0, 11, 12, 13, 14, 0, 0, 0, 22, 23, 0, 11, 12, 13, 14, 30 },
		{ 27, 0, 0, 0, 0, 20, 21, 22, 23, 0, 0, 0, 0, 0, 0, 20, 21, 22, 23, 30 },
		{ 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30 },
		{ 27, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 6, 6, 6, 6, 30 },
		{ 6, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 41 },
};

float WORLD_OFFSET_X = .8f;
float WORLD_OFFSET_Y = 1.f;
float TILE_SIZE = .08f;

void worldToTileCoordinates(float worldX, float worldY, int *gridX, int *gridY) {
	*gridX = (int)((worldX + (WORLD_OFFSET_X)) / TILE_SIZE);
	*gridY = (int)((-worldY + (WORLD_OFFSET_Y)) / TILE_SIZE);
}

float gridToYTop(int x, int y)
{
	float movedown = .08*y;
	return WORLD_OFFSET_Y - movedown;
}
float gridToYBot(int x, int y)
{
	float movedown = .08*(y+1);
	return WORLD_OFFSET_Y - movedown;
}
float gridToXLeft(int x, int y)
{
	float moveright = .08*(x);
	return -WORLD_OFFSET_X + moveright;
}
float gridToXRight(int x, int y)
{
	float moveright = .08*(x+1);
	return -WORLD_OFFSET_X + moveright;
}

GLuint LoadTexture(const char *image_path) {
	SDL_Surface *surface = IMG_Load(image_path);
	GLuint textureID;
	glGenTextures(1, &textureID); // how many names to generate, and address of arrays where names go
	glBindTexture(GL_TEXTURE_2D, textureID); // says, gltexture2d is bound to textureid now
	glTexImage2D(GL_TEXTURE_2D, 0, 4, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);//sets texture data of target
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//target, property, property definition, sets the gltextureminfilter property of gltexture2d to gllinear
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	SDL_FreeSurface(surface);
	return textureID;
}
GLuint LoadTexture24(const char *image_path) {
	SDL_Surface *surface = IMG_Load(image_path);
	GLuint textureID;
	glGenTextures(1, &textureID); // how many names to generate, and address of arrays where names go
	glBindTexture(GL_TEXTURE_2D, textureID); // says, gltexture2d is bound to textureid now
	glTexImage2D(GL_TEXTURE_2D, 0, 4, surface->w, surface->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surface->pixels);//sets texture data of target
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//target, property, property definition, sets the gltextureminfilter property of gltexture2d to gllinear
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	SDL_FreeSurface(surface);
	return textureID;
}
void DrawText(int fontTexture, string text, float x, float y) {
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, fontTexture); // so gltexture_2d knows what textureid to draw
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(x, y, 0);
	float texture_size = 1.0 / 16.0f;

	float r = .5, g = .5, b = .5, a = 1.0;
	float spacing = 0.;
	float size = .05f;

	vector<float> vertexData;
	vector<float> texCoordData;
	vector<float> colorData;

	for (unsigned int i = 0; i < text.size(); i++)
	{
		float texture_x = (float)(((int)text[i]) % 16) / 16.0f;
		float texture_y = (float)(((int)text[i]) / 16) / 16.0f;

		colorData.insert(colorData.end(), { r, g, b, a, r, g, b, a, r, g, b, a, r, g, b, a });

		vertexData.insert(vertexData.end(), { ((size + spacing)*i) + (-0.5f*size), .5f*size,
			((size + spacing)*i) + (-.5f*size), -.5f*size,
			((size + spacing)*i) + (.5f*size), -.5f*size,
			((size + spacing)*i) + (.5f*size), .5f*size
		});

		texCoordData.insert(texCoordData.end(), { texture_x, texture_y, texture_x, texture_y + texture_size, texture_x +
			texture_size, texture_y + texture_size, texture_x + texture_size, texture_y });
	}

	glColorPointer(4, GL_FLOAT, 0, colorData.data());
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, vertexData.data());
	glEnableClientState(GL_VERTEX_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoordData.data());
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glDrawArrays(GL_QUADS, 0, text.size() * 4);

	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisable(GL_BLEND);
	glPopMatrix();
}

class AppDelegate {
	public:
		SDL_Event event;
		bool win = false;
		int score = 0;
		int LEVEL_HEIGHT = 50;
		int LEVEL_WIDTH = 20;
		float sincelastshottime = 0;

		enum GameState {STATE_GAME_LEVEL,STATE_GAME_WIN,STATE_GAME_LOSE};
		GameState state;
		AppDelegate();
		~AppDelegate();

		//Textures
		GLuint coinid,enemyid,fontid,playerid,terrainid,cloudid,bulletid;

		//Entities
		Player player;
		Cloud cloud1;
		Cloud cloud2;
		Cloud cloud3;
		Coin coin;
		vector<Enemy*> enemies;
		vector<Bullet*> bullets;
		vector<ParticleEmitter> particleEmitters;

		//Sounds
		Mix_Music *gameThemeSound;
		Mix_Chunk *laserSound;

		void Init();

		bool UpdateAndRender();

		void Render();
		void RenderGameLevel();
		void RenderGameOver();
		void RenderGameOverLose();

		void Update(float elapsed);
		void UpdateGameLevel(float elapsed);
		void UpdateGameOver(float elapsed);
		void UpdateGameOverLose(float elapsed);

		void UpdatePlayer(Player* player, float elapsed);
		void UpdateCloud(Cloud* cloud, float elapsed);
		bool UpdateBullet(Bullet* bullet, float elapsed);
		void UpdateEnemy(Enemy* enemy, float elapsed);
		void UpdateCoin(Coin* coin, float elapsed);

		bool CoinCollision();
		bool BulletCollision(Bullet * bullet, Enemy * enemy);
		bool EnemyCollision(Enemy* enemy);

		void drawWorld();

	private:
		bool done;
		float lastFrameTicks;
		SDL_Window* displayWindow;
};

AppDelegate::AppDelegate(){

	Init();
	done = false;
	lastFrameTicks = 0.0;
}

void AppDelegate::Init(){
	SDL_Init(SDL_INIT_VIDEO); //SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK); // for initing and taking over joystick too. if not also quitte
	displayWindow = SDL_CreateWindow("Simon Project 4", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 750, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
	SDL_GL_MakeCurrent(displayWindow, context);
	//Initialize SDL_Mixer
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

	glClearColor(0.74902f, .847059f, 0.847059f, 1.0f);//background color 
	//glClearColor(0.f, 0.f, 0.0f, 1.0f);//black background color 

	//Set State
	state = STATE_GAME_LEVEL;

	//Setup
	glViewport(0, 0, 600, 750);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-.8, .8, -1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);

	//LoadTextures coinid,enemy,fontid,player,terrainid,cloudid;
	fontid = LoadTexture("pngs/font.png");
	coinid = LoadTexture("pngs/coin.png");
	enemyid = LoadTexture("pngs/enemy.png");
	playerid = LoadTexture("pngs/player.png");
	terrainid = LoadTexture("pngs/terrain.png");
	cloudid = LoadTexture("pngs/cloud2.png");
	bulletid = LoadTexture("pngs/bullet.png");

	//Create/Init Entities
	player = Player(playerid, 0.f, 0.f);
	cloud1 = Cloud(cloudid, -.5f, .8f, -.05f, .22f, .12f);
	cloud2 = Cloud(cloudid, .4f, .7f, -.06f, .2f, .1f);
	cloud3 = Cloud(cloudid, 0.f, .5f, -.07f, .2f, .1f);
	coin = Coin(coinid, 2.f, 2.f); // .6,.8

	//Init/create Sounds
	gameThemeSound = Mix_LoadMUS("sounds/gameThemeSound.mp3");
	laserSound = Mix_LoadWAV("sounds/laserSound.wav");

	//Play game Theme
	Mix_PlayMusic(gameThemeSound, -1);
}

AppDelegate::~AppDelegate() {
	Mix_FreeChunk(laserSound);
	Mix_FreeMusic(gameThemeSound);
	SDL_Quit();
}

void AppDelegate::Render() {
	glClear(GL_COLOR_BUFFER_BIT);

	switch (state)
	{
		case STATE_GAME_LEVEL:
			RenderGameLevel();
			break;
		case STATE_GAME_WIN:
			RenderGameOver();
			break;
		case STATE_GAME_LOSE:
			RenderGameOverLose();
			break;
	}
	SDL_GL_SwapWindow(displayWindow);
}

void AppDelegate::Update(float elapsed) {
	switch (state) {
		case STATE_GAME_LEVEL:
			UpdateGameLevel(elapsed);
			break;
		case STATE_GAME_WIN:
			UpdateGameOver(elapsed);
			break;
		case STATE_GAME_LOSE:
			UpdateGameOverLose(elapsed);
			break;
	}
}

bool AppDelegate::UpdateAndRender(){
	float ticks = (float)SDL_GetTicks() / 1000.0f;
	float elapsed = ticks - lastFrameTicks;
	lastFrameTicks = ticks;
	Update(elapsed);
	Render();
	return done;
}

void AppDelegate::RenderGameLevel(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	float camerashiftX, camerashiftY;
	if (player.x > 0 || player.x < 0) { camerashiftX = 0; }
	else{ camerashiftX = -player.x; }
	if (player.y>0) { camerashiftY = 0.f; }
	else if (player.y < -2.f){ camerashiftY = 2.f; }
	else{ camerashiftY = -player.y; }

	glTranslatef(camerashiftX, camerashiftY, 0.);

	//Draw Clouds
	cloud1.Draw();
	cloud2.Draw();
	cloud3.Draw();

	//Draw World
	drawWorld();

	//Draw Player
	player.Draw();

	//Draw Enemies
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i]->Draw();
	}

	//Draw Bullets
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->Draw();
	}

	//Draw Coin
	coin.Draw();


	DrawText(fontid, std::to_string(player.health), -.75, -.7);
	DrawText(fontid, std::to_string(score), -.75, -.75);
	DrawText(fontid, std::to_string(particleEmitters.size()), -.75, -.8);

	//Draw particles
	for (int i = 0; i < particleEmitters.size(); i++)
	{
		particleEmitters[i].Draw();
	}
}

void AppDelegate::UpdateGameLevel(float elapsed)
{
	sincelastshottime += elapsed;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE) {
			done = true;
		}
		else if (event.type == SDL_KEYDOWN){
			if (event.key.keysym.scancode == SDL_SCANCODE_SPACE) {
				if (sincelastshottime > .1)
				{
					Mix_PlayChannel(-1, laserSound, 0);
					float vely = .0005*(rand() % 200 - 100);
					float velx = 0;
					if (player.lastflagDirec == 1){ velx = 1.5; }
					if (player.lastflagDirec == -1){ velx = -1.5; }
					Bullet * bullet = new Bullet(bulletid, player.x, player.y, velx, vely);
					bullets.push_back(bullet);
					sincelastshottime = 0;
				}
			} else if (event.key.keysym.scancode == SDL_SCANCODE_UP) {
				player.y -= .01;

				float startx = player.x - player.width / 2.f;
				float endx = player.x + player.width / 2.f;
				for (float i = startx; i <= endx; i += .00999)
				{
					float worldx = i;
					float worldy = player.y - player.height / 2.f;
					int gridX, gridY;
					worldToTileCoordinates(worldx, worldy, &gridX, &gridY);
					if (!(gridX>19 || gridY < 0))
					{
						if (levelData[gridY][gridX] != 6 && levelData[gridY][gridX] != 0 && levelData[gridY][gridX] != 11 && levelData[gridY][gridX] != 12 && levelData[gridY][gridX] != 13 && levelData[gridY][gridX] != 14) // then there is collision
						{
							player.velocity_y = 1.5;
							break;
						}
					}
				}

				player.y += .01;
				
			}
		}

	}
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_RIGHT]) {
		player.x += player.velocity_x*elapsed;
		float bound = .8f - (player.width / 2.f) - (1.6f / 20.f);
		if (player.x > bound - .001){ player.x = bound - .001; }
		if (player.flagDirection != 1)
		{
			player.animationElapsed = 0;
			player.flagDirection = 1;
			player.lastflagDirec = 1;
			player.currentIndex = 0;
		}
	}
	else if (keys[SDL_SCANCODE_LEFT]) {
		player.x -= player.velocity_x*elapsed;
		float bound = -.8f + (player.width / 2.f) + (1.6f / 20.f);
		if (player.x < bound + .001){ player.x = bound + .001; }
		if (player.flagDirection != -1)
		{
			player.animationElapsed = 0;
			player.flagDirection = -1;
			player.lastflagDirec = -1;
			player.currentIndex = 0;
		}
	}
	else
	{
		player.flagDirection = 0;
	}
	//check collision left
	float starty = player.y - player.height / 2.f;
	float endy = player.y + player.height / 2.f;
	for (float i = starty; i <= endy; i += .00999)
	{
		float worldx = player.x - player.width / 2.f;
		float worldy = i;
		int gridX, gridY;
		worldToTileCoordinates(worldx, worldy, &gridX, &gridY);
		if (!( gridX>19 || gridY < 0 ))
		{
			if (levelData[gridY][gridX] != 6 && levelData[gridY][gridX] != 0 && levelData[gridY][gridX] != 11 && levelData[gridY][gridX] != 12 && levelData[gridY][gridX] != 13 && levelData[gridY][gridX] != 14) // then there is collision
			{
				player.x = gridToXRight(gridX, gridY) + player.width / 2.f; // fix penetration
			}
		}
	}
	//check collision right
	for (float i = starty; i <= endy; i += .00999)
	{
		float worldx = player.x + player.width / 2.f;
		float worldy = i;
		int gridX, gridY;
		worldToTileCoordinates(worldx, worldy, &gridX, &gridY);
		if (!(gridX>19 || gridY < 0 ))
		{
			if (levelData[gridY][gridX] != 6 && levelData[gridY][gridX] != 0 && levelData[gridY][gridX] != 11 && levelData[gridY][gridX] != 12 && levelData[gridY][gridX] != 13 && levelData[gridY][gridX] != 14) // then there is collision
			{
				player.x = gridToXLeft(gridX, gridY) - player.width / 2.f; // fix penetration
			}
		}
	}


	//update Clouds
	UpdateCloud(&cloud1, elapsed);
	UpdateCloud(&cloud2, elapsed);
	UpdateCloud(&cloud3, elapsed);
	//update Player
	UpdatePlayer(&player, elapsed);
	
	//update Enemies - loop
	//generate new enemy maybe
	float prob = (rand() % 4000);
	if (prob < 100)
	{
		float X = .1*((rand() % 13)-6.0);
		float flag = rand() % 2;
		if (flag == 0){ flag = -1; }
		Enemy * enemy = new Enemy(enemyid, X, 1.2);
		enemy->flagDirection = -flag;
		float scale = .01*((rand() % 25) + 74);
		if (flag == -1){ enemy->velocity_x *= -1; }
		enemy->velocity_x *= scale;
		enemy->height *= scale; enemy->width *= scale;
		enemies.push_back(enemy);
	}
	//update enemy
	for (int i = 0; i < enemies.size(); i++)
	{
		UpdateEnemy(enemies[i], elapsed);
	}

	//update Bullets - loop
	//two locations, here, just move and destroy bullet based on stuff
	for (int i = 0; i < bullets.size(); i++){
		bool remove = UpdateBullet(bullets[i], elapsed);
		if (remove){
			bullets.erase(bullets.begin() + i);
			i--;
		}
		else{
			for (int j = 0; j < enemies.size(); j++){
				if(BulletCollision(bullets[i],enemies[j]))
				{
					ParticleEmitter pe = ParticleEmitter(enemies[j]->x, enemies[j]->y);
					particleEmitters.push_back(pe);
					
					bullets.erase(bullets.begin() + i);
					enemies.erase(enemies.begin() + j);
					score++; i--;
					if (score > 25)
					{
						coin.x = .6;
						coin.y = .8;
					}
					break;
				}
			}
		}
	}

	//update coin
	UpdateCoin(&coin, elapsed);

	//Update ParticleEmitters
	for (int i = 0; i < particleEmitters.size(); i++){
		bool done = particleEmitters[i].Update(elapsed,gravity);
		if (done)
		{
			particleEmitters.erase(particleEmitters.begin() + i);
			i--;
		}
	}
	
}
void AppDelegate::RenderGameOver(){
	DrawText(fontid, "You win", 0.f, 0.f);
	DrawText(fontid, std::to_string(score), 0.f, -.3f);
}
void AppDelegate::RenderGameOverLose(){
	DrawText(fontid, "You LOSE, score=", 0.f, 0.f);
	DrawText(fontid, std::to_string(score), 0.f, -.3f);
}
void AppDelegate::UpdateGameOver(float elapsed)
{
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE) {
			done = true;
		}
	}
}
void AppDelegate::UpdateGameOverLose(float elapsed)
{
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE) {
			done = true;
		}
	}
}

void AppDelegate::UpdatePlayer(Player* player, float elapsed){
	player->animationElapsed += elapsed;
	if (player->animationElapsed > 1.0 / player->framesPerSecond) {
		player->currentIndex++;
		player->animationElapsed = 0.0;

		if (player->currentIndex > player->numFrames - 1) {
			player->currentIndex = 0;
		}
	}

	
	//update y velocity
	player->velocity_y -= gravity*elapsed;
	//update y position
	player->y += player->velocity_y*elapsed;

	if (player->y  < -3.f) // if has fallen through floor, move back up
	{
		player->y = -2.5f;
		player->velocity_y = 0.f;
	}

	//check collision top
	float startx = player->x - player->width / 2.f;
	float endx = player->x + player->width / 2.f;
	for (float i = startx; i <= endx; i += .00999)
	{
		float worldx = i;
		float worldy = player->y + player->height / 2.f;
		int gridX, gridY;
		worldToTileCoordinates(worldx, worldy, &gridX, &gridY);
		if (!( gridX>19 || gridY < 0 ))
		{
			if (levelData[gridY][gridX] != 6 && levelData[gridY][gridX] != 0 && levelData[gridY][gridX] != 11 && levelData[gridY][gridX] != 12 && levelData[gridY][gridX] != 13 && levelData[gridY][gridX] != 14) // then there is collision
			{
				player->y = gridToYBot(gridX, gridY) - player->height / 2.f - .001; // fix penetration
				player->velocity_y = 0.f;
			}
		}
	}
	//check collision bot
	//startx = player->x - player->width / 2.f;
	//endx = player->x + player->width / 2.f;
	for (float i = startx; i <= endx; i += .00999)
	{
		float worldx = i;
		float worldy = player->y - player->height / 2.f;
		int gridX, gridY;
		worldToTileCoordinates(worldx, worldy, &gridX, &gridY);
		if (!( gridX>19 || gridY < 0 ))
		{
			if (levelData[gridY][gridX] != 6 && levelData[gridY][gridX] != 0 && levelData[gridY][gridX] != 11 && levelData[gridY][gridX] != 12 && levelData[gridY][gridX] != 13 && levelData[gridY][gridX] != 14) // then there is collision
			{
				player->y = gridToYTop(gridX, gridY) + player->height / 2.f + .001; // fix penetration
				player->velocity_y = 0.f;
			}
		}
	}

	//check collision with enemy, if collide, decrement health
	if (player->invincibility > 0){
		player->invincibility -= elapsed;
	}
	for (int i = 0; i < enemies.size(); i++)
	{
		if (EnemyCollision(enemies[i]))
		{
			if (player->invincibility <= 0)
			{
				player->health--;
				score--;
				player->invincibility = 2.;
				if (player->health == 0)
				{
					state = STATE_GAME_LOSE;
				}
			}
			break;
		}
	}

	//check collision with coin, if collide, win
	if (CoinCollision())
	{
		state = STATE_GAME_WIN;
	}
}

void AppDelegate::UpdateCloud(Cloud* cloud, float elapsed){
	cloud->x += cloud->velocity_x*elapsed;
	if (cloud->x < -1.f){
		cloud->x = 1.f;
		cloud->y = (float)(rand() % 5 + 5) / 10.f;
	}
}
bool AppDelegate::UpdateBullet(Bullet* bullet, float elapsed)//bool is should it be removed
{
	bullet->x += elapsed*bullet->velocity_x;
	bullet->y += elapsed*bullet->velocity_y;

	float bound = .8f - (bullet->width / 2.f) - (1.6f / 20.f);
	if (bullet->x > bound - .001)
	{
		return true;
	}

	bound = -.8f + (bullet->width / 2.f) + (1.6f / 20.f);
	if (bullet->x < bound + .001)
	{
		return true;
	}

	//check collision left
	float starty = bullet->y - bullet->height / 2.f;
	float endy = bullet->y + bullet->height / 2.f;
	for (float i = starty; i <= endy; i += .00999)
	{
		float worldx = bullet->x - bullet->width / 2.f;
		float worldy = i;
		int gridX, gridY;
		worldToTileCoordinates(worldx, worldy, &gridX, &gridY);
		if (!( gridX>19 || gridY < 0 ))
		{
			if (levelData[gridY][gridX] != 6 && levelData[gridY][gridX] != 0 && levelData[gridY][gridX] != 11 && levelData[gridY][gridX] != 12 && levelData[gridY][gridX] != 13 && levelData[gridY][gridX] != 14) // then there is collision
			{
				return true;
			}
		}
	}
	//check collision right
	for (float i = starty; i <= endy; i += .00999)
	{
		float worldx = bullet->x + bullet->width / 2.f;
		float worldy = i;
		int gridX, gridY;
		worldToTileCoordinates(worldx, worldy, &gridX, &gridY);
		if (!( gridX>19 || gridY < 0 ))
		{
			if (levelData[gridY][gridX] != 6 && levelData[gridY][gridX] != 0 && levelData[gridY][gridX] != 11 && levelData[gridY][gridX] != 12 && levelData[gridY][gridX] != 13 && levelData[gridY][gridX] != 14) // then there is collision
			{
				return true;
			}
		}
	}

	if (bullet->y< -3.f) // if has fallen through floor, move back up
	{
		return true;
	}

	//check collision top
	float startx = bullet->x - bullet->width / 2.f;
	float endx = bullet->x + bullet->width / 2.f;
	for (float i = startx; i <= endx; i += .00999)
	{
		float worldx = i;
		float worldy = bullet->y + bullet->height / 2.f;
		int gridX, gridY;
		worldToTileCoordinates(worldx, worldy, &gridX, &gridY);
		if (levelData[gridY][gridX] != 6 && levelData[gridY][gridX] != 0 && levelData[gridY][gridX] != 11 && levelData[gridY][gridX] != 12 && levelData[gridY][gridX] != 13 && levelData[gridY][gridX] != 14) // then there is collision
		{
			return true;
		}
	}
	//check collision bot
	for (float i = startx; i <= endx; i += .00999)
	{
		float worldx = i;
		float worldy = bullet->y - bullet->height / 2.f;
		int gridX, gridY;
		worldToTileCoordinates(worldx, worldy, &gridX, &gridY);
		if (levelData[gridY][gridX] != 6 && levelData[gridY][gridX] != 0 && levelData[gridY][gridX] != 11 && levelData[gridY][gridX] != 12 && levelData[gridY][gridX] != 13 && levelData[gridY][gridX] != 14) // then there is collision
		{
			return true;
		}
	}
	return false;
}

void AppDelegate::UpdateEnemy(Enemy* enemy, float elapsed)
{
	enemy->animationElapsed += elapsed;
	if (enemy->animationElapsed > 1.0 / enemy->framesPerSecond) {
		enemy->currentIndex++;
		enemy->animationElapsed = 0.0;

		if (enemy->currentIndex > enemy->numFrames - 1) {
			enemy->currentIndex = 0;
		}
	}

	enemy->x += elapsed*enemy->velocity_x;
	float bound = .8f - (enemy->width / 2.f) - (1.6f / 20.f);
	if (enemy->x > bound - .001)
	{
		enemy->x = bound - .001; 
		enemy->flagDirection *= -1;
		enemy->velocity_x *= -1;
		enemy->animationElapsed = 0;
		enemy->currentIndex = 0;
	}
	
	bound = -.8f + (enemy->width / 2.f) + (1.6f / 20.f);
	if (enemy->x < bound + .001)
	{
		enemy->x = bound + .001; 
		enemy->flagDirection *= -1;
		enemy->velocity_x *= -1;
		enemy->animationElapsed = 0;
		enemy->currentIndex = 0;
	}

	//check collision left
	float starty = enemy->y - enemy->height / 2.f;
	float endy = enemy->y + enemy->height / 2.f;
	for (float i = starty; i <= endy; i += .00999)
	{
		float worldx = enemy->x - enemy->width / 2.f;
		float worldy = i;
		int gridX, gridY;
		worldToTileCoordinates(worldx, worldy, &gridX, &gridY);
		if (!( gridX>19 || gridY < 0 ))
		{
			if (levelData[gridY][gridX] != 6 && levelData[gridY][gridX] != 0 && levelData[gridY][gridX] != 11 && levelData[gridY][gridX] != 12 && levelData[gridY][gridX] != 13 && levelData[gridY][gridX] != 14) // then there is collision
			{
				enemy->x = gridToXRight(gridX, gridY) + enemy->width / 2.f+.001; // fix penetration
				enemy->flagDirection *= -1;
				enemy->velocity_x *= -1;
				enemy->animationElapsed = 0;
				enemy->currentIndex = 0;
			}
		}
	}
	//check collision right
	for (float i = starty; i <= endy; i += .00999)
	{
		float worldx = enemy->x + enemy->width / 2.f-.001;
		float worldy = i;
		int gridX, gridY;
		worldToTileCoordinates(worldx, worldy, &gridX, &gridY);
		if (!( gridX>19 || gridY < 0 ))
		{
			if (levelData[gridY][gridX] != 6 && levelData[gridY][gridX] != 0 && levelData[gridY][gridX] != 11 && levelData[gridY][gridX] != 12 && levelData[gridY][gridX] != 13 && levelData[gridY][gridX] != 14) // then there is collision
			{
				enemy->x = gridToXLeft(gridX, gridY) - enemy->width / 2.f; // fix penetration
				enemy->flagDirection *= -1;
				enemy->velocity_x *= -1;
				enemy->animationElapsed = 0;
				enemy->currentIndex = 0;
			}
		}
	}

	//update y velocity
	enemy->velocity_y -= gravity*elapsed;
	//update y position
	enemy->y += enemy->velocity_y*elapsed;

	if (enemy->y < -3.f) // if has fallen through floor for some reason, move back up
	{
		enemy->y = 1.f;
		enemy->velocity_y = 0.f;
	}

	//check collision top
	float startx = enemy->x - enemy->width / 2.f;
	float endx = enemy->x + enemy->width / 2.f;
	for (float i = startx; i <= endx; i += .00999)
	{
		float worldx = i;
		float worldy = enemy->y + enemy->height / 2.f;
		int gridX, gridY;
		worldToTileCoordinates(worldx, worldy, &gridX, &gridY);
		if (levelData[gridY][gridX] != 6 && levelData[gridY][gridX] != 0 && levelData[gridY][gridX] != 11 && levelData[gridY][gridX] != 12 && levelData[gridY][gridX] != 13 && levelData[gridY][gridX] != 14) // then there is collision
		{
			enemy->y = gridToYBot(gridX, gridY) - enemy->height / 2.f - .001; // fix penetration
			enemy->velocity_y = 0.f;
		}
	}
	//check collision bot
	//startx = player->x - player->width / 2.f;
	//endx = player->x + player->width / 2.f;
	for (float i = startx; i <= endx; i += .00999)
	{
		float worldx = i;
		float worldy = enemy->y - enemy->height / 2.f;
		int gridX, gridY;
		worldToTileCoordinates(worldx, worldy, &gridX, &gridY);
		if (levelData[gridY][gridX] != 6 && levelData[gridY][gridX] != 0 && levelData[gridY][gridX] != 11 && levelData[gridY][gridX] != 12 && levelData[gridY][gridX] != 13 && levelData[gridY][gridX] != 14) // then there is collision
		{
			enemy->y = gridToYTop(gridX, gridY) + enemy->height / 2.f + .001; // fix penetration
			enemy->velocity_y = 0.f;
		}
	}


}
void AppDelegate::UpdateCoin(Coin* coin, float elapsed)
{
	coin->animationElapsed += elapsed;
	if (coin->animationElapsed > 1.0 / coin->framesPerSecond) {
		coin->currentIndex++;
		coin->animationElapsed = 0.0;

		if (coin->currentIndex > coin->numFrames - 1) {
			coin->currentIndex = 0;
		}
	}
}

void AppDelegate::drawWorld()
{
	int SPRITE_COUNT_X = 9;
	int SPRITE_COUNT_Y = 8;
	float TILE_SIZE = 2.f / 25.f; //total height is 2, -1 to 1. divided by 25 tiles
	vector<float> vertexData;
	vector<float> texCoordData;
	int size = 0;
	for (int y = 0; y < LEVEL_HEIGHT; y++)
	{
		for (int x = 0; x < LEVEL_WIDTH; x++)
		{
			if (levelData[y][x] != 0)
			{

				float u = (float)(((int)levelData[y][x]) % SPRITE_COUNT_X) / (float)SPRITE_COUNT_X;
				float v = (float)(((int)levelData[y][x]) / SPRITE_COUNT_X) / (float)SPRITE_COUNT_Y;
				float spriteWidth = 1.0f / (float)SPRITE_COUNT_X;
				float spriteHeight = 1.0f / (float)SPRITE_COUNT_Y;
				vertexData.insert(vertexData.end(), {
					TILE_SIZE * x, -TILE_SIZE * y,
					TILE_SIZE * x, (-TILE_SIZE * y) - TILE_SIZE,
					(TILE_SIZE * x) + TILE_SIZE, (-TILE_SIZE * y) - TILE_SIZE,
					(TILE_SIZE * x) + TILE_SIZE, -TILE_SIZE * y
				});
				texCoordData.insert(texCoordData.end(), { u, v,
					u, v + (spriteHeight),
					u + spriteWidth, v + (spriteHeight),
					u + spriteWidth, v
				});
				size += 4;
			}
		}
	}
	//Set up
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBindTexture(GL_TEXTURE_2D, terrainid); // so gltexture_2d knows what textureid to draw
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	//glLoadIdentity();
	glTranslatef(-.8f, 1.f, 0.f);

	//Draw
	glVertexPointer(2, GL_FLOAT, 0, vertexData.data());
	glEnableClientState(GL_VERTEX_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoordData.data());
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glDrawArrays(GL_QUADS, 0, size);

	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_BLEND);
	glPopMatrix();
}
bool AppDelegate::CoinCollision(){
	float playerbot = player.y - player.height / 2.f;
	float playertop = player.y + player.height / 2.f;
	float playerright = player.x + player.width / 2.f;
	float playerleft = player.x - player.width / 2.f;

	float coinbot = coin.y - coin.height / 2.f;
	float cointop = coin.y + coin.height / 2.f;
	float coinright = coin.x + coin.width / 2.f;
	float coinleft = coin.x - coin.width / 2.f;

	if (playerbot > cointop)
	{
		return false;
	}
	if (playertop < coinbot)
	{
		return false;
	}
	if (playerleft > coinright)
	{
		return false;
	}
	if (playerright < coinleft)
	{
		return false;
	}
	
	return true;
}
bool AppDelegate::BulletCollision(Bullet * bullet, Enemy * enemy){
	float bulletbot = bullet->y - bullet->height / 2.f;
	float bullettop = bullet->y + bullet->height / 2.f;
	float bulletright = bullet->x + bullet->width / 2.f;
	float bulletleft = bullet->x - bullet->width / 2.f;

	float enemybot = enemy->y - enemy->height / 2.f;
	float enemytop = enemy->y + enemy->height / 2.f;
	float enemyright = enemy->x + enemy->width / 2.f;
	float enemyleft = enemy->x - enemy->width / 2.f;

	if (bulletbot > enemytop)
	{
		return false;
	}
	if (bullettop < enemybot)
	{
		return false;
	}
	if (bulletleft > enemyright)
	{
		return false;
	}
	if (bulletright < enemyleft)
	{
		return false;
	}

	return true;
}
bool AppDelegate::EnemyCollision(Enemy* enemy)
{
	float playerbot = player.y - player.height / 2.f;
	float playertop = player.y + player.height / 2.f;
	float playerright = player.x + player.width / 2.f;
	float playerleft = player.x - player.width / 2.f;

	float enemybot = enemy->y - enemy->height / 2.f;
	float enemytop = enemy->y + enemy->height / 2.f;
	float enemyright = enemy->x + enemy->width / 2.f;
	float enemyleft = enemy->x - enemy->width / 2.f;

	if (playerbot > enemytop)
	{
		return false;
	}
	if (playertop < enemybot)
	{
		return false;
	}
	if (playerleft > enemyright)
	{
		return false;
	}
	if (playerright < enemyleft)
	{
		return false;
	}

	return true;
}
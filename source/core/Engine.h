#pragma once

class Engine
{
public:

	Engine() = default;

public:

	void create(unsigned int width, unsigned int height, const char* id, bool isFullscreen);
	void setup();
	void destroy();

public:

	void update();
	void render();

public:

	void updateDelta();
	void updateEvent();
	void updateInput();
	void updateLogic();

public:

	void renderClear();
	void renderDraw();
	void renderDisplay();

public:

	bool isRunning();
	bool isPaused();

private:

	class RenderWindow*				window		= nullptr;
	class Clock*					clock		= nullptr;
	class RandomNumberGenerator*	rng			= nullptr;
	float							deltaTime	= 0.f;
	bool							paused		= true;
	bool							acceptInput	= false;
	int								score		= 0;

private:

	class SoundBuffer* bufferChop		= nullptr;
	class SoundBuffer* bufferDeath		= nullptr;
	class SoundBuffer* bufferOutOfTime	= nullptr;

private:

	class Sound* chop		= nullptr;
	class Sound* death		= nullptr;
	class Sound* outOfTime	= nullptr;

private:

	class Font* font = nullptr;

private:

	class Text* textMessage = nullptr;
	class Text* textScore	= nullptr;

private:

	class Texture* textureAxe			= nullptr;
	class Texture* textureBackground	= nullptr;
	class Texture* textureBee			= nullptr;
	class Texture* textureBranch		= nullptr;
	class Texture* textureCloud			= nullptr;
	class Texture* textureLog			= nullptr;
	class Texture* texturePlayer		= nullptr;
	class Texture* textureRip			= nullptr;
	class Texture* textureTree1			= nullptr;
	class Texture* textureTree2			= nullptr;

private:

	class Timebar* timebar = nullptr;

private:

	class Axe*		axe			= nullptr;
	class Sprite*	background	= nullptr;
	class Bee*		bee			= nullptr;
	class Sprite*	branch		= nullptr;
	class Cloud*	cloud1		= nullptr;
	class Cloud*	cloud2		= nullptr;
	class Cloud*	cloud3		= nullptr;
	class Log*		log			= nullptr;
	class Player*	player		= nullptr;
	class Sprite*	rip			= nullptr;
	class Tree*		tree		= nullptr;
	class Sprite*	tree2		= nullptr;
	class Sprite*	tree3		= nullptr;
	class Sprite*	tree4		= nullptr;
	class Sprite*	tree5		= nullptr;

};


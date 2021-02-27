#include "Engine.h"

// std/stl includes
#include <iostream>
#include <sstream>

// sfml derived includes
#include "RenderWindow.h"
#include "View.h"
#include "Clock.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Color.h"
#include "SoundBuffer.h"
#include "Sound.h"
#include "Font.h"
#include "Text.h"
#include "Texture.h"
#include "Sprite.h"
#include "RandomNumberGenerator.h"

// sprite derived includes
#include "Timebar.h"
#include "Axe.h"
#include "Bee.h"
#include "Log.h"
#include "Cloud.h"
#include "Player.h"
#include "Tree.h"

void Engine::create(unsigned int width, unsigned int height, const char* id, bool isFullscreen)
{
	{ // core initialization/creation

		static const auto videoMode = VideoMode(width, height);
		static const auto title		= Title(id);
		static const auto style		= (isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
		static const auto settings	= ContextSettings();

		window	= new RenderWindow(videoMode, title, style, settings);
		clock	= new Clock;
		rng		= new RandomNumberGenerator;

	}

	{ // sound buffer initialization/creation

		bufferChop		= new SoundBuffer;
		bufferDeath		= new SoundBuffer;
		bufferOutOfTime	= new SoundBuffer;

	}

	{ // sound initialization/creation

		chop		= new Sound;
		death		= new Sound;
		outOfTime	= new Sound;

	}

	{ // font initialization/creation

		font = new Font;

	}

	{ // text initialization/creation

		textMessage = new Text;
		textScore	= new Text;

	}

	{ // texture initialization/creation

		textureAxe			= new Texture;
		textureBackground	= new Texture;
		textureBee			= new Texture;
		textureBranch		= new Texture;
		textureCloud		= new Texture;
		textureLog			= new Texture;
		texturePlayer		= new Texture;
		textureRip			= new Texture;
		textureTree1		= new Texture;
		textureTree2		= new Texture;

	}

	{ // timebar modification/setup

		timebar = new Timebar;

	}

	{ // sprite initialization/creation

		axe			= new Axe;
		background	= new Sprite;
		bee			= new Bee;
		branch		= new Sprite;
		cloud1		= new Cloud;
		cloud2		= new Cloud;
		cloud3		= new Cloud;
		log			= new Log;
		player		= new Player;
		rip			= new Sprite;
		tree		= new Tree;
		tree2		= new Sprite;
		tree3		= new Sprite;
		tree4		= new Sprite;
		tree5		= new Sprite;

	}
}

void Engine::setup()
{
	{ // core modification/setup

		window->setFramerateLimit(60);

	}

	{ // sound buffer initialization/creation

		bufferChop->loadFromFile(		"resource/sound/chop.wav");
		bufferDeath->loadFromFile(		"resource/sound/death.wav");
		bufferOutOfTime->loadFromFile(	"resource/sound/out_of_time.wav");

	}

	{ // sound initialization/creation

		chop->setBuffer(		*bufferChop);
		death->setBuffer(		*bufferDeath);
		outOfTime->setBuffer(	*bufferOutOfTime);

	}

	{ // font modification/setup

		font->loadFromFile("resource/fonts/KOMIKAP_.ttf");

	}

	{ // text modification/setup

		textMessage->setFont(	*font);
		textScore->setFont(		*font);

		textMessage->setString(	"Press Enter to start!"	);
		textScore->setString(	"Score = 0"				);

		textMessage->setCharacterSize(	75	);
		textScore->setCharacterSize(	100	);

		textMessage->setFillColor(	Color::White	);
		textScore->setFillColor(	Color::White	);

		textMessage->setOrigin(
			textMessage->getLocalBounds().left	+ (textMessage->getLocalBounds().width	/ 2),
			textMessage->getLocalBounds().top	+ (textMessage->getLocalBounds().height / 2));
		textScore->setOrigin(0, 0);

		textMessage->setPosition(window->getSize().x / 2.f, window->getSize().y / 2.f);
		textScore->setPosition(20, 20);

	}

	{ // texture modification/setup
	
		textureAxe->loadFromFile(		"resource/graphics/axe.png"			);
		textureBackground->loadFromFile("resource/graphics/background.png"	);
		textureBee->loadFromFile(		"resource/graphics/bee.png"			);
		textureBranch->loadFromFile(	"resource/graphics/branch.png"		);
		textureCloud->loadFromFile(		"resource/graphics/cloud.png"		);
		textureLog->loadFromFile(		"resource/graphics/log.png"			);
		texturePlayer->loadFromFile(	"resource/graphics/player.png"		);
		textureRip->loadFromFile(		"resource/graphics/rip.png"			);
		textureTree1->loadFromFile(		"resource/graphics/tree1.png"		);
		textureTree2->loadFromFile(		"resource/graphics/tree2.png"		);

	}

	{ // rectangle shape modification/setup

		timebar->setStartWidth(400);
		timebar->setStartHeight(80);
		timebar->setSize(vec2f(timebar->getStartWidth(), timebar->getStartHeight()));
		timebar->setFillColor(Color::Red);
		timebar->setPosition((window->getSize().x / 2.f) - (timebar->getStartWidth() / 2.f), 980);
		timebar->setTimeRemaining(6.f);
		timebar->setWidthPerSecond(timebar->getStartWidth() / timebar->getTimeRemaining());

	}

	{ // generic sprite modification/setup

		axe->setup(			*textureAxe			, vec2f(	0	,	0		), vec2f(	2000,	830		), Color(	255,	255,	255,	255	)	);	// visible
		background->setup(	*textureBackground	, vec2f(	0	,	0		), vec2f(	0	,	0		), Color(	255,	255,	255,	255	)	);	// visible
		bee->setup(			*textureBee			, vec2f(	0	,	0		), vec2f(	0	,	800		), Color(	255,	255,	255,	255	)	);	// visible
		branch->setup(		*textureBranch		, vec2f(	0	,	0		), vec2f(	0	,	0		), Color(	255,	255,	255,	255	)	);	// visible
		cloud1->setup(		*textureCloud		, vec2f(	0	,	0		), vec2f(	0	,	0		), Color(	255,	255,	255,	255	)	);	// visible
		cloud2->setup(		*textureCloud		, vec2f(	0	,	0		), vec2f(	0	,	250		), Color(	255,	255,	255,	255	)	);	// visible
		cloud3->setup(		*textureCloud		, vec2f(	0	,	0		), vec2f(	0	,	500		), Color(	255,	255,	255,	255	)	);	// visible
		log->setup(			*textureLog			, vec2f(	0	,	0		), vec2f(	2000,	720		), Color(	255,	255,	255,	255	)	);	// visible
		player->setup(		*texturePlayer		, vec2f(	0	,	0		), vec2f(	2000,	720		), Color(	255,	255,	255,	255	)	);	// visible
		rip->setup(			*textureRip			, vec2f(	0	,	0		), vec2f(	2000,	860		), Color(	255,	255,	255,	255	)	);	// visible
		tree->setup(		*textureTree1		, vec2f(	0	,	0		), vec2f(	810	,	0		), Color(	255,	255,	255,	255	)	);	// visible
		tree2->setup(		*textureTree2		, vec2f(	0	,	0		), vec2f(	10	,	0		), Color(	255,	255,	255,	255	)	);	// visible
		tree3->setup(		*textureTree2		, vec2f(	0	,	0		), vec2f(	200	,	-450	), Color(	255,	255,	255,	255	)	);	// visible
		tree4->setup(		*textureTree2		, vec2f(	0	,	0		), vec2f(	1500,	-100	), Color(	255,	255,	255,	255	)	);	// visible
		tree5->setup(		*textureTree2		, vec2f(	0	,	0		), vec2f(	1700,	-400	), Color(	255,	255,	255,	255	)	);	// visible

		// specific sprite modification/setup
		{

			tree->setup(6, *branch, *rng);

		}

	}
}

void Engine::destroy()
{
	{ // core destruction

		delete window;
		delete clock;

	}

	{ // sound buffer destruction

		delete bufferChop;
		delete bufferDeath;
		delete bufferOutOfTime;

	}

	{ // sound destruction

		delete chop;
		delete death;
		delete outOfTime;

	}

	{ // font destruction

		delete font;

	}

	{ // text destruction

		delete textMessage;
		delete textScore;

	}

	{ // texture destruction

		delete textureAxe;
		delete textureBackground;
		delete textureBee;
		delete textureBranch;
		delete textureCloud;
		delete textureLog;
		delete texturePlayer;
		delete textureRip;
		delete textureTree1;
		delete textureTree2;

	}

	{ // sprite destruction

		delete axe;
		delete background;
		delete bee;
		delete branch;
		delete cloud1;
		delete cloud2;
		delete cloud3;
		delete log;
		delete player;
		delete rip;
		delete tree;
		delete tree2;
		delete tree3;
		delete tree4;
		delete tree5;

	}
}

void Engine::update()
{
	updateDelta();
	updateEvent();
	updateInput();

	if (!paused)
	{
		updateLogic();
	}
}

void Engine::render()
{
	renderClear();
	renderDraw();
	renderDisplay();
}

void Engine::updateDelta()
{
	deltaTime = (float)clock->restart().asSeconds();
}

void Engine::updateEvent()
{
	Event event;

	while (window->pollEvent(event))
	{
		switch (event.type)
		{
			case Event::Closed:
			{
				window->close();
			}
			break;

			case Event::KeyReleased:
			{
				if (!paused)
				{
					acceptInput = true;

					axe->setPosition(2000, axe->getPosition().y);
				}
			}
			break;
		}
	}
}

void Engine::updateInput()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window->close();
	}

	if (Keyboard::isKeyPressed(Keyboard::Return))
	{
		paused	= false;
		score	= 0;
		timebar->setTimeRemaining(5);

		for (auto i = 1; i < tree->getNumOfBranches(); i++)
		{
			tree->getSides()[i] = Side::None;
		}

		rip->setPosition(675, 2000);
		player->setPosition(580, 720);
		acceptInput = true;
	}

	if (acceptInput)
	{
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			player->side = Side::Right;
			score++;
			timebar->setTimeRemaining(timebar->getTimeRemaining() + (2 / score) + .15);
			axe->setPosition(axe->AXE_POSITION_RIGHT, axe->getPosition().y);
			player->setPosition(1200, 720);
			tree->updateBranch(*rng);
			log->setPosition(810, 720);
			log->setSpeed(vec2f(-5000, log->getSpeed().y));
			log->setActive(true);
			acceptInput = false;
			chop->play();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			player->side = Side::Left;
			score++;
			timebar->setTimeRemaining(timebar->getTimeRemaining() + (2 / score) + .15);
			axe->setPosition(axe->AXE_POSITION_LEFT, axe->getPosition().y);
			player->setPosition(580, 720);
			tree->updateBranch(*rng);
			log->setPosition(810, 720);
			log->setSpeed(vec2f(5000, log->getSpeed().y));
			log->setActive(true);
			acceptInput = false;
			chop->play();
		}
	}
}

void Engine::updateLogic()
{
	{ // timebar logic

		timebar->update(*window, deltaTime, paused, *textMessage, *outOfTime);

	}

	{ // bee logic

		bee->update(deltaTime, rng->range(200, 400), vec2f(2000, rng->range(500, 1000)));
	
	}

	{ // cloud(s) logic(s)

		cloud1->update(deltaTime, rng->range(5, 200), vec2f(-cloud1->getGlobalBounds().width, rng->range(0, 150)),		window->getSize().x);
		cloud2->update(deltaTime, rng->range(5, 200), vec2f(-cloud1->getGlobalBounds().width, rng->range(150, 300)),	window->getSize().x);
		cloud3->update(deltaTime, rng->range(5, 200), vec2f(-cloud1->getGlobalBounds().width, rng->range(300, 450)),	window->getSize().x);

	}

	{ // tree

		tree->update(*window);
		log->update(deltaTime);

	}

	{ // text logic(s)

		std::stringstream ss;
		ss << "Score = " << score;
		textScore->setString(ss.str());

	}

	if (tree->getSides()[5] == player->side)
	{
		paused = true;
		acceptInput = false;

		rip->setPosition(525, 760);
		player->setPosition(2000, 660);
		log->setPosition(2000, log->getPosition().y);
		axe->setPosition(2000, log->getPosition().y);
		textMessage->setString("SQUISHED!!!");
		textMessage->setOrigin(textMessage->getLocalBounds().width / 2, textMessage->getLocalBounds().top + (textMessage->getLocalBounds().height / 2));
		textMessage->setPosition(window->getSize().x / 2.f, window->getSize().y / 2.f);
		death->play();
	}
}

void Engine::renderClear()
{
	window->clear(Color::Black);
}

void Engine::renderDraw()
{
	{ // sprites

		window->draw(*background);
		window->draw(*tree2);
		window->draw(*tree3);
		window->draw(*tree4);
		window->draw(*tree5);
		window->draw(*tree);
		window->draw(*cloud1);
		window->draw(*cloud2);
		window->draw(*cloud3);
		window->draw(*player);
		window->draw(*rip);
		window->draw(*axe);
		window->draw(*bee);
		window->draw(*log);

		for (auto i = 0; i < tree->getNumOfBranches(); i++)
		{
			window->draw(tree->getBranches()[i]);
		}

	}

	{ // timebar

		window->draw(*timebar);

	}


	{ // texts

		window->draw(*textScore);

		if (paused)
		{
			window->draw(*textMessage);
		}

	}
}

void Engine::renderDisplay()
{
	window->display();
}

bool Engine::isRunning()
{
	return window->isOpen();
}

bool Engine::isPaused()
{
	return paused;
}

#include "Engine.h"

int main()
{
	Engine engine;

	engine.create(1920, 1080, "Lumberjack", false);
	engine.setup();

	while ( engine.isRunning() )
	{
		engine.update();
		engine.render();
	}

	engine.destroy();
}
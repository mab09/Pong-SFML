#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Event/EventManager.h"
#include "../../Header/Gameplay/GameplayManager.h"

using namespace sf;
using namespace Core;
using namespace Event;
using namespace Gameplay;
using namespace std;

namespace Core
{
	class GameLoop
	{
	private:
		GameWindowManager* game_window_manager;
		EventManager* event_manager;
		GameplayManager* gameplay_manager;

	public:
		void initialize();

		bool isGameRunning();
		void pollEvent();
		void update();
		void render();
	};
}
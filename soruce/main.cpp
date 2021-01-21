#include <memory>
#include "Screen.hpp"
#include "Game.hpp"

#ifdef _DEBUG
#pragma comment(lib, "sfml-system-d.lib")
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-graphics-d.lib")
#else
#pragma comment(lib, "sfml-system.lib")
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-graphics.lib")
#endif

int main(int argc, char** argv) {
	// build first screen
	std::unique_ptr<sge::Screen> first_screen = std::make_unique<sge::Screen>(sf::View(sf::FloatRect(0.0f, 0.0f, 720.0f, 1280.0f)));

	// run the game
	sge::Game game;
	game.run(720 / 2, 1280 / 2, std::move(first_screen));
}
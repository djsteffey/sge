#include <SFML/Graphics.hpp>

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
	sf::RenderWindow rw;
	rw.create(sf::VideoMode(720 / 2, 1280 / 2), "SGE", sf::Style::Close | sf::Style::Titlebar);
	while (rw.isOpen()) {
		sf::Event event;
		while (rw.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				rw.close();
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				rw.close();
			}
		}

		rw.clear();

		rw.display();
	}
}
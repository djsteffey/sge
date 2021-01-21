#ifndef sge_Game_hpp
#define sge_Game_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

namespace sge{
    class Screen;

    class Game{
        public:
            Game();
            ~Game();
            void run(unsigned int width, unsigned int height, std::unique_ptr<Screen> first_screen);
            void setNextScreen(std::unique_ptr<Screen> screen);

        protected:

        private:
            void init(unsigned int width, unsigned int height);
            void shutdown();
            void events();
            void draw();
            void update();

            bool m_is_running;
            std::unique_ptr<Screen> m_current_screen;
            std::unique_ptr<Screen> m_next_screen;
            sf::RenderWindow m_render_window;
    };
}
#endif

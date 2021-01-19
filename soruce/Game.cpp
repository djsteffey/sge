#include "Game.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include "Screen.hpp"

namespace sge{
    Game::Game(){
        this->m_is_running = false;
        this->m_current_screen = nullptr;
        this->m_next_screen = nullptr;
    }

    Game::~Game(){

    }

    void Game::run(){
        // check if already running
        if (this->m_is_running){
            return;
        }

        // flag as running
        this->m_is_running = true;

        // initialize
        this->init();

        // run
        while(this->m_is_running){
            this->events();
            this->update();
            this->draw();
        }

        // done
        this->shutdown();
    }

    void Game::setNextScreen(std::unique_ptr<Screen> screen){
        this->m_next_screen = std::move(screen);
    }

    void Game::init(){
        this->m_render_window.create(sf::VideoMode(720 / 2, 1280 / 2), "SGE", sf::Style::Close | sf::Style::Titlebar);
    }

    void Game::shutdown(){
        this->m_render_window.close();
    }

    void Game::events(){
        sf::Event event;
        while(this->m_render_window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                this->m_is_running = false;
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
                this->m_is_running = false;
            }
        }
    }

    void Game::draw(){
        if (this->m_current_screen != nullptr){
            this->m_current_screen->draw(&this->m_render_window);
        }
    }

    void Game::update(){
        if (this->m_next_screen != nullptr){
            this->m_current_screen = std::move(this->m_next_screen);
            this->m_next_screen = nullptr;
        }
        if (this->m_current_screen != nullptr){
            this->m_current_screen->update(0.0f);
        }
    }
}

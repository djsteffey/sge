#include "Screen.hpp"
#include "Stage.hpp"

namespace sge {
	Screen::Screen(sf::View view) {
		this->m_stage = std::make_unique<Stage>(view);
	}

	Screen::~Screen() {

	}

	void Screen::draw(sf::RenderWindow* rw) {
		this->m_stage->draw(rw);
	}

	void Screen::update(float delta) {
		this->m_stage->update(delta);
	}
}

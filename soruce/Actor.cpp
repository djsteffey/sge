#include "Actor.hpp"

namespace sge {
	Actor::Actor() {
		this->m_position_x = 0.0f;
		this->m_position_y = 0.0f;
		this->m_size_width = 0.0f;
		this->m_size_height = 0.0f;
		this->m_color = sf::Color::White;
	}

	Actor::~Actor() {

	}

	void Actor::draw(sf::RenderWindow* rw) {

	}

	void Actor::update(float delta) {

	}
}

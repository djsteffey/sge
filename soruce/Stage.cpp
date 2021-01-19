#include "Stage.hpp"
#include "Actor.hpp"

namespace sge {
	Stage::Stage(sf::View view) {
		this->m_view = view;
	}

	Stage::~Stage() {

	}

	void Stage::draw(sf::RenderWindow* rw) {
		rw->setView(this->m_view);
		for (auto& kvp : this->m_actors){
			kvp.second->draw(rw);
		}
	}

	void Stage::update(float delta) {
		for (auto& kvp : this->m_actors) {
			kvp.second->update(delta);
		}
	}
}

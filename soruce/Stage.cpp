#include "Stage.hpp"
#include "Actor.hpp"
#include "util.hpp"

namespace sge {
	Stage::Stage(sf::View view) {
		this->m_view = view;
	}

	Stage::~Stage() {

	}

	void Stage::draw(sf::RenderWindow* rw) {
		rw->clear();
		rw->setView(this->m_view);
		for (auto& kvp : this->m_actors){
			kvp.second->draw(rw);
		}
		rw->display();
	}

	void Stage::update(float delta) {
		for (auto& kvp : this->m_actors) {
			kvp.second->update(delta);
		}
	}

    unsigned long Stage::addActor(std::unique_ptr<Actor> actor){
        unsigned long id = util::generateUniqueId();
        this->m_actors[id] = std::move(actor);
        return id;
    }
}

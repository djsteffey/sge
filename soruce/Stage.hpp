#ifndef sge_Stage_hpp
#define sge_Stage_hpp

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>

namespace sge {
	class Actor;

	class Stage {
	public:
		Stage(sf::View view);
		virtual ~Stage();
		virtual void draw(sf::RenderWindow* rw);
		virtual void update(float delta);
        virtual unsigned long addActor(std::unique_ptr<Actor>> actor);

	protected:
		sf::View m_view;
		std::map<unsigned long, std::unique_ptr<Actor>> m_actors;

	private:

	};
}
#endif
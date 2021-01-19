#ifndef sge_Actor_hpp
#define sge_Actor_hpp

#include <SFML/Graphics.hpp>

namespace sge {
	class Actor {
	public:
		Actor();
		virtual ~Actor();
		virtual void draw(sf::RenderWindow* rw);
		virtual void update(float delta);

	protected:
		float m_position_x;
		float m_position_y;
		float m_size_width;
		float m_size_height;
		sf::Color m_color;

	private:

	};
}
#endif
#ifndef sge_Screen_hpp
#define sge_Screen_hpp

#include <SFML/Graphics.hpp>
#include <memory>

namespace sge {
	class Stage;

	class Screen {
	public:
		Screen(sf::View view);
		virtual ~Screen();
		virtual void draw(sf::RenderWindow* rw);
		virtual void update(float delta);

	protected:
		std::unique_ptr<Stage> m_stage;

	private:

	};
}
#endif
#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(500, 500), "Convex Shape");

	sf::ConvexShape s;
	s.setPointCount(4);
	s.setFillColor(sf::Color::Green);

	s.setPoint(0, sf::Vector2f(100, 0));
	s.setPoint(1, sf::Vector2f(23, 40));
	s.setPoint(2, sf::Vector2f(150, 45));
	s.setPoint(3, sf::Vector2f(45, 60));

	while (window.isOpen()) {
		sf::Event eve;
		while (window.pollEvent(eve)) {
			if (eve.type == sf::Event::Closed) window.close();
		}
	
		window.clear();
		window.draw(s);
		window.display();
	}

	return 0;
}
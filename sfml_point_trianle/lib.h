#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;

class Engine {
	int PointsCreated = 0;
	sf::RenderWindow window;
	vector<sf::CircleShape> Points;

	sf::Font font;
	sf::Text DisplayPointsCreated;

	sf::ConvexShape DrawConvexShape();
	void OnMouseClick();
	void DrawPoint(sf::Vector2f pos);
	void DrawLine();
	void Clear();
	void Draw();

public:
	Engine();
	void Start();
};

Engine::Engine() {
	window.create(sf::VideoMode(500, 500), "Point triangle");
	font.loadFromFile("Roboto/Roboto-Medium.ttf");
	DisplayPointsCreated.setFont(font);
	DisplayPointsCreated.setCharacterSize(20);
	DisplayPointsCreated.setPosition(10, 10);
	DisplayPointsCreated.setFillColor(sf::Color::White);
}

void Engine::Clear() {
	PointsCreated = 0;
	Points.clear();
}

void Engine::Draw() {
	window.clear(sf::Color(100, 100, 200));

	window.draw(DisplayPointsCreated);

	for (const auto cir : Points) {
		window.draw(cir);
	}

	window.draw(DrawConvexShape());

	window.display();
}

sf::ConvexShape Engine::DrawConvexShape() {
	sf::ConvexShape cs;
	cs.setPointCount(PointsCreated);
	cs.setFillColor(sf::Color::Red);

	for (int i = 0; i < PointsCreated; i++) {
		cs.setPoint(i, sf::Vector2f(Points[i].getPosition().x, Points[i].getPosition().y));
	}

	return cs;
}

void Engine::DrawPoint(sf::Vector2f pos) {
	sf::CircleShape circle;
	circle.setRadius(10);
	circle.setOrigin(5, 5);
	circle.setFillColor(sf::Color::Green);
	circle.setPosition(sf::Vector2f(pos.x, pos.y));
	Points.push_back(circle);
}

void Engine::OnMouseClick() {
	sf::Vector2f mouse_pos;
	mouse_pos.x = sf::Mouse::getPosition(window).x;
	mouse_pos.y = sf::Mouse::getPosition(window).y;
	PointsCreated++;
	DisplayPointsCreated.setString("Points: " + std::to_string(PointsCreated));
	DrawPoint(mouse_pos);
}

void Engine::Start() {
	while (window.isOpen()) {
		sf::Event event;		
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) OnMouseClick();
			if (event.type == sf::Event::EventType::KeyPressed) {
				if (event.key.code == sf::Keyboard::Q) window.close();
				if (event.key.code == sf::Keyboard::D) 	DrawConvexShape();
				if (event.key.code == sf::Keyboard::R) 	Clear();
			}
		}
		
		Draw();
	}
}
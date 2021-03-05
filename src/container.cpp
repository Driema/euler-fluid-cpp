#include "../header/container.h"

Container::Container() {}

Container::Container(int size, float dt, float diff, float visc) {
	this->size = size;
	this->dt = dt;
	this->diff = diff;
	this->visc = visc;
	
	for (int i = 0; i < size; i++) {
		std::vector<Cell> cellRow;
		for (int j = 0; j < size; j++) {
			Cell c;
			c.position.x = j;
			c.position.y = i;	
			cellRow.push_back(c);
		}
		this->cells.push_back(cellRow);
	}
}

Container::~Container() {}

void Container::AddDensity(Pos p, float amount) {
	this->cells.at(p.y).at(p.x).d += amount;
}

void Container::AddVelocity(Pos p, Pos vec) {
	this->cells.at(p.y).at(p.x).position.x += vec.x;
	this->cells.at(p.y).at(p.x).position.y += vec.y;
}

void Container::Render(sf::RenderWindow& win) {
	for (auto& row : this->cells) {
		for (auto& c : row) {	
			sf::RectangleShape rect;
			rect.setFillColor(sf::Color(255, 255, 255));
			rect.setSize(sf::Vector2f(1, 1));
			rect.setPosition(c.position.x, c.position.y);
			win.draw(rect);
		}
	}	
}

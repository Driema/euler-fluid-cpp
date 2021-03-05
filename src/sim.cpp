#include "../header/sim.h"
#include<iostream>

const int WIDTH = 800;
const int HEIGHT = 800;

const int Sim::numParticles = 10;

Sim::Sim() : container(Container(WIDTH, 0.1f, 1, 1)), win(sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Euler fluid simulation - Github: https://github.com/driema/euler-fluid-cpp", sf::Style::Titlebar | sf::Style::Close)) {}

Sim::~Sim() {}

void Sim::Setup() {}

void Sim::Run() {
	this->Setup();

	while (this->win.isOpen()) {
		sf::Event e;
		while (this->win.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				this->win.close();
			}
		}

		this->CalcPositions();
		this->container.Render(this->win);
		
		this->win.display();
	}
}

void Sim::CalcPositions() {}


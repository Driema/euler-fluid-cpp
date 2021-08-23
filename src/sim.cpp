#include "../header/sim.h"
#include<iostream>

const int Sim::numParticles = 10;

Sim::Sim() : options(Options()), container(Container(0.2f, 0, 0.0000001f)) {
	this->win.create(sf::VideoMode(SIZE*SCALE, SIZE*SCALE), "Euler fluid simulation - Github: https://github.com/driema/euler-fluid-cpp", sf::Style::Titlebar | sf::Style::Close);
}

Sim::~Sim() {}

void Sim::Setup() {}

void Sim::Run() {
	this->Setup();
	sf::Vector2i previousMouse = sf::Mouse::getPosition(this->win);
	sf::Vector2i currentMouse = sf::Mouse::getPosition(this->win);

	while (this->win.isOpen()) {
		sf::Event e;
		while (this->win.pollEvent(e)) {
			switch (e.type) {
				case sf::Event::Closed:
					this->win.close();
					break;
				case sf::Event::KeyReleased:
					if (e.key.code == sf::Keyboard::Key::C) {
						Color c = (this->options.GetColor() == Color::Default) ?
							Color::Hsb : (this->options.GetColor() == Color::Hsb) ?
							Color::Velocity : Color::Default;

						this->options.SetColor(c);
					}
					break;
				default:
					break;
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))			
			this->container.AddDensity(currentMouse.y/SCALE, currentMouse.x/SCALE, 200);

		currentMouse = sf::Mouse::getPosition(this->win);

		float amountX = currentMouse.x - previousMouse.x;
		float amountY = currentMouse.y - previousMouse.y;

		this->container.AddVelocity(currentMouse.y/SCALE, currentMouse.x/SCALE, amountY / 10, amountX / 10);
		
		previousMouse = currentMouse;

		this->container.Step();
		this->container.Render(this->win, this->options.GetColor());
		this->container.FadeDensity(SIZE*SIZE);
		
		this->win.display();
	}
}


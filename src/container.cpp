#include "../header/container.h"
#include<iostream>

extern const int SIZE;
extern const int SCALE;

int IX(int x, int y, int N);

Container::Container() : physics(Physics()) {}

Container::Container(float dt, float diff, float visc) {
	this->size = SIZE;
	this->dt = dt;
	this->diff = diff;
	this->visc = visc;
	
	this->px = new float[SIZE*SIZE];
	this->py = new float[SIZE*SIZE];

	this->x = new float[SIZE*SIZE];
	this->y = new float[SIZE*SIZE];

	this->previousDensity = new float[SIZE*SIZE];
	this->density = new float[SIZE*SIZE];

	this->InitArr(px, SIZE*SIZE);
	this->InitArr(py, SIZE*SIZE);
	this->InitArr(x, SIZE*SIZE);
	this->InitArr(y, SIZE*SIZE);
	this->InitArr(previousDensity, SIZE*SIZE);
	this->InitArr(density, SIZE*SIZE);
}

Container::~Container() {
	delete[] this->px;
	delete[] this->py;

	delete[] this->x;
	delete[] this->y;
	
	delete[] this->previousDensity;
	delete[] this->density;	
}

void Container::InitArr(float* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 0;	
	}
}

void Container::AddDensity(float x, float y, float amount) {
	this->density[IX(x,y,this->size)] += amount;
}

void Container::AddVelocity(float x, float y, float px, float py) {
	int index = IX(x,y,this->size);

	this->x[index] += px;
	this->y[index] += py;
}

void Container::Step() {
	int N = this->size;
	float visc = this->visc;
	float diff = this->diff;
	float dt = this->dt;
	float* x = this->x;
	float* y = this->y;
	float* px = this->px;
	float* py = this->py;
	float* previousDensity = this->previousDensity;
	float* density = this->density;	

	this->physics.Diffuse(1, px, x, visc, dt, 16, N);	
	this->physics.Diffuse(2, py, y, visc, dt, 16, N);	

	this->physics.Project(px, py, x, y, 16, N);
	
	this->physics.Advect(1, x, px, px, py, dt, N);
	this->physics.Advect(2, y, py, px, py, dt, N);

	this->physics.Project(x, y, px, py, 16, N);

	this->physics.Diffuse(0, previousDensity, density, diff, dt, 16, N);	
	this->physics.Advect(0, density, previousDensity, x, y, dt, N);
}

void Container::Render(sf::RenderWindow& win) {
	win.clear();
	for (int i = 0; i < this->size; i++) {
		for(int j = 0; j < this->size; j++) {
			sf::RectangleShape rect;
			rect.setSize(sf::Vector2f(SCALE, SCALE));
			rect.setPosition(j * SCALE, i * SCALE);
			rect.setFillColor(sf::Color(255, 255, 255, this->density[IX(i,j,this->size)]));
			win.draw(rect);
		}
	}
}

void Container::FadeDensity(int size) {
	for (int i = 0; i < size; i++) {
		float d = this->density[i];
		density[i] = (d - 0.05f < 0) ? 0 : d - 0.05f; 
	}	
}

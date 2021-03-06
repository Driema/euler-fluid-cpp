#include<vector>
#include<SFML/Graphics.hpp>

#include "./physics.h"

class Container {
private:
	Physics physics;

	int size;

	float dt;
	float diff;
	float visc;
	
	float* px;
	float* py;

	float* x;
	float* y;

	float* previousDensity;
	float* density;

	void InitArr(float* arr, int size);
public:
	Container();
	Container(float dt, float diff, float visc);
	~Container();

	void AddDensity(float x, float y, float amount);
	void AddVelocity(float x, float y, float px, float py);
	void Step();
	void Render(sf::RenderWindow& win);
	void FadeDensity(int size);
};


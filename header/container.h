#include<vector>
#include<SFML/Graphics.hpp>

#include "./cell.h"

class Container {
private:
	int size;
	float dt;
	float diff;
	float visc;
	std::vector<std::vector<Cell>> cells;	
public:
	Container();
	Container(int size, float dt, float diff, float visc);
	~Container();

	void AddDensity(Pos p, float amount);
	void AddVelocity(Pos p, Pos vec);
	void Render(sf::RenderWindow& win);
};


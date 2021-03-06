#include<vector>

#include "./container.h"

class Sim {
private:
	sf::RenderWindow win;
	Container container;
	void Setup();
public:
	static const int numParticles;
	Sim();
	~Sim();
	void Run();
};

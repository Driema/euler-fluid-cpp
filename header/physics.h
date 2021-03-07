class Physics {
private:
	void LinSolve(int b, float x[], float x0[], float a, float c, int iter, int N);
	void SetBnd(int b, float x[], int N);
public:
	Physics();
	~Physics();

	void Diffuse(int b, float x[], float x0[], float diff, float dt, int iter, int N);
	void Project(float vx[], float vy[], float p[], float div[], int iter, int N);	
	void Advect(int b, float d[], float d0[], float vx[], float vy[], float dt, int N); 
};

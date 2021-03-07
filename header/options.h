class Options {
private:
	bool color;
public:
	Options(bool color=false);
	~Options();
	
	bool GetColor();
	void SetColor(bool value);
};

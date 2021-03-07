#include "../header/options.h"

Options::Options(Color color) {
	this->color = color;
}

Options::~Options() {}

Color Options::GetColor() { return this->color; }

void Options::SetColor(Color c) { this->color = c; }

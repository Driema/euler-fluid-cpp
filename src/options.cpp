#include "../header/options.h"

Options::Options(bool color) {
	this->color = color;
}

Options::~Options() {}

bool Options::GetColor() { return this->color; }

void Options::SetColor(bool value) { this->color = value; }

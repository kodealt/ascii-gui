// asciiGUI.h

#pragma once
//#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <math.h>
#define NOMINMAX
#include <Windows.h>

namespace asciiGUI
{
	extern std::vector<std::vector<char>> columns;

	void rect(const char& s = '#', int width = 3, int height = 3, int posx = 0, int posy = 0, const char& fill = ' ');

	void text(const std::string& text = "text", int posx = 0, int posy = 0);

	void draw();

	void clear();

	void circle(const char c = '#', int radius = 3, int posx = 0, int posy = 0);

};

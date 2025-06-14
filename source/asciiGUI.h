// asciiGUI.h

#pragma once
//#include <string>
#include <vector>
#include <string>
#include <algorithm>


namespace asciiGUI
{
	extern std::vector<std::vector<char>> columns;

	//int stack = 0;

	//int adder(int a, int b);

	void rect(const char& s = '#', int width = 3, int height = 3, int posx = 0, int posy = 0, const char& fill = ' ');

	//void row(const char& s = '#', int width = 3, const char& fill = ' ');

	void text(const std::string& text, int posx, int posy);

	void draw();
	
	//void normalize();

	void clear();
	//static void stack(const int& b = 1);

	void ReSize(int w = 30, int h = 120);

};

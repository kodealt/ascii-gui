// asciiGUI.cpp

#include "asciiGUI.h"
#include <iostream>
#include <Windows.h>
//int asciiGUI::adder(int a, int b) {
//	return a + b;
//}
//

int minw = 0;
int minh = 0;

void selfMax(int sW, int sH) {

	minw = (sW > minw) ? sW : minw;
	minh = (sH > minh) ? sH : minh;

}

void allocate(std::vector<std::vector<char>>& array, int aWidth, int aHeight) {

	
	/*if ((int)array.size() < aHeight) {
		array.resize(aHeight);

	}*/
	

	for (auto& row : array) {
		if (row.size() < aWidth) {
			/*int i = 0;
			for (; i < aWidth - row.size(); i++) {
				row.pop_back();
			}*/
			row.resize(aWidth, ' ');
			//row.erase(row.begin() + aWidth, row.end());
		}
	}



	return;
}



void normalize(std::vector<std::vector<char>>& array, int maximumWidth = 0, int maximumHeight = 0) {
		
		array.resize(maximumHeight);

		for (auto& row : array) {
			row.resize(maximumWidth, ' ');
		}
	}



namespace asciiGUI {

	std::vector<std::vector<char>> columns;

	int lastHeight, lastWidth = 0;

	void clear() {
		//normalize(columns);
		minw = 0;
		minh = 0;
		columns.clear();
		//std::cout << "\033[2J\033[1;1H";
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { (SHORT)0, (SHORT)0 };
		SetConsoleCursorPosition(hOut, pos);

		allocate(columns, lastHeight, lastHeight);
		return;
	}

	void asciiGUI::rect(const char& s, int width, int height, int posx, int posy, const char& fill) {

		int minHeight = posy + height; //account for \n
		
		int minWidth = posx + width;  //account for \n
		
		/*if (minHeight > maxh) maxh = minHeight;
		if (minWidth > maxw) maxw = minWidth;*/

		/*if ((int)columns.size() < minHeight) {
			columns.resize(minHeight);
		}

		for (auto& row : columns) {
			if ((int)row.size() < minWidth) {
				row.resize(minWidth, ' ');
			}
		}*/

		allocate(columns, minWidth, minHeight);

		for (int x = posx; x < posx + width; x++) { //top and bottom borders
			columns[posy][x] = s;
			columns[posy + height - 1][x] = s;
		}

		//columns[posy][width] = '\n';

		for (int y = posy + 1; y < posy + height - 1; y++) {
			columns[y][posx] = s;
			columns[y][posx + width - 1] = s;

			for (int x = posx + 1; x < posx + width - 1; x++) {
				columns[y][x] = fill;
			}

			//columns[c][width] = '\n';
		}

		

		return;

	}

	void text(const std::string& text, int posx, int posy) {

		int maxX = text.length() + posx;

		allocate(columns, maxX, posy);

		for (char c : text) {
			columns[posy][posx] = c;
			posx++;
		}

	}

	void draw() {

		

		std::string buffer;

		int cHeight = columns.size();
		int cWidth = 0;

		for (auto& row : columns) {
			cWidth = (((cWidth) > (int)row.size()) ? (cWidth) : (int(row.size())));
		}
		
		normalize(columns, cWidth, cHeight);
		
		std::cout << lastWidth << " ";
		std::cout << cWidth << " diff : ";
		int j = cWidth - lastWidth;
		std::cout << std::abs(j) << std::endl;

		lastHeight = cHeight;
		lastWidth = cWidth;

		//columns[0][0] = '0';

		for (std::vector<char>& row : columns) {
			for (char& c : row) {
				buffer += c;
				//std::cout << c;
			}
			//buffer+= '\n';
			
			//std::cout << std::endl;

			std::cout << buffer << std::endl;
			buffer = "";
		}


		std::cout << buffer << std::flush;

		/*std::cout << "maxVectorHeight: " << maxh << std::endl;
		std::cout << "maxVectorWidth: " << maxw << std::endl;*/
		return;
	}
	/*void ReSize(int w, int h) {
		dWidth = w;
		dHeight = h;

		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

		COORD buffer = { (SHORT)w, (SHORT)h };
		SetConsoleScreenBufferSize(hOut, buffer);

		SMALL_RECT windowsize = { 0, 0, (SHORT)(w - 1), (SHORT)(h - 1) };
		SetConsoleWindowInfo(hOut, TRUE, &windowsize);
	}*/
}

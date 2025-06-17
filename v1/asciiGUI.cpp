// asciiGUI.cpp

#include "asciiGUI.h"

int minw = 0;
int minh = 0;

void selfMax(int sW, int sH) {

	minw = (sW > minw) ? sW : minw;
	minh = (sH > minh) ? sH : minh;

}

void allocate(std::vector<std::vector<char>>& array, int aWidth, int aHeight) {

	
	if ((int)array.size() < aHeight) {
		array.resize(aHeight);

	}
	

	for (auto& row : array) {
		if ((int)row.size() < aWidth) {
			row.resize(aWidth, ' ');
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

	int lastHeight = 0;
	int lastWidth = 0;

	void clear() {
		std::cout << "\033[?25l";
		minw = 0;
		minh = 0;
		columns.clear();
		//std::cout << "\033[2J\033[1;1H";
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { (SHORT)0, (SHORT)0 };
		SetConsoleCursorPosition(hOut, pos);

		return;
	}

	void asciiGUI::rect(const char& s, int width, int height, int posx, int posy, const char& fill) {

		int minHeight = posy + height; //account for \n
		
		int minWidth = posx + width;  //account for \n

		allocate(columns, minWidth, minHeight);

		for (int x = posx; x < posx + width; x++) { //top and bottom borders
			columns[posy][x] = s;
			columns[posy + height - 1][x] = s;
		}

		for (int y = posy + 1; y < posy + height - 1; y++) {
			columns[y][posx] = s;
			columns[y][posx + width - 1] = s;

			for (int x = posx + 1; x < posx + width - 1; x++) {
				columns[y][x] = fill;
			}

		}

		

		return;

	}

	void text(const std::string& text, int posx, int posy) {

		int maxX = text.length() + posx;

		allocate(columns, maxX, posy + 1);

		for (char c : text) {
			columns[posy][posx] = c;
			posx++;
		}

	}

	void circle(const char c, int radius, int posx, int posy) {
		
		int minWidth = posx + radius * 2 + 1;
		int minHeight = posy + radius + 1;

		allocate(columns, minWidth, minHeight);
		
		for (int theta = 0; theta < 360; theta++) {
			double rad = theta * (3.14159265 / 180.0);

			int circlePosx = static_cast<int>(std::round(radius * 2 * std::cos(rad)));
			int circlePosy = static_cast<int>(std::round(radius * std::sin(rad)));

			int neoposx = posx - circlePosx;
			int neoposy = posy - circlePosy;
			
			if (neoposx >= 0 && neoposy >= 0) {
				
				columns[neoposy][neoposx] = c;
			}

		}

	}

	void draw() {

		std::string buffer;

		int cHeight = columns.size();
		int cWidth = 0;

		for (auto& row : columns) {
			int rowSize = row.size();
			cWidth = (cWidth > rowSize) ? cWidth : rowSize;
		}

		int maxHeight = std::max(cHeight, lastHeight + 1);
		int maxWidth = std::max(cWidth, lastWidth + 1);

		int remainingHeight = 0;
		if (lastHeight > cHeight) {
			remainingHeight = lastHeight - cHeight;
		}


		lastWidth = cWidth;
		lastHeight = cHeight;

		for (std::vector<char>& row : columns) {
			for (char& c : row) {
				buffer += c;
			}

			std::cout << buffer << "\033[K"  << std::endl;
			buffer = "";
		}

		for (int nline = 0; nline < remainingHeight; nline++) {
			buffer += "\033[K\n";
		}

		std::cout << buffer << std::flush;

		return;
	}
}

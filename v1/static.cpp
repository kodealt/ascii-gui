#include "asciiGUI.h"
#include <vector>
#include <algorithm>
#include <string> //to convert int to str
#include <conio.h> //_kbhit for exit on keypress

int main() {

	asciiGUI::clear();

	asciiGUI::text("showcase, but with a bargraph to show cool (dynamic (?)) stuff", 0, 0);

	std::vector<int> values = { 10, 17, 7, 3, 12 };
	int count = 0;

	for (int& i : values) {
		std::string value = std::to_string(i);
		asciiGUI::text(value, 0, (count * 3) + 3);
		asciiGUI::rect('#', i, 1, 5, (count * 3) + 3);

		int maxVal = 0;
		for (int& j : values) { maxVal = std::max(j, maxVal); }
		asciiGUI::text(value, (count * 4) + 50, maxVal + 4);
		asciiGUI::rect('$', 1, i, (count * 4) + 50, maxVal - i + 3);

		count++;
	}

	asciiGUI::draw();

	// yw

	// btw no circle because, well, its just a circle.

	_getch();
	return 0;

}
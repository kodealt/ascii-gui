#include "asciiGUI.h"
#include <Windows.h> // for Sleep
#include <string>

#include <conio.h> //_kbhit for exit on keypress

int main() {

	int unsigned i = 0; // define frame, unsigned because i cant be negative anyways:
	int frameTime = (1000 / 24); // 1000 because 1000 ms = 1s and 24 is frames per second (i think idk)

	std::string exampleString = "animation showcase";

	while (true) {

		asciiGUI::clear(); // clear for drawing again

		asciiGUI::rect('R', (i % 10) + 1, 5, std::floor((i % 1000) / 10), 5, 'f'); //1000/10 = 100 - 1 (0 indexing) = 99, 1 px shift every 10 frames for 99 times. 

		asciiGUI::circle('C', std::floor((i % 12) / 2) + 1, 14, 20); // essentailly same logic as before, but different at the same time.

		int chars = i % (exampleString.length() + 1);

		asciiGUI::text(exampleString.substr(0, chars), 2, 0);

		asciiGUI::draw();

		if (_kbhit()) {
			_getch();
			break;
		}

		Sleep(frameTime);
		i++;
	}

	// yes anything can be animated you just have to be creative enough

	return 0;

}
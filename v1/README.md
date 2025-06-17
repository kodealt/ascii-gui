# heh. tutorial. heh.

> ##   ver 1: the first good release

>  ok so one: i cant teach for shit so good luck

>  oh yeah btw good luck trying to delete shapes (you cant, you have to clear the screen and re-draw lmao)

###### btw better namespace name suggestions are appreciated  >> [@a_persan] (discord)

```cpp
#include "asciiGUI.h" // incl this tuff thing

int main() {

	// ok there are about 5 commands that you can call with namespace asciiGUI::
	 
	// >> gui edit (?)
	// ::clear(); > clear the screen, useful in loops.
	// ::draw(); > at the end, draw everything thats thats been requested before this. use this at the end.
	
	// >> shapes::
	// ::rect(); > create a rectangle. 
	// -- 6 inputs ::rect(char, int, int, int, int, char).
	// ---- function  :: (border, width, height, position x, position y, fill)
	// -- default:    :: ('#', 3, 3, 0, 0, ' ');
	// ::circle(); > circle.
	// -- 4 inputs ::circle(char, int, int, int).
	// ---- function    :: (border, radius, position x, position y) (no fill, transparent (?))
	// -- default:      :: ('#', 3, 0, 0)
	
	// >> text::
	// ::text(); > text in the render space.
	// -- 3 inputs ::text(string, int, int)
	// ---- function  :: (text, position x, position y)
	// -- default:    :: ("text", 0, 0)

	//ermmmm also yeah the thing is "layering" is based on the order you call them : (later = higher layer)

	// and yeah thats about it. 
	// some things you should keep in mind:
	//
	//
	//
	// ok now here is a showcase
	
	// ok i lied theyre labled animation.cpp (animation.exe) and static.cpp (static.exe)


	return 0;
}
```
#include "Keyboard.h"

/* z, Z		(122, 0), (90, 0)
 * space	(32, 0)
 * up		(224, 72)
 * down		(224, 80)
 * left		(224, 75)
 * right	(224, 77)
 */

int Keyboard::input()
{
	int kb;

	kb = _getch();

	if (kb != 224) {
		_getch();
		switch (kb) {
		case 90:
		case 122:
			return back;
		case 32:
			return drop;
		default:
			exit(1);
		}
	}

	kb = _getch();
	switch (kb) {
	case 72:
		return spin;
	case 80:
		return down;
	case 75:
		return moveLeft;
	case 77:
		return moveRight;
	default:
		exit(1);
	}
}
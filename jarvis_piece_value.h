
#ifndef __JARVIS_PIECE_VALUE_H__
#define __JARVIS_PIECE_VALUE_H__

#include <cctype>

inline int jarvis_piece_value(const char ch) noexcept {

	switch (tolower(ch)) {
		case 'p': return 100;
		case 'n': return 320;
		case 'b': return 330;
		case 'r': return 500;
		case 'q': return 900;
		case 'k': return 100'000;
		default:  return 0;
	}
}

#endif//__JARVIS_PIECE_VALUE_H__
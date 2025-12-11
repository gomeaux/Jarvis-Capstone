
#ifndef __JARVIS_RANDOM_H__
#define __JARVIS_RANDOM_H__

#include <cstdlib>

inline int __fastcall jarvis_random(int min, int max) noexcept {

	return (rand() % (max - min + 1)) + min;
}

#endif
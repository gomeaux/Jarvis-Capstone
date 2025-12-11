
#ifndef __JARVIS_EVALUATE_H__
#define __JARVIS_EVALUATE_H__

#include "jarvis_piece_square_score.h"
#include "jarvis_is_mated.h"
#include "jarvis_random.h"
#include "thc.h"

int jarvis_material_score(const thc::ChessRules& cr) noexcept {

	int mat = 0;
	for (int i = 0; i < 64; i++) {
		const char ch = cr.squares[i];
		const int val = jarvis_piece_value(ch);
		if (isupper(ch)) {
			mat += val;
		}
		else {
			mat -= val;
		}
	}
	return mat;
}

int jarvis_evaluate(thc::ChessRules& cr) noexcept {
	
	int eval = 0;

	if (jarvis_is_mated(cr)) {
		return cr.white ? INT_MAX : INT_MIN;
	}

	eval += jarvis_material_score(cr);
	eval += jarvis_piece_square_score(cr);
	eval += jarvis_random(-50, 50);

	return eval;
}

#endif//__JARVIS_EVALUATE_H__
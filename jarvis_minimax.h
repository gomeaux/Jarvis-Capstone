
#ifndef __JARVIS_MINIMAX_H__
#define __JARVIS_MINIMAX_H__

#include "jarvis_evaluate.h"
#include "thc.h"

int __fastcall jarvis_minimax(thc::ChessRules& cr, unsigned int depth, int alpha, int beta, bool is_maximizing) noexcept {

	thc::MOVELIST moves;

	cr.GenLegalMoveList(&moves);

	if (depth == 0 || moves.count <= 0) {
		return jarvis_evaluate(cr);
	}

	if (is_maximizing) { // White's move
		int max_eval = INT_MIN;
		for (int i = 0; i < moves.count; i++) {
			thc::Move mv = moves.moves[i];
			cr.PushMove(mv);
			int eval = jarvis_minimax(cr, depth - 1, alpha, beta, !is_maximizing);
			cr.PopMove(mv);
			max_eval = (eval > max_eval) ? eval : max_eval;
			alpha = (alpha > eval) ? alpha : eval;
			if (beta <= alpha) {
				break;
			}
		}
		return max_eval;
	}

	else { // Black's move
		int min_eval = INT_MAX;
		for (int i = 0; i < moves.count; i++) {
			thc::Move mv = moves.moves[i];
			cr.PushMove(mv);
			int eval = jarvis_minimax(cr, depth - 1, alpha, beta, !is_maximizing);
			cr.PopMove(mv);
			min_eval = (eval < min_eval) ? eval : min_eval;
			beta = (beta < eval) ? beta : eval;
			if (beta <= alpha) {
				break;
			}
		}
		return min_eval;
	}
}

#endif//__JARVIS_MINIMAX_H__
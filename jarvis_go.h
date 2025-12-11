
#ifndef __JARVIS_GO_H__
#define __JARVIS_GO_H__

#include <chrono>
#include "jarvis_minimax.h"
#include "thc.h"

bool jarvis_go(thc::ChessRules& cr, unsigned int depth) noexcept {

	int alpha = INT_MIN;
	int beta = INT_MAX;
	int best_eval = cr.white ? INT_MIN : INT_MAX;
	thc::MOVELIST moves;
	thc::Move best_move;

	cr.GenLegalMoveList(&moves);

	// begin timer
	auto start = std::chrono::high_resolution_clock::now();

	if (moves.count <= 0) {
		return false;
	}
	best_move = moves.moves[0];

	for (int i = 0; i < moves.count; i++) {
		
		thc::Move curr_move = moves.moves[i];

		thc::ChessRules copy = cr;
		copy.PlayMove(curr_move);

		// check if the other side is in mate
		//{
		//	std::vector<thc::Move> otherside_moves;
		//	copy.GenLegalMoveList(otherside_moves);
		//	if (otherside_moves.empty()) {
		//
		//		// enemy now has 0 moves. Check find OUR king and see if under attack
		//		const char king = cr.white ? 'k' : 'K';
		//		for (int i = 0; i < 64; i++) {
		//			if (copy.squares[i] == king) {
		//				if (copy.AttackedSquare((thc::Square)i, cr.white)) {
		//					best_move = curr_move;
		//					best_eval = cr.white ? INT_MAX : INT_MIN;
		//					std::printf("Mate found at %s (Eval %d)\n", best_move.TerseOut().c_str(), best_eval);
		//					goto PLAYBESTMOVE;
		//				}
		//			}
		//		}
		//	}
		//}
		int curr_eval = jarvis_minimax(copy, depth - 1, alpha, beta, false);

		// whites move
		if (cr.white) {
			if (curr_eval > best_eval) {
				best_eval = curr_eval;
				best_move = curr_move;
			}
		}

		else { // blacks move
			if (curr_eval < best_eval) {
				best_eval = curr_eval;
				best_move = curr_move;
			}
		}
	}

	PLAYBESTMOVE:
	std::printf("bestmove %s\n", best_move.TerseOut().c_str());

	// end time, print duration
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = end - start;
	std::printf("Total time: %.2lf ms\n", duration.count());

	return true;
}

#endif
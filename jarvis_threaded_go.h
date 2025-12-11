
#ifndef __JARVIS_THREADED_GO_H__
#define __JARVIS_THREADED_GO_H__

#include <thread>
#include <vector>
#include <mutex>
#include <limits>
#include <atomic>

#include "jarvis_minimax.h"

void jarvis_threaded_search(const thc::ChessRules &cr, thc::Move curr_move, int depth, std::atomic<int>& best_eval, thc::Move& best_move, std::mutex& mutex) {

	thc::ChessRules copy = cr;
	int curr_eval;

	copy.PlayMove(curr_move);

	std::printf("Evaluating %s... ", curr_move.TerseOut().c_str());
	curr_eval = jarvis_minimax(copy, depth - 1, INT_MIN, INT_MAX, !copy.white); 
	std::printf("%d\n", curr_eval);

	std::lock_guard<std::mutex> lock(mutex);

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

bool jarvis_threaded_go(thc::ChessRules& cr, unsigned int depth) {

	thc::MOVELIST            moves;
	std::vector<std::thread> threads;
	std::mutex               mutex;
	std::atomic<int>         best_eval;
	thc::Move                best_move;

	threads.reserve(64);

	cr.GenLegalMoveList(&moves);
	if (moves.count <= 0) {
		return false;
	}
	else if (depth == 0) {
		return jarvis_evaluate(cr);
	}
	best_move = moves.moves[0];

	std::printf("Evaluating %d moves.\n", moves.count);

	for (int i = 0; i < moves.count; i++) {

		const thc::Move curr_move = moves.moves[i];
		threads.emplace_back(jarvis_threaded_search, std::ref(cr), curr_move, depth, std::ref(best_eval), std::ref(best_move), std::ref(mutex));
		threads.back().join();
	}

	std::printf("bestmove %s\n", best_move.TerseOut().c_str());

	return true;
}

#endif//__JARVIS_THREADED_GO_H__
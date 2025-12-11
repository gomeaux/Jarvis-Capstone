
#ifndef __JARVIS_POSITION_H__
#define __JARVIS_POSITION_H__

#include <string>
#include <sstream>

#include "thc.h"

#define INITIAL_FEN ("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1")

bool jarvis_position(thc::ChessRules& cr, const std::string& input) noexcept {

	std::string token;
	std::stringstream ss(input);

	if (!(ss >> token) || token != "position") {
		return false;
	}
	if (!(ss >> token)) {
		return false;
	}
	else if (token == "fen") {
		std::string fen = "";
		for (int i = 0; i < 6; i++) {
			if (!(ss >> token)) {
				return false;
			}
			fen.append(token);
			fen.append(" ");
		}
		if (!cr.Forsyth(fen.c_str())) {
			return false;
		}
	}
	else if (token == "startpos") {
		cr.Forsyth(INITIAL_FEN);
	}
	else {
		return false;
	}

	if ((ss >> token) && token == "moves") {

		while (ss >> token) {

			thc::Move move;
			if (!move.TerseIn(&cr, token.c_str())) {
				return false;
			}

			cr.PlayMove(move);
		}
	}

	return true;
}

#endif//__JARVIS_POSITION_H__
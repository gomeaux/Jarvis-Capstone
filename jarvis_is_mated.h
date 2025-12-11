
#ifndef __JARVIS_IS_MATED_H__
#define __JARVIS_IS_MATED_H__

#include "thc.h"

// Checks for mate in the current position
// Perhaps call this during the evaluation stage, not during minimax?
inline bool __fastcall jarvis_is_mated(thc::ChessRules& cr) noexcept {

	// Check if the king is under attack
	thc::MOVELIST move_list;
	const char king = (cr.white) ? 'K' : 'k';
	for (int i = 0; i < 64; i++) {

		// King is found!
		if (cr.squares[i] == king) {

			cr.GenLegalMoveList(&move_list);

			// Mate requires king under attack, and no legal moves left.
			return cr.AttackedPiece((thc::Square)i) && move_list.count <= 0;
		}
	}

	return false;
}

#endif//__JARVIS_IS_MATED_H_
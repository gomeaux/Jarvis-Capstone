
#ifndef __JARVIS_PIECE_SQUARE_SCORE_H__
#define __JARVIS_PIECE_SQUARE_SCORE_H__

#include <array>
#include "jarvis_piece_value.h"
#include "thc.h"

#define JARVIS_MIRROR_INDEX(sq) ( ((7 - (sq / 8)) * 8) + (sq % 8) )

constexpr std::array<int, 64> pawn_table_mg = {
	 0,  0,  0,  0,  0,  0,  0,  0,
  50, 50, 50, 50, 50, 50, 50, 50,
  10, 10, 20, 30, 30, 20, 10, 10,
   5,  5, 10, 25, 25, 10,  5,  5,
   0,  0,  0, 20, 20,  0,  0,  0,
   5, -5,-10,  0,  0,-10, -5,  5,
   5, 10, 10,-20,-20, 10, 10,  5,
   0,  0,  0,  0,  0,  0,  0,  0
};

constexpr std::array<int, 64> pawn_table_eg = {
   0,  0,  0,  0,  0,  0,  0,  0,
  10, 10, 10, 10, 10, 10, 10, 10,
   5,  5, 10, 15, 15, 10,  5,  5,
   0,  0,  0, 20, 20,  0,  0,  0,
   5,  5, 10, 25, 25, 10,  5,  5,
  10, 10, 20, 30, 30, 20, 10, 10,
  20, 20, 30, 40, 40, 30, 20, 20,
   0,  0,  0,  0,  0,  0,  0,  0
};

constexpr std::array<int, 64> knight_table_mg = {
   -50,-40,-30,-30,-30,-30,-40,-50,
   -40,-20,  0,  0,  0,  0,-20,-40,
   -30,  0, 10, 15, 15, 10,  0,-30,
   -30,  5, 15, 20, 20, 15,  5,-30,
   -30,  0, 15, 20, 20, 15,  0,-30,
   -30,  5, 10, 15, 15, 10,  5,-30,
   -40,-20,  0,  5,  5,  0,-20,-40,
   -50,-40,-30,-30,-30,-30,-40,-50
};

constexpr std::array<int, 64> knight_table_eg = {
   -40,-30,-20,-20,-20,-20,-30,-40,
   -30,-10, 10, 15, 15, 10,-10,-30,
   -20, 10, 20, 25, 25, 20, 10,-20,
   -20, 15, 25, 30, 30, 25, 15,-20,
   -20, 15, 25, 30, 30, 25, 15,-20,
   -20, 10, 20, 25, 25, 20, 10,-20,
   -30,-10, 10, 15, 15, 10,-10,-30,
   -40,-30,-20,-20,-20,-20,-30,-40
};

constexpr std::array<int, 64> bishop_table_mg = {
   -20,-10,-10,-10,-10,-10,-10,-20,
   -10,  5,  0,  0,  0,  0,  5,-10,
   -10, 10, 10, 10, 10, 10, 10,-10,
   -10,  0, 10, 10, 10, 10,  0,-10,
   -10,  5,  5, 10, 10,  5,  5,-10,
   -10,  0,  5, 10, 10,  5,  0,-10,
   -10,  0,  0,  0,  0,  0,  0,-10,
   -20,-10,-10,-10,-10,-10,-10,-20
};

constexpr std::array<int, 64> bishop_table_eg = {
   -10, -5, -5, -5, -5, -5, -5,-10,
    -5, 10,  0,  0,  0,  0, 10, -5,
    -5,  0, 15, 10, 10, 15,  0, -5,
    -5,  5, 10, 20, 20, 10,  5, -5,
    -5,  5, 10, 20, 20, 10,  5, -5,
    -5,  0, 15, 10, 10, 15,  0, -5,
    -5, 10,  0,  0,  0,  0, 10, -5,
   -10, -5, -5, -5, -5, -5, -5,-10
};

constexpr std::array<int, 64> rook_table_mg = {
     0,  0,  5, 10, 10,  5,  0,  0,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
     5, 10, 10, 10, 10, 10, 10,  5,
     0,  0,  0,  0,  0,  0,  0,  0
};

constexpr std::array<int, 64> rook_table_eg = {
     0,  0,  5, 10, 10,  5,  0,  0,
     0,  0, 10, 15, 15, 10,  0,  0,
    -5,  0, 10, 20, 20, 10,  0, -5,
    -5,  0, 10, 20, 20, 10,  0, -5,
    -5,  0, 10, 20, 20, 10,  0, -5,
    -5,  0, 10, 20, 20, 10,  0, -5,
     0,  0, 10, 15, 15, 10,  0,  0,
     0,  0,  5, 10, 10,  5,  0,  0
};

constexpr std::array<int, 64> queen_table_mg = {
   -20,-10,-10, -5, -5,-10,-10,-20,
   -10,  0,  0,  0,  0,  0,  0,-10,
   -10,  0,  5,  5,  5,  5,  0,-10,
    -5,  0,  5,  5,  5,  5,  0, -5,
     0,  0,  5,  5,  5,  5,  0, -5,
   -10,  5,  5,  5,  5,  5,  0,-10,
   -10,  0,  5,  0,  0,  0,  0,-10,
   -20,-10,-10, -5, -5,-10,-10,-20
};

constexpr std::array<int, 64> queen_table_eg = {
   -10,-10,-10, -5, -5,-10,-10,-10,
   -10,  0,  0,  0,  0,  0,  0,-10,
   -10,  0,  5,  5,  5,  5,  0,-10,
    -5,  0,  5,  5,  5,  5,  0, -5,
     0,  0,  5,  5,  5,  5,  0, -5,
   -10,  5,  5,  5,  5,  5,  0,-10,
   -10,  0,  5,  0,  0,  0,  0,-10,
   -10,-10,-10, -5, -5,-10,-10,-10
};

constexpr std::array<int, 64> king_table_mg = {
   -30,-40,-40,-50,-50,-40,-40,-30,
   -30,-40,-40,-50,-50,-40,-40,-30,
   -30,-40,-40,-50,-50,-40,-40,-30,
   -30,-40,-40,-50,-50,-40,-40,-30,
   -20,-30,-30,-40,-40,-30,-30,-20,
   -10,-20,-20,-20,-20,-20,-20,-10,
    20, 20,  0,  0,  0,  0, 20, 20,
    20, 30, 10,  0,  0, 10, 30, 20
};

constexpr std::array<int, 64> king_table_eg = {
   -50,-40,-30,-20,-20,-30,-40,-50,
   -30,-20,-10,  0,  0,-10,-20,-30,
   -30,-10, 20, 30, 30, 20,-10,-30,
   -30,-10, 30, 40, 40, 30,-10,-30,
   -30,-10, 30, 40, 40, 30,-10,-30,
   -30,-10, 20, 30, 30, 20,-10,-30,
   -30,-30,  0,  0,  0,  0,-30,-30,
   -50,-30,-30,-30,-30,-30,-30,-50
};

inline bool jarvis_is_endgame(const thc::ChessRules& cr) noexcept {

    int       total      = 0;
    const int PAWN_VAL   = jarvis_piece_value('p');
    const int KNIGHT_VAL = jarvis_piece_value('n');
    const int BISHOP_VAL = jarvis_piece_value('b');
    const int ROOK_VAL   = jarvis_piece_value('r');
    const int QUEEN_VAL  = jarvis_piece_value('q');
    unsigned int pawn_count   = 0;
    unsigned int knight_count = 0;
    unsigned int bishop_count = 0;
    unsigned int rook_count   = 0;
    unsigned int queen_count  = 0;

    for (int i = 0; i < 64; i++) {

        const char ch = cr.squares[i];

        switch (tolower(ch)) {
            case 'p': pawn_count++;   break;
            case 'n': knight_count++; break;
            case 'b': bishop_count++; break;
            case 'r': rook_count++;   break;
            case 'q': queen_count++;  break;
        }
    }

    total =
        pawn_count * PAWN_VAL +
        knight_count * KNIGHT_VAL +
        bishop_count * BISHOP_VAL +
        rook_count * ROOK_VAL +
        queen_count * QUEEN_VAL;

    return total < 1300; // endgame threshold
}

int jarvis_piece_square_score(const thc::ChessRules& cr) noexcept {

	int eval = 0;
    const bool is_endgame = jarvis_is_endgame(cr);

    if (cr.white) {
        if (is_endgame) {
            for (int i = 0; i < 64; i++) {
                switch (tolower(cr.squares[i])) {
                    case 'p': eval += pawn_table_eg[i];   break;
                    case 'n': eval += knight_table_eg[i]; break;
                    case 'b': eval += bishop_table_eg[i]; break;
                    case 'r': eval += rook_table_eg[i];   break;
                    case 'q': eval += queen_table_eg[i];  break;
                    case 'k': eval += king_table_eg[i];   break;
                }
            }
        }
        else { // middlegame
            for (int i = 0; i < 64; i++) {
                switch (tolower(cr.squares[i])) {
                    case 'p': eval += pawn_table_mg[i];   break;
                    case 'n': eval += knight_table_mg[i]; break;
                    case 'b': eval += bishop_table_mg[i]; break;
                    case 'r': eval += rook_table_mg[i];   break;
                    case 'q': eval += queen_table_mg[i];  break;
                    case 'k': eval += king_table_mg[i];   break;
                }
            }
        }
    }
    else { // Black's POV
        if (is_endgame) {
            for (int i = 0; i < 64; i++) {
                switch (tolower(cr.squares[JARVIS_MIRROR_INDEX(i)])) {
                    case 'p': eval += pawn_table_eg[JARVIS_MIRROR_INDEX(i)];   break;
                    case 'n': eval += knight_table_eg[JARVIS_MIRROR_INDEX(i)]; break;
                    case 'b': eval += bishop_table_eg[JARVIS_MIRROR_INDEX(i)]; break;
                    case 'r': eval += rook_table_eg[JARVIS_MIRROR_INDEX(i)];   break;
                    case 'q': eval += queen_table_eg[JARVIS_MIRROR_INDEX(i)];  break;
                    case 'k': eval += king_table_eg[JARVIS_MIRROR_INDEX(i)];   break;
                }
            }
        }
        else { // middlegame
            for (int i = 0; i < 64; i++) {
                switch (tolower(cr.squares[i])) {
                    case 'p': eval += pawn_table_mg[JARVIS_MIRROR_INDEX(i)];   break;
                    case 'n': eval += knight_table_mg[JARVIS_MIRROR_INDEX(i)]; break;
                    case 'b': eval += bishop_table_mg[JARVIS_MIRROR_INDEX(i)]; break;
                    case 'r': eval += rook_table_mg[JARVIS_MIRROR_INDEX(i)];   break;
                    case 'q': eval += queen_table_mg[JARVIS_MIRROR_INDEX(i)];  break;
                    case 'k': eval += king_table_mg[JARVIS_MIRROR_INDEX(i)];   break;
                }
            }
        }
    }

	return eval;
}

#endif//__JARVIS_PIECE_SQUARE_SCORE_H__
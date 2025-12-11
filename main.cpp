
#include <iostream>
#include <string>
#include <thread>

#include "jarvis_go.h"
#include "jarvis_threaded_go.h"
#include "jarvis_position.h"
#include "thc.h"

int main(int argc, char** argv) {

	std::string input;
	thc::ChessRules chess;
	unsigned int depth = 6;

	std::ios::sync_with_stdio(true);
	srand(time(NULL));

	while (true) {

		std::getline(std::cin, input);

		if (input == "quit") {
			break;
		}

		else if (input == "isready") {
			std::puts("id name Jarvis");
			std::puts("id author Austin Comeaux");
			std::puts("readyok");
		}

		else if (input == "uci") {
			std::puts("uciok");
		}

		else if (input == "ucinewgame") {
			chess.Forsyth(INITIAL_FEN);
		}

		else if (input.rfind("position", 0) == 0) {
			
			if (!jarvis_position(chess, input)) {
				std::puts("Position command failed.");
				break;
			}
		}

		else if (input.rfind("go", 0) == 0) {

			if (!jarvis_threaded_go(chess, depth)) {
				std::puts("Go command failed!");
				break;
			}
		}

		else {
			std::printf("Unsupported command: %s\n", input.c_str());
		}
	}

	// End
	return 0;
}
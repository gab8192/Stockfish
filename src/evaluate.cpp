#include "evaluate.h"

#include <iostream>

namespace Stockfish {

namespace Eval {

  Value evaluate(Position& pos) {

    Value score = NNUE::evaluate(pos, pos.accumStack[pos.accumStackHead]);

    int phase =  3 * popcount(pos.pieces(KNIGHT))
               + 3 * popcount(pos.pieces(BISHOP))
               + 5 * popcount(pos.pieces(ROOK))
               + 12 * popcount(pos.pieces(QUEEN));    

    score = score * (200 + phase) / 256;

    // Make sure the evaluation does not mix with guaranteed win/loss scores
    score = std::clamp(score, VALUE_TB_LOSS_IN_MAX_PLY + 1, VALUE_TB_WIN_IN_MAX_PLY - 1);

    return score;
  }
}

}
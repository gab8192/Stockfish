#pragma once

#include "position.h"

namespace Stockfish {

class Position;

namespace Eval {

  /// <returns> A value relative to the side to move </returns>
  Value evaluate(Stockfish::Position& pos);
}
}
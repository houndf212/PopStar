#ifndef BOARD_H
#define BOARD_H
#include <memory>
#include "rng.h"
#include "matrix.h"

class Board
{
    friend class BoardHelper;
public:
    static const int Blank = 0;
    void reset(int colorNum);
    int click(Pos p);
public:
    Matrix m;
    Matrix gm;
};

#endif // BOARD_H

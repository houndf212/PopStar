#ifndef BOARDHELPER_H
#define BOARDHELPER_H
#include "board.h"
#include "posset.h"

class BoardHelper
{
public:
    //判断
    static bool isOver(const Board& b);
    static PosSet getSameAdjacency(const Matrix& m, Pos p);
    static PosSet getSameSet(const Board& b, Pos p);
    static PosSet getSameSet_r(const Matrix& m, const PosSet& as, Pos p);
};



#endif // BOARDHELPER_H

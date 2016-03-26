#include "board.h"
#include "matrixgenerator.h"

void Board::reset(int colorNum)
{
    MatrixGenerator::gen(m, colorNum);
}

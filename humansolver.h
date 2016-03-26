#ifndef HUMANSOLVER_H
#define HUMANSOLVER_H
#include "matrix.h"
#include "scorecalc.h"

class HumanSolver
{
public:
    static ScoreCalc solve(Matrix m);
private:
    static int clickPos(Matrix& m, Pos p);
};

#endif // HUMANSOLVER_H

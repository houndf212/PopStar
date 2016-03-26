#include "rndsolver.h"
#include <chrono>
#include <algorithm>
#include "matrixslice.h"
#include "matrixgame.h"

RNDSolver::RNDSolver()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    rng.seed(seed);
}

ScoreCalc RNDSolver::solve(Matrix m, ScoreCalc calc)
{
    while(true)
    {
        MatrixSlice s(m);
        if (s.isOver())
            break;

        int r = std::uniform_int_distribution<int>(0, s.getMovesCount()-1)(rng);
        Group g = s.getGroup(r);
        Pos p = g.front();
        Matrix::value_type v = m(p);
        int n = MatrixGame::removePosSet(m, g);
        calc.put(p, v, n);
    }
    return calc;
}


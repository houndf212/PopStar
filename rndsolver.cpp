#include "rndsolver.h"
#include <chrono>
#include <algorithm>
#include "matrixslice.h"
#include "matrixgame.h"
#include "maxfinder.h"

RNDSolver::RNDSolver()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    rng.seed(seed);
}

ScoreCalc RNDSolver::solve(Matrix m, ScoreCalc calc, int left)
{
    while(true)
    {
        MatrixSlice s(m);
        if (s.isOver())
            break;

        int mc = s.getMovesCount();
        if (mc>left)
        {
            int r = std::uniform_int_distribution<int>(0, mc-1)(rng);
            Group g = s.getGroup(r);
            Pos p = g.front();
            Matrix::value_type v = m(p);
            int n = MatrixGame::removePosSet(m, g);
            calc.put(p, v, n);
        }
        else
        {
            MaxFinder finder;
            return finder.findMax(m, calc);
        }
    }
    return calc;
}


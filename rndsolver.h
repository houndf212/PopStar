#ifndef RNDSOLVER_H
#define RNDSOLVER_H
#include "matrix.h"
#include "scorecalc.h"
#include <random>

class RNDSolver
{
public:
    RNDSolver();
    ScoreCalc solve(Matrix m, ScoreCalc calc);
private:
    std::default_random_engine rng;
};

#endif // RNDSOLVER_H

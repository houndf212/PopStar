#ifndef MAXSOLVER_H
#define MAXSOLVER_H

#include "matrix.h"
#include "scorecalccontainer.h"
#include <random>

class MaxSolver
{
public:
    ScoreCalc solve(const Matrix& m, const ScoreCalc& calc);
private:
    void solve_r(const Matrix &m, const ScoreCalc &score);
public:
    ScoreCalcContainer container;
};

#endif // MAXSOLVER_H

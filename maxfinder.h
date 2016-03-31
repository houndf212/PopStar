#ifndef MAXFINDER_H
#define MAXFINDER_H
#include "matrix.h"
#include "scorecalc.h"

class MaxFinder
{
public:
    ScoreCalc findMax(const Matrix& m, const ScoreCalc &calc);
private:
    void solve_r(const Matrix &m, const ScoreCalc &score);
private:
    ScoreCalc max_score;
private:
    int count;
};

#endif // MAXFINDER_H

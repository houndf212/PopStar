#ifndef CREATELENGTHSOLVER_H
#define CREATELENGTHSOLVER_H

#include "matrixslice.h"
#include "scorecalccontainer.h"

class CreateLengthSolver
{
public:
    ScoreCalc solve(Matrix m, ScoreCalc calc, int color);
private:
    GroupContainer removeChoice(const Matrix&m, const MatrixSlice& s) const;
    bool checkNeedRemove(const Matrix& m, const MatrixSlice& s) const;
    GroupContainer removeColor(const Matrix& m, const GroupContainer& moves) const;

    void solve_r(const Matrix& m, const ScoreCalc& score);
private:
    int max_color_size;
    int solve_color;
    ScoreCalcContainer container;
private:
    static int getColors(const Matrix& m, int color);
};

#endif // CREATELENGTHSOLVER_H

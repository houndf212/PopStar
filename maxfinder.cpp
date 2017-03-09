#include "maxfinder.h"
#include "matrixslice.h"
#include "matrixgame.h"
#include <iostream>
using namespace std;

ScoreCalc MaxFinder::findMax(const Matrix &m, const ScoreCalc& calc)
{
    count = 0;
    max_score = calc;
    solve_r(m, calc);
    cout<<"max finder: "<<count<<endl;
    return max_score;
}

void MaxFinder::solve_r(const Matrix &m, const ScoreCalc &score)
{
    MatrixSlice s(m);

    if (s.isOver())
    {
        ++count;
        if (max_score < score)
            max_score = score;
    }
    else
    {
        auto moves = s.getAllGroups();
        for (auto it=moves.cbegin(); it!=moves.cend(); ++it)
        {
            Pos p = (*it).front();
            Matrix::value_type v = m.get(p);
            Matrix lm = m;
            ScoreCalc sc = score;
            int n = MatrixGame::removePosSet(lm, *it);
            sc.put(p, v, n);
            solve_r(lm, sc);
        }
    }
}

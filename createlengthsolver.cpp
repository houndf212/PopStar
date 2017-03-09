#include "createlengthsolver.h"
#include "matrixslice.h"
#include "matrixgame.h"
#include <thread>
#include <algorithm>
using namespace std;

ScoreCalc CreateLengthSolver::solve(Matrix m, ScoreCalc calc, int color)
{
    solve_color = color;
    max_color_size = getColors(m, solve_color);
    MatrixSlice s(m);
    if (s.isOver())
        return calc;

    container.setPrintStep(10*10000);

    auto moves = removeChoice(m, s);
    cout << "first moves size: "<<moves.size()<<endl;
    solve_r(m, calc);
    return container.maxList.front();
}

GroupContainer CreateLengthSolver::removeChoice(const Matrix &m, const MatrixSlice &s) const
{
    if ( s.getMovesCount()==1 || !checkNeedRemove(m, s))
        return s.getAllGroups();
    else
    {
        GroupContainer g = s.getAllGroups();
        return removeColor(m, g);
    }
}

bool CreateLengthSolver::checkNeedRemove(const Matrix &m, const MatrixSlice &s) const
{
    if (s.getMovesCount() < 20)
        return false;
    else
    {
        return true;
    }
}

GroupContainer CreateLengthSolver::removeColor(const Matrix &m, const GroupContainer &moves) const
{
    GroupContainer ret;
    for (auto it=moves.cbegin(); it!=moves.cend(); ++it)
    {
        if (m.get((*it).front()) != solve_color)
            ret.push_back(*it);
    }
    if (ret.empty())
        return moves;
    else
        return ret;
}

void CreateLengthSolver::solve_r(const Matrix &m, const ScoreCalc &score)
{
    MatrixSlice s(m);

    if (s.isOver())
    {
        container.addScoreCalc(score);
    }
    else
    {
        auto moves = removeChoice(m, s);
        std::random_shuffle(moves.begin(), moves.end());
        for (auto it=moves.cbegin(); it!=moves.cend(); ++it)
        {
            Pos p = (*it).front();
            auto v = m.get(p);
            Matrix lm = m;
            ScoreCalc sc = score;
            int n = MatrixGame::removePosSet(lm, *it);
            sc.put(p ,v, n);
            solve_r(lm, sc);
        }
    }
}

int CreateLengthSolver::getColors(const Matrix &m, int color)
{
    int ret = 0;
    for (int r=0; r<m.row_size(); ++r)
        for(int c=0; c<m.col_size(); ++c)
        {
            if (m.get(Pos(r, c)) == color)
                ++ret;
        }

    return ret;
}


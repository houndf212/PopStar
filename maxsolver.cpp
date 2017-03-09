#include "maxsolver.h"
using namespace std;
#include "matrixslice.h"
#include "matrixgame.h"
#include <thread>
#include <algorithm>

ScoreCalc MaxSolver::solve(const Matrix &m, const ScoreCalc &calc)
{
    MatrixSlice s(m);
    if (s.isOver())
        return calc;

    container.setPrintStep(100*10000);
    cout << "first moves size: "<<s.getMovesCount()<<endl;
    auto moves = s.getAllGroups();
    std::vector<std::thread> threads;
    for (auto it=moves.cbegin(); it!=moves.cend(); ++it)
    {
        Pos p = (*it).front();
        Matrix::value_type v = m.get(p);
        Matrix lm = m;
        ScoreCalc sc = calc;
        int n = MatrixGame::removePosSet(lm, *it);
        sc.put(p, v, n);
        threads.push_back(std::thread(&MaxSolver::solve_r, this, lm, sc));
    }
    for (auto& th : threads) th.join();

    return container.maxList.front();
}

void MaxSolver::solve_r(const Matrix& m, const ScoreCalc& score)
{
    MatrixSlice s(m);

    if (s.isOver())
    {
        container.addScoreCalc(score);
    }
    else
    {
        auto moves = s.getAllGroups();
        // strategy here!
        std::reverse(moves.begin(), moves.end());
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

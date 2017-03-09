#include "humansolver.h"
#include <iostream>
using namespace std;

#include "matrixslice.h"
#include "matrixgame.h"

ScoreCalc HumanSolver::solve(Matrix m)
{
    ScoreCalc calc;
    while(true)
    {
        cout << m ;
        MatrixSlice s(m);
        if (s.isOver())
            break;

        int num=0;
        Matrix::value_type v;
        Pos p;
        do
        {
            cin >> p;
            v = m.get(p);
            num = clickPos(m, p);
            if (num == 0)
                cout<< "wrong point, try again!"<<endl;
        }while(num == 0);
        calc.put(p, v, num);
    }
    cout<< m;
    cout << calc << endl;
    return calc;
}

int HumanSolver::clickPos(Matrix &m, Pos p)
{
    if (!m.isInMatrix(p))
        return 0;

    MatrixSlice s(m);
    if (!s.canClick(p))
        return 0;

    Group ps = s.getGroup(p);
    return MatrixGame::removePosSet(m, ps);
}


#include <iostream>
#include <chrono>
#include <list>
#include <algorithm>
#include <string.h>
#include <thread>
#include <atomic>
using namespace std;

#include "matrixslice.h"
#include "matrixgenerator.h"
#include "matrixgame.h"
#include "scorecalc.h"
#include "humansolver.h"
#include "maxsolver.h"
#include "matrixinput.h"
#include "rndsolver.h"
#include "createlengthsolver.h"

void testCalAll(Matrix m)
{
    cout<<m;
    typedef chrono::high_resolution_clock::time_point timepoint;
    typedef chrono::high_resolution_clock::duration duration;
    timepoint t1 = chrono::high_resolution_clock::now();

    MaxSolver sl;
    auto sc = sl.solve(m, ScoreCalc());
    cout<<sc<<endl;
    int64_t sum = sl.container.counter;

    timepoint t2 = chrono::high_resolution_clock::now();
    duration d = t2-t1;
    cout <<"time: "<<chrono::duration_cast<chrono::milliseconds>(d).count()<<endl;
    double all = chrono::duration_cast<chrono::milliseconds>(d).count();

    cout <<"sum: "<<sum<<", avg: "<<all/sum<<endl;
}
void testRandSolve(Matrix m)
{
    int k=5*1;
    ScoreCalcContainer container;
    container.setPrintStep(1*2);
    RNDSolver solver;
    cout << m;
//    while (k-->0)
//    {
//        container.addScoreCalc(solver.solve(m, ScoreCalc(), 5));
//    }
    cout << solver.solve(m, ScoreCalc(), 3);

}

void testLengthSolve(Matrix m)
{
    cout << m;
    CreateLengthSolver s;
    s.solve(m, ScoreCalc() , 2);
}

int main()
{
    string str =
            "PYPGPGGRPG"
            "RBRBPYBGPG"
            "BBGYRBRRYB"
            "PBGYYRGBGG"
            "RPRBGGPGBB"
            "YBYBGBYYGP"
            "RGGGYBBYBG"
            "YRYYBYRGBB"
            "GRBGRRPGYY"
            "GPRGRGBBBP"
            ;
    Matrix m = MatrixInput::fromString(str);
//    m = MatrixGenerator::gen();
    cout << HumanSolver::solve(m)<<endl;
    testRandSolve(m);
//    cout<<m;
//    testCalAll(m);
//    testLengthSolve(m);
//    testThread();
    cout<<"exit!"<<endl;
    return 0;
}


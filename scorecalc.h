#ifndef SCORECALC_H
#define SCORECALC_H
#include <list>
#include <tuple>
#include <iostream>
#include "pos.h"
#include "matrix.h"

class ScoreCalc
{
    friend std::ostream& operator<<(std::ostream& os, const ScoreCalc& sc);
    typedef std::list<std::tuple<Pos, Matrix::value_type, int>> ClickList;
public:
    void put(Pos p, Matrix::value_type v, int n);
    int geScore() const;
private:
    ClickList lst;
};

std::ostream& operator<<(std::ostream& os, const ScoreCalc& sc);

#endif // SCORECALC_H

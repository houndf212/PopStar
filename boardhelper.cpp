#include "boardhelper.h"
#include "posset.h"

bool BoardHelper::isOver(const Board &b)
{
    const Matrix& m = b.m;
    for (int r=0; r<m.row_size(); ++r)
    {
        for(int c=0; c<m.col_size(); ++c)
        {
            PosSet s = getSameAdjacency(m, Pos(r, c));
            if (!s.empty())
                return false;
        }
    }
    return true;
}

PosSet BoardHelper::getSameAdjacency(const Matrix &m, Pos p)
{
    PosSet ret;
    assert(m.isInMatrix(p));

    int v = m(p);
    if (v != Board::Blank)
    {
        auto func = [&m, &ret](Pos p, int val)
        {
            if (m.isInMatrix(p) && m(p) == val)
                ret.insert(p);
        };

        func(Pos(p.row, p.col-1), v);
        func(Pos(p.row, p.col+1), v);
        func(Pos(p.row-1, p.col), v);
        func(Pos(p.row+1, p.col), v);
    }
    return ret;
}

PosSet BoardHelper::getSameSet(const Board &b, Pos p)
{
    PosSet ret;
    const Matrix& m = b.m;
    assert(m.isInMatrix(p));
    int v = m(p);
    if (v!=Board::Blank)
    {
        PosSet so;
        so.insert(p);
//        PosSet sn = getSameAdjacency(p);

    }
    return ret;
}

PosSet BoardHelper::getSameSet_r(const Matrix &m, const PosSet &as, Pos p)
{
    PosSet s = getSameAdjacency(m, p);
    return s - as;
}



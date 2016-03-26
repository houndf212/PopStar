#include "matrixslice.h"
using namespace std;

MatrixSlice::MatrixSlice(const Matrix &m)
{
    slice(m);
}

bool MatrixSlice::isOver() const
{
    return groupVec.empty();
}

bool MatrixSlice::canClick(Pos p) const
{
    assert(slicematrix.isInMatrix(p));
    int group = slicematrix(p);
    return group > Matrix_Alone_Pos;
}

Group MatrixSlice::getGroup(Pos p) const
{
    assert(slicematrix.isInMatrix(p));
    int group = slicematrix(p);
    return groupVec[group-Matrix_Alone_Pos-1];
}

void MatrixSlice::slice(const Matrix &m)
{
    unFlagAll();
    int groupNum = Matrix_Alone_Pos + 1;
    for (int r=0; r<m.row_size(); ++r)
    {
        for (int c=0; c<m.col_size(); ++c)
        {
            Pos p(r, c);
            if (isFlaged(p))
                continue;

            if (m(p) == Matrix_Blank)
            {
                slicematrix(p) = Matrix_Blank;
            }
            else
            {
                 Group s;
                 seedPos(m, p, &s, m(p), groupNum);
                 if (s.size() == 1)
                 {
                     assert (s.front() == p);
                     slicematrix(p) = Matrix_Alone_Pos;
                 }
                 else
                 {
                     assert(s.size() >= 2 );
                     groupVec.push_back(s);
                     ++groupNum;
                 }
            }
        }
    }
}

void MatrixSlice::seedPos(const Matrix &m, Pos p, Group *ps, Matrix::value_type v, int group)
{
    if (m.isInMatrix(p) && !isFlaged(p) && m(p) == v)
    {
        slicematrix(p) = group;
        ps->push_back(p);
        seedPos(m, Pos(p.row, p.col-1), ps, v, group);
        seedPos(m, Pos(p.row, p.col+1), ps, v, group);
        seedPos(m, Pos(p.row-1, p.col), ps, v, group);
        seedPos(m, Pos(p.row+1, p.col), ps, v, group);
    }
}

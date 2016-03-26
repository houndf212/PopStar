#include "matrix.h"
#include "iomanip"

using std::cout;
using std::endl;

const Matrix::value_type Matrix_Blank = 0;
const Matrix::value_type Matrix_Alone_Pos = 1;
const Matrix::value_type Matrix_Unflaged = -1;

std::ostream &operator<<(std::ostream &os, const Matrix &m)
{
    os<<"    0  1  2  3  4  5  6  7  8  9"<<endl;
    os<<" |------------------------------"<<endl;
    for (int r=0; r<m.row_size(); ++r)
    {
        os<<r << "| ";
        for (int c=0; c<m.col_size(); ++c)
        {
            os<<std::setw(2)<< int(m(Pos(r, c)));
            os<<" ";
        }
        os<<endl;
    }
    os<<endl;
    return os;
}

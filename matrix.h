#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "basic_matrix.h"
#include "pos.h"

typedef Basic_Matrix<int, 10, 10> Matrix;
extern const Matrix::value_type Matrix_Blank;
extern const Matrix::value_type Matrix_Alone_Pos;
extern const Matrix::value_type Matrix_Unflaged;

std::ostream& operator<<(std::ostream& os, const Matrix& m);

#endif // MATRIX_H

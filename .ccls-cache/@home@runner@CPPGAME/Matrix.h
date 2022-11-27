#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
using namespace std;

template <typename T> class Matrix {
private:
  int row, col;
  T **mat;

public:
  Matrix(int rows = 0, int cols = 0) : row(rows), col(cols), mat(NULL) {
    mat = new T *[rows];
    for (int i = 0; i < rows; i++)
      mat[i] = new T[cols];
  }
  ~Matrix() {
    for (int i = 0; i < row; i++)
      delete[] mat[i];
    delete[] mat;
  }
  T &elem(int r, int c) { return mat[r][c]; }
  int getRows() { return row; }
  int getCols() { return col; }
  T **getMatrix() { return mat; }
  void print(string title = "Mat") {
    cout << title << " " << row - 1 << "X" << col << endl;
    for (int y = 0; y < row; y++) {
      for (int x = 0; x < col; x++) {
        cout << mat[y][x];
      }
      cout << endl;
    }
  }
  T *&operator[](int r) {
    if (r >= 0 && r < row)
      return mat[r];
    else {
      cout << "Matrix<" << typeid(T).name() << ">::operator[" << r << "]"
           << endl;
      exit(-1);
    }
  }
};

#endif
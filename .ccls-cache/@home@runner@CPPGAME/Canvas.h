#ifndef __CANVAS_H__
#define __CANVAS_H__

#include "Matrix.h"
#include <iostream>
#include <string>
#define MAX_LINE 100
#define DIM 40
using namespace std;

class Canvas {
private:
  Matrix<char> board;
  int xMax, yMax;

public:
  Canvas(int width = 10, int height = 10)
      : xMax(width), yMax(height), board(height, width) {
    for (int y = 0; y < yMax; y++)
      for (int x = 0; x < xMax; x++) {
        board.elem(y, x) = '*';
        if (y == yMax - 1) {
          board.elem(y, x) = '-';
        }
      }
  }
  void draw(int x, int y, char val) {
    if (x >= 0 && x < xMax && y >= 0 && y < yMax) {
      board.elem(y, x) = val;
    }
  }
  void clear() {
    for (int y = 0; y < yMax; y++)
      for (int x = 0; x < xMax; x++) {
        draw(x, y, ' ');
      }
  }
  void print(string title = "<My Canvas>") {
    // cout << title << endl;
    // for (int y = 0; y < yMax; y++) {
    //   for (int x = 0; x < xMax; x++) {
    //     cout << board[y][x];
    //   }
    //   cout << endl;
    // }
    board.print();
    cout << endl;
  }
};

#endif

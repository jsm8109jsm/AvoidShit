#ifndef __SHIT_H__
#define __SHIT_H__

#include <iostream>

using namespace std;

class Shit {
private:
  int x, y;

public:
  Shit(int x, int y) : x(x), y(y){};
  // void move() { x++; }
  void move(int **map) {
    if (map[y][x] == 1) {
      map[y][x] = 0;
      map[y][x++] = 1;
    }
  }
  void print() { cout << x << " " << y << endl; }
};

#endif

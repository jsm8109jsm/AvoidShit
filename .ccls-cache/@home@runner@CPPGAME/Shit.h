#ifndef __SHIT_H__
#define __SHIT_H__

#include "Human.h"
#include <iostream>
#include <vector>

using namespace std;

class Shit {
private:
  int x, y;

public:
  Shit(int y, int x) : y(y), x(x){};
  void drop(int **map, int yMax, vector<Shit *> s, int index) {
    if (y == yMax - 1) {
      return;
    }
    map[y][x] = 0;
    y++;
    map[y][x] = 1;
    s[index] = new Shit(x, y);
  }
  void print() { cout << y << " " << x << endl; }
  bool hit(Human& h) {
    if (x == h.getX() && y == h.getY())
      return true;
    else
      return false;
  }
};

#endif

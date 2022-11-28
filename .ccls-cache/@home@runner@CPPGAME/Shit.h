#ifndef __SHIT_H__
#define __SHIT_H__

#include <iostream>
#include <vector>

using namespace std;

class Shit {
private:
  int x, y;

public:
  Shit(int x, int y) : x(x), y(y){};
  void move(int **map, int yMax, vector<Shit *> s, int index) {
    // if (map[x][y] == 1) {
    map[x][y] = 0;
    x++;
    map[x][y] = 1;
    s[index] = new Shit(x, y);
    // }
    if (x == yMax - 1) {
      return;
    }
  }
  void print() { cout << x << " " << y << endl; }
};

#endif

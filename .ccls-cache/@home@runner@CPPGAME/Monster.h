#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "Canvas.h"
#include <cstdlib>
#include <string>

class Monster {
protected:
  string name;
  char icon;

protected:
  int x, y, nItem;
  void clip(int xMax, int yMax) {
    if (x < 0)
      x = 0;
    if (x >= xMax)
      x = xMax - 1;
    if (y < 0)
      y = 0;
    if (y >= yMax)
      y = yMax - 1;
  }
  void eat(int **map) {
    if (map[y][x] == 1) {
      map[y][x] = 0;
      nItem++;
    }
  }

public:
  Monster(string name = "좀비", char icon = '@', int x = 0, int y = 0)
      : name(name), icon(icon), x(x), y(y), nItem(0) {}
  virtual ~Monster() { cout << "\t" << name << icon << " 다음에 또 만나~~\n"; }
  void draw(Canvas &canvas) { canvas.draw(x, y, icon); }
  virtual void move(int **map, int xMax, int yMax) {
    switch (rand() % 8) {
    case 0:
      y--;
      break; // up
    case 1:
      x++;
      y--;
      break; // right up
    case 2:
      x++;
      break; // right
    case 3:
      x++;
      y++;
      break; // right down
    case 4:
      y++;
      break; // down
    case 5:
      x--;
      y++;
      break; // left down
    case 6:
      x--;
      break; // left
    case 7:
      x--;
      y--;
      break; // left up
    }
    clip(xMax, yMax);
    eat(map);
  }
  void print() { cout << "\t" << name << icon << ":" << nItem << endl; }
};

#endif

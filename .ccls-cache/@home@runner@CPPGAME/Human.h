#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "Canvas.h"
#include "Input.h"
#include <cstdlib>
#include <string>

class Human {
private:
  int x, y;
  char icon;

public:
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
  Human(int x = 15, int y = 29, char icon = '^') : x(x), y(y), icon(icon) {}
  virtual ~Human() { cout << "다음에 또 만나~~\n"; }
  void draw(Canvas &canvas) { canvas.draw(x, y, icon); }
  void print() { cout << x << y << endl; }
  virtual void move(int **map, int xMax, int yMax) {
    int a = getch();
    if (a == 27) {
      int b = getch();
      int c = getch();
      switch (c) {
      case 67:
        x++;
        break; // right
      case 68:
        x--;
        break; // left
      }
      clip(xMax, yMax);
    }
  }
};

#endif

#ifndef __VARIOUS_MONSTER_H__
#define __VARIOUS_MONSTER_H__

#include "Input.h"
#include "Monster.h"

class Zombie : public Monster {
public:
  Zombie(string name = "좀비", char icon = '@', int x = 0, int y = 0)
      : Monster(name, icon, x, y) {}
  ~Zombie() { cout << " [  Zombie] "; }
};

class Donggyeom : public Monster {
public:
  Donggyeom(string name = "정동겸", char icon = '*', int x = 0, int y = 0)
      : Monster(name, icon, x, y) {}
  ~Donggyeom() { cout << " [ DGisGOD] "; }
  void move(int **map, int xMax, int yMax) {
    switch (rand() % 8) {
    case 0:
      y -= 3;
      break; // up
    case 1:
      x += 3;
      y -= 3;
      break; // right up
    case 2:
      x += 3;
      break; // right
    case 3:
      x += 3;
      y += 3;
      break; // right down
    case 4:
      y += 3;
      break; // down
    case 5:
      x -= 3;
      y += 3;
      break; // left down
    case 6:
      x -= 3;
      break; // left
    case 7:
      x -= 3;
      y -= 3;
      break; // left up
    }
    clip(xMax, yMax);
    eat(map);
  }
};

class Vampire : public Monster {
public:
  Vampire(string name = "뱀파이어", char icon = '@', int x = 0, int y = 0)
      : Monster(name, icon, x, y) {}
  ~Vampire() { cout << " [ Vampire] "; }
  void move(int **map, int xMax, int yMax) {
    switch (rand() % 4) {
    case 0:
      y--;
      break; // up
    case 1:
      x++;
      break; // right
    case 2:
      y++;
      break; // down
    case 3:
      x--;
      break; // left
    }
    clip(xMax, yMax);
    eat(map);
  }
};

class Human : public Monster {
public:
  Human(string name = "플레이어", char icon = '^', int x = 0, int y = 0)
      : Monster(name, icon, x, y) {}
  ~Human() { cout << " [   Human] "; }
  int getnItem() { return nItem; }
  void move(int **map, int xMax, int yMax) {
    int a = getch();
    if (a == 27) {
      int b = getch();
      int c = getch();
      switch (c) {
      case 66:
        y++;
        break; // up
      case 67:
        x++;
        break; // right
      case 65:
        y--;
        break; // down
      case 68:
        x--;
        break; // left
      }
      clip(xMax, yMax);
      eat(map);
    }
  }
};

#endif

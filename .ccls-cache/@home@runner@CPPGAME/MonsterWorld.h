#ifndef __MONSTER_WORLD_H__
#define __MONSTER_WORLD_H__

#include "Human.h"
#include "Input.h"
#include "Matrix.h"
#include "Shit.h"
#include <unistd.h>

#define MAX_SHIT 900

class MonsterWorld {
private:
  Matrix<int> map;
  int xMax, yMax, shitCount;
  float nMove;
  Human human;
  Canvas canvas;
  TerminalControl tc;
  Shit *shit[MAX_SHIT];

public:
  MonsterWorld(int width, int height)
      : xMax(width), yMax(height), nMove(0), shitCount(0),
        canvas(width, height), map(height, width) {
    for (int y = 0; y < yMax - 6; y++) {
      for (int x = 0; x < xMax; x++) {
        // map[y][x] = 1;
        if (rand() % 5 < 1) {
          shit[shitCount++] = new Shit(y, x);
          map.elem(y, x) = 1;
        }
      }
    }
  };
  // ~MonsterWorld() { delete human; };
  void print() {
    system("clear");
    canvas.clear();
    for (int y = 0; y < yMax; y++) {
      for (int x = 0; x < xMax; x++) {
        if (map.elem(y, x) == 1) {
          canvas.draw(x, y, '%');
        }
        if (y == yMax - 1) {
          canvas.draw(x, y, '-');
        }
      }
    }
    human.draw(canvas);
    canvas.print();
    cout << nMove << endl;
  };
  void play(int maxWalk, int wait) {
    print();
    cout << " 엔터를 누르세요...";
    getchar();
    tc.playModeSetting();
    // while(1) {
    for (int i = 0; i < maxWalk; i++) {
      for (int j = 0; j < shitCount - 1; j++) {
        shit[j]->move(map.getMatrix());
      }
      human.move(map.getMatrix(), xMax, yMax);
      nMove += 0.5;
      print();
      usleep(wait);
    }
    for (int j = 0; j < shitCount - 1; j++) {
      shit[j]->print();
    }

    tc.defaultSetting();
  }
};

#endif

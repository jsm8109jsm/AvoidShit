#ifndef __MONSTER_WORLD_H__
#define __MONSTER_WORLD_H__

#include "Input.h"
#include "Matrix.h"
#include "Monster.h"
#include <unistd.h>
#define MAX_MONSTER 20

class MonsterWorld {
private:
  Matrix<int> map;
  int xMax, yMax, nMon, nMove;
  Monster *mon[MAX_MONSTER];
  Canvas canvas;
  TerminalControl tc;

public:
  MonsterWorld(int width, int height)
      : xMax(width), yMax(height), nMove(0), nMon(0), canvas(width, height),
        map(height, width) {
    for (int y = 0; y < yMax; y++) {
      for (int x = 0; x < xMax; x++) {
        // map[y][x] = 1;
        map.elem(y, x) = 1;
      }
    }
  };
  ~MonsterWorld() {
    for (int i = 0; i < nMon; i++) {
      delete mon[i];
    }
  };
  void add(Monster *m) {
    if (nMon < MAX_MONSTER) {
      mon[nMon++] = m;
    }
  };
  int countItems() {
    int nItems = 0;
    for (int y = 0; y < yMax; y++) {
      for (int x = 0; x < xMax; x++) {
        if (map.elem(y, x) == 1) {
          nItems++;
        }
      }
    }
    return nItems;
  }
  void print() {
    system("clear");
    canvas.clear();
    for (int y = 0; y < yMax; y++) {
      for (int x = 0; x < xMax; x++) {
        if (map.elem(y, x) == 1) {
          canvas.draw(x, y, '.');
        }
      }
    }
    for (int i = 0; i < nMon; i++) {
      mon[i]->draw(canvas);
    }
    canvas.print();
    cout << "전체 이동 횟수 = " << nMove << endl;
    cout << "남은 아이템 수 = " << countItems() << endl;
    for (int i = 0; i < nMon; i++) {
      mon[i]->print();
    }
  };
  void play(int maxWalk, int wait) {
    print();
    cout << " 엔터를 누르세요...";
    getchar();
    tc.playModeSetting();
    for (int i = 0; i < maxWalk; i++) {
      for (int j = 0; j < nMon; j++) {
        mon[j]->move(map.getMatrix(), xMax, yMax);
      }
      nMove++;
      print();
      if (countItems() == 0)
        break;
      sleep(wait);
    }

    tc.defaultSetting();
  }
};

#endif

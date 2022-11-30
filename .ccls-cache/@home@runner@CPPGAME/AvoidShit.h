#ifndef __AVOID_SHIT_H__
#define __AVOID_SHIT_H__

#include "Human.h"
#include "Input.h"
#include "Matrix.h"
#include "Shit.h"
#include <unistd.h>
#include <vector>

#define MAX_SHIT 900

class AvoidShit {
private:
  Matrix<int> map;
  int xMax, yMax, shitCount;
  float nMove;
  Human human;
  Canvas canvas;
  TerminalControl tc;
  vector<Shit *> shit;

public:
  AvoidShit(int width, int height)
      : xMax(width), yMax(height), nMove(0), shitCount(0),
        canvas(width, height), map(height, width), shit(MAX_SHIT) {
    for (int y = 0; y < yMax - 6; y++) {
      for (int x = 0; x < xMax; x++) {
        // map[y][x] = 1;
        if (rand() % 5 < 1) {
          shit[shitCount++] = new Shit(y, x);
          map.elem(y, x) = 1;
        }
      }
    }
  }
  ~AvoidShit() { cout << "버틴 시간: " << nMove << "초" << endl; };
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
    while (1) {
      for (int x = 0; x < xMax; x++) {
        // map[y][x] = 1;
        if (rand() % 5 < 1) {
          shit[shitCount++] = new Shit(0, x);
          map.elem(0, x) = 1;
        }
      }
      for (int j = shitCount - 1; j >= 0; j--) {
        shit[j]->drop(map.getMatrix(), yMax, shit, j);
      }
      human.move(map.getMatrix(), xMax, yMax);
      nMove += 0.5;
      print();
      for (int j = shitCount - 1; j >= 0; j--) {
        if (shit[j]->hit(human))
          return;
      }
      usleep(wait);
    }

    tc.defaultSetting();
  }
};

#endif

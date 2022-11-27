#ifndef __RANKING_BOARD_H__
#define __RANKING_BOARD_H__

#include "PlayInfo.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
using namespace std;
#define NUM_MVP 5

class RankingBoard {
private:
  PlayInfo MVP[NUM_MVP];
  int nMVP = NUM_MVP;

public:
  void print(string title = "게임 랭킹") {
    system("clear");
    cout << title << endl;
    // MVP 출력
    for (int i = 0; i < nMVP; i++) {
      cout << "[" << i + 1 << "위] " << MVP[i].name << "\t" << MVP[i].score
           << endl;
    }
    cout << "엔터를 입력하세요.";
    getchar();
    cout << endl;
  }
  int add(int nItem) {
    if (nItem < MVP[nMVP - 1].score)
      return 0;
    int rank = nMVP - 1;
    for (; rank > 0; rank--) {
      if (nItem < MVP[rank - 1].score)
        break;
      MVP[rank] = MVP[rank - 1];
    }

    MVP[rank].score = nItem;
    cout << "[" << rank + 1 << "위] 이름을 입력하세요: ";
    cin >> MVP[rank].name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    return rank + 1;
  }
  void save(string filename) {
    ofstream ofs;
    ofs.open(filename);
    for (int i = 0; i < nMVP; i++) {
      ofs << MVP[i];
    }
    ofs.close();
  }
  void load(string filename) {
    ifstream ifs;
    ifs.open(filename);
    for (int i = 0; i < nMVP; i++) {
      ifs >> MVP[i];
    }
    ifs.close();
  }
};

#endif
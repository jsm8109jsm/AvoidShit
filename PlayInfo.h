#ifndef __PLAYINFO_H__
#define __PLAYINFO_H__
#include <iostream>
#include <string>
using namespace std;

class PlayInfo {
private:
  int score;
  string name;
  friend class RankingBoard;

public:
  PlayInfo(int score = 0, string name = "XXX") : score(score), name(name) {}
  friend ostream &operator<<(ostream &os, const PlayInfo &obj) {
    os << obj.name << "\t" << obj.score << endl;
    return os;
  }
  friend istream &operator>>(istream &is, PlayInfo &obj) {
    is >> obj.name >> obj.score;
    return is;
  }
};

#endif
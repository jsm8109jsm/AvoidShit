#include "MonsterWorld.h"
#include "RankingBoard.h"
#include "VariousMonster.h"
#define RANK_FILENAME "MonsterWold.txt"
#include <time.h>

int main(void) {

  RankingBoard rank;
  rank.print("[게임 랭킹] : 시작");

  srand((unsigned int)time(NULL));
  int width = 16, height = 8;

  MonsterWorld game(width, height);
  game.add(new Zombie("허접한좀비", '!', rand() % width, rand() % height));
  game.add(new Vampire("난뱀파이어", '@', rand() % width, rand() % height));
  game.add(new Donggyeom("기만의천재", '*', rand() % width, rand() % height));
  Human *human = new Human("나는사람임", '^', rand() % width, rand() % height);
  game.add(human);
  game.play(5, 1);

  rank.add(human->getnItem());
  rank.print("[게임 랭킹] : 종료");
  rank.save(RANK_FILENAME);
  return 0;
}

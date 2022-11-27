#include "Human.h"
#include "MonsterWorld.h"
#include "RankingBoard.h"
#define RANK_FILENAME "MonsterWold.txt"
#include <time.h>

int main(void) {

  RankingBoard rank;
  rank.print("[게임 랭킹] : 시작");

  srand((unsigned int)time(NULL));
  int width = 30, height = 30;

  MonsterWorld game(width, height + 1);
  Human human(width / 2, height - 2, '|');

  game.play(10, 500000);

  // rank.print("[게임 랭킹] : 종료");
  // rank.save(RANK_FILENAME);
  return 0;
}

#include "Human.h"
#include "AvoidShit.h"
#include <time.h>

int main(void) {

  srand((unsigned int)time(NULL));
  int width = 30, height = 30;

  AvoidShit game(width, height + 1);
  Human human(width / 2, height - 2);

  game.play(10, 500000);
  return 0;
}

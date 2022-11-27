#ifndef __INPUT_H__
#define __INPUT_H__

#include <iostream>
#include <limits>
#include <termios.h>
#include <unistd.h> // read 함수
using namespace std;

class TerminalControl {
private:
  struct termios init_terminal_setting;

public:
  TerminalControl() { tcgetattr(0, &init_terminal_setting); }
  void defaultSetting() {
    tcsetattr(0, TCSANOW, &init_terminal_setting);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  void playModeSetting() {
    struct termios terminal_setting;
    tcgetattr(0, &terminal_setting); // 현재 터미널 설정 읽기
    terminal_setting.c_lflag &= ~ICANON;
    terminal_setting.c_lflag &= ~ECHO;
    terminal_setting.c_cc[VMIN] = 0;  // 최소 입력 문자 수 설정
    terminal_setting.c_cc[VTIME] = 0; // 최소 읽기 대기 시간 설정
    tcsetattr(0, TCSANOW, &terminal_setting); // 터미널에 설정 입력
  }
};

int getch(void) {
  int buf = 0;
  read(0, &buf, 1);
  return buf;
}
#endif
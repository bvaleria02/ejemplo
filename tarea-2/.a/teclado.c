#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <stdlib.h>

static struct termios old, current;

char getch(void){
  char ch;
  tcgetattr(0, &old);
  current = old;
  current.c_lflag &= ~ICANON;
  current.c_lflag &= ~ECHO;
  tcsetattr(0, TCSANOW, &current);
  ch = getchar();
  tcsetattr(0, TCSANOW, &old);
  return ch;
}

int main(){
  int a = 0;
  unsigned char b = 0;
  while (a == 0){
    b = getch();
    printf("%.2x", b);
  };
  return 0;
}

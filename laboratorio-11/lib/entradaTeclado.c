#include "lib1122021.h"

#include <stdio.h>
#include <termios.h>

static struct termios old, current;

char getch(void);

int entradaTeclado(){
  int tecla = 0;
  tecla = getch();
  switch(tecla){
    case 'm'        : tecla = 1;
                      break;
    case 'M'        : tecla = 1;
                      break;
    case 'x'        : tecla = 2;
                      break;
    case 'X'        : tecla = 2;
                      break;
    case 0x1b       : tecla = (tecla << 8) + getch();
                      tecla = (tecla << 8) + getch();
                      switch(tecla){
                          case 0x1b5b44 : tecla = 3;
                                          break;
                          case 0x1b5b43 : tecla = 4;
                                          break;
                          case 0x1b5b41 : tecla = 5;
                                          break;
                          case 0x1b5b42 : tecla = 6;
                                          break;
                      };
                      break;
    case 0xA        : tecla = 7;
                      break;
  };
  return tecla;
}

char getch(void){                         // Lee la entrada de teclado sin necesidad de pulsar enter
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

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <termios.h>
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

#define clear() printf("\033[H\033[J")
#define HL_BLUE  "\33[38;5;0;48;5;32m"
#define HL_NO     "\33[m"

char ScreenPrefix (char i){
            switch (i){
                    case 0  : printf("\033[0;100m \033[0;0m");
                              break;
                    case 1  : printf("\033[0;30m█\033[0;0m");
                              break;
                    case 2  : printf("\033[0;90m▒\033[0;0m");
                              break;
                    case 3  : printf("▒");
                              break;
                    case 4  : printf(" ");
                              break;
                    default : printf(" ");
                  };
              return(0);
            }

int delay (long i){
  i = i << 4;
  for (size_t j = 0; j < i; j++) {
    j++;
    j -= 1;
    j++;
    j -= 1;
  };
}

char InitDisplay(unsigned char display[32][128], unsigned long time_seed){
  unsigned long momentary = time_seed;
  unsigned char noise_value = 0;
  for (size_t i = 0; i < 32; i++) {
    for (size_t j = 0; j < 128; j++) {
      display[i][j] = 0;
    };
  };
  for (size_t i = 0; i < 32; i++) {
    for (size_t j = 0; j < 128; j++) {
      momentary = ((momentary * 3) - 515) >> 1;
      noise_value = momentary & 0x3;
      display[i][j] = noise_value;
    };
  };
}

char ScreenPrint(unsigned char display[32][128], char position[2]){
  clear();
  printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗");
  for (size_t i = 0; i < 32; i++) {
    printf("\n║");
    for (size_t j = 0; j < 128; j++) {
        if (position[1] == j){
          if (position[0] == i){
            printf("\033[0;96m█\033[0;0m");
          } else {
              ScreenPrefix(display[i][j]);
            };
        } else {
          ScreenPrefix(display[i][j]);
        };
      };
    printf("║");
  };
  printf("\n╠════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣");
  printf("\n║                                                                                                                                ║");
  printf("\n║                                                                                                                                ║");
  printf("\n║                                                                                                                                ║");
  printf("\n║                                                                                                                                ║");
  printf("\n╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
  return(0);
}

int KeyboardInput(unsigned char display[32][128], char position[2]){
    int i = 0;
    char key = 0;
    do {
        key = getch();
        key = key & 0xDF;
        printf("%c", key);
        switch(key){
            case  'W' : if (position[0] == 0){
                            position[0] = 0;
                          } else {
                              if (display[position[0] - 1][position[1]] == 1){
                                position[0] = position[0];
                              } else {
                                position[0] = position[0] - 1;
                            };
                          };
                        i = 1;
                        break;

            case  'A' : if (position[1] == 0){
                            position[1] = 0;
                          } else {
                              if (display[position[0]][position[1] - 1] == 1){
                                position[1] = position[1];
                              } else {
                            position[1] = position[1] - 1;
                            };
                          };
                        i = 2;
                        break;

            case  'S' : if (position[0] == 31){
                            position[0] = 31;
                          } else {
                              if (display[position[0] + 1][position[1]] == 1){
                                position[0] = position[0];
                              } else {
                            position[0] = position[0] + 1;
                            };
                          };
                        i = 3;
                        break;

            case  'D' : if (position[1] == 127){
                            position[1] = 127;
                          } else {
                              if (display[position[0]][position[1] + 1] == 1){
                                position[1] = position[1];
                              } else {
                            position[1] = position[1] + 1;
                            };
                          };
                        i = 4;
                        break;

            default   : i = 0;
                        break;
        };
      } while (i == 0);
    do {
      ScreenPrint(display, position);
      delay(625000);
      switch (i){
          case  1 : if (display[position[0]][position[1]] == 3){
                        if (display[position[0] - 1][position[1]] == 1){
                          i = 0;
                        } else if (position[0] == 0){
                            position[0] = 0;
                            i = 0;
                        } else {
                          position[0] = position[0] - 1;
                        };
                      } else {
                        i = 0;
                      };
                    break;
          case  2 : if (display[position[0]][position[1]] == 3){
                        if (display[position[0]][position[1] - 1] == 1){
                          i = 0;
                        } else if (position[1] == 0){
                            position[1] = 0;
                            i = 0;
                        } else {
                          position[1] = position[1] - 1;
                        };
                      } else {
                        i = 0;
                      };
                    break;
          case  3 : if (display[position[0]][position[1]] == 3){
                        if (display[position[0] + 1][position[1]] == 1){
                          i = 0;
                        } else if (position[0] == 31){
                            position[0] = 31;
                            i = 0;
                        } else {
                          position[0] = position[0] + 1;
                        };
                      } else {
                        i = 0;
                      };
                    break;
          case  4 : if (display[position[0]][position[1]] == 3){
                        if (display[position[0]][position[1]+1] == 1){
                          i = 0;
                        } else if (position[1] == 127){
                            position[1] = 127;
                            i = 0;
                        } else {
                          position[1] = position[1] + 1;
                        };
                      } else {
                        i = 0;
                      };
                    break;
                  };
        } while (i != 0);
    return(key);
}

int main () {
  time_t time_seed = 0;
  char position[2] = {16, 48};
  unsigned char display[32][128];
  int i = 1;
  int keyboard = 0;
  time_seed = time(0);
  // BUCLE
  InitDisplay(display, time_seed);
  //InitPlayer(display, position);
  while (i != 0){
  ScreenPrint(display, position);
  keyboard = KeyboardInput(display, position);
  };
  return(0);
}

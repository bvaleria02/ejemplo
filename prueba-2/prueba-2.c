#include <stdio.h>
#define clear() printf("\033[H\033[J")
#include <termios.h>
static struct termios old, current;

// Profe, tenga compasión de mí, no alcancé a terminar por el tiempo

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
  int mapa[10][10] = {{  2,  9,  0,  0, 10,  9,  6, 10,  5,  4},
                      {  9,  6,  5,  0,  0,  9,  6,  3,  2,  8},
                      {  3,  3,  8, 10,  6,  9,  5,  4,  3,  9},
                      {  2,  6,  3,  6,  4,  3,  6,  2,  8,  3},
                      {  6,  6,  9, 10,  3,  4,  6,  2,  9,  9},
                      {  4, 10,  4,  4,  9,  0,  9, 10,  8,  8},
                      {  2,  2,  0,  3,  5,  4,  4,  6,  6,  5},
                      {  8,  4,  1,  3,  9,  5,  6,  6,  7,  7},
                      {  8,  1,  4,  9,  5,  7,  7,  3,  4,  4},
                      {  4,  8,  5,  4,  2,  3,  3,  2,  3,  6}};

  int escaneo[10][10] = {{0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0}};

  int pasadas[10][10] =   {{0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0}};
  int ponderacion[10];
  int coordenadas[10][2];
  int misiones = 0;
  int a = 0;
  int c = 0;
  char tecla = 0;
  clear();
  printf("Ingrese el \033[0;33mnúmero\033[0;0m de \033[0;34mmisiones\033[0;0m a encomendar\nMisiones :");
  while(c==0){
    scanf("%d", &misiones);
    if (misiones < 2){
      printf("\033[0;31mValor incorrecto\033[0;0m");
      c = 0;
      scanf("%d", &misiones);
    } else if (misiones > 10){
      printf("\033[0;31mValor incorrecto\033[0;0m");
      c = 0;
      scanf("%d", &misiones);
    } else {
      c = 1;
    };
  };
  for (int b = 0; b < misiones; b++) {
    clear();
    c = 0;
    for (int i = 0; i < 10; i++) {
      printf("\n%d\t: ", i+1);
      for (int j = 0; j < 10; j++) {
        if (escaneo[i][j] == 0){
          printf("-- ");
        } else {
          printf("%.2d ", escaneo[i][j]);
          };
        };
      };
      while (c == 0){
        printf("\nIngrese las \033[0;34mcoordenadas de la \033[0;36mmisión %d\033[0;0m, de la forma \033[0;33mfila \033[0;36mcolumna\nCoordenadas : \033[0;0m", a+1);
        scanf("%d %d", &coordenadas[a][0], &coordenadas[a][1]);
        coordenadas[a][0] = coordenadas[a][0]-1;
        coordenadas[a][1] = coordenadas[a][1]-1;
        if (escaneo[coordenadas[a][0]][coordenadas[a][1]] != 0){
          printf("\033[0;31mAquí no puedes colocar un valor\033[0;0m");
          c = 0;
        } else {
          escaneo[coordenadas[a][0]][coordenadas[a][1]] = mapa[coordenadas[a][0]][coordenadas[a][1]];
          pasadas[coordenadas[a][0]][coordenadas[a][1]] = pasadas[coordenadas[a][0]][coordenadas[a][1]]++;
          c = 1;
        };
      };
      c = 0;
      while(c < 10){
        clear();
        printf("%d %d\n", coordenadas[a][0], coordenadas[a][1]);
        for (int i = 0; i < 10; i++) {
          printf("\n%d\t: ", i+1);
          for (int j = 0; j < 10; j++) {
            if (escaneo[i][j] == 0){
              printf("-- ");
            } else {
              printf("%.2d ", escaneo[i][j]);
              };
            };
          };
        printf("\nIngrese a donde moverse: \033[0;32mW=\033[0;0mArriba, \033[0;32mA=\033[0;0mIzquierda, \033[0;32mS=\033[0;0mAbajo, \033[0;32mD=\033[0;0m Derecha, \033[0;32mX=\033[0;0mDetenerse\n");
        tecla = getch();
        tecla = tecla & 0xDF;
        switch(tecla){
          case  'W' : coordenadas[a][0] = coordenadas[a][0] - 1;
                      break;
          case  'A' : coordenadas[a][1] = coordenadas[a][1] - 1;
                      break;
          case  'S' : coordenadas[a][0] = coordenadas[a][0] + 1;
                      break;
          case  'D' : coordenadas[a][1] = coordenadas[a][1] + 1;
                      break;
          case  'X' : c = 11;
                      break;

        };
        escaneo[coordenadas[a][0]][coordenadas[a][1]] = mapa[coordenadas[a][0]][coordenadas[a][1]];
        pasadas[coordenadas[a][0]][coordenadas[a][1]] = pasadas[coordenadas[a][0]][coordenadas[a][1]]++;
        if (pasadas[coordenadas[a][0]][coordenadas[a][1]] < 2){
            ponderacion[a] = ponderacion[a] + mapa[coordenadas[a][0]][coordenadas[a][1]];
          };
        c++;
      };
      a++;
    };
    for (int i = 0; i < misiones; i++) {
      printf("\nMisión \033[0;32m%d=\033[0;0m \033[0;36m%d\033[0;0m", i+1, ponderacion[i]);
    };
  return(0);
}

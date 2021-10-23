#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#define clear() printf("\033[H\033[J")

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

int ScrPrnt(char memoria[43], int longitud_x, int longitud_total){
  int x_contador = 0;
  int i = 0;
  printf("---------------------------------------\n");
  while (i < longitud_total){
    if (x_contador == longitud_x){
      printf("\n");
      x_contador = 0;
    };
    switch(memoria[i]){
        case '1'  : printf("[\033[0;31mR\033[0;0m]   ");
                    x_contador++;
                    i++;
                    break;
        case '2'  : printf("[\033[0;33mA\033[0;0m]   ");
                    x_contador++;
                    i++;
                    break;
        default   : printf("[ ]   ");
                    x_contador++;
                    i++;
    };
  };
  printf("\n---------------------------------------\n");
  x_contador = 0;
  while (x_contador < longitud_x){
      printf("\033[0;34m|%d|   \033[0;0m", x_contador+1);
      x_contador++;
  };
  printf("\n");
  i = 0;
  return(i);
};

int KbdInput(char Teclado, int Turno, int longitud_x){
    int i = 0;
    int a = 0;
    printf("\n");
    switch (Turno){
          case  0   : printf("Turno de \033[0;31mRojo\033[0;0m:");
                      break;
          case  1   : printf("Turno de \033[0;33mAmarillo\033[0;0m:");
                      break;
    };
    printf("\n-------------------\nIngrese una fila para tirar una ficha\n\033[0;36mFila = \033[0;0m");
    while(i == 0){
      Teclado = getch();
      a = Teclado - 0x30;
      if (a < 1){
          i = 0;
          printf("\n\033[0;31m¡Valor inválido!\033[0;0m:");
          printf("\n-------------------\nIngrese una fila para tirar una ficha\n\033[0;36mFila = \033[0;0m");
      } else if (a > longitud_x){
        i = 0;
        printf("\n\033[0;31m¡Valor inválido!\033[0;0m:");
        printf("\n-------------------\nIngrese una fila para tirar una ficha\n\033[0;36mFila = \033[0;0m");
      } else {
        i = 1;
      };
    };
    printf("\n");
    return(Teclado);
}

int WriteMemory(char memoria[43], char Teclado, int Turno, int longitud_x){
    int i = 0;
    int a = 0;
    int b = 6;
    a = Teclado - 49;
    while (i < b){
      switch (memoria[a]){
        case '0'    : a = a + longitud_x;
                      i++;
                      break;
        case '1'    : i = 126;
                      break;
        case '2'    : i = 126;
                      break;
      };
    };
    if (a < 7){
      i = 127;
    } else if (i == 5){
      i = 126;
    } else if (memoria[a] == 0){
      i = 126;
    } else {
      switch (a){
          case 43 : i = 126;
                    break;
          case 44 : i = 126;
                    break;
          case 45 : i = 126;
                     break;
          case 48 : i = 126;
                    break;
      };
    };
    switch (i){
        case  126 : a = a - longitud_x;
                    memoria[a] = Turno + 49;
                    break;
        case  127 : printf("\033[0;31m¡No se puede colocar una ficha aquí!\033[0;0m\n");
                    Turno = Turno ^ 0x1;
                    break;
    };
    Turno = Turno + (a << 8);
    return(Turno);
}

int Logica_interna (char memoria[43], int longitud_x, int posicion, int Turno){
  int i = 0;
  int j = 0;
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int ganador = 0;
  int memoria_posicion = 0;
  memoria_posicion = posicion;
  // Detectar lateralmente
  while(j < 4){
      c = posicion / longitud_x;
      i = 0;
      b = 0;
      while (i < 4){
      b = b << 2;
      d = (posicion - (3- i))/longitud_x;
      if (c == d){
        a = memoria[posicion - (3 - i)];
        } else {
          a = 0x30;
        };
      a = a - 0x30;
      b = b + a;
      i++;
      };
      switch (b){
          case 0x55 : // printf("rojo ganó");
                      ganador = 1;
                      i=254;
                      j=254;
                       break;
          case 0xAA : // printf("amarillo ganó");
                      ganador = 2;
                      i=254;
                      j=254;
                      break;
  };
  j++;
  posicion += 1;
  };
  // detectar verticalmente
  j = 0;
  posicion = memoria_posicion;
  while (j < 1){
      i = 0;
      b = 0;
      posicion = memoria_posicion + (i * longitud_x);
      while (i < 4){
          a = posicion + ((3 - i) * longitud_x);
          if (a < 0){
            a = 0x30;
          } else if (a > 42){
            a = 0x30;
          } else {
            a = memoria[a];
          };
          a = a - 0x30;
          b = b << 2;
          b = b + a;
          i++;
      };
      j++;
  };
  switch (b){
          case 0x55 : // printf("rojo ganó");
                      ganador = 1;
                      i=254;
                      j=254;
                      break;
          case 0xAA : // printf("amarillo ganó");
                      ganador = 2;
                      i=254;
                      j=254;
                      break;
  };
  return(ganador);
}

int Ganadores (int c){
  short a = 0;
  int d = 0;
  int e = 0;
  //while (i == 0){
  d=0;
  //clear();
  printf("\n%c%c\t______________________________________\t%c%c", a, a, a, a);
  printf("\n%c%c\t| _________JUEGO TERMINADO___________ |\t%c%c", a, a, a, a);
  printf("\n%c%c\t| |                                 | |\t%c%c", a, a, a, a);
  printf("\n\t| |           Ha ganado:            | |   ");
  printf("\n%c%c\t| |                                 | |\t%c%c", a, a, a, a);
  switch (c){
      case 1  :
                printf("\n%c%c\t| |              \033[0;31mRojo\033[0;0m               | |\t%c%c", a, a, a, a);
                break;
      case 2  : printf("\n%c%c\t| |            \033[0;33mAmarillo\033[0;0m             | |\t%c%c", a, a, a, a);
                break;
  };
  printf("\n%c%c\t| |_________________________________| |\t%c%c", a, a, a, a);
  printf("\n%c%c\t|_____________________________________|\t%c%c\n", a, a, a, a);
  e++;
  e = e & 0x7f;
  a = e + 0x20;
  while (d < 100000000){
    d++;
  };
//};
  return(c);
}

int Pantalla_Titulo(){
  clear();
  int i = 0;
  char a = 0;
  char b = 0;
  int c = 0;
  printf(" _________________________________________________\n");
  printf("|\\            *                    _    _        |\n");
  printf("| \\                     *         | |  | |       |\n");
  printf("|  \\    *            ___    *     | |  | |       |\n");
  printf("|   \\_        *     / | \\         | |__| |       |\n");
  printf("|   | |============/  |  \\        |____  |       |\n");
  printf("|   |_|============\\  |  /             | |       |\n");
  printf("|    /           *  \\_|_/     *        | |       |\n");
  printf("|   /    *                *            |_|       |\n");
  printf("|  /     _________________________________       |\n");
  printf("| /    //    \033[0;32mComandos:\033[0;32m      \033[0;36mj. Jugar\033[0;0m      \\\\     |\n");
  printf("|/    //                    \033[0;36mc. Créditos\033[0;0m    \\\\    |\n");
  printf("|   _//                     \033[0;36ma. Ayuda\033[0;0m        \\\\_  |\n");
  printf("|  |_|=======================================|_| |\n");
  printf("|________________________________________________|\n");
  printf("\n\n\033[0;33mPresione una tecla: \033[0;0m");
  while (i == 0){
    scanf("%c", &a);
    switch (a){
        case  'a' : clear();

                    break;
        case  10  : i = 0;
                    break;
        case  'c' : clear();
                    printf("Cuatro en linea\n----------------------------\n\n");
                    printf("\033[0;32mCreado por  : \033[0;36mBenjamín Valeria\n\033[0;32mUniversidad : \033[0;36mUniversidad de la Frontera\n\033[0;32mCarrera     : \033[0;36mIngeniería Civil Electrónica\n\033[0;32mCopyright   : \033[0;36m2021. Todos los derechos reservados\n\n\n\033[0;0mAnte cualquier error, \033[0;34mreportarlo\033[0;0m en el \033[0;33mrepositorio de Github\033[0;36m\nhttps://github.com/bvaleria02/laboratorios-programacion/tree/main/proyecto-programacion");
                    printf("\n\n\033[0;34mPresione una tecla\033[0;0m para salir o jugar\n");
                    while(c<800000000){
                      c++;
                    };
                    a = 0;
                    c=0;
                    while(c==0){
                    scanf("%c", &b);
                    switch(b){
                      case  10  : c = 1;
                                  //printf("Presione una tecla:");
                                  break;
                      case 'j'  : i=1;
                                  c=1;
                                  break;
                      case 'c'  : i=0;
                                  break;
                      default   : clear();
                                  i = 0;
                                  c=1;
                                  //printf("Presione una tecla:");
                    };};
                    break;
        case  'j' : clear();
                    i = 1;
                    break;
        default   : i = 0;
    };
  };
  return(a);
}

int Retardo (int i) {
  int a = 0;
  while (a < i){
    a++;
  };
  return (i);
}

int main(){
    // Variable Generales
    int longitud_x = 7;
    int longitud_total = 42;
    char Teclado = 0;
    int Turno = 0;
    char memoria[43] = "000000000000000000000000000000000000000000";
    int posicion = 0;
    // Variables Temporales
    int c = 0;
    // Programa
    clear();
    Pantalla_Titulo();
    Retardo(200000000);
    ScrPrnt(memoria, longitud_x, longitud_total);
    while (c==0){
        Teclado = KbdInput(Teclado, Turno, longitud_x);
        Turno = WriteMemory(memoria, Teclado, Turno, longitud_x);
        //clear();
        Teclado = 0;
        ScrPrnt(memoria, longitud_x, longitud_total);
            posicion = Turno >> 0x8;
            Turno = Turno & 0x1;
            Turno = Turno ^ 0x1;
        c = Logica_interna(memoria, longitud_x, posicion, Turno);
    };
    Ganadores(c);
    return(0);
}

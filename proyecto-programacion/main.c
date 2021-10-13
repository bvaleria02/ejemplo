#include <stdio.h>

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

int KbdInput(char Teclado, int Turno){
    int i = 0;
    printf("\n");
    switch (Turno){
          case  0   : printf("Turno de \033[0;31mRojo\033[0;0m:");
                      break;
          case  1   : printf("Turno de \033[0;33mAmarillo\033[0;0m:");
                      break;
    };
    printf("\n-------------------\nIngrese una fila para tirar una ficha\n\033[0;36mFila = \033[0;0m");
    while(i == 0){
      scanf("%c", &Teclado);
      switch(Teclado){
          case  '1' : i = 1;
                      break;
          case  '2' : i = 1;
                      break;
          case  '3' : i = 1;
                      break;
          case  '4' : i = 1;
                      break;
          case  '5' : i = 1;
                      break;
          case  '6' : i = 1;
                      break;
          case  '7' : i = 1;
                      break;
          case  10  : i = 0;
                      break;
          default   : i = 0;
                      printf("\n\033[0;31m¡Valor inválido!\033[0;0m:");
                      printf("\n-------------------\nIngrese una fila para tirar una ficha\n\033[0;36mFila = \033[0;0m");
                      break;

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

    return(Turno);
}

int Logica(char memoria[43], int longitud_x){
  int i = 0;
  return(i);
}

int main(){
    // Variable Generales
    int longitud_x = 7;
    int longitud_total = 42;
    char Teclado = 0;
    int Turno = 0;
    char memoria[43] = "000000000000000000000000000000000000000000";
    // Variables Temporales
    int i = 0;
    int c = 0;
    // Programa
    ScrPrnt(memoria, longitud_x, longitud_total);
    while (c==0){
        Teclado = KbdInput(Teclado, Turno);
        Turno = WriteMemory(memoria, Teclado, Turno, longitud_x);
        ScrPrnt(memoria, longitud_x, longitud_total);
         Turno = Turno ^ 0x1;
    };
    return(0);
}

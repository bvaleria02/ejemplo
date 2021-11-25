#include <stdio.h>
#include <string.h>
#include <math.h>

void impresion(char *texto, int alto, int modo, int numero);
void saludo();
void despedida();
int doble(int numero);
void decimal(int numero);

int main(){
    int numero = 0;
    int dobleNumero;
    saludo();
    printf("\nIngrese un número para calcular el doble.\nNúmero = ");
    scanf("%i", &numero);
    dobleNumero = doble(numero);
    decimal(dobleNumero);
    despedida();
    return 0;
};

void saludo(){
    impresion("Hola Mundo", 2, 1, 0);
}

void despedida(){
    impresion("Hasta Luego", 2, 1, 0);
}

void decimal(int numero){
    impresion("", 2, 0, numero);
}

int doble(int numero){
    numero = numero << 1;
    return numero;
}

/* Modo       0 = Entero
              1 = string
*/

void impresion (char *texto, int alto, int modo, int numero){
    int longitud;
    int potencia10 = 10;
    switch(modo){
      case 0  : while (numero >= potencia10){
                    longitud++;
                    if (numero < potencia10){
                      continue;
                    } else {
                      potencia10 = potencia10 * 10;
                    };
                };
                break;
      case 1  : longitud = strlen(texto);
                break;
    };
    printf("\n┌");
    for (int i = 0; i < longitud + 2; i++) {
      printf("─");
    };
    printf("┐");
    for (int i = 0; i < alto >> 1; i++) {
      printf("\n│");
      for (int j = 0; j < longitud + 2; j++) {
        printf(" ");
      };
      printf("│");
    };
    switch(modo){
      case 0  : printf("\n│ %d │", numero);
                break;
      case 1  : printf("\n│ %s │", texto);
                break;
    };
    for (int i = 0; i < alto >> 1; i++) {
      printf("\n│");
      for (int j = 0; j < longitud + 2; j++) {
        printf(" ");
      };
      printf("│");
    };
    printf("\n└");
    for (int i = 0; i < longitud + 2; i++) {
      printf("─");
    };
    printf("┘\n");
}

#include <stdio.h>

int main(){
      float Nota = 0;
      printf("Ingrese la nota cual desea consultar\n\033[0;36mNota = \033[0;0m");
      scanf("%f", &Nota);
      if (Nota < 1) {
        printf("La nota \033[0;36m%.1f\033[0;0m está \033[0;35mfuera del rango de medición\033[0;0m", Nota);
      } else if (Nota < 4){
        printf("La nota \033[0;36m%.1f\033[0;0m es \033[0;31minsuficiente\033[0;0m", Nota);
      } else  if (Nota < 5){
        printf("La nota \033[0;36m%.1f\033[0;0m es \033[0;33msuficiente\033[0;0m", Nota);
      } else if (Nota < 6){
        printf("La nota \033[0;36m%.1f\033[0;0m es \033[0;32mbuena\033[0;0m", Nota);
      } else if (Nota > 7){
        printf("La nota \033[0;36m%.1f\033[0;0m está \033[0;35mfuera del rango de medición\033[0;0m", Nota);
      } else {
        printf("La nota \033[0;36m%.1f\033[0;0m es \033[0;34mmuy buena\033[0;0m",Nota);
      };
      return 0;
}

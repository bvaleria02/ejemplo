#include <stdio.h>

int main(){
      float Prueba_1 = 0;
      float Prueba_2 = 0;
      float Prueba_3 = 0;
      float Tarea_1 = 0;
      float Tarea_2 = 0;
      float Tarea_3 = 0;
      float Laboratorios = 0;
      float Acumulador = 0;
      printf("\033[0;32mLaboratorio 5:        \033[0;31mActividad 5\n\033[0;0m");
      printf("------------------------------------\n\n");
      printf("Ingrese el valor de la \033[0;31mprimera prueba:\n\033[0;36mNota prueba 1 = \033[0;0m");
      scanf("%f", &Prueba_1);
      printf("Ingrese el valor de la \033[0;31mtercera prueba:\n\033[0;36mNota prueba 3 = \033[0;0m");
      scanf("%f", &Prueba_3);
      printf("Ingrese el valor de la \033[0;31mprimera tarea:\n\033[0;36mNota tarea 1 = \033[0;0m");
      scanf("%f", &Tarea_1);
      printf("Ingrese el valor de la \033[0;31msegunda tarea:\n\033[0;36mNota tarea 2 = \033[0;0m");
      scanf("%f", &Tarea_2);
      printf("Ingrese el valor de la \033[0;31mtercera tarea:\n\033[0;36mNota tarea 3 = \033[0;0m");
      scanf("%f", &Tarea_3);
      printf("Ingrese el valor de los \033[0;31mlaboratorios:\n\033[0;36mNota laboratorios = \033[0;0m");
      scanf("%f", &Laboratorios);
      printf("\nCalculando nota... \033[0;33mEspere un momento\033[0;0m\n");
      Acumulador = Prueba_1 * 20;
      Acumulador = Acumulador + Prueba_3 * 45;
      Acumulador = Acumulador + Tarea_1 * 20;
      Acumulador = Acumulador + Tarea_2 * 25;
      Acumulador = Acumulador + Tarea_3 * 35;
      Acumulador = Acumulador + Laboratorios * 20;
      Prueba_2 = 790 - Acumulador;
      Prueba_2 = Prueba_2 / 35;
      printf("\n------------------------------------");
      if (Prueba_1 < 4){
          printf("\n\n\t\033[0;36mPrueba 1:\033[0;31m        %.2f\033[0;0m    20%%", Prueba_1);
          } else {
            printf("\n\n\t\033[0;36mPrueba 1:\033[0;0m        %.2f    20%%", Prueba_1);
          };
      if (Prueba_3 < 4){
          printf("\n\t\033[0;36mPrueba 3:\033[0;31m        %.2f\033[0;0m    45%%", Prueba_3);
          } else {
            printf("\n\t\033[0;36mPrueba 3:\033[0;0m        %.2f    45%%", Prueba_3);
          };
      if (Tarea_1 < 4){
          printf("\n\t\033[0;36mTarea 1 :\033[0;31m        %.2f\033[0;0m    20%%", Tarea_1);
          } else {
            printf("\n\t\033[0;36mTarea 1 :\033[0;0m        %.2f    20%%", Tarea_1);
          };
      if (Tarea_2 < 4){
          printf("\n\t\033[0;36mTarea 2 :\033[0;31m        %.2f\033[0;0m    25%%", Tarea_2);
          } else {
            printf("\n\t\033[0;36mTarea 2 :\033[0;0m        %.2f    25%%", Tarea_2);
          };
      if (Tarea_3 < 4){
          printf("\n\t\033[0;36mTarea 3 :\033[0;31m        %.2f\033[0;0m    35%%", Tarea_3);
          } else {
            printf("\n\t\033[0;36mTarea 3 :\033[0;0m        %.2f    35%%", Tarea_3);
          };
      if (Laboratorios < 4){
          printf("\n\t\033[0;36mLaboratorios:\033[0;31m    %.2f\033[0;0m    20%%", Laboratorios);
          } else {
            printf("\n\t\033[0;36mLaboratorios:\033[0;0m    %.2f    20%%", Laboratorios);
          };
      printf("\n\n------------------------------------\n");
      Acumulador = Acumulador / 165;
      if (Acumulador < 4){
          printf("\nEL promedio con estas notas es \033[0;31m%.2f\033[0;0m", Acumulador);
          } else {
            printf("\nEL promedio con estas notas es \033[0;36m%.2f\033[0;0m", Acumulador);
          };
      if (Prueba_2 > 7){
          printf("\n\033[0;31mNo es posible pasar este curso con ninguna nota\033[0;0m");
          } else if (Prueba_2 < 1){
          printf("\n\033[0;32mEste curso puede ser pasado con cualquier nota\033[0;0m");
          } else {
          printf("\nLa nota mínima que debe tener la segunda prueba para pasar el curso es \033[0;36m%.2f\033[0;0m", Prueba_2);}
          ;
      printf("\n");
      return 0;
}

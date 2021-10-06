#include <stdio.h>

int main(){
    int edad = 0;
    int destino = 0;
    int acumulador = 0;
    int precio = 0;
    printf("\033[0;32mLaboratorio 6:        \033[0;31mActividad 4\n\033[0;0m");
    printf("------------------------------------\n\n");
    printf("\033[0;33mTurismos Buses que colisionan ltda.\033[0;0m\n");
    printf("------------------------------------\n\n");
    printf("Por favor, \033[0;34mingrese su edad\n\n\033[0;36mEdad = \033[0;0m");
    scanf("%d", &edad);
    printf("\nIngrese su \033[0;34mdestino\033[0;0m al cual ir:\n");
    printf("\t- \033[0;32m1. \033[0;33mDestino 1: \033[0;0mLa punta del cerro\n");
    printf("\t- \033[0;32m2. \033[0;33mDestino 2: \033[0;0mNinguna parte\n");
    printf("\ṭ- \033[0;32m3. \033[0;33mDestino 3: \033[0;0mChigualoco\n");
    while (acumulador == 0){
        printf("\n\033[0;36mDestino = \033[0;0m");
        scanf("%d", &destino);
        switch (destino){
            case 1:   acumulador = 1;
                      break;
            case 2:   acumulador = 1;
                      break;
            case 3:   acumulador = 1;
                      break;
            default:  acumulador = 0;
                      printf("\n\033[0;31mEl destino ingresado no es correcto\033[0;0m");
    };};
    destino -= 1;
    if (edad < 15){
        acumulador = 0;
    } else if (edad > 65){
        acumulador = 6;
    } else {
        acumulador = 3;
    };
    acumulador += destino;
    printf("\n------------------------------------\n\n");
    destino++;
    switch (acumulador){
        case 0:   precio += 2500;
                  printf("\t\033[0;36mEdad: \033[0;0m%d\t\t\033[0;36mDestino: \033[0;0m%d\n", edad, destino);
                  printf("\tEl precio es: \033[0;32m$%d\033[0;0m", precio);
                  break;
        case 1:   precio += 1200;
                  printf("\t\033[0;36mEdad: \033[0;0m%d\t\t\033[0;36mDestino: \033[0;0m%d\n", edad, destino);
                  printf("\tEl precio es: \033[0;32m$%d\033[0;0m", precio);
                  break;
        case 2:   precio += 2000;
                  printf("\t\033[0;36mEdad: \033[0;0m%d\t\t\033[0;36mDestino: \033[0;0m%d\n", edad, destino);
                  printf("\tEl precio es: \033[0;32m$%d\033[0;0m", precio);
                  break;
        case 3:   precio += 4200;
                  printf("\t\033[0;36mEdad: \033[0;0m%d\t\t\033[0;36mDestino: \033[0;0m%d\n", edad, destino);
                  printf("\tEl precio es: \033[0;32m$%d\033[0;0m", precio);
                  break;
        case 4:   precio += 3000;
                  printf("\t\033[0;36mEdad: \033[0;0m%d\t\t\033[0;36mDestino: \033[0;0m%d\n", edad, destino);
                  printf("\tEl precio es: \033[0;32m$%d\033[0;0m", precio);
                  break;
        case 5:   precio += 3800;
                  printf("\t\033[0;36mEdad: \033[0;0m%d\t\t\033[0;36mDestino: \033[0;0m%d\n", edad, destino);
                  printf("\tEl precio es: \033[0;32m$%d\033[0;0m", precio);
                  break;
        case 6:   precio += 3000;
                  printf("\t\033[0;36mEdad: \033[0;0m%d\t\t\033[0;36mDestino: \033[0;0m%d\n", edad, destino);
                  printf("\tEl precio es: \033[0;32m$%d\033[0;0m", precio);
                  break;
        case 7:   precio += 2000;
                  printf("\t\033[0;36mEdad: \033[0;0m%d\t\t\033[0;36mDestino: \033[0;0m%d\n", edad, destino);
                  printf("\tEl precio es: \033[0;32m$%d\033[0;0m", precio);
                  break;
        case 8:   precio += 2500;
                  printf("\t\033[0;36mEdad: \033[0;0m%d\t\t\033[0;36mDestino: \033[0;0m%d\n", edad, destino);
                  printf("\tEl precio es: \033[0;32m$%d\033[0;0m", precio);
                  break;
        default:  printf("\t\033[0;31mLos datos ingresados arriba no son válidos\033[0;0m");
    };
    printf("\n\n------------------------------------\n\n");
    return 0;
}

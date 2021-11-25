#include <stdio.h>
#include <stdlib.h>
#define clear() printf("\033[H\033[J")
#define HL_GREEN  "\33[38;5;0;48;5;34m"
#define HL_BLUE  "\33[38;5;0;48;5;32m"
#define HL_RED  "\33[38;5;0;48;5;160m"
#define HL_WHITE  "\33[38;5;0;48;5;255m"
#define HL_NO     "\33[m"
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

int pantalla (unsigned char a[512], char b[512], long offset, char nombre[128], long size, char edicion, unsigned char c[512]){
  clear();
  printf(HL_GREEN "OFFSET: ");
  printf(HL_WHITE "%08lX/%08lX", offset, size);
  printf(HL_NO"    /%s\n", nombre);
  printf("\033[0;92mOffset  \t\033[0;34m00  01  02  03  04  05  06  07  08  09  0A  0B  0C  0D  0E  0F\t\t");
  if (edicion == 1){
    printf(HL_RED"   Modo Edicion \n");
  } else {
    printf("\n");
  };
  printf(HL_NO"\033[0;0m---------------------------------------------------------------------------------------------------------");
  for (int i = 0; i < 32; i++) {
    printf("\n\033[0;92m%08lX\t\033[0;0m", offset + (i << 4));
    for (int j = 0; j < 34; j++) {
      if (edicion == 1){
        if (j < 16){
          if ((offset + (i<<4) + j-1) > size){
              printf("    ");
            } else if ((offset + (i<<4) + j-1) == size){
              printf(HL_RED "END ");
            } else if(a[(i<<4)+j] != c[(i<<4)+j]){
              printf("\033[0;91m%02X\033[0;0m  ", c[(i<<4)+j]);
              } else{
              printf("%02X  ", a[(i<<4)+j]);
            };
          } else if (j == 17) {
            printf(HL_NO "    |    \033[0;96m");
          } else if (j > 17){
            if ((offset + (i<<4) + j-18) >= size) {
              printf(" ");
            } else {
              printf("%c", b[(i<<4)+(j-18)]);
          };
        };



      } else {
        if (j < 16){
          if ((offset + (i<<4) + j-1) > size){
              printf("    ");
            } else if ((offset + (i<<4) + j-1) == size){
              printf(HL_RED "END ");
            } else {
              printf("%02X  ", a[(i<<4)+j]);
            };
          } else if (j == 17) {
            printf(HL_NO "    |    \033[0;96m");
          } else if (j > 17){
            if ((offset + (i<<4) + j-18) >= size) {
              printf(" ");
            } else {
              printf("%c", b[(i<<4)+(j-18)]);
          };
        };
      };
    };
  };
  printf("\n\033[0;0m---------------------------------------------------------------------------------------------------------\n");
  printf(HL_GREEN"A:");
  printf(HL_NO" Abrir Archivo\t");
  printf(HL_GREEN"D:");
  printf(HL_NO" Desplazamiento\t");
  if (edicion == 1){
    printf(HL_GREEN"C:");
    printf(HL_NO" Cerrar sin guardar\n");
  } else {
    printf(HL_GREEN"C:");
    printf(HL_NO" Cerrar\n");
  };
  printf(HL_GREEN"W:");
  printf(HL_NO" Anterior\t\t");
  printf(HL_GREEN"S:");
  printf(HL_NO" Siguiente\t\t");
  if (edicion == 1){
    printf(HL_GREEN"E:");
    printf(HL_NO" Edicion\t\t");
    printf(HL_GREEN"R:");
    printf(HL_NO" Reemplazar\t\t");
    printf(HL_GREEN"G:");
    printf(HL_NO" Guardar\n");
  } else {
    printf(HL_GREEN"E:");
    printf(HL_NO" Edicion\n");
  };
  return(0);
}

int despl_c(){
  return(0);
}

int main () {
    unsigned char a[512];
    unsigned char c[512];
    char b[512];
    int k = 0;
    int l = 0;
    char m = 0;
    char teclado;
    long offset = 0;
    long offset_2 = 0;
    int temp_byte;
    char write_byte = 0;
    long size = 0;
    char nombre[128];
    char nombre_2[128];
    char edicion = 0;
    unsigned char o[16];
    char q;
    int data_count;
    clear();
    printf(HL_BLUE "Ingrese la ruta del archivo:\33[m /");
    scanf("%[^\n]s", nombre);
    FILE *input_file = fopen (nombre, "rb+");
    FILE *output_file = fopen (".editedfile", "wb+");
    do {
      printf(HL_BLUE "Desplazamiento             :\33[m ");
      scanf("%lX", &offset);
      fseek(input_file, 0L, SEEK_END);
      size = ftell(input_file);
      if (offset > size){
        k = 0;
        printf("El valor está fuera del tamaño del archivo (%08lX)\n", size);
      } else if (offset > size - 0x200) {
        offset = size - 0x1F0;
        k = 1;
      } else {
        k = 1;
        };
  } while (k == 0);
    fseek(input_file, 0L, SEEK_END);
    size = ftell(input_file);
    offset = offset >> 4;
    offset = offset << 4;
    k = 0;
    while (k == 0){
      m = 0;
      fseek(input_file, offset, SEEK_SET);
      fseek(output_file, offset, SEEK_SET);
      fread(&a, sizeof(unsigned char),512,input_file);
      if (edicion == 1){
        fread(&c, sizeof(unsigned char),512,output_file);
      };
      for (int i = 0; i < 512; i++) {
        if (a[i] < 0x20){
          b[i] = 0x20;
        } else {
          b[i] = a[i];
        };
      };
      pantalla(a, b, offset, nombre, size, edicion, c);
      while (l == 0){
        teclado = getch();
        switch (teclado) {
          case 'a'    : l = 1;
                        break;
          case 'd'    : l = 2;
                        break;
          case 'c'    : l = 3;
                        break;
          case 'A'    : l = 1;
                        break;
          case 'D'    : l = 2;
                        break;
          case 'C'    : l = 3;
                        break;
          case 'W'    : l = 4;
                        break;
          case 'w'    : l = 4;
                        break;
          case 'S'    : l = 5;
                        break;
          case 's'    : l = 5;
                        break;
          case 'E'    : l = 6;
                        break;
          case 'e'    : l = 6;
                        break;
          case 'R'    : l = 7;
                        break;
          case 'r'    : l = 7;
                        break;
          case 'G'    : l = 8;
                        break;
          case 'g'    : l = 8;
                        break;
          default     : l = 0;
        };
      };
      switch (l) {
          case  1    :    edicion = 0;
                          pantalla(a, b, offset, nombre, size, edicion, c);
                          fclose (input_file);
                            printf("Ingrese la ruta del archivo: /");
                            scanf("%[^\n]s", nombre_2);
                            FILE *input_file = fopen (nombre_2, "rb");
                            if (input_file == NULL){
                              printf("file failed to load %s\n", nombre_2);
                              m = 0;
                              for (int p = 0; p < 128; p++) {
                                nombre_2[p] = nombre[p];
                              };
                              FILE *input_file = fopen (nombre, "rb+");
                              } else {
                                m = 1;
                                for (int p = 0; p < 128; p++) {
                                  nombre[p] = nombre_2[p];
                                };
                                fseek(input_file, 0L, SEEK_END);
                                size = ftell(input_file);
                                offset = 0;
                                fseek(input_file, offset, SEEK_SET);
                                fread(&a, sizeof(unsigned char),512,input_file);
                                for (int i = 0; i < 512; i++) {
                                  if (a[i] < 0x20){
                                    b[i] = 0x20;
                                  } else {
                                    b[i] = a[i];
                                  };
                                };
                              };
                        l = 0;
                        break;

          case  2    :  do {
                            printf("Desplazamiento:");
                            scanf("%lX", &offset);
                            if (offset > size){
                              m = 0;
                              printf("El valor está fuera del tamaño del archivo (%08lX)\n", size);
                            } else if (offset > size - 0x200) {
                              offset = size - 0x1F0;
                              m = 1;
                            } else {
                              m = 1;
                            };
                          } while (m == 0);
                        offset = offset >> 4;
                        offset = offset << 4;
                        l = 0;
                        break;

          case  3    :  //cerrar();
                        l = 1;
                        k = 1;
                        break;
          case  4     : if (offset < 0x200){
                          offset = 0;
                        } else {
                          offset = offset - 0x200;
                        };
                        l = 0;
                        break;
          case  5     : if (offset > size - 0x200) {
                            offset = size - 0x1F0;
                            offset = offset >> 4;
                            offset = offset << 4;
                          } else {
                            offset = offset + 0x200;
                        };
                        l = 0;
                        break;
          case  6     :   l = 0;
                          if (edicion == 1){
                            printf("¿Desea anular los cambios? (S/N) :");
                            while (l == 0){
                            l = getch();
                            switch (l){
                              case 's'    : edicion = 1;
                                            l = 1;
                                            break;
                              case 'S'    : edicion = 1;
                                            l = 1;
                                            break;
                              case 'n'    : edicion = 1;
                                            l = 2;
                                            break;
                              case 'N'    : edicion = 1;
                                            l = 2;
                                            break;
                              default     : l = 0;
                          }; };
                        };
                        if (l == 2){
                          l = 0;
                        } else {
                        edicion = edicion ^ 0x1;
                        if (edicion == 1){
                          FILE *input_file = fopen (nombre, "rb");
                          FILE *output_file = fopen (".editedfile", "rb+");
                          if (offset != 0){
                            fseek(input_file, 0, SEEK_SET);
                            fseek(output_file, 0, SEEK_SET);
                            };
                          for (int n = 0; n < size; n = n + 1) {
                            fread(&o, sizeof(unsigned char),1,input_file);
                            fwrite(&o, sizeof(unsigned char),1,output_file);
                          };
                          fseek(input_file, offset, SEEK_SET);
                          fseek(output_file, offset, SEEK_SET);
                        } else if (edicion == 0){
                          //fclose (output_file);
                        };
                        l = 0;
                      };
                        break;
          case  7     :   if (edicion == 1){
                            printf("Ingrese la dirección donde escribir: ");
                            scanf("%lX", &offset_2);
                            printf("Ingrese la cantidad de datos a escribir :");
                            scanf("%d", &data_count);
                            printf("\033[0;93mIngrese el valor a escribir: ");
                            fseek(output_file, offset_2, SEEK_SET);
                            for (int r = 0; r < data_count; r++) {
                              printf("\n\033[0;96mDato %d\033[0;0m - \033[0;92m%08lX :\033[0;0m", r+1, offset_2 + r);
                              scanf("%02X[^\n]", &temp_byte);
                              write_byte = temp_byte;
                              fwrite(&write_byte, sizeof(unsigned char), 1, output_file);
                            };
                            l=0;
                              } else {
                                l = 0;
                              };
                              break;
          case  8     :  if (edicion == 1){
                            //fclose (input_file);
                            FILE *input_file = fopen (nombre, "rb+");
                            fseek(input_file, 0, SEEK_SET);
                            fseek(output_file, 0, SEEK_SET);
                            for (int n = 0; n < size; n = n + 1) {
                              fread(&o, sizeof(unsigned char),1,output_file);
                              fwrite(&o, sizeof(unsigned char),1,input_file);
                            };
                            //fclose (input_file);
                            l = 0;
                            }else{
                              l = 0;
                            };
                            break;
        };
    };
    fclose (input_file);
    clear();
    return(0);
}

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <termios.h>
static struct termios old, current;
#include <stdlib.h>
#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

static char* note[]  =         {"C O", "C#0", "D 0", "Eb0" , "E 0" , "F 0", "F#0", "G 0", "G#0", "A 0", "Bb0", "B 0",
                                "C 1", "C#1", "D 1", "Eb1" , "E 1" , "F 1", "F#1", "G 1", "G#1", "A 1", "Bb1", "B 1",
                                "C 2", "C#2", "D 2", "Eb2" , "E 2" , "F 2", "F#2", "G 2", "G#2", "A 2", "Bb2", "B 2",
                                "C 3", "C#3", "D 3", "Eb3" , "E 3" , "F 3", "F#3", "G 3", "G#3", "A 3", "Bb3", "B 3",
                                "C 4", "C#4", "D 4", "Eb4" , "E 4" , "F 4", "F#4", "G 4", "G#4", "A 4", "Bb4", "B 4",
                                "C 5", "C#5", "D 5", "Eb5" , "E 5" , "F 5", "F#5", "G 5", "G#5", "A 5", "Bb5", "B 5",
                                "C 6", "C#6", "D 6", "Eb6" , "E 6" , "F 6", "F#6", "G 6", "G#6", "A 6", "Bb6", "B 6",
                                "C 7", "C#7", "D 7", "Eb7" , "E 7" , "F 7", "F#7", "G 7", "G#7", "A 7", "Bb7", "B 7",
                                "C 8", "C#8", "D 8", "Eb8" , "E 8" , "F 8", "F#8", "G 8", "G#8", "A 8", "Bb8", "B 8",
                                "C 9", "C#9", "D 9", "Eb9" , "E 9" , "F 9", "F#9", "G 9", "G#9", "A 9", "Bb9", "B 9",
                                "C A", "C#A", "D A", "EbA" , "E A" , "F A", "F#A", "G A", "---", "===", "---"};

static float frequency[]  =    {8.1758,    8.6620,    9.1770,    9.7227,   10.3009,   10.9134,   11.5623,   12.2499,   12.9783,   13.7500,   14.5676,   15.4339,
                                16.3516,   17.3239,   18.3540,   19.4454,   20.6017,   21.8268,   23.1247,   24.4997,   25.9565,   27.5000,   29.1352,   30.8677,
                                32.7032,   34.6478,   36.7081,   38.8909,   41.2034,   43.6535,   46.2493,   48.9994,   51.9131,   55.0000,   58.2705,   61.7354,
                                65.4064,   69.2957,   73.4162,   77.7817,   82.4069,   87.3071,   92.4986,   97.9988,  103.8262,  110.0000,  116.5409,  123.4708,
                               130.8128,  138.5913,  146.8324,  155.5635,  164.8138,  174.6141,  184.9972,  195.9977,  207.6523,  220.0000,  233.0819,  246.9417,
                               261.6255,  277.1826,  293.6648,  311.1270,  329.6276,  349.2282,  369.9944,  391.9954,  415.3047,  440.0000,  466.1638,  493.8833,
                               523.2511,  554.3653,  587.3295,  622.2540,  659.2551,  698.4565,  739.9888,  783.9908,  830.6094,  880.0000,  932.3276,  987.7666,
                              1046.5022, 1108.7306, 1174.6591, 1244.5079, 1318.5103, 1396.9130, 1479.9777, 1567.9818, 1661.2188, 1760.0000, 1864.6549, 1975.5334,
                              2093.0044, 2217.4609, 2349.3184, 2489.0159, 2637.0203, 2793.8259, 2959.9553, 3135.9631, 3322.4377, 3520.0000, 3729.3098, 3951.0669,
                              4186.0088, 4434.9219, 4698.6367, 4978.0317, 5274.0405, 5587.6519, 5919.9106, 6271.9263, 6644.8755, 7040.0000, 7458.6216, 7902.1318,
                              8372.0176, 8869.8447, 9397.2715, 9956.0635, 10548.0830, 11175.3027, 11839.8213, 12543.8555, 0, 0, 0, 0};

/*          display_position:
*                             0 = Y position
*                             1 = X position
*                             2 = atribute
*
*           atributes:
*                             0 = Frequency
*                             1 = Volume
*/

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

int Screen(unsigned char data[32][64], int display_position[3], int octave, int offset, float tempo){
  int a = 0;
  for (int i = 0; i < 32; i++) {
    a = 0;
    printf("║ %.2X |", (offset >> 6)+i);
    for (size_t j = 0; j < 8; j++) {
      if (display_position[0] == i){
        if (display_position[1] == j){
            printf("\033[0;30;47m");
          };
        };
      printf("%s ", note[data[i][a]]);
      if (data[i][a+1] == 0){
          printf("-- ");
        } else {
          printf("%.2X ", data[i][a+1]-1);
      };
      if (data[i][a+2] == 0){
          printf("-- ");
        } else {
          printf("%.2X ", data[i][a+2]-1);
      };
      if (data[i][a+3] == 0xFF){
          printf("--- ");
        } else {
          printf("%.1X%.2X ", data[i][a+3], data[i][a+4]);
      };
      if (data[i][a+5] == 0xFF){
          printf("--- ");
        } else {
          printf("%.1X%.2X ", data[i][a+5], data[i][a+6]);
      };
      if (j != 7){
        printf("\033[0;0m|");
      } else {
        printf("\033[0;0m ");
      };
      if (display_position[0] == i){
        if (display_position[1] == j){
          switch (display_position[2]) {
            case 0  : gotoxy((7 + 19 * display_position[1] + 0), display_position[0] +1);
                      printf("\033[0;30;46m%s\033[0;0m", note[data[i][a]]);
                      break;
            case 1  : gotoxy((7 + 19 * display_position[1] + 4), display_position[0] +1);
                      if (data[i][a+1] == 0){
                          printf("\033[0;30;46m--\033[0;0m");
                        } else {
                          printf("\033[0;30;46m%.2X\033[0;0m", data[i][a+1]-1);
                        };
                      break;
            case 2  : gotoxy((7 + 19 * display_position[1] + 7), display_position[0] +1);
                      if (data[i][a+2] == 0){
                          printf("\033[0;30;46m--\033[0;0m");
                        } else {
                        printf("\033[0;30;46m%.2X\033[0;0m", data[i][a+2]-1);
                        };
                      break;
            case 3  : gotoxy((7 + 19 * display_position[1] + 10), display_position[0] +1);
                      printf("\033[0;30;46m%.1X\033[0;0m", data[i][a+3]-1);
                      break;
            case 4  : gotoxy((7 + 19 * display_position[1] + 11), display_position[0] +1);
                      printf("\033[0;30;46m%.2X\033[0;0m", data[i][a+4]-1);
                      break;
            case 5  : gotoxy((7 + 19 * display_position[1] + 14), display_position[0] +1);
                      printf("\033[0;30;46m%.1X\033[0;0m", data[i][a+5]-1);
                      break;
            case 6  : gotoxy((7 + 19 * display_position[1] + 15), display_position[0] +1);
                      printf("\033[0;30;46m%.2X\033[0;0m", data[i][a+6]-1);
                      break;
          };
            gotoxy((26 + 19 * display_position[1]), display_position[0]+1);
          };
        };
      a += 8;
    };
    printf("║\n");
  };
  printf("║\n");
  printf("Octave: %d \tTempo: %.2f\n", octave, tempo);
  /*for (size_t i = 0; i < 1; i++) {
    for (size_t j = 0; j < 32; j++) {
      printf("%.2X", data[i][j]);
    };
    printf("\n");
  }*/
  return 0;
}

int genOut(short wave_array[8][1024], FILE *audio_out, int duration, int atributes[8][3], float sample_offset){
  short c = 0;
  int a = 0;
  unsigned int sample_counter_int;
  float freq[8];
  int volume[8];
  int wave_shape[8];
  short current_sample = 0;
    for (int j = 0; j < 8; j++) {
      if (atributes[j][0] == 0x81){
        volume[j]= 0;
      } else if (atributes[j][0] == 0x82){
        volume[j]= 0;
      } else {
        volume[j] = atributes[j][1] - 1;
      };
      freq[j] = frequency[(atributes[j][0])] / 43.0664;
      wave_shape[j] = atributes[j][2];
    };
    duration = sample_offset + duration;
    for (int i = 0; i < 8; i++) {
      printf("%d ", wave_shape[i]);
    };
  for (int i = sample_offset; i < duration; i++) {
    current_sample = 0;
    for (int j = 0; j < 8; j++) {
      sample_counter_int = freq[j] *i;
      sample_counter_int = sample_counter_int & 1023;
      a = wave_shape[j];
      c = wave_array[a][sample_counter_int];
      if (volume[j] == 0){
        c = 0;
        } else {
        c = ((c / 256) * volume[j]);
        };
      current_sample = current_sample + c;
    };
    //printf("%d %f %d %d\n", i, b, d, c);
    fwrite(&current_sample,sizeof(short),1,audio_out);
  };
  return (duration);
}

int DrawBox (int y, char *text_string){
  int array_counter = 0;
  int a = 0;
  int x = 0;
  int off_x = 0;
  int off_y = 0;
  printf("\n%s", text_string);
  x = strlen(text_string);
  x = x + 4;
  y = y + 1;
  off_x = 80 - (x >> 1);
  off_y = 16 - (y >> 1);
  gotoxy(off_x, off_y);
  printf("┌");
  for (int i = 0; i < x; i++) {
    printf("─");
  };
  printf("┐");
  for (int j = 0; j < y; j++) {
    gotoxy(off_x, off_y + 1 +j);
    printf("│");
    for (int i = 0; i < x; i++) {
      printf(" ");
    };
    printf("│");
  };
  gotoxy(off_x, off_y + y);
  printf("└");
  for (int i = 0; i < x; i++) {
    printf("─");
  };
  printf("┘");
  gotoxy(80 - (x >> 1) + 3, off_y + 1);
  printf("%s", text_string);
  return 0;
}

int main (){
    int atributes[8][3] = {{0x80, 0, 0}, {0x80, 0, 0}, {0x80, 0, 0}, {0x80, 0, 0}, {0x80, 0, 0}, {0x80, 0, 0}, {0x80, 0, 0}, {0x80, 0, 0}};
    short wave_array[8][1024];
    int offset = 0;
    int display_position[3] = {0, 0, 0};
    unsigned char data[32][64];
    int key = 55;
    float tempo = 140;
    int base_time = 0;
    base_time = (30/tempo)*44100;
    int volume = 0x1F;
    int sample_offset;
    int c = 0;
    char Key = 0;
    int octave = 0;
    int number_key[3] = {0, 0, 0};
    int a = 0;
    //printf("%d %f", base_time, tempo);
    FILE *file_data = fopen("tracker.bin", "rb+");
    FILE *wavetable = fopen("wave.raw", "rb");
    FILE *audio_out = fopen("audio.raw", "wb+");
    fseek(file_data, offset, SEEK_SET);
    fread(&data,sizeof(char),2048,file_data);
      while (c == 0){
        clear();
        Screen(data, display_position, octave, offset, tempo);
        key = getch();
        switch(key & 0xFFDF){
            case 'W': if (display_position[0] == 0){
                          display_position[0] = 0;
                        } else {
                          display_position[0] = display_position[0] - 1;
                      };
                      c = 3;
                      break;
            case 'A': if (display_position[1] == 0){
                          if (display_position[2] == 0){
                              display_position[1] = 0;
                              display_position[2] = 0;
                            } else {
                              display_position[2] = display_position[2] - 1;
                            };
                        } else {
                          if (display_position[2] == 0){
                          display_position[1] = display_position[1] - 1;
                          display_position[2] = 6;
                        } else {
                          display_position[2] = display_position[2] - 1;
                        };
                      };
                      c = 3;
                      break;
            case 'S': if (display_position[0] == 31){
                          display_position[0] = 31;
                        } else {
                          display_position[0] = display_position[0] + 1;
                      };
                      c = 3;
                      break;
            case 'D': if (display_position[1] == 7){
                          if (display_position[2] == 6){
                              display_position[1] = 7;
                              display_position[2] = 6;
                            } else {
                              display_position[2] = display_position[2] + 1;
                            };
                        } else {
                          if (display_position[2] == 6){
                          display_position[1] = display_position[1] + 1;
                          display_position[2] = 0;
                        } else {
                          display_position[2] = display_position[2] + 1;
                        };
                      };
                      c = 3;
                      break;
            case 'E': c = 1;
                      printf("\nAudio Exportado\n");
                      for (int n = 0; n < 8; n++) {
                        fread(&wave_array[n],sizeof(short),1024,wavetable);
                      };
                      fseek(audio_out, offset, SEEK_SET);
                      for (size_t k = 0; k < 8; k++) {
                        for (int l = 0; l < 2; l++) {
                          offset = l << 11;
                          fseek(file_data, offset, SEEK_SET);
                          fread(&data,sizeof(char),2048,file_data);
                        for (int i = 0; i < 32; i++) {
                            for (int j = 0; j < 8; j++) {
                              if (data[i][(j << 3) + 0] == 0x80){
                                atributes[j][0]= atributes[j][0];
                              } else {
                                atributes[j][0]= data[i][(j << 3) + 0];
                              };
                              if (data[i][(j << 3) + 1] == 0x00){
                                atributes[j][1]= atributes[j][1];
                              } else {
                                atributes[j][1]= data[i][(j << 3) + 1];
                              };
                              if (data[i][(j << 3) + 2] == 0x00){
                                atributes[j][2]= atributes[j][2];
                              } else if (data[i][(j << 3) + 2] > 0x7) {
                                atributes[j][2]= 7;
                              } else {
                                atributes[j][2]= data[i][(j << 3) + 2] - 1;
                              };
                            };
                          sample_offset = genOut(wave_array, audio_out, base_time, atributes, sample_offset);
                      };
                    };

                      };
                      break;
            case 'Z': c = 3;
                      if (octave == 0){
                        octave = 0;
                          } else {
                        octave = octave - 1;
                      };
                      break;
            case 'X': c = 3;
                      if (octave == 0xA){
                        octave = 0xA;
                          } else {
                        octave = octave + 1;
                        };
                      c = 3;
                      break;
            case 'T': if (offset > 2047){
                      offset = offset - 2048;
                      };
                      c = 3;
                      break;
            case 'Y': offset = offset + 2048;
                      c = 3;
                      break;
            case 'Q': DrawBox(3, "Set Song Tempo");
                      gotoxy(75, 17);
                      printf("Tempo: ");
                      scanf("%f", &tempo);
                      base_time = (30/tempo)*44100;
                      c = 0;
                      break;
            default : c = 0;
                      break;
        };
        if (c ==3){
          fseek(file_data, offset, SEEK_SET);
          fread(&data,sizeof(char),2048,file_data);
          c = 0;
        } else {
        if (display_position[2] == 0){
          switch (key){
              case  'C' : // Key C
                          key = (octave * 12) + 0;
                          c = 2;
                          break;

              case  'F' : // Key C sharp
                          key = (octave * 12) + 1;
                          c = 2;
                          break;
              case  'V' : // Key C
                          key = (octave * 12) + 2;
                          c = 2;
                          break;
              case  'G' : // Key C
                          key = (octave * 12) + 3;
                          c = 2;
                          break;
              case  'B' : // Key C
                          key = (octave * 12) + 4;
                          c = 2;
                          break;
              case  'N' : // Key C
                          key = (octave * 12) + 5;
                          c = 2;
                          break;
              case  'J' : // Key C
                          key = (octave * 12) + 6;
                          c = 2;
                          break;
              case  'M' : // Key C
                          key = (octave * 12) + 7;
                          c = 2;
                          break;
              case  'K' : // Key C
                          key = (octave * 12) + 8;
                          c = 2;
                          break;
              case  ',' : // Key C
                          key = (octave * 12) + 9;
                          c = 2;
                          break;
              case  'L' : // Key C
                          key = (octave * 12) + 10;
                          c = 2;
                          break;
              case  '.' : // Key C
                          key = (octave * 12) + 11;
                          c = 2;
                          break;
              case  '-' : // Key C
                          key = (octave * 12) + 12;
                          c = 2;
                          break;
              case  '/' : // Key C
                          key = 0x80;
                          c = 2;
                          break;
              default   : c = 0;
                          break;
          };
            if (c == 2){
            //key = key & 0x7F;
              /*if (c ==3){
                key = 0x80;
              };*/
          fseek(file_data, offset +((display_position[0] << 6) + (display_position[1] << 3)), SEEK_SET);
          fwrite(&key,sizeof(char),1,file_data);
          fseek(file_data, offset, SEEK_SET);
          fread(&data,sizeof(char),2048,file_data);
          c = 0;
          if (display_position[0] == 31){
            display_position[0] = 31;
          } else {
            display_position[0]++;
            };
          } else {
            c = 0;
          };
        };
      if (display_position[2] >= 1){
        number_key[0] = key;
        if (number_key[0] == '/'){
          number_key[0] = 0;
          c = 2;
          a = 0;
          if (display_position[2] == 5){
            number_key[0] = 0xFF;
          } else if (display_position[2] == 3){
            number_key[0] = 0xFF;
          };
        } else if (display_position[2] == 5){
          a = 1;
        } else if (display_position[2] == 3){
            a = 1;
        } else {
          number_key[1] = getch();
          a = 2;
        };
        for (int m = 0; m < a; m++) {
          switch(number_key[m]){
              case  '0' : number_key[m] = 0;
                          c = 1;
                          break;
              case  '1' : number_key[m] = 1;
                          c = 1;
                          break;
              case  '2' : number_key[m] = 2;
                          c = 1;
                          break;
              case  '3' : number_key[m] = 3;
                          c = 1;
                          break;
              case  '4' : number_key[m] = 4;
                          c = 1;
                          break;
              case  '5' : number_key[m] = 5;
                          c = 1;
                          break;
              case  '6' : number_key[m] = 6;
                          c = 1;
                          break;
              case  '7' : number_key[m] = 7;
                          c = 1;
                          break;
              case  '8' : number_key[m] = 8;
                          c = 1;
                          break;
              case  '9' : number_key[m] = 9;
                          c = 1;
                          break;
              case  'A' : number_key[m] = 10;
                          c = 1;
                          break;
              case  'B' : number_key[m] = 11;
                          c = 1;
                          break;
              case  'C' : number_key[m] = 12;
                          c = 1;
                          break;
              case  'D' : number_key[m] = 13;
                          c = 1;
                          break;
              case  'E' : number_key[m] = 14;
                          c = 1;
                          break;
              case  'F' : number_key[m] = 15;
                          c = 1;
                          break;
              default  : c = 0;
                         break;
          };
        };
        if (c >= 1){
          number_key[2] = (number_key[0] << 4) + number_key[1];
          if (display_position[2] ==3){
            number_key[2] = number_key[0];
          } else if (display_position[2] == 5){
            number_key[2] = number_key[0];
          };
          if (display_position[2] == 1){
            number_key[2]++;
            if (number_key[2] > 0x20){
              number_key[2] = 0x20;
            };
          } else if (display_position[2] == 2){
            number_key[2]++;
          };
          if (c == 2){
            number_key[2] = 0;
          };
          fseek(file_data, offset +((display_position[0] << 6) + (display_position[1] << 3)) + display_position[2], SEEK_SET);
          fwrite(&number_key[2],sizeof(char),1,file_data);
          fseek(file_data, offset, SEEK_SET);
          fread(&data,sizeof(char),2048,file_data);
          c = 0;
          if (display_position[0] == 31){
            display_position[0] = 31;
          } else {
            display_position[0]++;
            };
          } else {
            c = 0;
          };
        };
      };
    };

    return (0);
  }

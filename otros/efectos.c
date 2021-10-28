#include <stdio.h>

int main(){
    int a = 0;
    int b = 0;
    long offset = 0;
    long size = 0;
    int c = 0;
    int d = 0;
    FILE *input_1 = fopen ("audio_in_1.wav", "rb");
    FILE *input_2 = fopen ("audio_in_2.wav", "rb");
    FILE *output_file = fopen ("audio_out.wav", "wb+");
    //fseek(input_file, offset, SEEK_SET);
    for (size_t i = 0; i < 0x30; i++) {
      fread(&b, sizeof(char),1,input_1);
      fwrite(&b, sizeof(char),1,output_file);
    };
    fseek(input_1, 0L, SEEK_END);
    size = ftell(input_1);
    offset = 0x30;
    fseek(input_1, offset, SEEK_SET);
    fseek(input_2, offset, SEEK_SET);
    fseek(output_file, offset, SEEK_SET);
    while (offset <= size){
      /*fread(&a, sizeof(short),1,input_2);
      a = a >> 8;
      a = a - 256;
      a = a << 1;
      fseek(input_1, offset+a, SEEK_SET);
      fread(&b, sizeof(short),1,input_1);
      fseek(output_file, offset, SEEK_SET);
      fwrite(&b, sizeof(short),1,output_file);
      */
      fread(&a, sizeof(short),1,input_2);
      fread(&b, sizeof(short),1,input_1);
      b = b ^ a;
      fwrite(&b, sizeof(short),1,output_file);
      offset += 2;
    };
    return (0);
}

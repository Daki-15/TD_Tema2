#include "at.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int N){
   
   for(int i = 0; i<N; i++ )
   {
      if(!strcmp(data.strings[i], "<LF>")){
         printf("\n");
      } 
      printf("%s", data.strings[i-1]); // "[i-1]" just for prettier print out
   }
}

int main(int argc, char **argv) {
   FILE *f;
   int result, N=0;
   char ch;

   f = fopen(argv[1], "rb");

   if(f == NULL){
      printf("\nError on opening file...\n");
      exit(1);
   }

   while(!feof(f)) {
      ch = fgetc(f);
      //printf("%c", ch);
      result = parse(ch);
      N++;

      if(result == 0) {
         printf("\nError on changing state in automata...\n");
         exit(2);
      }
      if(data.ok_error == 1){
         printf("OK");
         print(N);
      }
   }
   
   return 0;
}
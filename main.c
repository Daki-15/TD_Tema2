#include "at.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(){
   int i=0;
   
   while (i<10)
   {
      printf("%s\n", data.strings[i]);
      i++;
   }
    
}

int main(int argc, char **argv) {
   FILE *f;
   int result;
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

      if(result == 0) {
         printf("\nError on changing state in automata...\n");
         exit(2);
      }
   }

   if(result == 1) {
      // protocol ok
      printf("OK\n");
      print();
      
      //printf("\n%lu", (unsigned long)data.line_count);
      //printf("\n%u", (unsigned)data.ok_error);
      // print result (struct...)
      // print(data); <- functie 
   }

   /*
   if(result == 2) {
      // work in progress... read more chars 
   }
   */
   // dupa ce automatul a fost setat, trebuie sa se reseteze, sa inceapa din nou din starea 0 
   // reinitializare variabile 
   return 0;
}
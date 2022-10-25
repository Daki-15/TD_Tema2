#include "at.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
   FILE *f;
   int result;
   char ch;

   f = fopen(argv[1], "rb");

   if(f == NULL){
      printf("\nError on opening file...\n");
      exit(1);
   }

   while(feof(f)) {
      ch = fgetc(f);
      result = parse(ch);

      if(result == 0) {
         printf("\nError on changing state in automata...\n");
         exit(2);
      }
   }

   if(result == 1) {
      // protocol ok
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
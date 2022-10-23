#include "at.h"
#include <stdio.h>


int main(int argc, char **argv) {
   FILE *f;
   int result;
   char ch;

   f = fopen(argv[1], "rb");
   //... // daca f e null sau nu
   while(feof(f)) {
      ch = fgetc(f);
      result = parse(ch);
      if(result == 0) {
         // protocol error
}
      if(result == 1) {
         // protocol ok
         // print result (struct...)
         // print(data); <- functie 
}
      if(result == 2) {
         // work in progress... read more chars 
}
   // dupa ce automatul a fost setat, trebuie sa se reseteze, sa inceapa din nou din starea 0 
   // reinitializare variabile 
}
   return 0;
}
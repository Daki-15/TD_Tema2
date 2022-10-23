#ifndef __AT_H
#define __AT_H

#include<stdint.h>

#define STR_CNT 100
#define STR_SIZE 100

typedef struct {
   uint32_t line_count;
   uint8_t ok_error;
   char strings[STR_CNT][STR_SIZE+1];
}DATA;
extern DATA data; 
uint8_t parse(char ch);
#endif
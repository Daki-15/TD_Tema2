// 0 - error state machine
// 1 - ok state machine
// 2 - work in progress
#include "at.h"
#include <string.h>

DATA data; 
#define STR_SIZE 100

uint8_t parse(char ch){
   //o variabila care tine minte starea curenta a automatului
   static uint8_t current_state = 0;
   data.line_count = 0;
   uint8_t _count=0;

   switch (current_state) {
    case 0:{
        if(ch == 13){ // CR
            current_state = 1;
            strcpy(data.strings[_count++], "<CH>");
        }
    } break; 

    case 1:{
        if(ch == 10){ // LF
            current_state = 2;
            strcpy(data.strings[_count++], "<LF>");
            data.line_count++;
        }
        else{
           // state error
           current_state = 10;
        } 
    } break;

    case 2: {
         switch (ch) {
           case '+': {
                current_state = 20;
                strcpy(data.strings[_count++], "+");
            } break;
            case 'O': {
               current_state = 30;
               strcpy(data.strings[_count++], "O");
            } break; 
            case 'E': {
               current_state = 40;
               strcpy(data.strings[_count++], "E");
            } break;
            default: {
               // error state 
               current_state = 10; //return to 0(start) state
            }
         }
    }break; 

    case 20:{
        if(ch == 13){ //CR
            current_state = 21;
            strcpy(data.strings[_count++], "<CH>");
        }
        else{// ch != CR or LF
           current_state = 20;
           strncat(data.strings[_count++], &ch, 1);
        }
    } break;

    case 21:{
        if(ch == 10){ // LF
            current_state = 22;
            strcpy(data.strings[_count++], "<LF>");
            data.line_count++;
        }
        else{
            // state error
           current_state = 10;
        }
    } break; 

    case 22:{
        switch(ch){
            case 13:{ //CR
                current_state = 23;
                strcpy(data.strings[_count++], "<CH>");
            } break;
            case 43:{ // '+'
                current_state = 20;
                strcpy(data.strings[_count++], "+");
            } break;
            default:
                // state error
                current_state = 10;
        }
    } break;

    case 23:{
        if(ch == 10){ // LF
            current_state = 24;
            strcpy(data.strings[_count++], "<LF>");
            data.line_count++;
        }
        else{
            // state error
           current_state = 10;
        }
    } break; 

    case 24:{
        switch (ch) {
           case 'O': {
                current_state = 30;
                strcpy(data.strings[_count++], "O");
            } break;
            case 'E': {
               current_state = 40;
               strcpy(data.strings[_count++], "E");
            } break;
            default: {
               // error state 
               current_state = 10; //return to 0(start) state
            }
        }
    } break; 

    case 30:{   
        if(ch == 75){ // 'K'
            current_state = 31;
            data.line_count++;
            strcpy(data.strings[_count++], "K");
        }
        else{
            // state error
           current_state = 10;
        }
    } break;

    case 31:{   
        if(ch == 13){ // CR
            current_state = 32;
            strcpy(data.strings[_count++], "<CH>");
        }
        else{
            // state error
           current_state = 10;
        }
    } break;

    case 32:{   
        if(ch == 10){ // LF
            current_state = 33;
            strcpy(data.strings[_count++], "<LF>");
            data.line_count++;
        }
        else{
            // state error
           current_state = 10;
        }
    } break;

    case 33:{   
        data.ok_error = 1;
        return 1;  // 1 - ok state machine
    } break;

    case 40:{   
        if(ch == 82){ // 'R'
            current_state = 41;
            strcpy(data.strings[_count++], "R");
        }
        else{
            // state error
           current_state = 10;
        }
    } break;

    case 41:{   
        if(ch == 82){ // 'R'
            current_state = 42;
            strcpy(data.strings[_count++], "R");
        }
        else{
            // state error
           current_state = 10;
        }
    } break;

    case 42:{   
        if(ch == 79){ // 'O'
            current_state = 43;
            strcpy(data.strings[_count++], "O");
        }
        else{
            // state error
           current_state = 10;
        }
    } break;

    case 43:{   
        if(ch == 82){ // 'R'
            current_state = 44;
            strcpy(data.strings[_count++], "R");
        }
        else{
            // state error
           current_state = 10;
        }
    } break;

    case 44:{   
        if(ch == 13){ // CR
            current_state = 32;
            strcpy(data.strings[_count++], "<CH>");
        }
        else{
            // state error
           current_state = 10;
        }
    } break;

    case 10:{
        current_state = 0;
        _count=0;
        return 0; // 0 - error state machine
    } break;

    default:{
        // error state 
        current_state = 0;
        _count=0;
        return 0; // 0 - error state machine
    }
    }
}
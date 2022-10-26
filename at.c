// 0 - error state machine
// 1 - ok state machine
// 2 - work in progress
#include "at.h"

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
            data.strings[_count++][STR_SIZE]=13;
        }
    } break; 

    case 1:{
        if(ch == 10){ // LF
            current_state = 2;
            data.line_count++;
            data.strings[_count++][STR_SIZE]=10;
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
                data.line_count++;
                data.strings[_count++][STR_SIZE]=43;
            } break;
            case 'O': {
               current_state = 30;
               data.line_count++;
               data.strings[_count++][STR_SIZE]=79;
            } break; 
            case 'E': {
               current_state = 40;
               data.line_count++;
               data.strings[_count++][STR_SIZE]=69;
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
            data.strings[_count++][STR_SIZE]=13;
        }
        else{// ch != CR or LF
           current_state = 20;
           data.strings[_count++][STR_SIZE]=ch;
           //data.line_count++;
        }
    } break;

    case 21:{
        if(ch == 10){ // LF
            current_state = 22;
            data.strings[_count++][STR_SIZE]=10;
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
                data.strings[_count++][STR_SIZE]=13;
            } break;
            case 43:{ // '+'
                current_state = 20;
                data.strings[_count++][STR_SIZE]=43;
            } break;
            default:
                // state error
                current_state = 10;
        }
    } break;

    case 23:{
        if(ch == 10){ // LF
            current_state = 24;
            data.strings[_count++][STR_SIZE]=10;
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
                data.strings[_count++][STR_SIZE]=79;
            } break;
            case 'E': {
               current_state = 40;
               data.strings[_count++][STR_SIZE]=69;
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
            data.strings[_count++][STR_SIZE]=75;
        }
        else{
            // state error
           current_state = 10;
        }
    } break;

    case 31:{   
        if(ch == 13){ // CR
            current_state = 32;
            data.line_count++;
            data.strings[_count++][STR_SIZE]=13;
        }
        else{
            // state error
           current_state = 10;
        }
    } break;

    case 32:{   
        if(ch == 10){ // LF
            current_state = 33;
            data.line_count++;
            data.strings[_count++][STR_SIZE]=10;
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
            data.strings[_count++][STR_SIZE]=82;
        }
        else{
            // state error
           current_state = 10;
        }
    } break;

    case 41:{   
        if(ch == 82){ // 'R'
            current_state = 42;
            data.strings[_count++][STR_SIZE]=82;
        }
        else{
            // state error
           current_state = 10;
        }
    } break;

    case 42:{   
        if(ch == 79){ // 'O'
            current_state = 43;
            data.strings[_count++][STR_SIZE]=79;
        }
        else{
            // state error
           current_state = 10;
        }
    } break;

    case 43:{   
        if(ch == 82){ // 'R'
            current_state = 44;
            data.strings[_count++][STR_SIZE]=82;
        }
        else{
            // state error
           current_state = 10;
        }
    } break;

    case 44:{   
        if(ch == 13){ // CR
            current_state = 32;
            data.strings[_count++][STR_SIZE]=13;
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
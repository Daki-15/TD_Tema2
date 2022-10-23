// 0 - error state machine
// 1 - ok state machine
// 2 - work in progress
#include "at.h"

DATA data; 

uint8_t parse(char ch){
   //o variabila care tine minte starea curenta a automatului
   static uint8_t current_state = 0;
   switch (current_state) {
    case 0:{
        if(ch == 13) // CR
            current_state = 1;
    } break; 

    case 1:{
        if(ch == 10) // LF {
            current_state = 2;
        else{
           // state error
           current_state = -1;
        } 
    } break;

    case 2: {
         switch (ch) {
           case '+': {
                current_state = 20;
            } break;
            case 'O': {
               current_state = 30;
            } break; 
            case 'E': {
               current_state = 40;
            } break;
            default: {
               // error state 
               current_state = -1; //return to 0(start) state
            }
         }
    }break; 

    case 20:{
        if(ch == 13) //CR
            current_state = 21;
        else{// ch != CR or LF
           current_state = 20; 
        }
    } break;

    case 21:{
        if(ch == 10) // LF
            current_state = 22;
    } break; 

    case 22:{
        if(ch == 13) // CR
            current_state = 23;
    } break;

    case 23:{
        if(ch == 10) // LF
            current_state = 24;
    } break; 

    case 24:{
        if(ch == 79) // 'O'
            current_state = 30;
        if(ch == 69) // 'E'
            current_state = 40;
    } break; 

    case 30:{   
        if(ch == 75) // 'K'
            current_state = 31;
    } break;

    case 31:{   
        if(ch == 13) // CR
            current_state = 32;
    } break;

    case 32:{   
        if(ch == 10) // LF
            current_state = 33;
    } break;

    case 33:{   
        return 1;  // 1 - ok state machine
    } break;

    case 40:{   
        if(ch == 82) // 'R'
            current_state = 41;
    } break;

    case 41:{   
        if(ch == 82) // 'R'
            current_state = 42;
    } break;

    case 42:{   
        if(ch == 79) // 'O'
            current_state = 43;
    } break;

    case 43:{   
        if(ch == 82) // 'R'
            current_state = 44;
    } break;

    case 44:{   
        if(ch == 13) // CR
            current_state = 32;
    } break;

    case -1:{
        current_state = 0;
        return 0; // 0 - error state machine
    } break;

    }
}
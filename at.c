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
           current_state = 0; //return to 0(start) state
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
               current_state = 0; //return to 0(start) state
            }
         }
    }break; 
    case 20:{
        if(ch == 13) //CR
            current_state = 21;
        else{// ch != CR or LF
           // state error
           current_state = 20; //return to 0(start) state
        }
    } break;
    case 21:{
        if(ch == 10) // LF
            current_state = 22;
    } break; 
    case 22:{
        if(ch == 13) // CR
            current_state = 1;
    } break; 

    }
}
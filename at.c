// 0 - error state machine
// 1 - ok state machine

#include "at.h"

DATA data; 
#define ERROR_STATE 10
#define CAR_SIZE 1

uint8_t parse(char ch){
   //o variabila care tine minte starea curenta a automatului
   static uint8_t current_state = 0;
   static int _count;

   switch (current_state) {
    case 0:{
        data.line_count = 0;
        data.ok_error = 0;
        _count = 0;
        if(ch == 13){ // CR
            data.strings[_count++][CAR_SIZE]= 13;
            current_state = 1;
        } else{
            current_state = ERROR_STATE;
        }
    } break; 

    case 1:{
        if(ch == 10){ // LF
            data.strings[_count++][CAR_SIZE]= 10;
            data.line_count++;
            current_state = 2;
        }
        else{
           // state error
           current_state = ERROR_STATE;
        } 
    } break;

    case 2: {
         switch (ch) {
           case 43: { // ' + '
                current_state = 20;

            } break;
            case 79: { //' O '
               data.strings[_count++][CAR_SIZE] = 79;
               current_state = 30;
            } break; 
            case 69: { // ' E '
               data.strings[_count++][CAR_SIZE] = 69;
               current_state = 40;
            } break;
            default: {
               // error state 
               current_state = ERROR_STATE; //return to 0(start) state
            }
         }
    }break; 

    case 20:{
        if(ch != 13) { // ch != CR or LF
            data.strings[_count++][CAR_SIZE] = ch;
            current_state = 20;
        }
        else{ // CR
            data.strings[_count++][CAR_SIZE]= 13;
            current_state = 21;
        }
    } break;

    case 21:{
        if(ch == 10){ // LF
            data.strings[_count++][CAR_SIZE]= 10;
            data.line_count++;
            current_state = 22;
        }
        else{
            // state error
           current_state = ERROR_STATE;
        }
    } break; 

    case 22:{
        switch(ch){
            case 13:{ //CR
                data.strings[_count++][CAR_SIZE]= 13;
                current_state = 23;

            } break;
            case 43:{ // ' + '
                current_state = 20;

            } break;
            default:
                // state error
                current_state = ERROR_STATE;
        }
    } break;

    case 23:{
        if(ch == 10){ // LF
            data.strings[_count++][CAR_SIZE]= 10;
            data.line_count++;
            current_state = 24;
        }
        else{
            // state error
           current_state = ERROR_STATE;
        }
    } break; 

    case 24:{
        switch (ch) {
           case 79: { // ' O '
                data.strings[_count++][CAR_SIZE] = 79;
                current_state = 30;

            } break;
            case 69: { // ' E '
               data.strings[_count++][CAR_SIZE] = 69;
               current_state = 40;

            } break;
            default: {
               // error state 
               current_state = ERROR_STATE; //return to 0(start) state
            }
        }
    } break; 

    case 30:{   
        if(ch == 75){ // ' K '
            data.strings[_count++][CAR_SIZE] = 75;
            current_state = 31;
        }
        else{
            // state error
           current_state = ERROR_STATE;
        }
    } break;

    case 31:{   
        if(ch == 13){ // CR
            data.strings[_count++][CAR_SIZE]= 13;
            current_state = 32;
        }
        else{
            // state error
           current_state = ERROR_STATE;
        }
    } break;

    case 32:{   
        if(ch == 10){ // LF
            data.strings[_count++][CAR_SIZE]= 10;
            data.line_count++;
            current_state = 33;
        }
        else{
            // state error
           current_state = ERROR_STATE;
        }
    } break;

    case 33:{   
        current_state = 0;
        data.ok_error = 1;
        _count = 0;
    
        return data.ok_error;  // 1 - ok state machine
    } break;

    case 40:{   
        if(ch == 82){ // ' R '
            data.strings[_count++][CAR_SIZE] = 82;
            current_state = 41;
        }
        else{
            // state error
           current_state = ERROR_STATE;
        }
    } break;

    case 41:{   
        if(ch == 82){ // ' R '
            data.strings[_count++][CAR_SIZE] = 82;
            current_state = 42;
        }
        else{
            // state error
           current_state = ERROR_STATE;
        }
    } break;

    case 42:{   
        if(ch == 79){ // ' O '
            data.strings[_count++][CAR_SIZE] = 79;
            current_state = 43;
        }
        else{
            // state error
           current_state = ERROR_STATE;
        }
    } break;

    case 43:{   
        if(ch == 82){ // ' R '
            data.strings[_count++][CAR_SIZE] = 82;
            current_state = 44;
        }
        else{
            // state error
           current_state = ERROR_STATE;
        }
    } break;

    case 44:{   
        if(ch == 13){ // CR
            data.strings[_count++][CAR_SIZE]= 13;
            current_state = 32;
        }
        else{
            // state error
           current_state = ERROR_STATE;
        }
    } break;

    case ERROR_STATE:{
        data.ok_error = 0;
        return data.ok_error; // 0 - error state machine
    } break;

    default:{
        current_state = 0;
        return 0; // 0 - error state machine
    }
    }
}
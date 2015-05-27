#include <stdio.h>
#include "SMLED3.h"
#include "time.h"
#include "LED.h"
#include "button.h"


//State Diagram LED3
int LED3_SM(State *state, int previousTime,int counter){
    int target =0;
    int button = pressedButton();
	previousTime = 0;
    target = counter + 1;
    if(target >6 ){
        *state = INITIAL;
    }else{
       switch(* state){
			case INITIAL:
                if(button ==1 ){
                    turnOnLED3();
                    *state = Led3On;
                }else
                    *state = INITIAL;
                    break;
			case Led3Off:
                 if(delay(100)){  
                    turnOnLED3();
					previousTime = getCurrentTime();
                    *state = Led3On;
                }  
                 break;
            case Led3On:
                if(delay(100)){
					turnOffLED3();
					previousTime = getCurrentTime();
                    *state = Led3Off;
                }
                break;
			case FINAL:
                break;
		}
		return *state;
    }
        
}



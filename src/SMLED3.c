#include <stdio.h>
#include "SMLED3.h"
#include "time.h"
#include "LED.h"
#include "button.h"
#include "readButton.h"

//State Diagram LED3
int LED3_SM(State *state){
	static int timer = 0;
	int clock=0;
	
	static int previousTime = 0;
	
		switch(*state){
			case INITIAL:
                *state = STATEA;
				break;
			case STATEA:
				if(timer != 0){
				if(getCurrentTime()-previousTime >  two_hundred_millisec){
					turnOnLED3();
					previousTime = getCurrentTime();
					*state = STATEB;
					timer -- ;
				}
				}
				break;
			case STATEB:
				if(getCurrentTime()-previousTime >  two_hundred_millisec){
					turnOffLED3();
					previousTime = getCurrentTime();
					*state = FINAL;
				}
				break;
			case FINAL:
				*state = STATEA;
				break;
		}
		return *state;
}

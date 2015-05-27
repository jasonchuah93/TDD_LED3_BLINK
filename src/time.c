#include "time.h"

int getCurrentTime(){
	
    int counter = 0;
    int currentTime = 0;
    
    if(counter++ >= 100){
		counter = 0;
			currentTime++;
	}
	return currentTime;
}

int delay(int delayCycle){
	int previousTime = 0;
	if((getCurrentTime() - previousTime) < delayCycle){
        return 1;
    }else
        return 0;
}

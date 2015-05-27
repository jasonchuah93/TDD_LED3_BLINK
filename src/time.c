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
	static int previousTime = 0;
	while((getCurrentTime() - previousTime) < delayCycle);
	previousTime = getCurrentTime();
}

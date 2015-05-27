#include "readButton.h"
#include "button.h"
#include "LED.h"

int readButton(){
    int buttonIsRead;
    buttonIsRead = pressedButton();
    if(buttonIsRead == 1)
        return 1;
    else
        return 0;
}
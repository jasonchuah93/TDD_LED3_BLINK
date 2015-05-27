#include "unity.h"
#include "SMLED3.h"
#include "time.h"
#include "readButton.h"
#include "mock_LED.h"
#include "mock_button.h"

void setUp(void){}

void tearDown(void){}

void test_LED3_should_not_blink_if_button_is_not_pressed(void){
    State state = INITIAL;
    pressedButton_IgnoreAndReturn(0);
    turnOffLED3_IgnoreAndReturn(1);
    turnOnLED3_IgnoreAndReturn(0);
    
    LED3_SM(&state);
    TEST_ASSERT_EQUAL(STATEA,state);
}

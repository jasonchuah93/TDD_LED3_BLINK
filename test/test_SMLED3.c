#include <stdio.h>
#include "unity.h"
#include "SMLED3.h"
#include "mock_time.h"
#include "mock_LED.h"
#include "mock_button.h"

void setUp(void){}

void tearDown(void){}

void test_LED3_should_not_change_state_if_button_is_not_pressed(void){
    uint32_t previousTime = 0;
    State state = INITIAL;
    pressedButton_IgnoreAndReturn(0);
    turnOffLED3_IgnoreAndReturn(1);
    turnOnLED3_IgnoreAndReturn(0);
    LED3_SM(&state ,previousTime,1);
    TEST_ASSERT_EQUAL(INITIAL,state);
    
}


void test_LED3_should_change_state_to_LedOn_if_button_is_pressed(void){
    uint32_t previousTime = 0;
    State state = INITIAL;
    pressedButton_IgnoreAndReturn(1);
    turnOnLED3_IgnoreAndReturn(1);
    
    LED3_SM(&state, previousTime,0);
    
    TEST_ASSERT_EQUAL(Led3On,state);
}

void test_LED3_should_blink_5_times_and_stop(void){
    uint32_t previousTime = 0;
    State state = INITIAL;
    
    pressedButton_IgnoreAndReturn(1);    
    turnOnLED3_IgnoreAndReturn(1);
    getCurrentTime_IgnoreAndReturn(0);
    LED3_SM(&state, previousTime,0);
    TEST_ASSERT_EQUAL(Led3On,state);
   
    delay_ExpectAndReturn(100,1);
    turnOffLED3_IgnoreAndReturn(1);
    getCurrentTime_IgnoreAndReturn(100);
    LED3_SM(&state, previousTime,1);
    TEST_ASSERT_EQUAL(Led3Off,state);
      
    delay_ExpectAndReturn(100,1);
    getCurrentTime_IgnoreAndReturn(200);
    turnOnLED3_IgnoreAndReturn(1);
    LED3_SM(&state, previousTime,1);
    TEST_ASSERT_EQUAL(Led3On,state);
   
    delay_ExpectAndReturn(100,1);
    getCurrentTime_IgnoreAndReturn(300);
    turnOffLED3_IgnoreAndReturn(1);
    LED3_SM(&state, previousTime,2);
    TEST_ASSERT_EQUAL(Led3Off,state);
    
    delay_ExpectAndReturn(100,1);
    getCurrentTime_IgnoreAndReturn(400);
    turnOnLED3_IgnoreAndReturn(1);
    LED3_SM(&state, previousTime,2);
    TEST_ASSERT_EQUAL(Led3On,state);
    
    delay_ExpectAndReturn(100,1);
    getCurrentTime_IgnoreAndReturn(500);
    turnOffLED3_IgnoreAndReturn(1);
    LED3_SM(&state, previousTime,3);
    TEST_ASSERT_EQUAL(Led3Off,state);
    
    delay_ExpectAndReturn(100,1);
    getCurrentTime_IgnoreAndReturn(600);
    turnOffLED3_IgnoreAndReturn(1);
    LED3_SM(&state, previousTime,3);
    TEST_ASSERT_EQUAL(Led3On,state);
   
    delay_ExpectAndReturn(100,1);
    getCurrentTime_IgnoreAndReturn(700);
    turnOffLED3_IgnoreAndReturn(1);
    LED3_SM(&state, previousTime,4);
    TEST_ASSERT_EQUAL(Led3Off,state);
    
    delay_ExpectAndReturn(100,1);
    getCurrentTime_IgnoreAndReturn(800);
    turnOnLED3_IgnoreAndReturn(1);
    LED3_SM(&state, previousTime,4);
    TEST_ASSERT_EQUAL(Led3On,state);
    
    delay_ExpectAndReturn(100,1);
    getCurrentTime_IgnoreAndReturn(900);
    turnOffLED3_IgnoreAndReturn(1);
    LED3_SM(&state, previousTime,5);
    TEST_ASSERT_EQUAL(Led3Off,state);
    
    delay_ExpectAndReturn(100,1);
    getCurrentTime_IgnoreAndReturn(1000);
    turnOnLED3_IgnoreAndReturn(1);
    LED3_SM(&state, previousTime,5);
    TEST_ASSERT_EQUAL(Led3On,state);
    
    LED3_SM(&state, previousTime,6);
    TEST_ASSERT_EQUAL(INITIAL,state);
}



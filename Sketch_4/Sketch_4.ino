//Sketch_4
/* This program goes with Lab 4 of the OpenTag laser tag tutorial.
It plays a basic game of free for all laser tag. A player is out
if they get tagged 5 times.
*/


#include <TimerOne.h>
//TimerOne will make it easy to pule an infrared LED 38,000 times
//a second

// Variables (nicknames for pins)
int button_pin = 12;
int led_pin = 11;
int ir_led_pin = 10;
int ir_receiver_pin = 9;

//you start with 5 health. This is the first time that we will use
//a variable to keep track of and change a number.
int health = 5;

void setup() {
  //first, start up the TimerOne library. We want it to pulse
  //38,000 times a second, which is about once every 26 milliseconds
  Timer1.initialize(26);
  
  //tell the arduino if a pin is input/output
  pinMode( button_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  pinMode(ir_led_pin, OUTPUT);
  pinMode(ir_receiver_pin, INPUT);
}

void loop() {
  int button_state = digitalRead( button_pin );   //read button
  if (button_state == HIGH) {        //if the button is pushed
    /* If we are pushing the button, then we are trying to send
    a tag. However, we can only tag if we have more than 0 health.
    We can use the if statement and a comparative function called
    greather than, which uses the > symbol. Greather than will
    be true (the code in the if statement will be run) if the
    number on the left is greather than the number on the right.
    We want to send a tag if health is greater than 0. In code,
    that is written as:
    */
    if (health > 0){                    //if we have health
      //so, we know that we are pushing the button and have health
      //now we can send a tag.
      //first, pulse the infrared LED with the TimerOne code
      Timer1.pwm(ir_led_pin, 512);      //send pulse
      delay(10);                        //delay for 10 milliseconds
      Timer1.disablePwm(ir_led_pin);    //turn off Timer One
    }
  }
  
  //now, we want to see if we are getting tagged
  int ir_receiver_state = digitalRead(ir_receiver_pin);
  //if the receiver sees something, it will send a LOW or 0 signal
  if (ir_receiver_state == 0){
    //when we are tagged, we lose 1 health.
    /* In order to tell the arduino to subtract 1 health, we 
    need to tell it what health should now be. To do this, we 
    will say that the health I should have is equal to the health
    that I had minus 1. That line of code is written below.
    */
    health = health - 1;
    //now that we see something, indicate it by turning the LED
    //on for 1 second
    digitalWrite(led_pin, HIGH);
    delay(1000);                 //a delay of 1000 is 1 second
    digitalWrite(led_pin, LOW);  //then turn LED off
  }
}
//Tia tia tia!

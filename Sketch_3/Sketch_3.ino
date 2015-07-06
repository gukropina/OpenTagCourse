//Sketch_3
/* This program goes with Lab 3 of the OpenTag laser tag tutorial.
It sends a pulsed IR signal (38,000 times a second) when a button
is pressed and turns on an LED if a signal is seen
*/

/*
first, let's add the TimerOne library. To add a library, you
type #include and then the library name inside <>
*/

#include <TimerOne.h>
//TimerOne will make it easy to pule an infrared LED 38,000 times
//a second

// Variables (nicknames for pins)
int button_pin = 12;
int led_pin = 11;
int ir_led_pin = 10;
int ir_receiver_pin = 9;

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
  if (button_state == HIGH) {
    /*so, this is the first change. What we want to do is have
    the arduino turn on the infrared LED on and off at 38,000
    times a second. 
    we already know that digitalWrite is the command to tell the
    arduino to set a pin to HIGH or LOW voltage. We want to
    do that 38,000 times a second. That means we need to
    turn the LED off then on about every 0.026 seconds.
    (1/38,000 = 0.02632)
    We could use digitialWrite to turn the infrared LED on and off,
    or, we could use the TimerOne code to turn the infrared LED
    on and off at precisely the time we want. We just need to tell
    the arduino how long to pulse the LED. For that, we use the
    delay function. The delay function tells the arduino to pause
    for a set number of microseconds, or 1/1000th's of a second.
    For our code, we will have the infrared LED pulse for 10 
    milliseconds every time we push the button
    */
    //first, pulse the infrared LED with the TimerOne code
    Timer1.pwm(ir_led_pin, 512);      //send pulse
    delay(10);                        //delay for 10 milliseconds
    Timer1.disablePwm(ir_led_pin);    //turn off Timer One
  }
  /*we don't need to do anything if the button is low
  else {
    digitalWrite(led_pin, LOW);
  }
  */
  //now, we want to see if we are getting tagged
  int ir_receiver_state = digitalRead(ir_receiver_pin);
  //if the receiver sees something, it will send a LOW or 0 signal
  if (ir_receiver_state == 0){
    //now that we see something, indicate it by turning the LED
    //on for 1 second
    digitalWrite(led_pin, HIGH);
    delay(1000);                 //a delay of 1000 is 1 second
    digitalWrite(led_pin, LOW);  //then turn LED off
  }
}
//Mj csy ger xyvr sr er PIH, csy ger hs ercxlmrk!

//Sketch_7
/* This program goes with Lab 7 of the OpenTag laser tag tutorial.
It plays a basic game of free for all laser tag. A player is out
if they get tagged 5 times.
We will change the unit so that it only sends a tag when the button is pressed.
*/


#include <TimerOne.h>
//TimerOne will make it easy to pule an infrared LED 38,000 times a second

// Variables (nicknames for pins)
int button_pin = 12;
int led_pin = 11;
int ir_led_pin = 10;
int ir_receiver_pin = 9;
int piezo_pin = 2;

//you start with 5 health.
int health = 5;

void setup() {
  //start timer1 at 38,000 times a second, which is about once every 26 milliseconds
  Timer1.initialize(26);
  
  //tell the arduino if a pin is input/output
  pinMode( button_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  pinMode(ir_led_pin, OUTPUT);
  pinMode(ir_receiver_pin, INPUT);
  pinMode(piezo_pin, OUTPUT);
  
  //startup noise
  int count = 0;
      for (count = 1; count < 20; count++){
        tone(piezo_pin, count*250);
        delay(25);
        noTone(piezo_pin);
        delay(10);
      }
}

void loop() {
  int button_state = digitalRead( button_pin );   //read button
  /*
  Now that we know what state the button is in, we want to know if the button
  has gone from high to low. To do this, we are going to use a function. 
  A function is a piece of code that you write and give a name. As the code you
  write gets more complicated, you can write functions to break the code up into
  smaller pieces that perform a specific function.
  
  A function can have inputs and outputs. You put functions after void loop(){
  code. (go to the bottom of the code to see the change_state_checker function
  We are going to write the change_state_checker function to output a 0 if the
  button hasn't been pressed, and a 1 if the button is pressed.
  */
  int button_changed = change_state_checker( button_state );
  if (button_changed == 1) {           //if the button is pushed
    if (health > 0){                    //if we have health
    
      Timer1.pwm(ir_led_pin, 512);      //send pulse
      delay(10);                        //delay for 10 milliseconds
      Timer1.disablePwm(ir_led_pin);    //turn off Timer One
 
      tone(piezo_pin, 5000);           //make a high pitched sound
      delay(25);                       //wait for 0.025 seconds
      noTone(piezo_pin);               //stop making sound
      delay(25);                       //wait for a little bit
    }
    else{                              //if we don't have health
      //if we don't have helth, make a different sound
      tone(piezo_pin, 220);           //play first sound
      delay(25);
      noTone(piezo_pin);
      delay(10);                      //add a delay between notes
      tone(piezo_pin, 110);           //play second sound
      delay(75);                      //play second sound longer
      noTone(piezo_pin);
    }
  }
  
  //now, we want to see if we are getting tagged
  int ir_receiver_state = digitalRead(ir_receiver_pin);
  //if the receiver sees something, it will send a LOW or 0 signal
  if (ir_receiver_state == 0){
    //when we are tagged, we lose 1 health.
    health = health - 1;
    
    //turn on LED to also indicate that we were tagged
    digitalWrite(led_pin, HIGH);    //turn LED on
    
    /*****
    We also want to make a sound to indicate that we have 
    received a tag. Let's make it make three sounds this time.
    */
    tone(piezo_pin, 500);          //play first sound
    delay(50);
    noTone(piezo_pin);
    delay(10);
    tone(piezo_pin, 3500);           //play second sound
    delay(50);
    noTone(piezo_pin);
    delay(10);
    tone(piezo_pin, 500);          //play third sound
    delay(100);
    noTone(piezo_pin);              //stop playing sound 
    delay(10);
    
    digitalWrite(led_pin, LOW);     //then turn LED off
    
    if (health == 0){              //if we are out of health
      //if we are out of healh, make the I'm out sound
      int count = 0;               //create a variable
      for (count = 20; count > 0; count--){  //play sounds from high to low pitch
        tone(piezo_pin, count*250);
        delay(25);
        noTone(piezo_pin);
        delay(10);
      }
    }
  }
}

/*
below is the function change_state_checker. It outputs an integer (int), which
is why there is int in front of the name of the function. All of the variables
that we use will be integers, so whenever a function outputs a number or has
a number as an input, we will have it be an int. 
The name of the function is:
change_state_checker. Name functions something that describes what they do
so that you remember what they do. This one checks if the state of the button
has changed. It takes in the current_state of the button, which is also an
integer, which is why there is int in front of it.
I put a /**** in front of and behind the function description so that I can find
it easily in the code. You should always have a description of what the function
does above it so that you know what it does. It will also help you write the 
function if you know what it is supposed to take as an input and output.
*/

/**********
change_state_checker
checks to see if the button has already been pressed
Outputs 1 if button changes from 0 to 1
outputs 0 otherwise
***********/
int change_state_checker(int current_state){
  //in order to know whether the button was just pressed, we need to know the
  //last state of the button (whether or not the button was pressed the last time
  //that we checked the state of the button.
  static int last_state;
  /*you need to tell the arduino to remember the variable last_state. If you make
  it a static int, then the arduino will remember it every time the code calls
  this function.
  we want to check if the current state of the button is not equal to the state
  the button was in before (the last state). To check if something is not equal,
  you use != instead of ==. 
  */
  if (current_state != last_state){     //if the state of the button has changed
  /*
  Now we want to check to see if the button's last state was low. This means that
  the button went from unpressed to pressed
  */
     if (last_state == 0){       //if the last state of the button was not pressed
      //before I output something out of the function, I need to set the
      //last_state of the button to the current_state. That means that the next
      //time that we call this function, it will say that the last state is
      //the state that the button is now
      last_state = current_state;          //save the change in the current state
      return 1;     //if the button changed from 0 to 1, output 1
     }
  }
  /* 
  If the button did not go from high to low, we want to return a 0. First, though,
  we need to tell the arduino to set the last state to the current state so that
  the next time we call the function, the arduino will remember the state that the
  button is now
  */
  last_state = current_state;       //reset last_state to current_state
  return 0;                         //return 0 if I didn't get a change from 0 to 1
 }
 
//Srpc sri tia tiv tywl

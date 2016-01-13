//Sketch_8_Answer
/* 
This program will tell the arduino how to display numbers on a seven
segment display. It goes with the laser tag course.
This code only comes with comments. It is intended to help the
reader understand what they need to tell the arduino to do
(Aka, what code to write)
Remember to add comments!
*/

// Variables (nicknames for pins)
/*
We will need a variable for each of the pins that we connect to the
seven segment display so that we can turn that pin on or off
depending on what number we want to display.
All of our variables will be integers, meaning they will start with
int (variable name) = (pin number);
with the stuff in () replaced with the variable name and pin number.
*/
int top_seg = 4;            //top segment connected to pin 4
int top_right_seg = 5;      //top right segment connected to pin 5
int bottom_right_seg = 7;  //bottom right segment connected to pin 7
int bottom_seg = 8;         //bottom segment connected to pin 8
int bottom_left_seg = 9;    //bottom left segment connected to pin 9
int top_left_seg = 3;       //top left segment connected to pin 3
int middle_seg = 2;         //middle segment connected to pin 2
int dot_seg = 6;            //dot segment is connected to pin 6


void setup() {
  /*
  Now we need to tell the arduino if the pins that we are using are
  inputs or outputs. We will be sending a signal out to light up
  each of the pins of the seven segment display. You use the 
  pinMode() function to set whether a pin is an input or output. 
  pinMode() accepts two inputs, the pin number and whether it is an
  INPUT or OUTPUT.
  for example: pinMode(pin_3, OUTPUT);
  the command above would set pin 3 to be an output (assuming pin_3 is
  a variable that you set to 3)
  */
  //Note: a common error is not putting the right variable name in
  //check spelling.
  pinMode(top_seg, OUTPUT);
  pinMode(top_right_seg, OUTPUT);
  pinMode(bottom_right_seg, OUTPUT);
  pinMode(bottom_seg, OUTPUT);
  pinMode(bottom_left_seg, OUTPUT);
  pinMode(top_left_seg, OUTPUT);
  pinMode(middle_seg, OUTPUT);
  pinMode(dot_seg, OUTPUT);
}

//now for the main loop da loop
void loop() {
  /*
  we've told our arduino what pins we are using and whether those
  pins are inputs or outputs. Now we need to tell it what to display.
  Just for fun, we want to have the display switch between two numbers,
  0 and 1. You will should program the arduino to turn off all of the
  segments (maybe by writing a function to do that, since you will need
  to do that twice...), and then turn on the segments that correstpond
  to either 0 or 1. You can have it waid for 1 second between the digits.
  Be sure to add comments to your code so that you know what it is doing.
  */
  
  //turn off everything
  clear_seven_seg_display();
  //display a 0 on the seven segment display
  digitalWrite(top_seg, HIGH);
  digitalWrite(top_right_seg, HIGH);
  digitalWrite(bottom_right_seg, HIGH);
  digitalWrite(bottom_seg, HIGH);
  digitalWrite(bottom_left_seg, HIGH);
  digitalWrite(top_left_seg, HIGH);
  //delay for 1 second
  delay(1000);
  
  //now do the same thing for the number 1
  clear_seven_seg_display();
  digitalWrite(top_right_seg, HIGH);
  digitalWrite(bottom_right_seg, HIGH);
  delay(1000);
  
}

/*
Now we want to write a function that turns off all of the digits. Use
this function in the loop above so that you don't have to copy and
paste it every time you want to turn the segments off before 
turning them on to display a new digit.

/**********
clear_seven_seg_display
This function turns off all of the digits on the seven segment display
inputs: Nothing (void)
outputs: turns off all pins on the seven segment display (pins 2-9)
         Nothing to arduino
**********/
void clear_seven_seg_display( void ){
  int clear_counter = 2;
  for (clear_counter = 2, counter < 10, counter++){
    digitalWrite(clear_counter, LOW);
  }
  /*
  Note: you could also do this by writing digitalWrite( pin, LOW) a 
  bunch of times. But why do that when you have a for loop?
  If the pins aren't hooked up to 2-9, this function won't work though.
  */
}

//Tlia. Xlex aew e psx sj gshmrk. Asyphr'x mx fi kviex mj csy hmhr'x lezi xs hs epp xlex asvo xs hmwtpec e ryqfiv?

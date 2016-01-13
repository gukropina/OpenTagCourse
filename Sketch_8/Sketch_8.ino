//Sketch_8
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
  
}

/*
Now we want to write a function that turns off all of the digits. Use
this function in the loop above so that you don't have to copy and
paste it every time you want to turn the segments off before 
turning them on to display a new digit.
*/

//Tlia. Xlex aew e psx sj gshmrk. Asyphr'x mx fi kviex mj csy hmhr'x lezi xs hs epp xlex asvo xs hmwtpec e ryqfiv?

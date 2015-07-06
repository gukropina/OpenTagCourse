// this is a comment. A comment is not code that the arduino will try to run.
// a comment is a note to the programmer.
// a comment that is on one line starts with two slashes: //

/* a comment that spans multiple
lines starts with /* and ends with */

// You should always leave yourself comments that explain what you are doing
// When you don't, you'll forget what the code does and have trouble
// coming back to it later and changing stuff.

/*
When you know what you are doing, then you don't need to leave as detailed
comments, but until that point, good comments are key to good code
*/

/*
Speaking of good comments, notice how much easier this comment is to read
than the last one because there is one space before I started writing.
making your comments easy to read and understand is good and worth the time.
Don't make your comments so long that people have to make the arduino window bigger just so that they can see them because this is annoying for people who don't want to expand their window just so they can read the comment that you put in your code but decided not to press enter any time soon because you just had to write it all on one line
*/

/*
Normally, you would start a file with the following:
Name and Purpose of the file
Whether or not it is in the public domain (useful to know if other people
want to use your code).

For Example:
Sketch_2 is meant to introduce people to the arduino integrative
development environment (IDE) that is used to program the arduino
microcontroller. It goes over comments, intputs/outputs and if/else statements
This code is in the public domain.
*/

/*
The arduino has many pins that can be used to receive information from
the world (it can receive input) or send information out (output).
The arduino's pins can be used for either input or output, so you need to tell
the arduino which function that
you want the pin to perform. For this lesson and lab, we will be re-creating
turning on an LED with a button. To do this, we need to tell the arduino
which pins to use and whether we want those pins to be inputs or outputs.
The arduino's pins are labeled with numbers, but that's not easy to remember.
When programming, you can create nicknames (called variables) to name things
so that they that are easier to remember. For example, if we want to put our LED onto
pin 11 on the arduino board, we may want to create a nickname (variable) for that pin
and call it led_pin, so that we can use the word led_pin in our code instead of
the number 11. That line of code is shown below. It
creates a variable (an int or integer, which will be described later)
called led_pin and sets it equal to 13. the ; tells the arduino code that it is
the end of the line of code.
Note: nicknames (variables) can't have spaces. You can use underscores (_)
though, to separate your words and make them easier to read
*/
int led_pin = 11;

/*
We also want to give a nickname for the pin that we attach to
the button. Why? Because we want to see if the button is pressed and
turn on the LED if the button is pressed, so we need another nickname
to keep track of the pin that the button is attached to.
*/
int button_pin = 12;

/*
Now that we have nicknames that we can remember, we can start coding.
Arduino sketches always have two things:
1. a setup routine
2. a loop routine.
The setup routine is run
every time the processor is turned on or reset. This is where you set
pins to be inputs or outputs or do things that you want to happen every time
you start or reset the arduino. After that comes the loop routine, which
runs whatever code is in the loop over and over and over until the arduino
turns off.
*/

/*
the setup routine runs once when you press reset and when the arduino
turns on for the first time:
it looks like this:
void setup() {
Here are what that means:
1. void means that the routine does not send anything back
after it is done running. You can have the arduino return or send something
after it is done running some code, but this code doesn't require that.
2. setup is the name of the routine. A routine or grouping of code is called a
function, which we will explore more later
3. The two parenthesis () mean that there is no input to setup. Other functions
can have inputs, which you would put between the parenthesis (we don't need
and input for setup, and never will)
4. Finally, the curly bracket, { tells the arduino that all the code
starting here is for the setup function.
*/

void setup() {

/*
So, we want to have our led pin be an output. Fortunately, the arduino IDE
has a lot of built in functions that make it easy to do things. For example,
the pinMode function lets you tell the arduino to change a pin to an input
or output. You can set a pin to an input or ourput by writing the command
pinMode( pin to set, OUTPUT or INPUT);
You'll notice that output is written in all capitals.
That is because OUTPUT has a special meaning in arduino sketches, and when
the code is compiled from code that you can read (for example, the word
pinMode) into code that the arduino actually runs (it only understands 1s
and 0s, voltage high and voltage low), the compiler (the software that
converts human readable code into machine readable code) will replace
all instances of the word OUTPUT with the correct value so that the arduino
knows to make the pin an OUTPUT. This is similar to how we created a
nickname for the pin that we attached our LED and button to.
*/
pinMode(led_pin, OUTPUT);
//now we need to set the button pin to be an input
pinMode( button_pin, INPUT);
// we now have our pins set, so we can write our code.

} //this curly bracket ends the setup routine.
// curly brackets tell the program that all the code you write in between the
// brackets belongs to a specific routine or function.

// the loop routine runs over and over again forever:
void loop() {
/*
Now that we have set everything up, we can tell the arduino what to do.
But first we need to have a clear idea of what we want it to do.
We want the arduino to see whether or not a button is pressed and turn on
an LED only if it is pressed. Written another way, if the button is pressed,
we want to turn the LED on, otherwise we will turn it off.
Fortunately, there is a command called if that checks to see if something
is on or off. Since the arduino only understands voltage, it thinks that
HIGH voltage (5 volts) is on and LOW voltage (0 Volts) is off. Remember
that the arduino can't count to 5. If it sees a HIGH voltage signal, it
will count that as a 1.
*/

/*
Now that we know that we want to use an if statement to check to see if the
button is pressed, we are going to make another variable that keeps track of
the button so that we can see if that variable is high or low (1 or 0).
The circuit is shown in Lesson 1, and the button_pin will be high (1) if
the button is pressed and low (0) if the button is not pressed. We want to
read the voltage of the button pin, and to do that arduino has a command
called digitalRead. This reads in the value of a pin as either high (1) or
low (0). It is called digitalRead because it will read in only a digital
value, which is either 1 or 0. It will only output 1 or 0, nothing in between.
If the voltage value is not 0V or 5V, it will round to 1 or 0 depending on
how close the voltage is to 0 or 5. digitalRead works by writing
digitalRead( pin to read voltage from);
*/
int button_state = digitalRead( button_pin );
/*
Note: In later code, all of our variables that we want to use throughout the
sketch (global variables) will be defined before we call the setup routine.
This is so that every time we run the loop, we don't make another
button_state variable. I'm doing it this way so that you can see what is
going on.
*/

/*
Now we want to see if the button is high or low. To do that, we want to
check to see if the button_state variable is equal to 1 or 0. To compare
two values, we can use two equals signs (==). One equals sign is used to
set a value, for example button_state = 0. Two equals signs tells the
arduino to compare the two values and see if they are equal. If they are,
then the statement is true or 1. If not, the statement is false or 0. This
is how we can use the if statement, by checking to see if a certain condition
is true.
Note: after a function or an if statement, you should indent your code to make
it easier to know where that code fits in the grand scheme of things.
*/
  if (button_state == HIGH) {
  // turn LED on
  digitalWrite(led_pin, HIGH);
  }
/*
But what if the button is not pressed? Then we want to execute a different
piece of code. After an if (or series of if statements), you can write an
else statement that will run if the if code did not run. So, we want
to turn the LED off if the button is not pressed. To do that, we use the
else command (which doesn't have a condition to check, and uses curly
brackets to tell the arduino what code to execute.
*/
  else {
  //turn LED off
  digitalWrite(led_pin, LOW);
  }

/*
That's it. The arduino will now constantly check the the voltage on the
button pin and turn the LED on or off depending on whether the button is
pressed or not.
*/

} // this curly bracket ends the loop. When the arduino runs the code and gets
// to this point, it will start the loop over.

/*
Here is the complete code without my comments. Does it make sense?
*/

// Hmh csy jmkyvi syx xli Giewev gmtliv?
// 4

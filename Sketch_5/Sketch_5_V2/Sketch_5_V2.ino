//Sketch_5
/* This program goes with Lab 5 of the OpenTag laser tag tutorial.
It plays a basic game of free for all laser tag. A player is out
if they get tagged 5 times.
We add a piezo speaker to this code to make sounds when you send a
tag, receive a tag, can't tag, and are out.
*/


#include <TimerOne.h>
//TimerOne will make it easy to pule an infrared LED 38,000 times
//a second

// Variables (nicknames for pins)
int button_pin = 12;
int led_pin = 11;
int ir_led_pin = 10;
int ir_receiver_pin = 9;
int piezo_pin = 2;

//you start with 5 health.
int health = 5;

void setup() {
  //first, start up TimerOne. We want it to pulse
  //38,000 times a second, which is about once every 26 milliseconds
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
        //start with the highest note. Since I'm using 20 notes,
        //I want to have each note go lower in pitch by
        //5000/20 = 250 (since my highest note is 5000)
        //I want to multiply my count by 250. To do that, I use
        //the * symbol, which stands for multiplication in the
        //arduino programming language.
        tone(piezo_pin, count*250);
        delay(25);
        noTone(piezo_pin);
        delay(10);
      }
}

void loop() {
  int button_state = digitalRead( button_pin );   //read button
  if (button_state == HIGH) {           //if the button is pushed
    if (health > 0){                    //if we have health
      Timer1.pwm(ir_led_pin, 512);      //send pulse
      delay(10);                        //delay for 10 milliseconds
      Timer1.disablePwm(ir_led_pin);    //turn off Timer One
      /*******
      now we want to make a sound to indicate that we are
      sending a tag. To tell the arduino to play a sound on the
      piezo we attached to the piezo_pin, we use the tone function.
      This function is build into arduino. The tone function
      needs to know what pin the piezo is connected to and what
      pitch the sound should be. The pitches can as high as 
      5,000 vibrations per second and as low as 31. You can
      experiment with different values and choose the pitch
      that sounds good to you. We are going to start with having
      the arduino make a high pitched sound when you send a tag
      */
      tone(piezo_pin, 5000);           //make a high pitched sound
      delay(25);                       //wait for 0.025 seconds
      noTone(piezo_pin);               //stop making sound
      delay(25);                       //wait for a little bit
    }
    else{                              //if we don't have health
      /********
      So, if we don't have enough health, make a different sound
      We can make a lower pitched sound to make it sound
      different then the sending tag code. In fact, we can have
      two different notes play to make it sound cooler
      */
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
    
    /******
    If we don't have any health left, we want to make another
    sound to indicate that we don't have any health left
    I want it to play 20 notes from across the pitches the
    arduino can play. However, I don't
    want to copy and paste the same code 20 times. Can't we write
    some code that does the same thing over again a few times?
    I mean, we have a mail loop, can't we have a smaller one?
    Yes!
    It's called a for loop. A for loop basically tells the arduino
    do do something a certain number of times. You are telling the
    arduino to count between two numbers, and every time it counts
    it does a specific thing.
    */
    if (health == 0){              //if we are out of health
      /*
      first, we need to tell the arduino what number to start
      counting from. We are going to have the arduino count down
      from 20. So to start, we create a variable for the arduino
      to keep track of what number it counted to
      Now that we know where the arduino should count to, we need
      to tell it when to stop. We want to stop counting when the
      count is 0. So, we will say to keep counting as long as the
      count is greater than 0. This is the second part of the for 
      loop.
      The final part is to tell the arduino if we are counting 
      up or counting down. To count up, we put two + simbols.
      To count down, we put two - symbols.
      when you put it all together, the command looks like this:
      for(variable we count with; when to stop counting; count up or
      count down)
      So, here's the for loop, below
      */
      int count = 0;
      for (count = 20; count > 0; count--){
        //start with the highest note. Since I'm using 20 notes,
        //I want to have each note go lower in pitch by
        //5000/20 = 250 (since my highest note is 5000)
        //I want to multiply my count by 250. To do that, I use
        //the * symbol, which stands for multiplication in the
        //arduino programming language.
        tone(piezo_pin, count*250);
        delay(25);
        noTone(piezo_pin);
        delay(10);
      }
    }
  }
}
//Xyri mr ribx xmqi. Wii alex M hmh xlivi? Xyri.

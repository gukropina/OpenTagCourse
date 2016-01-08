//this is a comment on one line

/*
this is a comment
on multiple lines
*/

//Variables (pins)

int led_pin = 11;         //LED is connected to pin 11
int button_pin = 12;      //Button is connected to pin 12

//start with setup routine to tell the arduino what to do with the pins

void setup() {
  pinMode(led_pin, OUTPUT);   //set led_pin to output to send electricity out
  pinMode(button_pin, INPUT); //set button_pin to input to sense electricity
}

//start the main loop

void loop() {
  //create a new variable and check the if the button is pressed.
  int button_state = digitalRead( button_pin );
  //digitalRead tells the arduino to check if there is voltage at a pin
  
  //check if there was voltage there.
  if(button_state == HIGH){
    //if there was, turn on the LED
    digitalWrite(led_pin, HIGH);
  }
  else{
    //if not, turn LED off
    digitalWrite(led_pin, LOW);
  }
  
}

// Hmh csy jmkyvi syx xli Giewev gmtliv?
// 4

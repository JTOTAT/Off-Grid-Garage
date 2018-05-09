/*
 
 Turns on and off a string of light emitting diodes(LED) connected to SSR via digital
 pins 5,4,3 when switch is activated on pins 6,8,9.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 
 */

// constants won't change. They're used here to


// pins 6,8,9 are switch pins
// pins 3,4,5 are SSR pins
// need flag not on time loops

// set pin numbers:
const int SWPin1 = 6;     // Mag Sw1 at door
const int SWPin2 = 8;     // Mag Sw2 at car
const int SWPin3 = 9;     // Latch switch at door
const int SSR3 =  3;      // the number of the SSR1 pin
const int SSR4 =  4;      // the number of the SSR1 pin
const int SSR5 =  5;      // the number of the SSR1 pin

// variables will change:
int SW1State = 0;         // variable for reading the PIR1 status
int SW2State = 0;         // variable for reading the Switch1 status

int walkway = 0;


void setup() {

   Serial.begin(9600);
  // initialize the LED pin as an output:

  pinMode(6, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  
  pinMode(SSR3, OUTPUT);
  pinMode(SSR4, OUTPUT);
  pinMode(SSR5, OUTPUT);  
}

void loop() {
  

 //read the pushbutton value into a variable
   int SWPin1= digitalRead(6);
   //print out the value of the pushbutton
    Serial.print("SWPin1");       
   Serial.println(SWPin1);
   
//read the pushbutton value into a variable
   int SWPin2= digitalRead(8);
   //print out the value of the pushbutton
   Serial.print("SWPin2");   
   Serial.println(SWPin2);

    //read the pushbutton value into a variable
   int SWPin3= digitalRead(9);
   //print out the value of the pushbutton
  Serial.print("SWPin3");   
   Serial.println(SWPin3);

  
 
 if (SWPin3 == HIGH) {  // pin 9 wall switch 
     digitalWrite(SSR5, LOW);
   } else {
     digitalWrite(SSR5, HIGH);
   }

if (SWPin1 == HIGH) {  // pin 6 mag reed switch at door pulled to ground
     digitalWrite(SSR5, LOW);
   } else {
     digitalWrite(SSR5, HIGH);
     walkway = 1; // going INTO 
    delay (60000); // this might miss garage door switch!
   }

if (SWPin2 == HIGH) {  // pin 6 mag reed switch at garage door pulled to ground
     digitalWrite(SSR5, LOW);
   } else {
     digitalWrite(SSR5, HIGH);// unless walkway = 1
     walkway = 2; // driving into garage 
    delay (120000);
   }
 
   delay (200);
}

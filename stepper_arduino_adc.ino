/*
 * File: Stepper Motor Speed Control using ADC - Arduino 
 * Author: ron / Rakesh Mondal
 * December 20, 2013, 4:21 AM
 ** www.rakeshmondal.info                      
 */ 
int readADC = A0;    //input pin for the potentiometer
int onbrdLED = 13, l1 = 8, l2 = 9, l3 = 10 , l4 = 11;
int Spd;             // Variable to set the delay accoding to ADC val
int sometempvariable = 0;  // Some temp  var for adc val

void setup()
  {
    Serial.begin(9600);
    DDRB = B001111; // Setting ddrb register to set pin 8 to 11 as output
   }
   
void loop() 
{
sometempvariable = analogRead(readADC);  

  if (sometempvariable <=  85)    {  Spd =8;  }
else if (sometempvariable <= 170) { Spd = 10; }
else if (sometempvariable <= 255) { Spd = 12; }
else if (sometempvariable <= 340) { Spd = 15; }
else if (sometempvariable <= 425) { Spd = 17; }
else if (sometempvariable <= 510) { Spd = 20; }
else if (sometempvariable <= 595) { Spd = 23; }
else if (sometempvariable <= 680) { Spd = 27; }
else if (sometempvariable <= 765) { Spd = 31; }
else if (sometempvariable <= 850) { Spd = 40; }
else if (sometempvariable <= 935) { Spd = 45; }
 else  {  Spd = 60; }

Serial.println(Spd);   // print ADC value of analog reading

//--------------------
digitalWrite(onbrdLED, HIGH);  
digitalWrite(l1, HIGH); digitalWrite(l2, HIGH); digitalWrite(l3, LOW); digitalWrite(l4, LOW);  
delay(Spd); 

digitalWrite(onbrdLED, LOW); 
digitalWrite(l1, LOW); digitalWrite(l2, HIGH); digitalWrite(l3, HIGH); digitalWrite(l4, LOW);  
delay(Spd); 

digitalWrite(onbrdLED, HIGH); 
digitalWrite(l1, LOW); digitalWrite(l2, LOW); digitalWrite(l3, HIGH); digitalWrite(l4, HIGH);  
delay(Spd); 
   
digitalWrite(onbrdLED, LOW);  
digitalWrite(l1, HIGH); digitalWrite(l2, LOW); digitalWrite(l3, LOW); digitalWrite(l4, HIGH);  
delay(Spd); 
//---------------------
}

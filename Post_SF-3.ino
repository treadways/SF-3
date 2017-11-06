
const int led = 7;      //give pins names
const int buzzer = 11;
const int sensor = 0;
const int button = 4;

int lightLevel, buttonState; //create variables
int alarmStatus = 0;


void setup()   //set up pins
{
  pinMode(led, OUTPUT);  
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);
  
}

void loop()
{
  lightLevel = analogRead(sensor); //read sensor to see if there's light
  lightLevel = map(lightLevel, 420, 850, 0, 100);  //put sensor data on a scale between 0-100
  lightLevel = constrain(lightLevel, 0, 100); //only use data in range 0-100

  if (lightLevel > 50) //higher light level than 0 to only be sesitive to light directly near it turned on (for the purpose of this assignment)
  {
    alarmStatus = 1; //create a variable to initiate while loop
  }

  while (alarmStatus == 1) //start loop if sensor recieved light
  {
   alarm(); //start alarm function

   buttonState = digitalRead(button); //read button signal
   
   if (buttonState == HIGH) //if button is pressed start if statement
   {
    reset(); //reset function
   }
  }
}

void alarm() //this function turns on the alarm (both the buzzer and lights)
{
   digitalWrite(led, HIGH); //turn on lights
   
   tone(buzzer, 200, 10); //my own obnoxious noise alarm
   delay(10);
   tone(buzzer, 400, 10);
   delay(10);
   tone(buzzer, 600, 10);
   delay(10);
}   

void reset() //this function resets the buzzer and lights
{
    digitalWrite(led, LOW); //turn off lights
    tone(buzzer, 0, 10); //turn off buzzer
    alarmStatus = 0; //put status back to 0
    delay(5000); //wait five seconds before letting sensor recieve data
}



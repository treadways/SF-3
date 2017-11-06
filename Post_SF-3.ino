
const int led = 7;      //set up pins
const int buzzer = 11;
const int sensor = 0;
const int button = 4;

int lightLevel, buttonState; 
int alarmStatus = 0;


void setup()
{
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);
  
}

void loop()
{
  lightLevel = analogRead(sensor);
  lightLevel = map(lightLevel, 420, 850, 0, 100);
  lightLevel = constrain(lightLevel, 0, 100);

  if (lightLevel > 15)
  {
    digitalWrite(led, HIGH);

    alarmStatus = 1;
  }

  while (alarmStatus == 1)
  {
   tone(buzzer, 200, 10);
   delay(10);
   tone(buzzer, 400, 10);
   delay(10);
   tone(buzzer, 600, 10);
   delay(10);
   
   buttonState = digitalRead(button);
   
   if (buttonState == HIGH)
   {
    digitalWrite(led, LOW);
    tone(buzzer, 0, 10);
    delay(5000);
    alarmStatus = 0;
   }
  }
}



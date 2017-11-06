
const int led = 7;      //set up pins
const int buzzer = 11;
const int sensor = 0;
const int button = 4;

int lightLevel, buttonState; alarmStatus


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
    
    int i = 200;
    while ( i < 800);
    {
    i++;
    tone(buzzer, i);
    }
    
    while ((i >= 800) && (i < 1400))
    {
      i++;
      tone(buzzer, 1400 - i);
    }
    alarmStatus = 1;
  }
  
 while (alarmStatus == 1)
  {
   buttonState = digitalRead(button);
   
   if (buttonState == HIGH)
   {
    digitalWrite(led, LOW);
    noTone(buzzer);
    delay(5000);
   }
  }
}



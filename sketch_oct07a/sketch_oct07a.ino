const int LEDS[5] = {4,5,6,7,8};
int buzz_pin = 3;
int hum_pin = A0;
int humValue = 0;
int mapValue = 0;

void setup(){
  Serial.begin(9600);
  for(int i= 0; i < 5; i ++){
    pinMode(LEDS[i], OUTPUT);
  }
  pinMode(buzz_pin, OUTPUT);
  pinMode(hum_pin, INPUT);  
}

void loop(){
  humValue = analogRead(hum_pin);
  Serial.println(humValue);
  Serial.print(' ');
  Serial.println(mapValue);
  Serial.print(' ');
  
  mapValue = map(humValue, 0, 876, 0, 100);
  
  if(mapValue <= 20){
    tone(buzz_pin, 1000, 100);
    delay(100);
  }
  
  if(mapValue >= 80){
    tone(buzz_pin, 2000, 1000);
  }
  
  if(mapValue = 100){
    for(int i= 0; i < 5; i ++){
      //mapValue = map(humValue, 0, 876, 0, 100);
      digitalWrite(LEDS[i], HIGH);
    }
    } else if(mapValue < 100){
      for(int i= 0; i < 5; i ++){
          digitalWrite(LEDS[i], LOW);
      }
  }
}

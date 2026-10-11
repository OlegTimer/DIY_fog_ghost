//by OlegTim
#define HC_TRIG 12
#define HC_ECHO 11
#define RELAY1 10
#define RELAY2 9
int cooldown = 60000 ;
int counter = 0 ;
int trigcount = 7 ;
int work = 4000 ;

float getDist(uint8_t trig, uint8_t echo) {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  uint32_t us = pulseIn(echo, HIGH);
  return us / 58.2;
}

void setup() {
     
  pinMode(HC_TRIG, OUTPUT); 
  pinMode(HC_ECHO, INPUT);  
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  digitalWrite(RELAY1, HIGH);   
  digitalWrite(RELAY2, HIGH); 
}

void loop() {
  float dist = getDist(HC_TRIG, HC_ECHO); 
    Serial.println(dist); 
  delay(250);
  
  if (dist < 80.0) {
    if (counter>trigcount){
      counter=0;
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);
   delay(work);
  digitalWrite(RELAY1, HIGH);   
  digitalWrite(RELAY2, HIGH);               
  delay(cooldown);
    }
    else{counter++;}
  }
  
}
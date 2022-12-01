#define SensorPin A0
int sensorValue = 0;
int sensorValueP;

int suchost = 30;
#define rele 7

char income = 0;

void setup() {
  Serial.begin(9600);

  pinMode(rele, OUTPUT);
}

void loop() {
  if(Serial.available()>0){
    income = Serial.read();
    Serial.println(income);
  }

  switch(income){
    case '1':
    digitalWrite(rele, LOW);
    break;

    default:
    sensorValue = analogRead(SensorPin);
    delay(30);
    if(map(sensorValue, 703, 420, 0, 100) <= suchost){
      digitalWrite(rele, LOW);
    }else{
      digitalWrite(rele, HIGH);
  }
  }
  

}

#define SensorPin A0
int sensorValue = 0;
int sensorValueP;

int suchost = 30;
#define rele 7

void setup() {
  Serial.begin(9600);

  pinMode(rele, OUTPUT);
}

void loop() {
  sensorValue = analogRead(SensorPin);
  sensorValueP = map(sensorValue, 703, 420, 0, 100);
  Serial.println(sensorValueP);

  if(sensorValueP <= suchost){
    
  }

}

//knihovny Adafruit
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
// Resetuje piny (důležité pro knihovnu; v kódu nepoužito)
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


#define SensorPin A0 //definujeme pin vlhkoměru
int sensorValue = 0; //proměnná hodnot z vlhkoměru
int sensorValueP; //proměnná, do které převádíme hodnoty vlhkoměru na procenta
char income="0";
int suchost = 25; // proměnná, do které v procentech zapíšeme požadovanou porovnávací hodnotu
#define rele 7

void setup() {
Serial.begin(9600); //spuštění výpisů do Serial monitoru

display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //zde sdělíme kódu, že budeme používat displej

pinMode(rele, OUTPUT);

}
void displaySensor(){
  //prodleva pro načtení displeje
  delay(2000);
  // Vyčistí displej od minulého zobrazení
  display.clearDisplay();
  //nastaví barvu (správně by se jiná než bílá neměla používat)
  display.setTextColor(WHITE);
  //nastaví velikost písma
  display.setTextSize(1);
  //nastaví pozici kurzoru pro výpis
  display.setCursor(0,0);
  //vypíše vedle sebe následující: Vlhkost: <hodnota>%
  display.print("Vlhkost: ");
  display.print(map(sensorValue, 653, 380, 0, 100));
  display.print("%");
}

void loop() {
  displaySensor(); //spustí se výše definovaná metoda
  display.display(); //provedou se všechny operace pro displej

if(Serial.available()>0){
    income = Serial.read();
    Serial.println(income);
 }
 
  switch(income){
  case '1':
  digitalWrite(rele, LOW);   
  break;
  
  default:
  sensorValue = analogRead(SensorPin); //do sensorValue se uloží výpis z vlhkoměru
  Serial.println(map(sensorValue, 653, 380, 0, 100));
    delay(30); //prodleva 30ms
    if(map(sensorValue, 653, 380, 0, 100) >= suchost){ //kontrola když je hodnota z vlhkoměru vyšší než suchost
    digitalWrite(7, HIGH); //sepne relé
    delay(500); // pro lepší funkčnost displeje 
    }else{
    digitalWrite(7, LOW);//nesepne relé
    }
    
  }  

  
  }

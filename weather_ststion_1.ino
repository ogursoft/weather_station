#include <OneWire.h>
#include <DallasTemperature.h>
 
OneWire oneWire(15);// вход датчиков 18b20
DallasTemperature ds(&oneWire);

byte qty; // количество градусников на шине 

void setup() {
  Serial.begin(9600);
  ds.begin();
  
  qty = ds.getDeviceCount(); 
  Serial.print("Found ");
  Serial.print(qty);
  Serial.println(" devices.");
    //
  
}

void loop() {
  ds.requestTemperatures(); // считываем температуру с датчиков
  
  for (int i = 0; i < qty; i++){ // крутим цикл 
    Serial.print("Sensor ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(ds.getTempCByIndex(i)); // отправляем температуру
    Serial.println("C"); 
  } 
  Serial.println();
}

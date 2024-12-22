#include <DHT.h>

#define DHTPIN 4     // G4 on ESP32
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("DHT22 Module Test!");
  delay(2000);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(1000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C");
  Serial.print("\tHumidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000);
}
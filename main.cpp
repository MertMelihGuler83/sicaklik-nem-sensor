#include <DHT.h>

#define DHTPIN 2      // DHT11 veri pini Arduino'nun 2 numaralı pinine bağlı
#define DHTTYPE DHT11 // Sensör tipi DHT11 olarak ayarlandı

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Veri alınamıyor");
    return;
  }

  Serial.print("Nem: ");
  Serial.print(humidity);
  Serial.print("%  Sıcaklık: ");
  Serial.print(temperature);
  Serial.println("°C");

  delay(2000);
}

#include <LiquidCrystal.h>
#include <DHT.h>

// Pin definitions
#define MQ135_PIN A0
#define LDR_PIN A1
#define BUZZER 8
#define DHTPIN 7
#define DHTTYPE DHT11

// Initialize LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

int gasValue = 0;
int ldrValue = 0;
float temperature;
float humidity;

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  dht.begin();

  pinMode(BUZZER, OUTPUT);

  lcd.print("Air Monitor");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read sensors
  gasValue = analogRead(MQ135_PIN);
  ldrValue = analogRead(LDR_PIN);
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  // Check if DHT reading failed
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT Error!");
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error   ");
    delay(2000);
    return;
  }

  // Display Gas Value
  lcd.setCursor(0, 0);
  lcd.print("Gas:");
  lcd.print(gasValue);
  lcd.print("   ");

  // Display Temp & Humidity
  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print("C H:");
  lcd.print(humidity);
  lcd.print("% ");

  // Buzzer condition
  if (gasValue > 400) {   // Threshold
    digitalWrite(BUZZER, HIGH);
  } else {
    digitalWrite(BUZZER, LOW);
  }

  // Serial Monitor (debugging)
  Serial.print("Gas: ");
  Serial.print(gasValue);
  Serial.print(" | Temp: ");
  Serial.print(temperature);
  Serial.print(" | Humidity: ");
  Serial.print(humidity);
  Serial.print(" | LDR: ");
  Serial.println(ldrValue);

  delay(2000);
}

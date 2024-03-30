// Определение пинов и интервалов
const int pin3 = 3;
const unsigned long interval3 = 10000;  // 10 мс
const int pin5 = 5;
const unsigned long interval5 = 1000;   // 1 мс
const int pin6 = 6;
const unsigned long interval6 = 500;    // 500 мкс
const int pin9 = 9;
const unsigned long interval9 = 100;    // 100 мкс
const int pin10 = 10;
const unsigned long interval10 = 50;    // 50 мкс

unsigned long previousMicros3 = 0;
unsigned long previousMicros5 = 0;
unsigned long previousMicros6 = 0;
unsigned long previousMicros9 = 0;
unsigned long previousMicros10 = 0;

void setup() {
  pinMode(pin3, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
}

void loop() {
  unsigned long currentMicros = micros();

  // Пин 3
  if (currentMicros - previousMicros3 >= interval3) {
    previousMicros3 = currentMicros;
    digitalWrite(pin3, !digitalRead(pin3));
  }

  // Пин 5
  if (currentMicros - previousMicros5 >= interval5) {
    previousMicros5 = currentMicros;
    digitalWrite(pin5, !digitalRead(pin5));
  }

  // Пин 6
  if (currentMicros - previousMicros6 >= interval6) {
    previousMicros6 = currentMicros;
    digitalWrite(pin6, !digitalRead(pin6));
  }

  // Пин 9
  if (currentMicros - previousMicros9 >= interval9) {
    previousMicros9 = currentMicros;
    digitalWrite(pin9, !digitalRead(pin9));
  }

  // Пин 10
  if (currentMicros - previousMicros10 >= interval10) {
    previousMicros10 = currentMicros;
    digitalWrite(pin10, !digitalRead(pin10));
  }
}

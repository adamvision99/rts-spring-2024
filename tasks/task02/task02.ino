#include <TaskManagerIO.h>

// Определение констант пинов и периодов в микросекундах
const int pins[] = {3, 5, 6, 9, 10};
const unsigned long periods[] = {10000, 1000, 500, 100, 50}; // Периоды для каждого пина
const int numPins = sizeof(pins) / sizeof(pins[0]); // Количество пинов
int states[numPins] = {LOW}; // Начальные состояния пинов, инициализированы как LOW

void setup() {
  // Настройка направления каждого пина на OUTPUT
  for (int i = 0; i < numPins; i++) {
    pinMode(pins[i], OUTPUT);
    // Запланировать переключение каждого пина с соответствующим периодом
    taskManager.scheduleFixedRate(periods[i], [i] {
      states[i] = !states[i]; // Переключение состояния
      digitalWrite(pins[i], states[i]); // Установить новое состояние пина
    }, TIME_MICROS);
  }
}

void loop() {
  taskManager.runLoop(); // Выполнение планировщика задач
}

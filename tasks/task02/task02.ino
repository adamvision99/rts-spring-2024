#include <TaskScheduler.h>

// Инициализируем объект планировщика задач
Scheduler scheduler;

// Создаем таски для каждого из импульсов
Task task1(10, TASK_FOREVER, [](){
  digitalWrite(3, HIGH);
  delayMicroseconds(5000);
  digitalWrite(3, LOW);
  delay(5000);
});

Task task2(1000, TASK_FOREVER, [](){
  digitalWrite(5, HIGH);
  delayMicroseconds(500);
  digitalWrite(5, LOW);
  delay(500);
});

Task task3(500, TASK_FOREVER, [](){
  digitalWrite(6, HIGH);
  delayMicroseconds(250);
  digitalWrite(6, LOW);
  delay(250);
});

Task task4(100, TASK_FOREVER, [](){
  digitalWrite(9, HIGH);
  delayMicroseconds(50);
  digitalWrite(9, LOW);
  delay(50);
});

Task task5(50, TASK_FOREVER, [](){
  digitalWrite(10, HIGH);
  delayMicroseconds(25);
  digitalWrite(10, LOW);
  delay(25);
});

void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  // Добавляем созданные таски в планировщик
  scheduler.addTask(task1);
  scheduler.addTask(task2);
  scheduler.addTask(task3);
  scheduler.addTask(task4);
  scheduler.addTask(task5);

  // Задаем интервал обновления планировщика (1 мс)
  scheduler.startPeriodic(1);
}

void loop() {
  // Запускаем планировщик задач
  scheduler.execute();
}
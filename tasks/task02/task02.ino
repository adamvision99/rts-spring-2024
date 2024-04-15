#include <TaskScheduler.h>

// Инициализируем объект планировщика задач
Scheduler scheduler;

bool state1 = HIGH, state2 = HIGH, state3 = HIGH, state4 = HIGH, state5 = HIGH;

// Создаем таски для каждого из импульсов
Task task1(5000, TASK_FOREVER, [](){
  digitalWrite(3, state1);
  state1 = !state1;
}, nullptr, true);

Task task2(500, TASK_FOREVER, [](){
  digitalWrite(5, state2);
  state2 = !state2;
}, nullptr, true);

Task task3(250, TASK_FOREVER, [](){
  digitalWrite(6, state3);
  state3 = !state3;
}, nullptr, true);

Task task4(50, TASK_FOREVER, [](){
  digitalWrite(9, state4);
  state4 = !state4;
}, nullptr, true);

Task task5(25, TASK_FOREVER, [](){
  digitalWrite(10, state5);
  state5 = !state5;
}, nullptr, true);

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

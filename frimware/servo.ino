
//Servo moove func
void servoRun(int targetPos) {
  if (targetPos > position) {
    while (targetPos > position) {
      position++;
      servo.write(position); // сообщаем микро серво угол поворота
      delay(20); // ждем 10 мс, пока микро серво не сделает поворот
    }
  }
  if (targetPos < position) {
    while (targetPos < position) {
      position--;
      servo.write(position); // сообщаем микро серво угол поворота
      delay(20); // ждем 10 мс, пока микро серво не сделает поворот
    }
  }
}

#define LEFT_IR 13
#define DOWN_IR 12
#define RIGHT_IR 11
#define UP_IR 10

#define LEFT_RED 9
#define LEFT_YELLOW 8
#define LEFT_GREEN 7

#define DOWN_RED 6
#define DOWN_YELLOW 5
#define DOWN_GREEN 4

#define RIGHT_RED 3
#define RIGHT_YELLOW 2
#define RIGHT_GREEN 1

#define UP_RED A1
#define UP_YELLOW A2
#define UP_GREEN A3

void setup() {
  pinMode(LEFT_IR, INPUT);
  pinMode(DOWN_IR, INPUT);
  pinMode(RIGHT_IR, INPUT);
  pinMode(UP_IR, INPUT);

  pinMode(LEFT_RED, OUTPUT);
  pinMode(LEFT_YELLOW, OUTPUT);
  pinMode(LEFT_GREEN, OUTPUT);

  pinMode(DOWN_RED, OUTPUT);
  pinMode(DOWN_YELLOW, OUTPUT);
  pinMode(DOWN_GREEN, OUTPUT);

  pinMode(RIGHT_RED, OUTPUT);
  pinMode(RIGHT_YELLOW, OUTPUT);
  pinMode(RIGHT_GREEN, OUTPUT);

  pinMode(UP_RED, OUTPUT);
  pinMode(UP_YELLOW, OUTPUT);
  pinMode(UP_GREEN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  setAllRedsHigh();
  manageTraffic();
}

void setAllRedsHigh() {
  digitalWrite(LEFT_RED, HIGH);
  digitalWrite(RIGHT_RED, HIGH);
  digitalWrite(UP_RED, HIGH);
  digitalWrite(DOWN_RED, HIGH);
}

void manageTraffic() {
  if (digitalRead(LEFT_IR)) {
    Serial.println("Left IR detected");
    setLaneLights(LEFT_RED, LEFT_YELLOW, LEFT_GREEN, 3000, 5000);
  } else {
    Serial.println("Left IR not detected");
    setLaneLights(LEFT_RED, LEFT_YELLOW, LEFT_GREEN, 2000, 10000);
  }

  if (digitalRead(DOWN_IR)) {
    setLaneLights(DOWN_RED, DOWN_YELLOW, DOWN_GREEN, 3000, 5000);
  } else {
    setLaneLights(DOWN_RED, DOWN_YELLOW, DOWN_GREEN, 2000, 10000);
  }

  if (digitalRead(RIGHT_IR)) {
    setLaneLights(RIGHT_RED, RIGHT_YELLOW, RIGHT_GREEN, 3000, 5000);
  } else {
    setLaneLights(RIGHT_RED, RIGHT_YELLOW, RIGHT_GREEN, 2000, 10000);
  }

  if (digitalRead(UP_IR)) {
    setLaneLights(UP_RED, UP_YELLOW, UP_GREEN, 3000, 5000);
  } else {
    setLaneLights(UP_RED, UP_YELLOW, UP_GREEN, 2000, 10000);
  }
}

void setLaneLights(int red, int yellow, int green, int yellowDuration, int greenDuration) {
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  delay(yellowDuration);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  delay(greenDuration);
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
}

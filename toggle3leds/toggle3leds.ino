
enum State {
  RED,
  GREEN,
  WHITE,
};

int pushButton = 2;
int joystickSwtch = 6;
const int X_PIN = A0; // analog pin connected to X output
const int Y_PIN = A1; // analog pin connected to Y output


int redLed = 8;
int greenLed = 12;
int whiteLed = 13;

enum State state = RED;

int enteredIfFlag = 0;
int x_offset;
int y_offset;

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
pinMode(joystickSwtch, INPUT_PULLUP);

  pinMode(redLed, OUTPUT);
  pinMode(whiteLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  x_offset = analogRead(X_PIN);  // Read X-axis value
  y_offset = analogRead(Y_PIN);  // Read Y-axis value

}

void loop() {
  int buttonState = digitalRead(pushButton);
  int joystickSwtchState = digitalRead(joystickSwtch);

  int xValue = analogRead(X_PIN) - x_offset;  // Read X-axis value
  int yValue = analogRead(Y_PIN) - y_offset;  // Read Y-axis value

  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" | Y: ");
  Serial.print(yValue);
  Serial.print(" | swtch: ");
  Serial.println(joystickSwtchState);

  if (buttonState == 1 && enteredIfFlag == 0){
    state = switchState(state);
    enteredIfFlag = 1;
  }

  if(buttonState == 0){
    enteredIfFlag = 0;
  }

  if(state == RED){
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(whiteLed, LOW);
  } else if(state == GREEN){
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(whiteLed, LOW);
  } else if(state == WHITE){
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(whiteLed, HIGH);
  }

  delay(5);
}

State switchState(State s){
  if(s == RED){
    return GREEN;
  } else if(s == GREEN){
    return WHITE;
  } else if (s == WHITE) {
    return RED;
  }
}

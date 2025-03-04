
enum State {
  RED,
  GREEN,
  WHITE,
};

int pushButton = 2;
int redLed = 8;
int greenLed = 12;
int whiteLed = 13;

enum State state = RED;

int enteredIfFlag = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);

  pinMode(redLed, OUTPUT);
  pinMode(whiteLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

}

void loop() {
  int buttonState = digitalRead(pushButton);

  Serial.println(buttonState);

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

  delay(1);
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

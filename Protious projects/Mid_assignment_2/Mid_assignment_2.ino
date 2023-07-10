#define BUTTON_1_PIN 2
#define BUTTON_2_PIN 3
#define BUTTON_3_PIN 4

#define DISPENSE_PIN 5

#define DRINK_A_PIN 6
#define DRINK_B_PIN 7
#define DRINK_C_PIN 8

#define DELAY_DURATION 3000 // 3 seconds

void setup() {
  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
  pinMode(BUTTON_2_PIN, INPUT_PULLUP);
  pinMode(BUTTON_3_PIN, INPUT_PULLUP);

  pinMode(DISPENSE_PIN, OUTPUT);

  pinMode(DRINK_A_PIN, OUTPUT);
  pinMode(DRINK_B_PIN, OUTPUT);
  pinMode(DRINK_C_PIN, OUTPUT);
}

void loop() {
  int buttonPress = readButtonPress();

  if (buttonPress > 0) {
    dispenseDrinks(buttonPress);
  }
}

int readButtonPress() {
  if (digitalRead(BUTTON_1_PIN) == LOW) {
    return 1;
  } else if (digitalRead(BUTTON_2_PIN) == LOW) {
    return 2;
  } else if (digitalRead(BUTTON_3_PIN) == LOW) {
    return 3;
  }

  return 0;
}

void dispenseDrinks(int numDrinks) {
  delay(DELAY_DURATION);

  for (int i = 0; i < numDrinks; i++) {
    selectDrink(i + 1);
    delay(DELAY_DURATION);
    dispenseDrink();
    delay(DELAY_DURATION);
  }
}

void selectDrink(int drinkNumber) {
  if (drinkNumber == 1) {
    digitalWrite(DRINK_A_PIN, HIGH);
    digitalWrite(DRINK_B_PIN, LOW);
    digitalWrite(DRINK_C_PIN, LOW);
  } else if (drinkNumber == 2) {
    digitalWrite(DRINK_A_PIN, LOW);
    digitalWrite(DRINK_B_PIN, HIGH);
    digitalWrite(DRINK_C_PIN, LOW);
  } else if (drinkNumber == 3) {
    digitalWrite(DRINK_A_PIN, LOW);
    digitalWrite(DRINK_B_PIN, LOW);
    digitalWrite(DRINK_C_PIN, HIGH);
  }
}

void dispenseDrink() {
  digitalWrite(DISPENSE_PIN, HIGH);
  delay(DELAY_DURATION);
  digitalWrite(DISPENSE_PIN, LOW);
}


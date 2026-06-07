/*
 * acoustic levitator
 * drives two hc-sr04 transmitters through an l298n to levitate small objects
 */

// pins going to l298n inputs
const int PIN_A = A0;
const int PIN_B = A1;

// 40khz = 25us period, 12us per half cycle
const int HALF_PERIOD = 12;

void setup() {
  pinMode(PIN_A, OUTPUT);
    pinMode(PIN_B, OUTPUT);
}

void loop() {
    // alternate the two pins to push signal through the h-bridge
  digitalWrite(PIN_A, HIGH);
    digitalWrite(PIN_B, LOW);
  delayMicroseconds(HALF_PERIOD);

    digitalWrite(PIN_A, LOW);
  digitalWrite(PIN_B, HIGH);
    delayMicroseconds(HALF_PERIOD);
}

// Inputs of the 4016. Will be set
const int A_IN = 8;
const int B_IN = 9;
const int C_IN = 10;
const int D_IN = 11;

// Outputs of the 4016. Will be read. Pull these down with a resistor.
const int A_OUT = A5;
const int B_OUT = A4;
const int C_OUT = A3;
const int D_OUT = A2;

// Controls of the 4016. Will be set.
const int A_CTL = 2;
const int B_CTL = 3;
const int C_CTL = 4;
const int D_CTL = 5;

void setup() {
  for (int pin = 8; pin <= 11; pin++) pinMode(pin, OUTPUT);
  for (int pin = A2; pin <= A5; pin++) pinMode(pin, INPUT);
  for (int pin = 2; pin <= 5; pin++) pinMode(pin, OUTPUT);

  Serial.begin(9600);
}

void checkSwitch(int controlPin, int inputPin, int outputPin) {
  digitalWrite(inputPin, HIGH);
  digitalWrite(controlPin, HIGH);
  delay(1000);
  Serial.print("Checking ");
  Serial.print(controlPin - 1);
  Serial.print(" ON state: ");
  Serial.println(digitalRead(outputPin) == HIGH ? "PASS" : "FAIL");
  
  digitalWrite(controlPin, LOW);
  delay(1000);
  Serial.print("Checking ");
  Serial.print(controlPin - 1);
  Serial.print(" OFF state: ");
  Serial.println(digitalRead(outputPin) == LOW ? "PASS" : "FAIL");
} 

void loop() {
  Serial.println("4016 type CMOS Quad Bilateral Switch tester by QOTF-Alexi.");
  Serial.println("Make sure all outputs are pulled down with a resistor.");
  Serial.println("Alternating pass-fail usually means no IC is inserted or that the IC is fully dead.");
  checkSwitch(A_CTL, A_IN, A_OUT);
  checkSwitch(B_CTL, B_IN, B_OUT);
  checkSwitch(C_CTL, C_IN, C_OUT);
  checkSwitch(D_CTL, D_IN, D_OUT);
  Serial.println("DONE TESTING. Insert next IC and press RESET.");
  while(true){
  }
}

#define start 23
#define ls1 21
#define ls2 5
#define s1 18
#define s2 19
#define s3 22


#define p1 33
#define p2 14
#define mp 27
#define conv 32
#define g 2
#define r 26
#define heater 25
int b;



void setup() {
  pinMode(start, INPUT_PULLUP);
  pinMode(ls1, INPUT_PULLUP);
  pinMode(ls2, INPUT_PULLUP);
  pinMode(s1, INPUT_PULLUP);
  pinMode(s2, INPUT_PULLUP);
  pinMode(s3, INPUT_PULLUP);


  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(mp, OUTPUT);
  pinMode(conv, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(heater, OUTPUT);
  b = 1;
  Serial.begin(9600);
}


void loop() {
Serial.println(b);

  if (b == 1) {
    digitalWrite(p1, LOW);
    digitalWrite(p2, LOW);
    digitalWrite(conv, LOW);
    digitalWrite(heater, LOW);
    digitalWrite(mp, LOW);
    digitalWrite(g, LOW);
    digitalWrite(r, HIGH);
    b = 2;
  }
  if (b == 2) {
    if (digitalRead(start) == 0) {
      b = 3;
    }
  }
  if (b == 3) {
    digitalWrite(p1, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(r, LOW);
    b = 4;
  }

  if (b == 4) {
    if (digitalRead(ls2) == 0) {
      b = 5;
    }
  }

  if (b == 5) {
    digitalWrite(p1, LOW);
    digitalWrite(heater, HIGH);
    delay(5000);
    digitalWrite(heater, LOW);
    digitalWrite(p2, HIGH);
    b = 6;
  }

  if (b == 6) {
    if (digitalRead(ls1) == 0) {
      b = 7;
    }
  }
  if (b == 7) {
    digitalWrite(p2, LOW);
    b = 8;
  }
  if (b == 8) {
    if ((digitalRead(s1) == 1) && (digitalRead(s3) == 1)) {
      b = 9;
    }
  }
  if (b == 9) {
    delay(2000);
    digitalWrite(conv, HIGH);
    b = 10;
  }
  if (b == 10) {
    if (digitalRead(s2) == 0) {
      b = 11;
    }
  }
  if (b == 11) {
    digitalWrite(conv, LOW);
    digitalWrite(mp, HIGH);
    delay(5000);
    digitalWrite(mp, LOW);
    digitalWrite(conv, HIGH);
    b = 12;
  }
  if (b == 12) {
    if (digitalRead(s3) == 0) {
      b = 1;
    }
  }
}                                                                               
                                                                                                                                           
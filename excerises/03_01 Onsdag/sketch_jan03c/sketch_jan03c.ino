#define LED_RED 11
#define LED_GREEN 9
#define LED_BLUE 10
#define KNAP 1

void setup() {
  // put your setup code here, to run once:

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);

  pinMode(1, INPUT);
  digitalWrite(KNAP, HIGH);

  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean green = 0;
  boolean red = 0;
  boolean blue = 0;
  unsigned int count = 0;
  unsigned int colour = 0;

  while(1){
  if(!digitalRead(KNAP)){
    colour++;
    if(colour > 3){ 
      colour = 0;
    }
  }
  delay(500);
  
  switch (colour){
    case 0:
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_BLUE, LOW);
      break;
    case 1:
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_BLUE, LOW);
      break;
    case 2:
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED_BLUE, LOW);
      break;
    case 3:
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_BLUE, HIGH);
      break;
    
  }
  }

}

/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

#define DOT_TIME 300
#define DASH_TIME 3*DOT_TIME
#define LETTER_PAUSE 3*DOT_TIME
#define WORD_PAUSE 7*DOT_TIME

byte morse_letter[26][5] = {
{0,0,0,1,2},{0,2,1,1,1},{0,2,1,2,1},{0,0,2,1,1},{0,0,0,0,1},
{0,1,1,2,1},{0,0,2,2,1},{0,1,1,1,1},{0,0,0,1,1},{0,1,2,2,2},
{0,0,2,1,2},{0,1,2,1,1},{0,0,0,2,2},{0,0,0,2,1},{0,0,2,2,2},
{0,1,2,2,1},{0,2,2,1,2},{0,0,1,2,1},{0,0,1,1,1},{0,0,0,0,2},
{0,0,1,1,2},{0,1,1,1,2},{0,0,1,2,2},{0,2,1,1,2},{0,2,1,2,2},{0,2,2,1,1}};

byte morse_number[10][5] = {
{2,2,2,2,2},
{1,2,2,2,2},
{1,1,2,2,2},
{1,1,1,2,2},
{1,1,1,1,2},
{1,1,1,1,1},
{2,1,1,1,1},
{2,2,1,1,1},
{2,2,2,1,1},
{2,2,2,2,1}
};

void letter_blink(char C);



void dot(){
  Serial.print('.');
}

void dash(){
  Serial.print('-');
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  char str[10];
  
  letter_blink('s');
  letter_blink('o');
  letter_blink('s');
  letter_blink('0');
  letter_blink('0');
  letter_blink('1');
  letter_blink('2');
  letter_blink('3');
  letter_blink('4');
  letter_blink('5');
  
  
//  letter_blink('æ');
//  letter_blink('ø');
//  letter_blink('å');
  Serial.print('\n');
//  sprintf(str, "%u %u %u %u  ",'a','æ','ø','å');
//  Serial.print(str);
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}

void letter_blink(char C){
  int index = 0;
  byte morseSend[5];

  if(C >= 'a' && C <= 'z'){
    index = C - 'a';
    for(int i=0; i<5; i++){
      morseSend[i] = morse_letter[index][i];
    }
  }else if(C >= '0' && C <= '9' ){
    index = C - '0';
    for(int i=0; i<5; i++){
      morseSend[i] = morse_number[index][i];
    }
  }
/*  else if(C >= 'æ' && C <= 'ø' && C <= 'å' ){
    
    switch (C){
      case 'æ':
        morseSend[0] = 0;
        morseSend[1] = 1;
        morseSend[2] = 2;
        morseSend[3] = 1;
        morseSend[4] = 2;
        Serial.println("FOUND æ");
        break;
      case 'ø':
        morseSend[0] = 0;
        morseSend[1] = 2;
        morseSend[2] = 2;
        morseSend[3] = 2;
        morseSend[4] = 1;
        Serial.println("FOUND ø");
        break;
      case 'å':
        morseSend[0] = 1;
        morseSend[1] = 2;
        morseSend[2] = 2;
        morseSend[3] = 1;
        morseSend[4] = 2;
        Serial.println("FOUND å");
        break;
     default:
        morseSend[0] = 0;
        morseSend[1] = 0;
        morseSend[2] = 0;
        morseSend[3] = 0;
        morseSend[4] = 0;
        break;
    }
  }*/
  

//  *morseSend = *morse_letter[index];

  for(int i = 0; i<5; i++){
    if(morseSend[i] == 1){
      dot();
    }else if(morseSend[i] == 2){
      dash();
    }
  }
  Serial.print("   ");
}



#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5


void blinkLedRed(){
digitalWrite(LED1, HIGH);
digitalWrite(LED1, LOW);
}

void blinkLedBlue(){
digitalWrite(LED2, HIGH);
digitalWrite(LED2, LOW);
}
void blinkLedGreen(){
digitalWrite(LED3, HIGH);
digitalWrite(LED3, LOW);
}
void blinkLedYel(){
digitalWrite(LED4, HIGH);
digitalWrite(LED4, LOW);
}



void setup() {
  // put your setup code here, to run once:
    pinMode(LED1, OUTPUT); 
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT); 
    Serial.begin(115200);
    pinMode(A0, INPUT);
}

int getCoefDelay(){
int valueAnalogSig = analogRead(A0);
int coefDelay;

if(valueAnalogSig > 100){
coefDelay = valueAnalogSig/100;
coefDelay *=1000;
}else{
coefDelay = valueAnalogSig/10;
coefDelay *=100;
}
if(coefDelay<100){coefDelay=100;}
return coefDelay;
}


void loop() {
Serial.println("Time delay in ms");
Serial.println(getCoefDelay());
 blinkLedRed();
  delay(getCoefDelay());
 blinkLedBlue();
  delay(getCoefDelay());
   blinkLedGreen();
  delay(getCoefDelay()); 
blinkLedYel();
  delay(getCoefDelay());
}

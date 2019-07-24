const int E1 = 6;
const int M1 = 7;
const int E2 = 5;
const int M2 = 4;
const int pingauche = 9;
const int pindroite = 10;
const int pinmillieu = 11;
const int digitalSonPin = 3;           // define Sensor's D0 pin
const int pirPin = 12;                // Input for HC-S501 . detecteur de mouvement
      
int speede = 0;
int compare = 0;
int dValue = 0;
int pirValue;
int actionMotor = 0;
int instructionRasp = -1;

void setup()
{
Serial.begin(9600);
pinMode(M1, OUTPUT);
pinMode(M2, OUTPUT); 
pinMode(pingauche,INPUT);  //Capteur IR sur pin-11 numérique
pinMode(pindroite,INPUT);
pinMode(pinmillieu,INPUT);
pinMode(digitalSonPin,INPUT);  // le son 
pinMode(pirPin, INPUT); // detecteur de mouvement
}
void loop()
{
    int gauche = digitalRead(pingauche); 
    int millieu = digitalRead(pinmillieu);
    int droite = digitalRead(pindroite);
    instructionRasp = Serial.read();
  
  if(millieu == 0 ){

    stopMotor();
    delay(1000);
    goBackward(100);
    delay(1000);
        stopMotor();
  }else if(gauche == 0 ){

    stopMotor();
    delay(1000);
    goBackward(100);
    delay(1000);
        stopMotor();

  }else if(droite == 0 ){

    stopMotor();
    delay(1000);
    goBackward(100);
    delay(1000);
    stopMotor();


  }else{

if(instructionRasp == 53){
  startMotor(200);  
  delay(1000);
  instructionRasp = 0;
}
if(instructionRasp == 54){
  stopMotor();
  delay(1000);

instructionRasp = 0;
}
if(instructionRasp == 55){
goBackward(200);
delay(1000);
  instructionRasp = 0;
}

if(instructionRasp == 56){
turnRight();
delay(1000);
instructionRasp = 0;
  
}
if(instructionRasp == 57){
 turnLeft();
 delay(1000);
 instructionRasp = 0;
}
  }

// partie du son ----------------------------------

dValue = digitalRead(digitalSonPin);
Serial.println(dValue);

// partie detection de mouvement 

pirValue = digitalRead(pirPin);
Serial.println(pirValue);

}

void test(int speede){
 delay(10);
 digitalWrite(M1,LOW);
 digitalWrite(M2,HIGH);
 analogWrite(E1, speede); //PWM Speed Control
 analogWrite(E2, speede); //PWM Speed Control

 
 }


 void startMotor(int speede){
 digitalWrite(M1,LOW);
 digitalWrite(M2,HIGH);
 analogWrite(E1, speede); //PWM Speed Control
 analogWrite(E2, speede); //PWM Speed Control
 }

 void stopMotor(){
 delay(100);
 Serial.write(123);
 digitalWrite(M1,LOW);
 digitalWrite(M2,HIGH);
 analogWrite(E1, 0); //PWM Speed Control
 analogWrite(E2, 0); //PWM Speed Control
  
 }

void goBackward(int speede){
 delay(100);
 digitalWrite(M1,HIGH);
 digitalWrite(M2,LOW);
 analogWrite(E1, speede); //PWM Speed Control
 analogWrite(E2, speede); //PWM Speed Control
 }

void turnLeft(){
 delay(100);
 digitalWrite(M1,HIGH);
 digitalWrite(M2,HIGH);
 analogWrite(E1, 00); //PWM Speed Control
 analogWrite(E2, 100); //PWM Speed Control
  
}
void turnRight(){
 delay(100);
 digitalWrite(M1,LOW);
 digitalWrite(M2,LOW);
 analogWrite(E1, 100); //PWM Speed Control
 analogWrite(E2, 00); //PWM Speed Control
}

void turnRandom(){
int leNBrandom = random(100,240);
 delay(100);
 digitalWrite(M1,HIGH);
 digitalWrite(M2,HIGH);
 analogWrite(E1, leNBrandom); //PWM Speed Control
 analogWrite(E2, leNBrandom); //PWM Speed Control
  
}
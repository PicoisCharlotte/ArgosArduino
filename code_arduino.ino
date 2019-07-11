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
Serial.println("START!");
pinMode(M1, OUTPUT);
pinMode(M2, OUTPUT); 
Serial.print("essai de capteur IR");
pinMode(pingauche,INPUT);  //Capteur IR sur pin-11 numérique
pinMode(pindroite,INPUT);
pinMode(pinmillieu,INPUT);

pinMode(digitalSonPin,INPUT);  // le son 

pinMode(pirPin, INPUT); // detecteur de mouvement
}
void loop()
{

  instructionRasp = Serial.read();

  
  Serial.print("instructionRasp : ");
  Serial.println(instructionRasp);

if(instructionRasp == 53){
  startMotor(200);  
  
  instructionRasp = 0;
}
if(instructionRasp == 54){
stopMotor();

instructionRasp = 0;
}
if(instructionRasp == 55){
goBackward(200);
delay(3000);
  instructionRasp = 0;
}

if(instructionRasp == 56){
turnRight();
delay(3000);
instructionRasp = 0;
  
}
if(instructionRasp == 57){
 turnLeft();
 delay(3000);
 instructionRasp = 0;
}


  delay(1000);
  // recuperation des valeur des capteurs IR // pour les mures
    int gauche = digitalRead(pingauche); 
    int millieu = digitalRead(pinmillieu);
    int droite = digitalRead(pindroite);
// ici faire un test de le faire reculer si les capteur detect qqchose


// partie du son ----------------------------------

dValue = digitalRead(digitalSonPin);
Serial.print("valeur du son : ");
Serial.println(dValue);

// partie detection de mouvement 

 pirValue = digitalRead(pirPin);
 Serial.print("valeur de mouvement : ");
Serial.println(pirValue);

if(pirValue == 1){
   // Serial.send(783);
}
if(dValue == 1){
   // Serial.send(783);
}

    */
}

void test(int speede){
 delay(10);
 digitalWrite(M1,LOW);
 digitalWrite(M2,HIGH);
 analogWrite(E1, speede); //PWM Speed Control
 analogWrite(E2, speede); //PWM Speed Control

 
 }


 void startMotor(int speede){
 delay(100);
 digitalWrite(M1,LOW);
 digitalWrite(M2,HIGH);
 analogWrite(E1, speede); //PWM Speed Control
 analogWrite(E2, speede); //PWM Speed Control
  delay(3000);
 }

 void stopMotor(){
 delay(100);
  Serial.write("test ,ca stoppe : ");
  Serial.write(123);
 Serial.println("ca stoppe ");
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
  delay(3000);
 }

void turnRight(){
 delay(100);
 digitalWrite(M1,HIGH);
 digitalWrite(M2,HIGH);
 analogWrite(E1, 150); //PWM Speed Control
 analogWrite(E2, 150); //PWM Speed Control
  delay(100);
  
}
void turnLeft(){
 delay(100);
 digitalWrite(M1,LOW);
 digitalWrite(M2,LOW);
 analogWrite(E1, 150); //PWM Speed Control
 analogWrite(E2, 150); //PWM Speed Control
  delay(100);
}

void turnRandom(){
int leNBrandom = random(100,240);
 delay(100);
 digitalWrite(M1,HIGH);
 digitalWrite(M2,HIGH);
 analogWrite(E1, leNBrandom); //PWM Speed Control
 analogWrite(E2, leNBrandom); //PWM Speed Control
 delay(1000);
  
}
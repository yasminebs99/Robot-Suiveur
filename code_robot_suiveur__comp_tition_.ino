// Moteur A
int IN1=4;
int IN2=5;
int enb=9;
//Moteur B
int IN3=6;
int IN4=7;
int ena=3;
//capteur infrarouge gauche
int outg=12;
//capteur infrarouge milieu
int outm=8;
//capteur infrarouge droite
int outd=2;
//capteur ultrason
int trig =10;
int echo=11;
long duration;
long cm;//distance

void setup() {
  pinMode(IN1,OUTPUT);//sets the trigPin as an output
  pinMode(IN2,OUTPUT);//sets the echoPin as an input
  pinMode(enb,OUTPUT);
    pinMode(IN3,OUTPUT);//sets the trigPin as an output
  pinMode(IN4,OUTPUT);//sets the echoPin as an input
  pinMode(ena,OUTPUT);
  pinMode(outg,INPUT);
  pinMode(outd,INPUT);
  pinMode(outm,INPUT);
pinMode(trig,OUTPUT);
digitalWrite(trig,LOW);
pinMode(echo,INPUT);
}
void av(){
analogWrite(ena,100);
 digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
analogWrite(enb,100);
 digitalWrite(IN3,HIGH);
 digitalWrite(IN4,LOW);
}
void gc(){
analogWrite(ena,100);
 digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
analogWrite(enb,10);
 digitalWrite(IN3,HIGH);
 digitalWrite(IN4,LOW);
}
void dr(){
analogWrite(ena,10);
 digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
analogWrite(enb,100);
 digitalWrite(IN3,HIGH);
 digitalWrite(IN4,LOW);
}
void stp(){
analogWrite(ena,100);
 digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
analogWrite(enb,100);
 digitalWrite(IN3,LOW);
 digitalWrite(IN4,LOW);
}
void loop() {
digitalWrite(trig,HIGH);
delayMicroseconds (10);
digitalWrite(trig,LOW);
duration=pulseIn(echo,HIGH);
cm= duration/58;
if(cm>20){
if(digitalRead(outg)==LOW&&digitalRead(outm)==LOW&&digitalRead(outd)==LOW){
                        av();}
else if(digitalRead(outg)==LOW&&digitalRead(outm)==LOW&&digitalRead(outd)==HIGH){
                        av();}
else if (digitalRead(outg)==LOW&&digitalRead(outm)==HIGH&&digitalRead(outd)==LOW){
                        stp();}
else if (digitalRead(outg)==LOW&&digitalRead(outm)==HIGH&&digitalRead(outd)==HIGH){
                        gc();}
else if (digitalRead(outg)==HIGH&&digitalRead(outm)==LOW&&digitalRead(outd)==LOW){
                        av();}
else if (digitalRead(outg)==HIGH&&digitalRead(outm)==LOW&&digitalRead(outd)==HIGH){
                        av();}
else if (digitalRead(outg)==HIGH&&digitalRead(outm)==HIGH&&digitalRead(outd)==LOW){
                        dr();}
else if (digitalRead(outg)==HIGH&&digitalRead(outm)==HIGH&&digitalRead(outd)==HIGH){
                        av();}
}
else {stp();}
}

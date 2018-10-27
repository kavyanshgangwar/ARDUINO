int m1,m2,m3;//autonomous part is written as black strip in bw
int i=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(5,OUTPUT);
pinMode(4,OUTPUT);
pinMode(3,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(2,HIGH);
char a;
if(Serial.available())
{
a = Serial.read();
Serial.println(a);
}

if(a=='R')
{analogWrite(11,255);
analogWrite(5,255);
digitalWrite(13,LOW);//left backward
digitalWrite(12,HIGH);
digitalWrite(4,HIGH);//right forward
digitalWrite(3,LOW);}
if(a=='L')
{
  analogWrite(11,255);
  analogWrite(5,255);
  digitalWrite(13,HIGH);//left forward
  digitalWrite(12,LOW);
  digitalWrite(4,LOW);//right backward
  digitalWrite(3,HIGH);
}
if(a=='F')
{
 analogWrite(11,255);
 analogWrite(5,255);
 digitalWrite(13,HIGH);
 digitalWrite(12,LOW);
 digitalWrite(4,HIGH);
 digitalWrite(3,LOW); 
}
if(a=='B')
{
  analogWrite(11,255);
  analogWrite(5,255);
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(3,HIGH);
 
}
if(a=='0')
{analogWrite(11,0);
analogWrite(5,0);
digitalWrite(13,LOW);
digitalWrite(12,LOW);
digitalWrite(4,LOW);
digitalWrite(3,LOW);
}
if(a=='A' || a=='M')
{
m1=analogRead(A0);
m2=analogRead(A1);
m3=analogRead(A2);

 if(m1>500 && m2<500 && m3>500 )
{ analogWrite(11,127);
 analogWrite(5,127);
 digitalWrite(13,HIGH);
 digitalWrite(12,LOW);
 digitalWrite(4,HIGH);
 digitalWrite(3,LOW);

 }
 if(m1>500 && m2<500 && m3<500)
 {analogWrite(11,255);
  analogWrite(5,255);
  digitalWrite(12,HIGH);//left forward
  digitalWrite(13,LOW);
  digitalWrite(3,LOW);//right backward
  digitalWrite(4,HIGH);}
  if(m1<500 && m2<500 && m3>500)
  {analogWrite(11,255);
analogWrite(5,255);
digitalWrite(12,LOW);//left backward
digitalWrite(13,HIGH);
digitalWrite(3,HIGH);//right forward
digitalWrite(4,LOW);
}

if(m1<500 && m2>500 && m3<500)//led blink ka case at start and end
{if(i==0)
{digitalWrite(7,HIGH);
digitalWrite(8,LOW);
delay(1000);
digitalWrite(7,LOW);
i++;
while(m1>500 && m2<500 && m3>500)
{ analogWrite(11,255);
 analogWrite(5,255);
 digitalWrite(13,HIGH);
 digitalWrite(12,LOW);
 digitalWrite(4,HIGH);
 digitalWrite(3,LOW);
 m1=analogRead(A0);
m2=analogRead(A1);
m3=analogRead(A2);
}
}
else if(i>0)
{digitalWrite(9,HIGH);
digitalWrite(8,LOW);
delay(1000);
digitalWrite(9,LOW);
}
}
}}

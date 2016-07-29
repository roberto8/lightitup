


#define delayTime 20
//used to check recieving variable
#include <SoftwareSerial.h>
#include <time.h>

SoftwareSerial Genotronex(0, 1); // RX, TX
//sets serial ports as 0 and 1

byte red=11;
byte green=10;
byte blue=9;
//arduino pwm pins


//bluetoot variables
byte BluetoothData;
//used to receive all the other variables to the bulb
char color;
//color = recieves R,G or B to set changing color
byte clrintens;
//clrintens = color intesity
char colorinit;
//colorinit = initializes color reception
int time1;
/*gets time in seconds/miliseconds so that if start time =/ from 0,
calculates color to start point ex if 09:00a.m. start color =/ from
24:00 so calculates time diference and then calculates color changing to set start point*/
int startrgb;
//variable to store start color, to make calcules(given by external device)
int intervall;
//intervall of addition/subtraction
int positivity;
//sets changing value (if it's -1 or +1)
int storergb;
//var used to store RGB vallue changed in calcules;
int endcolor;
//receives end color; tom make if =/ change


unsigned long time;
//timer
boolean command_off=false;
boolean command_button1=false;
boolean modo_ldr=false;
//sets ldr to off, s there are no interferecnes

unsigned long duracao=10000;
int redVal;
int blueVal;
int greenVal;
//declares color intesity variables
int ldr_pin=0;
//sets ldr input pin as 0
int ldr;
//ldr value variable
void setup() {

  Genotronex.begin(9600);
  Genotronex.println("BLOUETHOOTH IS ON! CHOOSE A COLOR!");
  pinMode(red,OUTPUT);
    pinMode(green,OUTPUT);
      pinMode(blue,OUTPUT);

}


void app_ldr(){
int i;
float ldr1=0;
ldr=0;
for(i=0;i<10;i++){
  ldr=ldr+analogRead(ldr_pin);
}
ldr1=(int) ldr/11;


ldr=map(ldr1, 0,1023,255,0);

Genotronex.println(ldr);
muda_ldr(ldr);

}
void muda_ldr(int valor_ldr){

  if (valor_ldr>30) {
    valor_ldr=0;
  }
  analogWrite(red,valor_ldr);
  analogWrite(green,valor_ldr);
  analogWrite(blue,valor_ldr);
}

void define_luz(char cor, int intensidade){
  //gets changing color variable then the intesity var
 int int1=0;
  int1=intensidade;
  switch (cor) {
    //receives second rgb variable (color first letter(R/G/B))
    //then 0-255 variable sets brightness
    case 'R':

      analogWrite(red,int1);
      break;
    case 'G':
    analogWrite(green,int1);
      //do something when var equals 2
      break;
      case 'B':
    analogWrite(blue,int1);

      break;
    default:
      // if nothing else matches, do the default
      // default is optional
    break;

  }
}


void loop() {

   if (Genotronex.available()){
BluetoothData=Genotronex.read();
   }
   //sets first rgb variable to receive "u"
   //colorinit §not set to nothing
   if(colorinit=='u'){
    modo_ldr=false;
  color=Genotronex.read();
  Serial.print(color);
  Genotronex.println(color);
    clrintens=Genotronex.read();
    Serial.print(clrintens);
define_luz(color,clrintens);
   Genotronex.println("color");
   } else


if(BluetoothData=='l'){
  //ldr mode is on!
modo_ldr=true;


   } else


 if(BluetoothData=='t' || BluetoothData=='v' || BluetoothData=='x' || BluetoothData=='k' || BluetoothData=='y' || BluetoothData=='m' ){
  modo_ldr=false;

switch (BluetoothData) {
    case 't':
      duracao=5000;
      break;
    case 'v':
    duracao=10000;
      break;
      case 'x':
 duracao=15000;
      break;
       case 'k':
 duracao=20000;
      break;
       case 'y':
 duracao=25000;
      break;
       case 'm':
 duracao=30000;
      break;
    default:
      // if nothing else matches, do the default
      // default is optional
      //timer variables to low to test not real world situatuions
      //need to create new timer settings on the app so that time variable is definied by the user
    break;
  }


if (command_button1){
  modo_ldr=false;
  time = millis();
  command_off=true;
  command_button1=false;
   analogWrite(red,255);
  analogWrite(green,255);
  analogWrite(blue,255);
   Genotronex.println("LED's ON");
   //sets led on after time run out (millis sets time variable)

}


 } else





   //turn modes into switch
   //modes colors aren0t right
   //simple mode(if var = x then do this))
  if (BluetoothData=='d'){
    modo_ldr=false;
  analogWrite(red,0);
  analogWrite(green,0);
  analogWrite(blue,0);
  modo_ldr=false;
   Genotronex.println("LED's OFF");
  } else

  if (BluetoothData=='a'){
    modo_ldr=false;
  analogWrite(red,255);
  analogWrite(green,255);
  analogWrite(blue,255);
   Genotronex.println("LED's ON");
  } else


   if (BluetoothData=='r'){
    modo_ldr=false;
  analogWrite(red,33);
  analogWrite(green,33);
  analogWrite(blue,33);
   Genotronex.println("reading");
  } else


  if (BluetoothData=='s'){
    modo_ldr=false;
  analogWrite(red,25);
  analogWrite(green,25);
  analogWrite(blue,25);
   Genotronex.println("sleeping light");
  } else
   if (BluetoothData=='o'){
    modo_ldr=false;
  analogWrite(red,51);
  analogWrite(green,51);
  analogWrite(blue,51);

   Genotronex.println("romance");
  } else


 if (BluetoothData=='c'){
  modo_ldr=false;
  analogWrite(red,76);
  analogWrite(green,76);
  analogWrite(blue,76);
   Genotronex.println("cinema");
  } else
   if (BluetoothData=='p'){
    modo_ldr=false;
  //party cross fade
  int redVal = 255;
  int blueVal = 0;
  int greenVal = 0;

  for( int i = 0 ; i < 255 ; i += 1 ){

    blueVal += 1;
    redVal -= 1;
    analogWrite(green, greenVal);
    analogWrite( blue,  blueVal );
    analogWrite( red,  redVal );

    delay( delayTime );
  }

  redVal = 0;
  blueVal = 255;
  greenVal = 0;
  for( int i = 0 ; i < 255 ; i += 1 ){

    redVal += 1;
    greenVal +=1;
    blueVal -= 1;

    analogWrite( red, redVal );
    analogWrite( blue,blueVal );
    analogWrite( green, greenVal );

    delay( delayTime );
  }

  redVal = 255;
  blueVal = 0;
  greenVal = 255;
  for( int i = 0 ; i < 255 ; i += 1 ){


    redVal -= 1;
    blueVal += 1;

    analogWrite(green, greenVal);
    analogWrite( red, redVal );
    analogWrite( blue,blueVal );
    delay( delayTime );
  }
   Genotronex.println("party");
  } else
   if (BluetoothData=='z'){

  analogWrite(red,102);
  analogWrite(green,102);
  analogWrite(blue,102);
   Genotronex.println("zen");
  }
    //
if ((command_off)  && (millis() >= time+duracao)){
//led's off
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
command_off=false;

}if (modo_ldr) {
  app_ldr();

}
if (BluetoothData=="c")//create variable to ciclo circadiano
{
  //insert ciclo circadiano code
  time1 = Genotronex.read();
  Genotronex.println(time1);
  startrgb = Genotronex.read();
  Genotronex.println(startrgb);//try hexadecimal conversion to receive only one variable
  intervall = Genotronex.read();
  Genotronex.println(intervall);
  positivity = Genotronex.read();
  Genotronex.println(positivity);
  endcolor = Genotronex.read();
  Genotronex.println(endcolor);
  //only do this on startup
  //receive and store all variables
analogWrite(red, HIGH);//add variable to change color, need to split variable
analogWrite(green,HIGH );//
analogWrite(blue, HIGH);

if(storergb < endcolor || storergb > endcolor)//check how to make different preposition in c++
{
  if (positivity == "+")
  {
    //add +1 to color
    //analogWrite
  }
  if (positivity == "-")
  {
    //subtract -1 to color
    //analogWrite
  }

}
  delay(intervall);//sets delay to received time variables

}
//read after 100 miliseconds
delay(100);
   }

#define PIN_LED1 11
#define PIN_LED2 13

#define pas 2
char data;
int x;


void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED1,OUTPUT);
  digitalWrite(PIN_LED2,LOW);
  pinMode(PIN_LED2,OUTPUT);
  pinMode(PIN_LED1,OUTPUT);
  analogWrite(PIN_LED1,0);
  Serial.begin(9600);
  x=0;
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    data=Serial.read();
      if(data=='1')
      {
        digitalWrite(PIN_LED2,HIGH);
        Serial.write('1');
      }
      else if(data=='0')
      {
        digitalWrite(PIN_LED2,LOW);
        Serial.write('1');
      }
      else if(data=='2')
      {
        if(x+pas<=255)
        x=x+pas;
        analogWrite(PIN_LED1,x);
      }
      else if(data=='3')
      {
        if((x>pas))
        x=x-pas;
        else
        x=0;

        analogWrite(PIN_LED1,x);
      }
    }
  }
 

int count = 0;
int detect = A0;
int buzzer  = 8;
int ledPin = 7;
int button = 6;
int object1 ;
int object2 ;
int object3 ;
int object4 ;
void setup() {
  // put your setup code here, to run once:
pinMode(button ,INPUT);
pinMode(ledPin,OUTPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);
Serial.println("Start your counting");
}

void loop() {
  // put your main code here, to run repeatedly:
back:
    int object = analogRead(detect);
    int b=digitalRead(button);
    object1 = object;
    object2 = object1;
    int back;


   if ( (object2>100) && (object3>100) && (object4>100)){
    //count = 00000;
    
    Serial.println("Object has stopped moving");
    Serial.print("Current Counter:" );
    Serial.println(count);
    delay(1000);
    goto back;
    
   }

    if (object >= 100){
      objectisthere();
    }
    if (b == 0){
      count = 0;
      Serial.println("-------------------");
      Serial.println("");
      Serial.println("Start the new counting");
      Serial.print("Counter: ");
      Serial.println(count);
    }
    object3 = object2;
    object4 = object3;
    delay(1000);
    }

void objectisthere()
{
  digitalWrite(ledPin,HIGH);
  tone(buzzer,5600,300);
  count =count + 1;
  Serial.print("Counter:");
  Serial.println(count);
  delay(800);
  digitalWrite(ledPin,LOW);
  
}

const int motor1Pin1 = 5;
const int motor1Pin2 = 4;
const int enablem1Pin3 = 3;
const int motor2Pin1 = 7;
const int motor2Pin2 =8;
const int enablem2Pin3 = 9;
byte serialA;
int arr[5];

int in0=0,in1=0,in2=0,in3=0,in4=0;
//analogWrite(enablem1Pin3,150);
//analogWrite(enablem1Pin3,150);
void setup() 
{

  
 Serial.begin(9600);

    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enablem1Pin3, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(enablem2Pin3, OUTPUT);
    // defining pinmode for inputs 
     pinMode(A0,INPUT);
     pinMode(A1,INPUT);
     pinMode(A2,INPUT);
     pinMode(A3,INPUT);
     pinMode(A4,INPUT);

}
void forward()
{
   
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        analogWrite(enablem1Pin3,180);
        analogWrite(enablem2Pin3,180);
}
void backward()
{
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2,HIGH);
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        analogWrite(enablem1Pin3,150);
        analogWrite(enablem2Pin3,150);
}
void forward_left()
{
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        analogWrite(enablem1Pin3,34);
        analogWrite(enablem2Pin3,89);
}
void goku_left()
{
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        analogWrite(enablem1Pin3,45);
        analogWrite(enablem2Pin3,100);
}
void goku_right()
{

        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        analogWrite(enablem1Pin3,100);
        analogWrite(enablem2Pin3,45);

}

void forward_right()
{

        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        analogWrite(enablem1Pin3,89);
        analogWrite(enablem2Pin3,34);

}

void left()
{
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        analogWrite(enablem1Pin3,60);
        analogWrite(enablem2Pin3,60);
        delay(60);
        do
        {
        read_sensors();
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        analogWrite(enablem1Pin3,100);
        analogWrite(enablem2Pin3,100);
        if(arr[3]==1)
          break;
        }while(1);
}
void right()
{
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        analogWrite(enablem1Pin3,60);
        analogWrite(enablem2Pin3,60);
        delay(60);
        do
        {
        read_sensors();
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        analogWrite(enablem1Pin3,100);
        analogWrite(enablem2Pin3,100);
        if(arr[1]==1)
          break;
        }while(1);
}
void wait()
{
  delay(1000);
}
void read_sensors()
{
  in0=analogRead(A0);
     in1=analogRead(A1);
     in2=analogRead(A2);
     in3=analogRead(A3);
     in4=analogRead(A4);

   
     if(in0>267)
        arr[0]=0;
     else
        arr[0]=1;
     if(in1>267)
        arr[1]=0;
     else
        arr[1]=1;
     if(in2>267)
        arr[2]=0;
     else
        arr[2]=1;
     if(in3>267)
        arr[3]=0;
     else
        arr[3]=1;
     if(in4>267)
        arr[4]=0;
     else
        arr[4]=1;

}
void loop() 
{
     read_sensors();

     if((arr[0]==0 && arr[1]==1 && arr[2]==1 && arr[3]==1 && arr[4]==0)||(arr[0]==1 && arr[1]==1 && arr[2]==1 && arr[3]==1 && arr[4]==1)||(arr[0]==0 && arr[1]==0 && arr[2]==1 && arr[3]==0 && arr[4]==0))
        forward();
     else if((arr[0]==0 && arr[1]==1 && arr[2]==1 && arr[3]==0 && arr[4]==0)||(arr[0]==1 && arr[1]==1 && arr[2]==1 && arr[3]==0 && arr[4]==0))
        forward_right();
     else if((arr[0]==0 && arr[1]==0 && arr[2]==1 && arr[3]==1 && arr[4]==0)||(arr[0]==0 && arr[1]==0 && arr[2]==1 && arr[3]==1 && arr[4]==1))
        forward_left();
/*     else if((arr[0]==1 && arr[1]==1 && arr[2]==0 && arr[3]==0 && arr[4]==0)||(arr[0]==1 && arr[1]==0 && arr[2]==0 && arr[3]==0 && arr[4]==0))
        goku_left();
     else if((arr[0]==1 && arr[1]==1 && arr[2]==0 && arr[3]==0 && arr[4]==0)||(arr[0]==1 && arr[1]==0 && arr[2]==0 && arr[3]==0 && arr[4]==0))
        goku_right();
  */   else if(arr[0]==1 && arr[1]==1 && arr[2]==1 && arr[3]==1 && arr[4]==0)
        right();
     else if(arr[0]==0 && arr[1]==1 && arr[2]==1 && arr[3]==1 && arr[4]==1)
        left(); 
    
   
        
    delay(5);
     /*if(arr[0]==0 && arr[1]==0 && arr[2]==0 && arr[3]==0 && arr[4]==0)
     {
        forward();
        delay(150);

        
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        digitalWrite(enablem1Pin3, LOW);
        digitalWrite(enablem2Pin3, LOW); 
     }*/
}

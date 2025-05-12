//definition of motor pins
int RIR = 22 ;
int LIR = 13  ;

#define ena 14
#define in1 27
#define in2 26
#define in3 25
#define in4 33
#define enb 32

void forward (){

        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        analogWrite(ena, 200);
        analogWrite(enb, 200);

        Serial.println("Forward");


}

void backward (){

        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        analogWrite(ena, 150);
        analogWrite(enb, 150);
        delay(500);

        Serial.println("Back");


}

void leftward (){
  
        digitalWrite(in1, HIGH); //first wheel moves forward
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW); //second wheel moves backwards
        digitalWrite(in4, HIGH);
        analogWrite(ena, 200);
        analogWrite(enb, 200);
        delay(500);

        Serial.println("Left");

}

void rightward (){
  
        digitalWrite(in1, LOW); //first wheel moves backwardas
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH); //second wheel moves forward
        digitalWrite(in4, LOW);
        analogWrite(ena, 200);
        analogWrite(enb, 200);
        delay(500);

        Serial.println("Right");

}

void stop (){

        analogWrite(ena, 0);
        analogWrite(enb, 0);
        delay(1000);

}

void setup () { 
//serial monitor for checking values of ir
Serial.begin(9600);      //setting up o/p pin
pinMode (RIR , INPUT) ;   //IR sensor output is fed into ESP pin 13 as an input
pinMode (LIR , INPUT) ;

pinMode (in2, OUTPUT) ;  //motor1
pinMode (in1, OUTPUT) ;
pinMode (ena, OUTPUT) ;

pinMode (in4, OUTPUT) ;  //motor2
pinMode (in3, OUTPUT) ;
pinMode (enb, OUTPUT) ;

stop ();
}

void loop() {
    int reading_right = digitalRead(RIR); 
    int reading_left = digitalRead(LIR);
    //to get readings from IR sensor
    if ( reading_right == 0 & reading_left == 1) {             //in case of right obstacle 
      stop();
      backward ();
      leftward ();
    }

    else if (  reading_right == 1 & reading_left == 0 ) {        //in case of left obstacle
        stop();
        backward ();
        rightward();  
    }
    else if ( reading_right == 0 & reading_left == 0) {            //in case of left and right obstacles 
      stop();
      backward ();
      rightward ();
    }

    else {        //in case of no obstacle
        
        forward();  

    } 
}
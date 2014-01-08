
include <Stepper.h>




const int stepsPerRevolution =200;

Stepper myStepperX(stepsPerRevolution, 8, 7);

Stepper myStepperY(stepsPerRevolution, 9, 10);

Stepper myStepperZ(stepsPerRevolution, 11, 12);

char buffer[5];

char chStartPacket = '[';

char chEndpacket =']';

char integerDataType = 'I';

char buf[10];

int index = 0;

int intValue = 0;



void setup(){

myStepper1.SetSpeed(30);

myStepper2.SetSpeed(30);

myStepper2.SetSpeed(30);

Serial.begin(9600);

int currentXAxis = 0;

int currentYAxis = 0;

int currentZAxis = 0;

int newXAxis = 180;//aus Serieller Schnittstelle auslesen

int newYAxis = 180;//aus Serieller Schnittstelle auslesen

int newZAxis = 180;//aus Serieller Schnittstelle auslesen
}




void loop(){


 if(Serial.available() > 0){

    if(Serial.peek() == chStartPacket ){
      
      index = 0;                                
      
      Serial.read();                           
    }  
    
    else if (Serial.peek()  == integerDataType){
      
      Serial.read();                           
      
    }
    else if (Serial.peek() == chEndpacket){    
    
      Serial.read();                           
      
      intValue = atoi(buf);
      
      Serial.println(intValue);                
      
    }
    else{                                      
    
      buf[index] = Serial.read();
      
      index++;
      
      buf[index] = '\0';
    }

  }



if(currentXAxis < newXAxis){

	myStepperX.step(stepsPerRevolution);

	delayMicros(newXAxis/0,0015)
}

else if(currentXAxis > newXAxis){

	myStepperX.step(-stepsPerRevolution);

	delayMicros(newXAxis/0,0015)
}

else{
  
Serial.println("Fehler in der Eingabe!!");

}

//----

if(currentYAxis < newYAxis){

	myStepperY.step(stepsPerRevolution);

	delayMicros(newYAxis/0,0015)
}

else if(currentYAxis > newYAxis){

	myStepperY.step(-stepsPerRevolution);

	delayMicros(newYAxis/0,0015)
}

else{
  
Serial.println("Fehler in der Eingabe!!");

}

//----

if(currentZAxis < newZAxis){

	myStepperZ.step(stepsPerRevolution);

	delayMicros(newZAxis/0,0015)

}

if(currentZAxis > newZAxis){

	myStepperZ.step(-stepsPerRevolution);

	delayMicros(newZAxis/0,0015)
}
else{
  
Serial.println("Fehler in der Eingabe!!");

}


}


  #define TRIGGER_PIN 7
  #define ECHO_PIN 8
  
  int onFar = 12;
  int arkaFar = 2;
  int stopFar = 3;
  int korna = 11;

  char BTkomutu;
  int hiz = 255;
  
// L298N Motor Sürücü Bağlantıları
  const int motorA1 = 6;  // IN3
  const int motorA2 = 5;  // IN1
  const int motorB1 = 9;  // IN2
  const int motorB2 = 10; // IN4

  
void ileri() {
  analogWrite(motorA1, hiz);
  analogWrite(motorA2, 0);
  
  analogWrite(motorB1, hiz);
  analogWrite(motorB2, 0);
}

void ileriSag() {
  analogWrite(motorA1, hiz/3); 
  analogWrite(motorA2, 0); 
  
  analogWrite(motorB1, hiz);      
  analogWrite(motorB2, 0);
}

void ileriSol() {
  analogWrite(motorA1,hiz);
  analogWrite(motorA2, 0);
    
  analogWrite(motorB1, hiz/3);
  analogWrite(motorB2, 0);
}

void sag() {
  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0); 
  
  analogWrite(motorB1, hiz);   
  analogWrite(motorB2, 150); 
}

void sol() {
  analogWrite(motorA1, hiz);
  analogWrite(motorA2, 150); 
  
  analogWrite(motorB1, 0); 
  analogWrite(motorB2, 0); 
}

void geri() {
  analogWrite(motorA1, 0);
  analogWrite(motorA2, hiz); 
  
  analogWrite(motorB1, 0);   
  analogWrite(motorB2, hiz);
}

void geriSag() {
  analogWrite(motorA1, 0);   
  analogWrite(motorA2, hiz);
  
  analogWrite(motorB1, 0);   
  analogWrite(motorB2, hiz/3);
}

void geriSol() {
  analogWrite(motorA1, 0);   
  analogWrite(motorA2, hiz/3); 
  
  analogWrite(motorB1, 0); 
  analogWrite(motorB2, hiz);
}

void dur() {
  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0);
  
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
}


void setup() {
  
  Serial.begin(9600);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(onFar, OUTPUT);
  pinMode(arkaFar, OUTPUT);
  pinMode(stopFar, OUTPUT);
  dur();
}

void loop() {

  BTkomutu = Serial.read();

  if (BTkomutu == '0') {
    hiz = 0;
  }
  else if (BTkomutu == '1') {
    hiz = 10;
  }
  else if (BTkomutu == '2') {
    hiz = 35;
  }
  else if (BTkomutu == '3') {
    hiz = 65;
  }
  else if (BTkomutu == '4') {
    hiz = 90;
  }
  else if (BTkomutu == '5') {
    hiz = 120;
  }
  else if (BTkomutu == '6') {
    hiz = 150;
  }
  else if (BTkomutu == '7') {
    hiz = 175;
  }
  else if (BTkomutu == '8') {
    hiz = 200;
  }
  else if (BTkomutu == '9') {
    hiz = 225;
  }
  else if (BTkomutu == 'q') {
    hiz = 255;
  }

  
/// Araç Hareketi ///

  if(BTkomutu=='F') {
        ileri();  
       }              
  else if(BTkomutu=='I') {  
        ileriSag();
       }
  else if(BTkomutu=='G') {  
        ileriSol();  
       }
  else if(BTkomutu=='R') {  
        sag(); 
       }
  else if(BTkomutu=='L') {  
        sol();  
       }
  else if(BTkomutu=='B') {  
        geri();
       }
  else if(BTkomutu=='J') {  
        geriSag();
       }
  else if(BTkomutu=='H') {  
        geriSol();
       }
  else if(BTkomutu=='S') {  
        dur();
       }


// ---------- Araç Farları ve Kornası ------------

  else if(BTkomutu=='W') {  
        digitalWrite(onFar, HIGH);
       }
  else if(BTkomutu=='w') {  
        digitalWrite(onFar, LOW);
       }
  else if(BTkomutu=='U') {  
        digitalWrite(arkaFar, HIGH);
       }
  else if(BTkomutu=='u') {  
        digitalWrite(arkaFar, LOW);
       }
  else if(BTkomutu=='V') {  
        digitalWrite(korna, HIGH);
       }
  else if(BTkomutu=='v') {  
        digitalWrite(korna, LOW);
       }
  
  else if
  (BTkomutu=='F' || BTkomutu=='I' || BTkomutu=='G' 
  || BTkomutu=='B' || BTkomutu=='L' || BTkomutu=='R'
  || BTkomutu=='H' || BTkomutu=='J') {  
        digitalWrite(stopFar, LOW);
       }

  else if(BTkomutu=='S') {  
        digitalWrite(stopFar, HIGH);
       }











  
}

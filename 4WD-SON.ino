  #define trigger 7
  #define echo 8

  long sure;
  long mesafe;
  
  int onFar = 12;
  int arkaFar = 2;
  int stopFar = 3;
  int korna = 11;

  char BTkomutu;
  int hiz = 255;
  
// L298N Motor Sürücü Bağlantıları
  const int ileriSolMotorlar = 5;  // IN1 
  const int ileriSagMotorlar = 6;  // IN3
  
  const int geriSolMotorlar = 9;  // IN2
  const int geriSagMotorlar = 10; // IN4

  
void ileri() {
  analogWrite(ileriSagMotorlar, hiz);
  analogWrite(ileriSolMotorlar, 0);
  
  analogWrite(geriSolMotorlar, hiz);
  analogWrite(geriSagMotorlar, 0);
}

void ileriSag() {
  analogWrite(ileriSagMotorlar, hiz/3); 
  analogWrite(ileriSolMotorlar, 0); 
  
  analogWrite(geriSolMotorlar, hiz);      
  analogWrite(geriSagMotorlar, 0);
}

void ileriSol() {
  analogWrite(ileriSagMotorlar,hiz);
  analogWrite(ileriSolMotorlar, 0);
    
  analogWrite(geriSolMotorlar, hiz/3);
  analogWrite(geriSagMotorlar, 0);
}

void sag() {
  analogWrite(ileriSagMotorlar, 0);
  analogWrite(ileriSolMotorlar, 0); 
  
  analogWrite(geriSolMotorlar, hiz);   
  analogWrite(geriSagMotorlar, 150); 
}

void sol() {
  analogWrite(ileriSagMotorlar, hiz);
  analogWrite(ileriSolMotorlar, 150); 
  
  analogWrite(geriSolMotorlar, 0); 
  analogWrite(geriSagMotorlar, 0); 
}

void geri() {
  analogWrite(ileriSagMotorlar, 0);
  analogWrite(ileriSolMotorlar, hiz); 
  
  analogWrite(geriSolMotorlar, 0);   
  analogWrite(geriSagMotorlar, hiz);
}

void geriSag() {
  analogWrite(ileriSagMotorlar, 0);   
  analogWrite(ileriSolMotorlar, hiz);
  
  analogWrite(geriSolMotorlar, 0);   
  analogWrite(geriSagMotorlar, hiz/3);
}

void geriSol() {
  analogWrite(ileriSagMotorlar, 0);   
  analogWrite(ileriSolMotorlar, hiz/3); 
  
  analogWrite(geriSolMotorlar, 0); 
  analogWrite(geriSagMotorlar, hiz);
}

void dur() {
  analogWrite(ileriSagMotorlar, 0);
  analogWrite(ileriSolMotorlar, 0);
  
  analogWrite(geriSolMotorlar, 0);
  analogWrite(geriSagMotorlar, 0);
}


void setup() {
  
  pinMode(ileriSagMotorlar, OUTPUT);
  pinMode(ileriSolMotorlar, OUTPUT);
  pinMode(geriSolMotorlar, OUTPUT);
  pinMode(geriSagMotorlar, OUTPUT);
  
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(onFar, OUTPUT);
  pinMode(arkaFar, OUTPUT);
  pinMode(stopFar, OUTPUT);
  pinMode(korna, OUTPUT);
  dur();
  Serial.begin(9600);
}

void loop() {

  digitalWrite(trigger, LOW); //sensör pasif hale getirildi
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH); //Sensore ses dalgasının üretmesi için emir verildi
  delayMicroseconds(10);
  digitalWrite(trigger, LOW); //Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi

  sure = pulseIn(echo, HIGH); //ses dalgasının geri dönmesi için geçen sure ölçülüyor
  mesafe = sure / 29.1 / 2; //ölçülen süre uzaklığa çevriliyor
  
  if(digitalRead(BTkomutu)==LOW) { 
     BTkomutu = 'S';
     }
  
  BTkomutu = Serial.read();

  if (BTkomutu == '0') {
    hiz = 0;
  }
  else if (BTkomutu == '1') {
    hiz = 50;
  }
  else if (BTkomutu == '2') {
    hiz = 75;
  }
  else if (BTkomutu == '3') {
    hiz = 100;
  }
  else if (BTkomutu == '4') {
    hiz = 125;
  }
  else if (BTkomutu == '5') {
    hiz = 150;
  }
  else if (BTkomutu == '6') {
    hiz = 175;
  }
  else if (BTkomutu == '7') {
    hiz = 200;
  }
  else if (BTkomutu == '8') {
    hiz = 225;
  }
  else if (BTkomutu == '9') {
    hiz = 240;
  }
  else if (BTkomutu == 'q') {
    hiz = 255;
  }

  
/// Araç Hareketi ///

  if (mesafe >= 6) {

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
  else if(BTkomutu=='v') {  
        digitalWrite(korna, LOW);
       }
       
       }
  else {
    dur();
    geri();
    delay(250);
    dur();
  }
  
}

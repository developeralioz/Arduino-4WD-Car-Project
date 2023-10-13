//L298N Bağlantısı   
  const int motorA1  = 6;  // L298N'in IN3 Girişi
  const int motorA2  = 5;  // L298N'in IN1 Girişi
  const int motorB1  = 9; // L298N'in IN2 Girişi
  const int motorB2  = 10;  // L298N'in IN4 Girişi


 // int i=0; //Döngüler için atanan rastgele bir değişken
 // int j=0; //Döngüler için atanan rastgele bir değişken
  char state; //Bluetooth cihazından gelecek sinyalin değişkeni // int --> char
  int vSpeed=255;     // Standart Hız, 0-255 arası bir değer alabilir

void setup() {
    // Pinlerimizi belirleyelim
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);
    pinMode(2, OUTPUT); // bunu değiştir
    pinMode(3, OUTPUT);
    pinMode(12, OUTPUT);
    digitalWrite(2, HIGH);
    digitalWrite(12, HIGH);
    // 9600 baud hızında bir seri port açalım
    Serial.begin(9600);
}
 
void loop() {

  /*Bluetooth bağlantısı koptuğunda veya kesildiğinde arabayı durdur.
 (Aktif etmek için alt satırın "//" larını kaldırın.)*/
    // if(digitalRead(state)==LOW) { state='S'; }

  //Gelen veriyi 'state' değişkenine kaydet
    if(Serial.available() > 0){     
      state = Serial.read();   
    }
  
  /* Uygulamadan ayarlanabilen 4 hız seviyesi.(Değerler 0-255 arasında olmalı)*/
    if (state == '0'){
      vSpeed=0;}
    else if (state == '1'){
      vSpeed=100;}
    else if (state == '2'){
      vSpeed=180;}
    else if (state == '3'){
      vSpeed=200;}
    else if (state == '4'){
      vSpeed=255;}
     
  /***********************İleri****************************/
  //Gelen veri 'F' ise araba ileri gider.
    if (state == 'F') {
      analogWrite(motorA1, vSpeed); analogWrite(motorA2, 0);
        analogWrite(motorB1, vSpeed);      analogWrite(motorB2, 0); 
          digitalWrite(3, LOW);
    }
  /**********************İleri Sol************************/
  //Gelen veri 'G' ise araba ileri sol(çapraz) gider.
    else if (state == 'G') {
      analogWrite(motorA1,vSpeed ); analogWrite(motorA2, 0);  
        analogWrite(motorB1, vSpeed/3);    analogWrite(motorB2, 0);
          digitalWrite(3, LOW);
    }
  /**********************İleri Sağ************************/
  //Gelen veri 'I' ise araba ileri sağ(çapraz) gider.
    else if (state == 'I') {
        analogWrite(motorA1, vSpeed/3); analogWrite(motorA2, 0); 
        analogWrite(motorB1, vSpeed);      analogWrite(motorB2, 0);
          digitalWrite(3, LOW);
    }
  /***********************Geri****************************/
  //Gelen veri 'B' ise araba geri gider.
    else if (state == 'B') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, vSpeed);
          digitalWrite(3, LOW); 
    }
  /**********************Geri Sol************************/
  //Gelen veri 'H' ise araba geri sol(çapraz) gider
    else if (state == 'H') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed/3); 
        analogWrite(motorB1, 0); analogWrite(motorB2, vSpeed); 
          digitalWrite(3, LOW);
    }
  /**********************Geri Sağ************************/
  //Gelen veri 'J' ise araba geri sağ(çapraz) gider
    else if (state == 'J') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, vSpeed/3);
          digitalWrite(3, LOW);
    }
  /***************************Sol*****************************/
  //Gelen veri 'L' ise araba sola gider.
    else if (state == 'L') {
      analogWrite(motorA1, vSpeed);   analogWrite(motorA2, 150); 
        analogWrite(motorB1, 0); analogWrite(motorB2, 0);
          digitalWrite(3, LOW);
    }
  /***************************Sağ*****************************/
  //Gelen veri 'R' ise araba sağa gider
    else if (state == 'R') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, 0); 
        analogWrite(motorB1, vSpeed);   analogWrite(motorB2, 150); 
          digitalWrite(3, LOW);    
    }
  
  /************************Stop*****************************/
  //Gelen veri 'S' ise arabayı durdur.
    else if (state == 'S'){
        analogWrite(motorA1, 0);  analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
          digitalWrite(3, HIGH);
    }  
}

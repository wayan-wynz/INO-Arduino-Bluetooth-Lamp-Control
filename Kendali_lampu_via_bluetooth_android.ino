/* By I Wayan Sujane DBC 115 027
   kontrol Lampu via android konektivitas Bluetooth */

//==== Inisialisasi Pin LED ====//
int pinLampu1 = 5;    
int pinLampu2 = 4;
int pinLampu3 = 3;
int pinLampu4 = 2;  

char wayan;
  void setup () {
    pinMode(pinLampu1, OUTPUT);
    pinMode(pinLampu2, OUTPUT);
    pinMode(pinLampu3, OUTPUT);
    pinMode(pinLampu4, OUTPUT);
    Serial.begin(9600); //BaudRate Kecepatan transmisi data//
  }
//==== Tahap pengecekan data apakah sudah diterima  ====//
void loop() {
  if (Serial.available()) {
    wayan = Serial.read(); //membaca data yang diterima//
   
//----------Hidupkan dan matikan semua lampu-----------//
if (wayan == '1') {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
}

//----------Hidupkan setiap led dengan tombol----------//
else if(wayan == '2') {digitalWrite(5, HIGH);} //TERAS DEPAN//
//pin2//
    
else if(wayan == '3') {digitalWrite(4, HIGH);} //RUANG TAMU//
//pin3//

else if(wayan == '4') {digitalWrite(3, HIGH);} //KAMAR//
//pin4//

else if(wayan == '5') {digitalWrite(2, HIGH);} //DAPUR//
//pin5// 


//----------Matikan led dengan tombol----------//
else if (wayan == 'a') { //SEMUA LAMPU MATI//
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
}

else if(wayan == 'b') {digitalWrite(5, LOW);} //TERAS DEPAN//
//pin2//

else if(wayan == 'c') {digitalWrite(4, LOW);} //RUANG TAMU//
//pin3//

else if(wayan == 'd') {digitalWrite(3, LOW);} //KAMAR//
//pin4//

else if(wayan == 'e') {digitalWrite(2, LOW);} //DAPUR//
//pin5// 

//==== Mengirimkan data ke port serial menuju tampilan di android ====//    
    Serial.print("== ");
    Serial.println(wayan);
}
} 

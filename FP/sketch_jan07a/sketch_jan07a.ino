
#include <SPI.h>

long bacaJarak (int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  //set pin trigger as output
  digitalWrite(triggerPin, LOW); // mulai generate frekuensi set pin low
  digitalWrite(triggerPin, HIGH); // Sets the trigger pin HIGH
  delayMicroseconds(10); // diam 10 microseconds
  digitalWrite(triggerPin, LOW);  
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH); // Reads the echo pin, returns the sound wave travel time in microseconds
}



void setup()
{
  Serial.begin(9600);
  SPI.begin(); //memulai komunikasi SPI
  Serial.println("CLEARSHEET"); //membersihkan sheet             
  Serial.println("LABEL,Data,Tanggal,Waktu"); //membuat label kolom “Data, tanggal, dan waktu” pada sheet
}


void loop()
{
  int cm = 0; //reset cm ke 0
  cm = (0.03446 * bacaJarak(8, 7))/2;
  Serial.print("DATA,"); //mengaktifkan pengambilan data ditulis capslock
  Serial.print(cm); //menuliskan data jarak
  Serial.print (" cm"); //menambahkan akhiran cm
  Serial.print (","); //tanda baca , untuk pindah ke kolom berikutnya
  Serial.print ("DATE"); //mengambil data Tanggal dari sistem ke sheet
  Serial.print (","); //tanda baca , untuk pindah ke kolom berikutnya
  Serial.print ("TIME"); //mengambil data jam dari sistem ke sheet
  Serial.println (""); //membuat baris baru pada sheet
  delay(1000);
}

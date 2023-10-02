#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);


const int sensor = A0; //Sensor di hubungkan ke pin A0
const int buzzer = 2;     // inisialisasi buzzer pin pada 2

int nilai;                     // Variabel nilai

void setup() {
  pinMode(ldr, INPUT);    // Deklarasi LDR sebagai Input
  pinMode(buzzer, OUTPUT);  // Untuk menentukan pin buzzer sebagai output
  Serial.begin(9600);     // Baud komunikasi serial pada 9600
  lcd.init();
  lcd.backlight();
  lcd.clear();

   }

  void loop() {
  nilai = analogRead(ldr);     // Instruksi membaca nilai analog LDR
  Serial.print("Nilai LDR: "); // Menampilkan Nilai analog LDR pada Serial Monitor
  Serial.println(nilai);
  delay(1000);
  
  if (nilai < 800) { // buzzer On jika nilai analog lebih kecil dari 800
  digitalWrite(buzzer, HIGH); 
  lcd.setCursor(0, 0);
  lcd.print("Nilai LDR: ");
  lcd.print(nilai);
  lcd.setCursor(2, 1);
  lcd.print("Ruang Gelap");
  delay(4000);
  lcd.clear();
  }
    
   
  else {  // buzzer Off ika nilai analog lebih besar dari 900 
  digitalWrite(buzzer, LOW); 
  lcd.setCursor(0, 0);
  lcd.print("Nilai LDR: ");
  lcd.print(nilai);
  lcd.setCursor(2, 1);
  lcd.print("Ruang Terang");
  delay(2000);
  lcd.clear();
 
  }
}

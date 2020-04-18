// Josep Marcello
// 12 April 2020
// Sensor warna merah atau hijau

#define elif else if

// Pin yang digunakan
const int S0 = 3, S1 = 4, S2 = 9, S3 = 8, SensorOutput = 10;

// Menyimpan nilai RGB
int R, G, B;
// Warna yang sebelumnya dibaca
String prev_color;
// Warna yang dibaca
String now_color;

void setup() {
  // Inisialisasi varaibel
  prev_color = "NaN";
  now_color = "Red";
  // pin-pin output
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // pin-pin input
  pinMode(SensorOutput, INPUT);
  
  // Mempersiapkan serial monitor
  Serial.begin(9600);

  // Membuat scaling frequency menjadi 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}

void loop() {
  // Membaca warna merah
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  // Membaca frekuensi output
  R = pulseIn(SensorOutput, LOW);

  // Membaca warna hijau
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  // Membaca frekuensi output
  G = pulseIn(SensorOutput, LOW);
  
  //  Remapping nilai menjadi 0 sampai 255
  R = map(R,938,101,0,255);
  G = map(G,90,648,255,0);

/* Menuliskan komposisi RG warna yang dibaca ke serial monitor
 Debugging purposes */
//  //  Warna merah
//    Serial.print("R = ");
//    Serial.print(R);
//    delay(100);
//  //  Warna hijau
//    Serial.print(" | G = ");
//    Serial.println(G);
//    delay(100);

  // Menentukan warna sekarang dan warna sebelumnya
  if (G >= 170) now_color = "Green"; // Jika benda berwarna hijau diletakkan di atas sensor
  elif (R >= 200) now_color = "Red"; //  Jika benda berwarna merah diletakkan di atas sensor
  else now_color = "NaN"; //  Jika tidak ada benda yang diletakkan di atas sensor atau warnanya bukan hijau atau merah

//  Serial.println(now_color);
  
  // Menuliskan warna benda ke layar (jika warna benda yang sebelumnya dibaca berbeda dengan yang sekarang dibaca)
  if (now_color != prev_color)
  {
    prev_color = now_color;
    if (now_color == "Green")
    {
      Serial.println("Warna hijau terdeteksi");
      Serial.println(" __ __  ____  ____   ____  __ __ ");
      Serial.println("|  |  ||    ||    | /    ||  |  |");
      Serial.println("|  |  | |  | |__  ||  o  ||  |  |");
      Serial.println("|  _  | |  | __|  ||     ||  |  |");
      Serial.println("|  |  | |  |/  |  ||  _  ||  :  |");
      Serial.println("|  |  | |  |\  `  ||  |  ||     |");
      Serial.println("|__|__||____|\____||__|__| \__,_|");
    }
    else if (now_color == "Red")
    {
      Serial.println("Warna merah terdeteksi");
      Serial.println(" ___ ___    ___  ____    ____  __ __ ");
      Serial.println("|   |   |  /  _]|    \  /    ||  |  |");
      Serial.println("| _   _ | /  [_ |  D  )|  o  ||  |  |");
      Serial.println("|  \_/  ||    _]|    / |     ||  _  |");
      Serial.println("|   |   ||   [_ |    \ |  _  ||  |  |");
      Serial.println("|   |   ||     ||  .  \|  |  ||  |  |");
      Serial.println("|___|___||_____||__|\_||__|__||__|__|");
    }
    else
    {
      Serial.println("Tidak ada benda terdeteksi atau warnanya bukan hijau atau merah");
    }
    delay(1000);
  }
}

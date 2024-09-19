float suhu, kelembaban;
float suhuH, suhuM, suhuL;
float kelembabanH, kelembabanM, kelembabanL;
const char* kondisi_suhu = " ";
const char* kondisi_kelembaban = " ";
const char* hasil = " ";

float nilai_dingin[] = {0, 0, 25};
float nilai_normal[] = {20, 27, 36};
float nilai_panas[] = {35, 50, 50};

float nilai_kering[] = {55, 60, 60};
float nilai_lembab[] = {65, 75, 85};
float nilai_basah[] = {80, 90, 100};

//Rule Fuzzy
unsigned char suhuLow() {
  if (suhu <= nilai_dingin[1]) {
    suhuL = 1;
  }
  else if (suhu >= nilai_dingin[1] && suhu <= nilai_dingin[2]) {
    suhuL = (nilai_dingin[2] - suhu) / (nilai_dingin[2] - nilai_dingin[1]);
  }
  else if (suhu > nilai_dingin[2]) {
    suhuL = 0;
  }
  return suhuL;
}
unsigned char suhuMedium() {
  if (suhu < nilai_normal[0]) {
    suhuM = 0;
  }
  else if (suhu >= nilai_normal[0] && suhu <= nilai_normal[1]) {
    suhuM = (suhu - nilai_normal[0]) / (nilai_normal[1] - nilai_normal[0]);
  }
  else if (suhu >= nilai_normal[1] && suhu <= nilai_normal[2]) {
    suhuM = (nilai_normal[2] - suhu) / (nilai_normal[2] - nilai_normal[1]);
  }
  else if (suhu > nilai_normal[2]) {
    suhuM = 0;
  }
  return suhuM;
}
unsigned char suhuHigh () {
  if (suhu < nilai_panas[0]) {
    suhuH = 0;
  }
  else if (suhu >= nilai_panas[0] && suhu <= nilai_panas[1]) {
    suhuH = (suhu - nilai_panas[0]) / (nilai_panas[1] - nilai_panas[0]);
  }
  else if (suhu > nilai_panas[1]) {
    suhuH = 1;
  }
  return suhuH;
}

unsigned char kelembabanLow() {
  if (kelembaban <= nilai_kering[1]) {
    kelembabanL = 1;
  }
  else if (kelembaban >= nilai_kering[1] && kelembaban <= nilai_kering[2]) {
    kelembabanL = (nilai_kering[2] - kelembaban) / (nilai_kering[2] - nilai_kering[1]);
  }
  else if (kelembaban > nilai_kering[2]) {
    kelembabanL = 0;
  }
  return kelembabanL;
}

unsigned char kelembabanMedium() {
  if (kelembaban < nilai_lembab[0]) {
    kelembabanM = 0;
  }
  else if (kelembaban >= nilai_lembab[0] && kelembaban <= nilai_lembab[1]) {
    kelembabanM = (kelembaban - nilai_lembab[0]) / (nilai_lembab[1] - nilai_lembab[0]);
  }
  else if (kelembaban >= nilai_lembab[1] && kelembaban <= nilai_lembab[2]) {
    kelembabanM = (nilai_lembab[2] - kelembaban) / (nilai_lembab[2] - nilai_lembab[1]);
  }
  else if (kelembaban > nilai_lembab[2]) {
    kelembabanM = 0;
  }
  return kelembabanM;
}

unsigned char kelembabanHigh () {
  if (kelembaban < nilai_basah[0]) {
    kelembabanH = 0;
  }
  else if (kelembaban >= nilai_basah[0] && kelembaban <= nilai_basah[1]) {
    kelembabanH = (kelembaban - nilai_basah[0]) / (nilai_basah[1] - nilai_basah[0]);
  }
  else if (kelembaban > nilai_basah[1]) {
    kelembabanH = 1;
  }
  return kelembabanH;
}

//Step Fuzzifikasi
void fuzzifikasi() {
  suhuLow();
  suhuMedium();
  suhuHigh();
  kelembabanLow();
  kelembabanMedium();
  kelembabanHigh();
}

void fuzzy_rule() {
  fuzzifikasi();

  if (suhuL > suhuM && suhuL > suhuH) {
    kondisi_suhu = "Dingin";
  }
  else if (suhuL == suhuM && suhuL > suhuH) {
    kondisi_suhu = "Normal";
  }
  else if (suhuM > suhuL && suhuM > suhuH) {
    kondisi_suhu = "Normal";
  }
  else if (suhuM > suhuL && suhuM == suhuH) {
    kondisi_suhu = "Panas";
  }
  else if (suhuH > suhuL && suhuH > suhuM) {
    kondisi_suhu = "Panas";
  }

  if (kelembabanL > kelembabanM && kelembabanL > kelembabanH) {
    kondisi_kelembaban = "Kering";
  }
  else if (kelembabanL == kelembabanM && kelembabanL > kelembabanH) {
    kondisi_kelembaban = "Lembab";
  }
  else if (kelembabanM > kelembabanL && kelembabanM > kelembabanH) {
    kondisi_kelembaban = "Lembab";
  }
  else if (kelembabanM > kelembabanL && kelembabanM == kelembabanH) {
    kondisi_kelembaban = "Basah";
  }
  else if (kelembabanH > kelembabanL && kelembabanH > kelembabanM) {
    kondisi_kelembaban = "Basah";
  }

  //Step Defuzzifikasi
  if (kondisi_suhu == "Dingin" && kondisi_kelembaban == "Kering") {
    hasil = "Jelek" ;
  }
  else if (kondisi_suhu == "Dingin" && kondisi_kelembaban == "Lembab") {
    hasil = "Lumayan" ;
  }
  else if (kondisi_suhu == "Dingin" && kondisi_kelembaban == "Basah") {
    hasil = "Jelek" ;
  }
  else if (kondisi_suhu == "Normal" && kondisi_kelembaban == "Kering") {
    hasil = "Lumayan" ;
  }
  else if (kondisi_suhu == "Normal" && kondisi_kelembaban == "Lembab") {
    hasil = "Bagus" ;
  }
  else if (kondisi_suhu == "Normal" && kondisi_kelembaban == "Basah") {
    hasil = "Lumayan" ;
  }
  else if (kondisi_suhu == "Panas" && kondisi_kelembaban == "Kering") {
    hasil = "Jelek" ;
  }
  else if (kondisi_suhu == "Panas" && kondisi_kelembaban == "Lembab") {
    hasil = "Lumayan" ;
  }
  else if (kondisi_suhu == "Panas" && kondisi_kelembaban == "Basah") {
    hasil = "Jelek" ;
  }
}


void setup() {
  Serial.begin(9600);

  kelembaban = 85;
  suhu = 29;

  fuzzy_rule();

  Serial.println("Kondisi Suhu: " + String(kondisi_suhu));
  Serial.println("Kondisi Kelembaban: " + String(kondisi_kelembaban));
  Serial.println("Hasil: " + String(hasil));
}


void loop() {

}
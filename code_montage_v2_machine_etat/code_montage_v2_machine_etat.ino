//définitions nécessaires à la connexion BT
#include <SoftwareSerial.h>
#define rxPin 10 //cable jaune sur Tx
#define txPin 11 //cable vert sur Rx
#define baudrate 9600
SoftwareSerial mySerial(rxPin, txPin);

//bit qui portera l'information entre l'Arduino et l'application
byte serialRX;

//valeur désignant l'action à réaliser
int action = 0;

//OLED
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>
#include <Adafruit_SPIDevice.h>

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Wire.h>

#define oled Adafruit_SSD1306
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3C for 128x32
oled display(-1);


//gestion valeur tension
#define A0 0
int valeur = 0;
int R1 = 100000;
int R3 = 100000;
int R2 = 1000;
int R5 = 10000;
int Vcc = 5;

//fonction d'intialilsation de l'OLED au démarrage
void demarrage () {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.drawRect (1, 1, 124, 30, WHITE);
  display.setCursor(25, 15);
  display.println("Projet capteur");
  display.display();
  delay(600);
}


void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);

  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.begin(9600);
  demarrage();
}



// fonction permettant la lecture de la valeur en ADC sur l'arduino
float lectureValeur () {
  valeur = analogRead(A0);
  return valeur;
}

//fonction gérant l'affichage de la valeur sur l'OLED
void affichage_tension (float valeur) {
  display.clearDisplay();
  display.drawRect (1, 1, 124, 30, WHITE);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(30, 6);
  display.print("Valeur R =");
  display.setCursor(32, 15);
  float R3R2 = 10100000;//valeur numérique du calcul: 
  float VccVmes = 256; //valeur numérique du calcul:
  float R1R5 = 110000; //valeur numérique du calcul: 
  float val_res = ((R3R2 * VccVmes) / (valeur)) - R1R5; //Affichage de la résisitance
  display.print(val_res /1000000); //Pour obtenir une valeur en MOhm
  display.println("  MOhm");
  display.display();
}

//loop du programme: une machine à états permet de gérer les deux cas de figure simples imaginés: le lancement de mesure et l'arrêt de mesure
void loop() {
  while (mySerial.available()) {
    serialRX = mySerial.read();//lecture du bit envoyé par l'application: 2 cas possibles
    switch (serialRX) {
      case 1: //serialRX=1 permet d'engager la mesure
        action = 1;
        break;
      case 2: //serialRX=2 met fin à la mesure
        action = 2;
        break;
      default: break;
    }
  }
  switch (action) {
    case 1://code arduino permettant d'afficher la valeur sur l'OLED et d'envoyer à l'appli
      //valeur envoyée est en byte pour l'avoir en entier
      byte val = map(lectureValeur(), 0, 1024, 0, 255);
      mySerial.write(val); //write directement la valeur en ADC
      Serial.println(val);
      affichage_tension(val); //affiche la résistance du capteur graphite sur l'OLED
      delay(50);
      break;

    case 2://code arduino permettant de marquer l'arrêt de la mesure
      demarrage (); //il n'y a plus de mesure en cours, l'OLED affiche donc l'écran de démarrage
      break;

    default: break;//default case dans le cas où "action" n'a pas la valeur attendue
  }

}

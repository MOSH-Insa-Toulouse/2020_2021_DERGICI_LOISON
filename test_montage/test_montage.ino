//connexion BT
#include <SoftwareSerial.h>
#define rxPin 10 //cable jaune sur Tx
#define txPin 11 //cable vert sur Rx
#define baudrate 9600
SoftwareSerial mySerial(rxPin,txPin);

volatile byte RX = 0;
byte serialRX;
byte serialTX;
int action=0;

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
int valeur=0;
int R1=100000;
int R3=100000;
int R2=1000;
int R5=10000;
int Vcc=5;


void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);

  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);
  mySerial.begin(9600);
//démarrage
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.drawRect (1, 1, 124,30, WHITE);
  display.setCursor(25,15);
  display.println("Projet capteur");
  display.display();
  delay(600);
}


float lectureValeur () {
  valeur=analogRead(A0);
  return valeur;
  }

//affichage de la valeur sur l'OLED 
void affichage_tension (float valeur) {
  display.clearDisplay();
  display.drawRect (1, 1, 124,30, WHITE);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(30,6);
  display.print("Valeur R =");
  display.setCursor(32,15);
  float R3R2=10100000;
  float VccVmes=256;
  float R1R5=110000;
  float val_res=((R3R2*VccVmes)/(valeur))-R1R5; //Affichage de la résisitance 
  display.print(val_res/1000000);
  display.println("  MOhm");
  display.display();
  }


void loop() {
  //Valeur en byte pour l'avoir en entier 
      byte val = map(lectureValeur(), 0, 1024, 0, 255);
      mySerial.write(val); //write directement la valeur
      Serial.println(val);
      affichage_tension(val); //affiche la résistance du capteur graphite 
      delay(25);
}

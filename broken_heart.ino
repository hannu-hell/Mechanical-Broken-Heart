#include <FastLED.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Temperature sensor Pin
#define ONE_WIRE_BUS 8

// Neopixel definitions
#define NUM_LEDS 4
#define DATA_PIN 7
#define BRIGHTNESS  255

CRGB leds[NUM_LEDS];

const int en1 = 2;
const int in1 = 3;
const int in2 = 4;
const int limit_switch = 9;

bool home_pos = false;

bool boil = false;
bool hot = false;
bool warm = false;
bool comfy = false;
bool room = false;
bool cool = false;
bool cold = false;
bool freeze = false;

float temp_reading;



// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);


void setup() {
  sensors.begin();  // Start up the library
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(en1, OUTPUT);
  digitalWrite(en1, HIGH);
  pinMode(limit_switch, INPUT_PULLUP);
  leds[0] = CRGB::Blue;
  leds[1] = CRGB::Cyan;
  leds[2] = CRGB::Aqua;
  leds[3] = CRGB::Black;
  FastLED.show();
  for (int i=255; i>=0; i--){
    FastLED.setBrightness(i);
    FastLED.delay(5);
    FastLED.show();
  }
  for (int i=0; i<=255; i++){
    FastLED.setBrightness(i);
    FastLED.delay(5);
    FastLED.show();
  }
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(3500);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void loop() {
  
  int switchVal = digitalRead(limit_switch);
  if (switchVal == LOW){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    home_pos = true;
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(500);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
//   close up
  if (home_pos == false){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }

  sensors.requestTemperatures(); 
  temp_reading = sensors.getTempCByIndex(0);
  check_freeze();
  check_cold();
  check_cool();
  check_warm();
  check_room();
  check_comfy();
  check_hot();
  check_boil();

  
}

void check_freeze(){
//  sensors.requestTemperatures(); 
//  float temp_reading = sensors.getTempCByIndex(0);
  if (home_pos == true && freeze == false && temp_reading <= 0){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(2200);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    delay(100);
    turn_off_lights();
    leds[0] = CRGB::DarkMagenta;
    leds[1] = CRGB::BlueViolet;
    leds[2] = CRGB::Amethyst;
//    leds[3] = CRGB::DarkOrchid;
    FastLED.show();
    home_pos = false;
    reset_temperatures();
    freeze = true;
  }
}

void check_cold(){
//  sensors.requestTemperatures(); 
//  float temp_reading = sensors.getTempCByIndex(0);
  if (home_pos == true && cold == false && (temp_reading > 0 && temp_reading <= 10)){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(2000);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    delay(100);
    turn_off_lights();
    leds[0] = CRGB::Blue;
    leds[1] = CRGB::Cyan;
    leds[2] = CRGB::Aqua;
//    leds[3] = CRGB::Aquamarine;
    FastLED.show();
    home_pos = false;
    reset_temperatures();
    cold = true;
  }  
}

void check_cool(){
//  sensors.requestTemperatures(); 
//  float temp_reading = sensors.getTempCByIndex(0);
  if (home_pos == true && cool == false && (temp_reading > 10 && temp_reading <= 15)){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(1800);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    delay(100);
    turn_off_lights();
    leds[0] = CRGB::Lime;
    leds[1] = CRGB::LimeGreen;
    leds[2] = CRGB::MediumTurquoise;
//    leds[3] = CRGB::PaleGreen;
    FastLED.show();
    home_pos = false;
    reset_temperatures();
    cool = true;
  }    
}

void check_comfy(){
//  sensors.requestTemperatures(); 
//  float temp_reading = sensors.getTempCByIndex(0);
  if (home_pos == true && comfy == false && (temp_reading > 15 && temp_reading <= 20)){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(1500);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    delay(100);
    turn_off_lights();
    leds[0] = CRGB::LightSeaGreen;
    leds[1] = CRGB::LightSkyBlue;
    leds[2] = CRGB::LightBlue;
//    leds[3] = CRGB::LightCyan;
    FastLED.show();
    home_pos = false;
    reset_temperatures();
    comfy = true;
  }  
}

void check_room(){
//  sensors.requestTemperatures(); 
//  float temp_reading = sensors.getTempCByIndex(0);
  if (home_pos == true && room == false && (temp_reading > 20 && temp_reading <= 22)){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(1200);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    delay(100);
    turn_off_lights();
    leds[0] = CRGB::NavajoWhite;
    leds[1] = CRGB::Moccasin;
    leds[2] = CRGB::MistyRose;
//    leds[3] = CRGB::MintCream;
    FastLED.show();
    home_pos = false;
    reset_temperatures();
    room = true;
  }  
}

void check_warm(){
//  sensors.requestTemperatures(); 
//  float temp_reading = sensors.getTempCByIndex(0);
  if (home_pos == true && warm == false && (temp_reading > 22 && temp_reading <= 25)){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(1200);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    delay(100);
    turn_off_lights();
    leds[0] = CRGB::Gold;
    leds[1] = CRGB::Goldenrod;
    leds[2] = CRGB::Khaki;
//    leds[3] = CRGB::LemonChiffon;
    FastLED.show();
    home_pos = false;
    reset_temperatures();
    warm = true;
  }  
}

void check_hot(){
//  sensors.requestTemperatures(); 
//  float temp_reading = sensors.getTempCByIndex(0);
  if (home_pos == true && hot == false && (temp_reading > 25 && temp_reading <= 28)){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(1200);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    delay(100);
    turn_off_lights();
    leds[0] = CRGB::Chocolate;
    leds[1] = CRGB::Coral;
    leds[2] = CRGB::BurlyWood;
//    leds[3] = CRGB::LightSalmon;
    FastLED.show();
    home_pos = false;
    reset_temperatures();
    hot = true;
  }  
}

void check_boil(){
//  sensors.requestTemperatures(); 
//  float temp_reading = sensors.getTempCByIndex(0);
  if (home_pos == true && boil == false && temp_reading > 28){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(1200);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    delay(100);
    turn_off_lights();
    leds[0] = CRGB::DarkRed;
    leds[1] = CRGB::Crimson;
    leds[2] = CRGB::FireBrick;
//    leds[3] = CRGB::IndianRed;
    FastLED.show();
    home_pos = false;
    reset_temperatures();
    boil = true;
  }  
}

void reset_temperatures(){
  boil = false;
  hot = false;
  warm = false;
  comfy = false;
  room = false;
  cool = false;
  cold = false;
  freeze = false;
}

void turn_off_lights(){
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  FastLED.show();
  FastLED.delay(10);
}

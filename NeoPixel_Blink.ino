
#include <Adafruit_NeoPixel.h> // https://github.com/adafruit/Adafruit_NeoPixel

int State = LOW;
unsigned long previousMillis = 0;    // Blink(stores last time LED was updated)

#define PIN D8 // Which pin on the Arduino is connected to the NeoPixels?
#define NUMPIXELS 24 // How many ws2812 are in the string? 
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(85);  // Lower brightness and save eyeballs!
  pixels.show(); // Initialize all pixels to 'off'
}

void loop() {
  int PIXEL = 12;
  int R = 25; // red blinks with intensity 25
  int B = 1;
  int G = 1;
  int S = 10; // blinks / seconds

  blink(PIXEL, R, G, B, S); //PixelNumber, Red, Green, Blue, Blink/sec // R, G, B => intensity 3 - 255

}

void blink(int p, int R, int G, int B, int interval) {  //pixel_number, Reg, Green, Blue, Interval
  unsigned long currentMillis = millis();  //timer blink
  if (currentMillis - previousMillis >= 1000 / interval) {
    previousMillis = currentMillis;
    State = !State;
    R = (R * State);
    G = (G * State);
    B = (B * State);
    pixels.setPixelColor(p, pixels.Color(R , G , B));
    pixels.show();   // Send the updated pixel colors to the hardware.
    //   }
  }
}

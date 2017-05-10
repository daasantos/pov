#include <Adafruit_NeoPixel.h>

#define PIN 8    // Pin the strip is connected to
#define QTLD 8   // # Neopixels in the strip
#define DELAY 6  // Delay for each column in a image/letter

Adafruit_NeoPixel strip = Adafruit_NeoPixel(QTLD, PIN, NEO_GRB + NEO_KHZ800);

void setup(){
	Serial.begin(9600);
	strip.begin();          // Initialize the strip
	strip.setBrightness(8); // Dimmer lights for POV effect
	strip.show();           // Push data to the strip, after each call to setPixelColor(), show() must be called
}

uint8_t a[8] = { 0x7C, 0x7E, 0x13, 0x13, 0x7E, 0x7C, 0x00, 0x00 };
uint8_t b[8] = { 0x41, 0x7F, 0x7F, 0x49, 0x49, 0x7F, 0x36, 0x00 };
uint8_t c[8] = { 0x1C, 0x3E, 0x63, 0x41, 0x41, 0x63, 0x22, 0x00 };
uint8_t d[8] = { 0x41, 0x7F, 0x7F, 0x41, 0x63, 0x3E, 0x1C, 0x00 };
uint8_t e[8] = { 0x41, 0x7F, 0x7F, 0x49, 0x5D, 0x41, 0x63, 0x00 };
uint8_t f[8] = { 0x41, 0x7F, 0x7F, 0x49, 0x1D, 0x01, 0x03, 0x00 };
uint8_t g[8] = { 0x1C, 0x3E, 0x63, 0x41, 0x51, 0x73, 0x72, 0x00 };
uint8_t h[8] = { 0x7F, 0x7F, 0x08, 0x08, 0x7F, 0x7F, 0x00, 0x00 };
uint8_t i[8] = { 0x00, 0x41, 0x7F, 0x7F, 0x41, 0x00, 0x00, 0x00 };
uint8_t j[8] = { 0x30, 0x70, 0x40, 0x41, 0x7F, 0x3F, 0x01, 0x00 };
uint8_t k[8] = { 0x41, 0x7F, 0x7F, 0x08, 0x1C, 0x77, 0x63, 0x00 };
uint8_t l[8] = { 0x41, 0x7F, 0x7F, 0x41, 0x40, 0x60, 0x70, 0x00 };
uint8_t m[8] = { 0x7F, 0x7F, 0x0E, 0x1C, 0x0E, 0x7F, 0x7F, 0x00 };
uint8_t n[8] = { 0x7F, 0x7F, 0x06, 0x0C, 0x18, 0x7F, 0x7F, 0x00 };
uint8_t o[8] = { 0x1C, 0x3E, 0x63, 0x41, 0x63, 0x3E, 0x1C, 0x00 };
uint8_t p[8] = { 0x41, 0x7F, 0x7F, 0x49, 0x09, 0x0F, 0x06, 0x00 };
uint8_t q[8] = { 0x1E, 0x3F, 0x21, 0x71, 0x7F, 0x5E, 0x00, 0x00 };
uint8_t r[8] = { 0x41, 0x7F, 0x7F, 0x09, 0x19, 0x7F, 0x66, 0x00 };
uint8_t s[8] = { 0x26, 0x6F, 0x4D, 0x59, 0x73, 0x32, 0x00, 0x00 };
uint8_t t[8] = { 0x03, 0x41, 0x7F, 0x7F, 0x41, 0x03, 0x00, 0x00 };
uint8_t u[8] = { 0x7F, 0x7F, 0x40, 0x40, 0x7F, 0x7F, 0x00, 0x00 };
uint8_t v[8] = { 0x1F, 0x3F, 0x60, 0x60, 0x3F, 0x1F, 0x00, 0x00 };
uint8_t w[8] = { 0x7F, 0x7F, 0x30, 0x18, 0x30, 0x7F, 0x7F, 0x00 };
uint8_t x[8] = { 0x43, 0x67, 0x3C, 0x18, 0x3C, 0x67, 0x43, 0x00 };
uint8_t y[8] = { 0x07, 0x4F, 0x78, 0x78, 0x4F, 0x07, 0x00, 0x00 };
uint8_t z[8] = { 0x47, 0x63, 0x71, 0x59, 0x4D, 0x67, 0x73, 0x00 };

void displayColumn(uint8_t col){
	uint32_t color = strip.Color( 255, 0, 0 ); //R, G, B
	
	for(uint8_t i = 0; i < QTLD; i++){
		if((0x01 << i) & col){strip.setPixelColor(i, color);} // Bitwise to select which pixels to turn on/off
		else{strip.setPixelColor(i, 0);}
	}
	strip.show();
}

void displayChar(char* s){
	for (uint8_t ct = 0; ct <= strlen(s); ct++, s++){
		if (*s == 'a'){for (uint8_t i = 0; i < 8; i++){displayColumn(a[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'b'){for (uint8_t i = 0; i < 8; i++){displayColumn(b[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'c'){for (uint8_t i = 0; i < 8; i++){displayColumn(c[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'd'){for (uint8_t i = 0; i < 8; i++){displayColumn(d[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'e'){for (uint8_t i = 0; i < 8; i++){displayColumn(e[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'f'){for (uint8_t i = 0; i < 8; i++){displayColumn(f[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'g'){for (uint8_t i = 0; i < 8; i++){displayColumn(g[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'h'){for (uint8_t i = 0; i < 8; i++){displayColumn(h[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'i'){for (uint8_t j = 0; j < 8; j++){displayColumn(i[j]);delay(DELAY);}displayColumn(0);}
		if (*s == 'j'){for (uint8_t i = 0; i < 8; i++){displayColumn(j[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'k'){for (uint8_t i = 0; i < 8; i++){displayColumn(k[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'l'){for (uint8_t i = 0; i < 8; i++){displayColumn(l[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'm'){for (uint8_t i = 0; i < 8; i++){displayColumn(m[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'n'){for (uint8_t i = 0; i < 8; i++){displayColumn(n[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'o'){for (uint8_t i = 0; i < 8; i++){displayColumn(o[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'p'){for (uint8_t i = 0; i < 8; i++){displayColumn(p[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'q'){for (uint8_t i = 0; i < 8; i++){displayColumn(q[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'r'){for (uint8_t i = 0; i < 8; i++){displayColumn(r[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 's'){for (uint8_t i = 0; i < 8; i++){displayColumn(s[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 't'){for (uint8_t i = 0; i < 8; i++){displayColumn(t[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'u'){for (uint8_t i = 0; i < 8; i++){displayColumn(u[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'v'){for (uint8_t i = 0; i < 8; i++){displayColumn(v[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'w'){for (uint8_t i = 0; i < 8; i++){displayColumn(w[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'x'){for (uint8_t i = 0; i < 8; i++){displayColumn(x[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'y'){for (uint8_t i = 0; i < 8; i++){displayColumn(y[i]);delay(DELAY);}displayColumn(0);}
		if (*s == 'z'){for (uint8_t i = 0; i < 8; i++){displayColumn(z[i]);delay(DELAY);}displayColumn(0);}
		delay(DELAY);
	}
}

void loop(){
    byte str;
	while(Serial.available()){
		str = Serial.read();
		displayChar(&str);
	}
}

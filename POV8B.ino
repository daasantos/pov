#include <Adafruit_NeoPixel.h>

static const uint8_t pin = 8;     // Pin the strip is connected to
static const uint8_t nLED = 8;    // # Neopixels in the strip
static const uint8_t dTime = 8;   // Delay for each column in a image/letter

Adafruit_NeoPixel strip = Adafruit_NeoPixel(nLED, pin, NEO_GRB + NEO_KHZ800);

String inWord, stringColor;
uint32_t color = strip.Color(255, 0, 0);
bool stringComplete = false;
uint8_t a[nLED] = { 0x7C, 0x7E, 0x13, 0x13, 0x7E, 0x7C, 0x00, 0x00 };
uint8_t b[nLED] = { 0x41, 0x7F, 0x7F, 0x49, 0x49, 0x7F, 0x36, 0x00 };
uint8_t c[nLED] = { 0x1C, 0x3E, 0x63, 0x41, 0x41, 0x63, 0x22, 0x00 };
uint8_t d[nLED] = { 0x41, 0x7F, 0x7F, 0x41, 0x63, 0x3E, 0x1C, 0x00 };
uint8_t e[nLED] = { 0x41, 0x7F, 0x7F, 0x49, 0x5D, 0x41, 0x63, 0x00 };
uint8_t f[nLED] = { 0x41, 0x7F, 0x7F, 0x49, 0x1D, 0x01, 0x03, 0x00 };
uint8_t g[nLED] = { 0x1C, 0x3E, 0x63, 0x41, 0x51, 0x73, 0x72, 0x00 };
uint8_t h[nLED] = { 0x7F, 0x7F, 0x08, 0x08, 0x7F, 0x7F, 0x00, 0x00 };
uint8_t i[nLED] = { 0x00, 0x41, 0x7F, 0x7F, 0x41, 0x00, 0x00, 0x00 };
uint8_t j[nLED] = { 0x30, 0x70, 0x40, 0x41, 0x7F, 0x3F, 0x01, 0x00 };
uint8_t k[nLED] = { 0x41, 0x7F, 0x7F, 0x08, 0x1C, 0x77, 0x63, 0x00 };
uint8_t l[nLED] = { 0x41, 0x7F, 0x7F, 0x41, 0x40, 0x60, 0x70, 0x00 };
uint8_t m[nLED] = { 0x7F, 0x7F, 0x0E, 0x1C, 0x0E, 0x7F, 0x7F, 0x00 };
uint8_t n[nLED] = { 0x7F, 0x7F, 0x06, 0x0C, 0x18, 0x7F, 0x7F, 0x00 };
uint8_t o[nLED] = { 0x1C, 0x3E, 0x63, 0x41, 0x63, 0x3E, 0x1C, 0x00 };
uint8_t p[nLED] = { 0x41, 0x7F, 0x7F, 0x49, 0x09, 0x0F, 0x06, 0x00 };
uint8_t q[nLED] = { 0x1E, 0x3F, 0x21, 0x71, 0x7F, 0x5E, 0x00, 0x00 };
uint8_t r[nLED] = { 0x41, 0x7F, 0x7F, 0x09, 0x19, 0x7F, 0x66, 0x00 };
uint8_t s[nLED] = { 0x26, 0x6F, 0x4D, 0x59, 0x73, 0x32, 0x00, 0x00 };
uint8_t t[nLED] = { 0x03, 0x41, 0x7F, 0x7F, 0x41, 0x03, 0x00, 0x00 };
uint8_t u[nLED] = { 0x7F, 0x7F, 0x40, 0x40, 0x7F, 0x7F, 0x00, 0x00 };
uint8_t v[nLED] = { 0x1F, 0x3F, 0x60, 0x60, 0x3F, 0x1F, 0x00, 0x00 };
uint8_t w[nLED] = { 0x7F, 0x7F, 0x30, 0x18, 0x30, 0x7F, 0x7F, 0x00 };
uint8_t x[nLED] = { 0x43, 0x67, 0x3C, 0x18, 0x3C, 0x67, 0x43, 0x00 };
uint8_t y[nLED] = { 0x07, 0x4F, 0x78, 0x78, 0x4F, 0x07, 0x00, 0x00 };
uint8_t z[nLED] = { 0x47, 0x63, 0x71, 0x59, 0x4D, 0x67, 0x73, 0x00 };

void setup(){
	Serial.begin(9600);
	strip.begin();          	// Initialize the strip
	strip.setBrightness(4); // Dimmer lights for POV effect
	strip.show();           	// Push data to the strip, after each call to setPixelColor(), show() must be called
	inWord.reserve(64);
	stringColor.reserve(64);
}

void displayColumn(uint8_t col){
	for(uint8_t i = 0; i < nLED; i++){
		if ( (0x01 << i) & col ){ strip.setPixelColor(i, color); } // Bitwise to select which pixels to turn on/off
		else {strip.setPixelColor(i, 0);}
	}
	strip.show();
}

void displayChar(String str){
	for (uint8_t ct = 0; str.charAt(ct) != '.' ; ct++){
		if (str.charAt(ct) == 'a'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(a[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'b'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(b[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'c'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(c[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'd'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(d[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'e'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(e[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'f'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(f[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'g'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(g[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'h'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(h[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'i'){ for (uint8_t j = 0; j < nLED; j++){ displayColumn(i[j]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'j'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(j[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'k'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(k[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'l'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(l[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'm'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(m[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'n'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(n[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'o'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(o[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'p'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(p[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'q'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(q[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'r'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(r[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 's'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(s[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 't'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(t[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'u'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(u[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'v'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(v[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'w'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(w[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'x'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(x[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'y'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(y[i]); delay(dTime); } displayColumn(0); }
		else if (str.charAt(ct) == 'z'){ for (uint8_t i = 0; i < nLED; i++){ displayColumn(z[i]); delay(dTime); } displayColumn(0); }
		delay(dTime);
	}
}

void readData(){
  static bool readColor = false; // Needs to remember if ',' has been informed
  while(Serial.available()){
    char inChar = (char)Serial.read();
    if (inChar == '.') {
      inWord += inChar;
      stringComplete = true;
      readColor = false;
      Serial.println("inWord: " + inWord);
    }
    else if (inChar == ','){ readColor = true; stringColor = ""; }
  	else if (readColor){ stringColor += inChar;	Serial.println("stringColor: " + stringColor);
  	}
  	else { inWord += inChar; Serial.println("INWORD OK"); }
  }
  
  if (stringColor == "vermelho") color = strip.Color(255, 0, 0);
  else if (stringColor == "verde") color = strip.Color(0, 255, 0);
  else if (stringColor == "azul") color = strip.Color(0, 0, 255);
  else if (stringColor == "amarelo") color = strip.Color(255, 255, 0);
  else if (stringColor == "roxo") color = strip.Color(127, 0, 255);
  else if (stringColor == "laranja") color = strip.Color(255, 128, 0);
  else if (stringColor == "cinza") color = strip.Color(128, 128, 128);
}

void loop(){
  static String str;		   // Keeps last used string
  static bool started = false; // Remembers if a word has been informed since the program began
  readData();
  if (stringComplete){
    Serial.println("STRING COMPLETE");
    str = inWord;
    inWord = "";
    started = true;
    stringComplete = false;
  }
  if (started) displayChar(str);
}

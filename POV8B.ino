#include <Adafruit_NeoPixel.h>

const uint8_t pin = 8;     // Pin the strip is connected to
const uint8_t nLED = 8;    // # Neopixels in the strip
const uint8_t dTime = 8;   // Delay for each column in a image/letter
const uint8_t nextLine = 9;
const uint8_t nextSlide = 7;
const uint8_t laserSwitch = 6;
const uint8_t laserPin = 5;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(nLED, pin, NEO_GRB + NEO_KHZ800);

String inWord;
uint32_t color = strip.Color(255, 0, 0); // Default color
uint8_t pid, lineMax;
const uint8_t a[nLED] = { 0xfc,0xfe,0x13,0x13,0x13,0x13,0xfe,0xfc };
const uint8_t b[nLED] = { 0x41,0x7f,0x7f,0x49,0x49,0x49,0x7f,0x36 };
const uint8_t c[nLED] = { 0x3c,0x7e,0xc3,0x81,0x81,0x81,0xc3,0x42 };
const uint8_t d[nLED] = { 0xff,0xff,0x81,0x81,0xc3,0x7e,0x3c,0x00 };
const uint8_t e[nLED] = { 0xff,0xff,0x89,0x89,0x89,0x89,0x81,0x00 };
const uint8_t f[nLED] = { 0xff,0xff,0x09,0x09,0x09,0x09,0x01,0x00 };
const uint8_t g[nLED] = { 0x7e,0xff,0xc3,0x81,0x81,0xa1,0xf3,0xf2 };
const uint8_t h[nLED] = { 0xff,0xff,0x10,0x10,0x10,0x10,0xff,0xff };
const uint8_t i[nLED] = { 0x00,0x81,0x81,0xff,0xff,0x81,0x81,0x00 };
const uint8_t j[nLED] = { 0x60,0xe0,0x80,0x81,0x81,0xff,0x7f,0x01 };
const uint8_t k[nLED] = { 0xff,0xff,0x18,0x3c,0xe7,0xc3,0x00,0x00 };
const uint8_t l[nLED] = { 0xff,0xff,0x80,0x80,0x80,0x80,0xc0,0xe0 };
const uint8_t m[nLED] = { 0xff,0xff,0x0e,0x1c,0x1c,0x0e,0xff,0xff };
const uint8_t n[nLED] = { 0xff,0xff,0x06,0x0c,0x18,0x30,0xff,0xff };
const uint8_t o[nLED] = { 0x3c,0x7e,0xc3,0x81,0x81,0xc3,0x7e,0x3c };
const uint8_t p[nLED] = { 0xff,0xff,0x09,0x09,0x09,0x0f,0x06,0x00 };
const uint8_t q[nLED] = { 0x3e,0x7f,0x41,0x41,0xff,0xbe,0x80,0x00 };
const uint8_t r[nLED] = { 0xff,0xff,0x09,0x09,0x19,0xff,0xe6,0x00 };
const uint8_t s[nLED] = { 0x46,0xcf,0x8f,0x99,0x91,0xf1,0xf3,0x62 };
const uint8_t t[nLED] = { 0x03,0x01,0x01,0xff,0xff,0x01,0x01,0x03 };
const uint8_t u[nLED] = { 0xff,0xff,0xc0,0xc0,0xc0,0xc0,0xff,0xff };
const uint8_t v[nLED] = { 0x3f,0x7f,0xc0,0xc0,0xc0,0xc0,0x7f,0x3f };
const uint8_t w[nLED] = { 0xff,0xff,0x60,0x30,0x30,0x60,0xff,0xff };
const uint8_t x[nLED] = { 0xc3,0x66,0x3c,0x18,0x18,0x3c,0x66,0xc3 };
const uint8_t y[nLED] = { 0x0f,0x0f,0x08,0xf8,0xf8,0x08,0x0f,0x0f };
const uint8_t z[nLED] = { 0x07,0xc3,0xe1,0xb1,0x99,0x8d,0xc7,0xe3 };

void setup(){
  pinMode(nextLine, INPUT_PULLUP);
  pinMode(nextSlide, INPUT_PULLUP);
  pinMode(laserSwitch, INPUT_PULLUP);
  pinMode(laserPin, OUTPUT);
  Serial.begin(9600);
  strip.begin();          	    // Initialize the strip
  strip.setBrightness(4);		    // Dimmer lights for POV effect
  strip.show();           	    // Push data to the strip, after each call to setPixelColor(), show() must be called

  delay(15000);
  Serial.println("#S|RNTPD|[1]#"); // Read line number from Notepad
  while(!Serial.available());
  lineMax = Serial.parseInt() + 1;
  Serial.println("#S|CHIMG|[]#"); // Start slideshow
  while(!Serial.available());
  pid = Serial.parseInt();
    
}

void displayColumn(uint8_t col){
	for(uint8_t i = 0; i < nLED; i++){
		if ( (0x01 << i) & col ){ strip.setPixelColor(i, color); } // Bitwise to select which pixels to turn on/off
		else {strip.setPixelColor(i, 0);}
	}
	strip.show();
}

void displayChar(String str){
	const uint8_t ct = 0;
    
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

bool readData(){
  bool readColor = false;
  String stringColor;
  static uint8_t line = 2;
  static bool laserStatus = false;
  
  if(digitalRead(nextLine) == LOW) { 
    line++; 
    delay(500); 
  }
  if(digitalRead(laserSwitch) == LOW) {
    if(!laserStatus) (digitalWrite(laserPin, HIGH);
    else digitalWrite laserPin, LOW);
    laserStatus = !laserStatus;
    delay(500);
  }
  if(digitalRead(nextSlide) == LOW) {
    Serial.print("#S|SENDK|[");
    Serial.print(pid);
    Serial.println("& {RIGHT} ]#");
    delay(500);
  }
  if(line >= lineMax) line = 2;
    
  Serial.print("#S|RNTPD|["); // Read line from Notepad
  Serial.print(line);
  Serial.println("]#");
    
  while(Serial.available()){
    
    char inChar = (char)Serial.read();
  
    if (inChar == '.') {
      if (readColor){
          if (stringColor == "vermelho") color = strip.Color(255, 0, 0); // red
          else if (stringColor == "verde") color = strip.Color(0, 255, 0); // green
          else if (stringColor == "azul") color = strip.Color(0, 0, 255); // blue
          else if (stringColor == "roxo") color = strip.Color(128, 0, 255); // purple
          else if (stringColor == "rosa") color = strip.Color(255, 0, 255); // pink
          else if (stringColor == "turquesa") color = strip.Color(0, 255, 255); // teal
          else if (stringColor == "branco") color = strip.Color(255, 255, 255); // white
      }
    Serial.println("stringColor: " + stringColor);
    readColor = false;
	  return true;
    }
    else if (readColor) stringColor += inChar;
    else if (inChar == ','){
      readColor = true;
      stringColor = "";
      inWord += '.';
  }
    else inWord += inChar;
	
  }
  return false;
}

void loop(){
  static String str = "a"; // Default
  
  if (readData()){
    Serial.println("inWord: " + inWord);
    str = inWord;
    inWord = "";
  }
  displayChar(str);
}

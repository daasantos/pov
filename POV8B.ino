#include <Adafruit_NeoPixel.h>

#define PIN 8    // Pino ao qual a barra esta conectada
#define QTLD 8   // Quantidade de LEDs na barra
#define DELAY 6  // Delay para exibicao de cada coluna da imagem
#define BREAK 6  // Delay para exibicao de cada caracter/imagem em uma sequencia

Adafruit_NeoPixel strip = Adafruit_NeoPixel(QTLD, PIN, NEO_GRB + NEO_KHZ800);
void setup(){
	strip.begin();          // Inicializa a barra
	strip.setBrightness(1); // Luzes mais claras interferem com o efeito POV. Use o brilho minimo
	strip.show();           // Push dados para a barra mas como nao foi enviado nada para ela, todos os LEDs serao desligados
							            // Apos modificar os LEDs, show() deve ser chamado para enviar a mudanca a barra
}

uint8_t a[] = {0x7F,0xFF,0xC4,0xC4,0xC4,0xC4,0xFF,0x7F};
uint8_t e[] = {0xFF,0xFF,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB};
uint8_t i[] = {0x00,0x00,0x81,0xFF,0xFF,0x81,0x00,0x00};
uint8_t o[] = {0x7E,0xFF,0xC3,0xC3,0xC3,0xC3,0xFF,0x7E};
uint8_t u[] = {0xFF,0xFF,0x03,0x03,0x03,0x03,0xFF,0xFF};

void displayLine(uint8_t line){
	uint32_t color = strip.Color( 255, 0, 0 ); // R, G, B
	
	for(uint8_t i = 0; i < QTLD; i++){
		if((0x01 << i) & line){strip.setPixelColor(i, color);}
		else{strip.setPixelColor(i, 0);}
	}
  strip.show();
}


void displayChar(char ch){
  
  if (ch == 'a'){for (uint8_t i = 0; i < 8; i++){displayLine(a[i]);delay(DELAY);}displayLine(0);}
  if (ch == 'e'){for (uint8_t i = 0; i < 8; i++){displayLine(e[i]);delay(DELAY);}displayLine(0);}
  if (ch == 'i'){for (uint8_t j = 0; j < 8; j++){displayLine(i[j]);delay(DELAY);}displayLine(0);}
  if (ch == 'o'){for (uint8_t i = 0; i < 8; i++){displayLine(o[i]);delay(DELAY);}displayLine(0);}
  if (ch == 'u'){for (uint8_t i = 0; i < 8; i++){displayLine(u[i]);delay(DELAY);}displayLine(0);}
  delay(BREAK);
  
}

void displayString(char* s){
  
  for (uint8_t i = 0; i <= strlen(s); i++){
    displayChar(s[i]);
  }
  
}

void loop(){
  displayString("a");
}

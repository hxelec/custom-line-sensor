/*
Hardware:
ESP32-C3 Super Mini
0.96" OLED (I2C)
The line sensor shown in this repository

Connections:
SCL of OLED goes to GPIO4 of ESP32-C3 Super Mini
SDA of OLED goes to GPIO1 of ESP32-C3 Super Mini
GPIO0, 5, 7, 10, 21 goes to Output 1 - 5 of Line Sensor

Functionality:
When one of the outputs of the line sensor is low, a circle will show up in the corresponding position. You can see this in action in my YouTube video linked in README
*/

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 4, /* data=*/ 1, /* reset=*/ U8X8_PIN_NONE);

void setup(void) {
  pinMode(0, INPUT);
  pinMode(5, INPUT);
  pinMode(7, INPUT);
  pinMode(10, INPUT);
  pinMode(21, INPUT);
  u8g2.begin();
}

void loop(void) {
  u8g2.clearBuffer();					// clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
  if (digitalRead(0) == 0) {
    u8g2.drawFilledEllipse(21, 32, 5, 5, U8G2_DRAW_ALL);
  }
  if (digitalRead(5) == 0) {
    u8g2.drawFilledEllipse(42, 32, 5, 5, U8G2_DRAW_ALL);
  }
  if (digitalRead(7) == 0) {
    u8g2.drawFilledEllipse(63, 32, 5, 5, U8G2_DRAW_ALL);
  }
  if (digitalRead(10) == 0) {
    u8g2.drawFilledEllipse(84, 32, 5, 5, U8G2_DRAW_ALL);
  }
  if (digitalRead(21) == 0) {
    u8g2.drawFilledEllipse(105, 32, 5, 5, U8G2_DRAW_ALL);
  }
  if (digitalRead(0) == 1 && digitalRead(5) == 1 && digitalRead(7) == 1 && digitalRead(10) == 1 && digitalRead(21) == 1) {
    u8g2.clearDisplay();
  }
  u8g2.sendBuffer();					// transfer internal memory to the display
  delay(100);  
}

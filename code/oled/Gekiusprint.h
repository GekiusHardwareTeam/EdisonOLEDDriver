/*
 * Gekiusprint.h
 *
 *  Created on: 2015��3��6��
 *      Author: Jhon_Qiki
 */

#ifndef GEKIUSPRINT_H_
#define GEKIUSPRINT_H_

#include "Arduino.h"
#include "Print.h"

#define swap(a, b) { int16_t t = a; a = b; b = t; }

class GekiusPrint:public Print
{
public:
	GekiusPrint(int16_t w, int16_t h);
	virtual ~GekiusPrint();

	//	should be implemented in concrete hardware
	virtual void drawPixel(int16_t x, int16_t y, uint16_t color) = 0;

	  // These MAY be overridden by the subclass to provide device-specific
	  // optimized code.  Otherwise 'generic' versions are used.
	  virtual void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
	  virtual void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
	  virtual void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
	  virtual void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
	  virtual void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
	  virtual void fillScreen(uint16_t color);
	  virtual void invertDisplay(bool i);

	  // These exist only with Adafruit_GFX (no subclass overrides). we implement it for edison
	  void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
	  void drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color);
	  void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
	  void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color);
	  void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
	  void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
	  void drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
	  void fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
	  void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color);
	  void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color, uint16_t bg);
	  void drawXBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color);
	  void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size);
	  void setCursor(int16_t x, int16_t y);
	  void setTextColor(uint16_t c);
	  void setTextColor(uint16_t c, uint16_t bg);
	  void setTextSize(uint8_t s);
	  void setTextWrap(bool w);
	  void setRotation(uint8_t r);

	  virtual size_t write(uint8_t);

	  int16_t height(void) const;
	  int16_t width(void) const;

	  uint8_t getRotation(void) const;

	 protected:
	  const int16_t WIDTH, HEIGHT;   // This is the 'raw' display w/h - never changes
	  int16_t _width, _height; // Display w/h as modified by current rotation
	  int16_t cursor_x, cursor_y;
	  uint16_t textcolor, textbgcolor;
	  uint8_t  textsize, rotation;
	  bool wrap; // If set, 'wrap' text at right edge of display
};

#endif /* GEKIUSPRINT_H_ */

/*
 * SSD1306.h
 *
 *  Created on: Oct 19, 2014
 *      Author: jason
 */

#include <stdint.h>

#ifndef SSD1306_H_
#define SSD1306_H_

#define OLED_DC					12
#define OLED_CS					6
#define OLED_RESET      11

#define OLED_CMD_COLADDR			0x21
#define OLED_CMD_PAGEADDR			0x22
#define OLED_CMD_DISP_OFF			0xAE
#define OLED_CMD_CP_OFF			0x8D

#define OLED_COLS					128
#define OLED_PAGES					8
#define OLED_ROWS					64

enum PIXEL_COLOR {PIXEL_BLACK, PIXEL_WHITE};
enum TEXT_FONT {TEXT_FONT_5X8, TEXT_FONT_11X21};

class SSD1306
{
public:
	SSD1306(void);
	void init(void);
	void send_command(uint8_t);
	void send_data(uint8_t);
	void buffer_clear(void);
	void buffer_write(void);
	void pixel(uint8_t, uint8_t, enum PIXEL_COLOR);
	void text(uint8_t, uint8_t, enum TEXT_FONT, bool, char *);
	void hline(uint8_t, uint8_t, uint8_t, enum PIXEL_COLOR);
	void vline(uint8_t, uint8_t, uint8_t, enum PIXEL_COLOR);
	void power_off(void);
	void set_page_address(uint8_t);
	void set_col_address(uint8_t);
	void set_contrast(uint8_t);
};

#endif /* SSD1306_H_ */

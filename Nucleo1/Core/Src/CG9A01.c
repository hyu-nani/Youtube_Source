
#include "../Inc/main.h"
#include "../Inc/CG9A01.h"

extern SPI_HandleTypeDef hspi2;

void LCD_WR_REG(uint8_t dat)
{
    LCD_DC_Clr();
	HAL_SPI_Transmit(SPI_HANDLE, &dat, 1, 100) ;
    LCD_DC_Set();
}

void LCD_WR_DATA(uint16_t dat)
{
    uint8_t c[2]; 
    c[1] = dat>>8;
    c[0] = dat;
    HAL_SPI_Transmit(SPI_HANDLE, &c[1], 1, 100) ;
    HAL_SPI_Transmit(SPI_HANDLE, &c[0], 1, 100) ;
}

void LCD_WR_DATA8(uint8_t dat)
{
	HAL_SPI_Transmit(SPI_HANDLE, &dat, 1, 100) ;
}


void LCD_Address_Set(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	LCD_WR_REG(0x2A);	
	LCD_WR_DATA(x1);	
	LCD_WR_DATA(x2);	
	LCD_WR_REG(0x2b);	
	LCD_WR_DATA(y1);
	LCD_WR_DATA(y2);
}

void LCD_enter_sleep_mode(void)
{
    LCD_CS_Clr();
	LCD_WR_REG(0x10);
	LCD_CS_Set();
}
void LCD_sleep_out(void)
{
    LCD_CS_Clr();
	LCD_WR_REG(0x11);
	LCD_CS_Set();
}
void LCD_partial_mode_ON(void)
{
    LCD_CS_Clr();
	LCD_WR_REG(0x12);
	LCD_CS_Set();
}
void LCD_normal_display_mode_ON(void)
{
    LCD_CS_Clr();
	LCD_WR_REG(0x13);
	LCD_CS_Set();
}
void LCD_display_inversion_ON(void)
{
    LCD_CS_Clr();
	LCD_WR_REG(0x21);
	LCD_CS_Set();
}
void LCD_display_inversion_OFF(void)
{
    LCD_CS_Clr();
	LCD_WR_REG(0x20);
	LCD_CS_Set();
}
void LCD_display_ON(void)
{
    LCD_CS_Clr();
	LCD_WR_REG(0x29);
	LCD_CS_Set();
}
void LCD_display_OFF(void)
{
    LCD_CS_Clr();
	LCD_WR_REG(0x28);
	LCD_CS_Set();
}
void LCD_memory_write(uint16_t data)
{
    LCD_CS_Clr();
	LCD_WR_REG(0x2c);
	LCD_WR_DATA(data);
	LCD_CS_Set();
}
void LCD_tearing_effect_line_off(void)
{
    LCD_CS_Clr();
	LCD_WR_REG(0x34);
	LCD_CS_Set();
}
void LCD_tearing_effect_line_on(void)
{
    LCD_CS_Clr();
	LCD_WR_REG(0x35);
	LCD_CS_Set();
}

void LCD_Init(void)
{
    LCD_CS_Clr();
	LCD_RES_Clr();
	HAL_Delay(100);
	LCD_RES_Set();
	HAL_Delay(100);
	
	LCD_WR_REG(0xEF);
	LCD_WR_REG(0xEB);
	LCD_WR_DATA8(0x14);
	
	LCD_WR_REG(0xFE);
	LCD_WR_REG(0xEF);
	
	LCD_WR_REG(0xEB);
	LCD_WR_DATA8(0x14);
	
	LCD_WR_REG(0x84);
	LCD_WR_DATA8(0x40);
	
	LCD_WR_REG(0x85);
	LCD_WR_DATA8(0xFF);
	
	LCD_WR_REG(0x86);
	LCD_WR_DATA8(0xFF);
	
	LCD_WR_REG(0x87);
	LCD_WR_DATA8(0xFF);
	
	LCD_WR_REG(0x88);
	LCD_WR_DATA8(0x0A);
	
	LCD_WR_REG(0x89);
	LCD_WR_DATA8(0x21);
	
	LCD_WR_REG(0x8A);
	LCD_WR_DATA8(0x00);
	
	LCD_WR_REG(0x8B);
	LCD_WR_DATA8(0x80);
	
	LCD_WR_REG(0x8C);
	LCD_WR_DATA8(0x01);
	
	LCD_WR_REG(0x8D);
	LCD_WR_DATA8(0x01);
	
	LCD_WR_REG(0x8E);
	LCD_WR_DATA8(0xFF);
	
	LCD_WR_REG(0x8F);
	LCD_WR_DATA8(0xFF);
	
	
	LCD_WR_REG(0xB6);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x20);
	
	LCD_WR_REG(0x36);
	LCD_WR_DATA8(0x08);
	
	
	LCD_WR_REG(0x3A);
	LCD_WR_DATA8(0x05);
	
	
	LCD_WR_REG(0x90);
	LCD_WR_DATA8(0x08);
	LCD_WR_DATA8(0x08);
	LCD_WR_DATA8(0x08);
	LCD_WR_DATA8(0x08);
	
	LCD_WR_REG(0xBD);
	LCD_WR_DATA8(0x06);
	
	LCD_WR_REG(0xBC);
	LCD_WR_DATA8(0x00);
	
	LCD_WR_REG(0xFF);
	LCD_WR_DATA8(0x60);
	LCD_WR_DATA8(0x01);
	LCD_WR_DATA8(0x04);
	
	LCD_WR_REG(0xC3);
	LCD_WR_DATA8(0x13);
	LCD_WR_REG(0xC4);
	LCD_WR_DATA8(0x13);
	
	LCD_WR_REG(0xC9);
	LCD_WR_DATA8(0x22);
	
	LCD_WR_REG(0xBE);
	LCD_WR_DATA8(0x11);
	
	LCD_WR_REG(0xE1);
	LCD_WR_DATA8(0x10);
	LCD_WR_DATA8(0x0E);
	
	LCD_WR_REG(0xDF);
	LCD_WR_DATA8(0x21);
	LCD_WR_DATA8(0x0c);
	LCD_WR_DATA8(0x02);
	
	LCD_WR_REG(0xF0);
	LCD_WR_DATA8(0x45);
	LCD_WR_DATA8(0x09);
	LCD_WR_DATA8(0x26);
	LCD_WR_DATA8(0x2A);
	
	LCD_WR_DATA8(0x08);
	LCD_WR_DATA8(0x08);
	LCD_WR_REG(0xF1);
	LCD_WR_DATA8(0x43);
	LCD_WR_DATA8(0x70);
	LCD_WR_DATA8(0x72);
	LCD_WR_DATA8(0x36);
	LCD_WR_DATA8(0x37);
	LCD_WR_DATA8(0x6F);
	
	
	LCD_WR_REG(0xF2);
	LCD_WR_DATA8(0x45);
	LCD_WR_DATA8(0x09);
	LCD_WR_DATA8(0x08);
	LCD_WR_DATA8(0x08);
	LCD_WR_DATA8(0x26);
	LCD_WR_DATA8(0x2A);
	
	LCD_WR_REG(0xF3);
	LCD_WR_DATA8(0x43);
	LCD_WR_DATA8(0x70);
	LCD_WR_DATA8(0x72);
	LCD_WR_DATA8(0x36);
	LCD_WR_DATA8(0x37);
	LCD_WR_DATA8(0x6F);
	
	LCD_WR_REG(0xED);
	LCD_WR_DATA8(0x1B);
	LCD_WR_DATA8(0x0B);
	
	LCD_WR_REG(0xAE);
	LCD_WR_DATA8(0x77);
	
	LCD_WR_REG(0xCD);
	LCD_WR_DATA8(0x63);
	
	
	LCD_WR_REG(0x70);
	LCD_WR_DATA8(0x07);
	LCD_WR_DATA8(0x07);
	LCD_WR_DATA8(0x04);
	LCD_WR_DATA8(0x0E);
	LCD_WR_DATA8(0x0F);
	LCD_WR_DATA8(0x09);
	LCD_WR_DATA8(0x07);
	LCD_WR_DATA8(0x08);
	LCD_WR_DATA8(0x03);
	
	LCD_WR_REG(0xE8);
	LCD_WR_DATA8(0x34);
	
	LCD_WR_REG(0x62);
	LCD_WR_DATA8(0x18);
	LCD_WR_DATA8(0x0D);
	LCD_WR_DATA8(0x71);
	LCD_WR_DATA8(0xED);
	LCD_WR_DATA8(0x70);
	LCD_WR_DATA8(0x70);
	LCD_WR_DATA8(0x18);
	LCD_WR_DATA8(0x0F);
	LCD_WR_DATA8(0x71);
	LCD_WR_DATA8(0xEF);
	LCD_WR_DATA8(0x70);
	LCD_WR_DATA8(0x70);
	
	LCD_WR_REG(0x63);
	LCD_WR_DATA8(0x18);
	LCD_WR_DATA8(0x11);
	LCD_WR_DATA8(0x71);
	LCD_WR_DATA8(0xF1);
	LCD_WR_DATA8(0x70);
	LCD_WR_DATA8(0x70);
	LCD_WR_DATA8(0x18);
	LCD_WR_DATA8(0x13);
	LCD_WR_DATA8(0x71);
	LCD_WR_DATA8(0xF3);
	LCD_WR_DATA8(0x70);
	LCD_WR_DATA8(0x70);
	
	LCD_WR_REG(0x64);
	LCD_WR_DATA8(0x28);
	LCD_WR_DATA8(0x29);
	LCD_WR_DATA8(0xF1);
	LCD_WR_DATA8(0x01);
	LCD_WR_DATA8(0xF1);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x07);
	
	LCD_WR_REG(0x66);
	LCD_WR_DATA8(0x3C);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0xCD);
	LCD_WR_DATA8(0x67);
	LCD_WR_DATA8(0x45);
	LCD_WR_DATA8(0x45);
	LCD_WR_DATA8(0x10);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x00);
	
	LCD_WR_REG(0x67);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x3C);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x01);
	LCD_WR_DATA8(0x54);
	LCD_WR_DATA8(0x10);
	LCD_WR_DATA8(0x32);
	LCD_WR_DATA8(0x98);
	
	LCD_WR_REG(0x74);
	LCD_WR_DATA8(0x10);
	LCD_WR_DATA8(0x85);
	LCD_WR_DATA8(0x80);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x4E);
	LCD_WR_DATA8(0x00);
	
	LCD_WR_REG(0x98);
	LCD_WR_DATA8(0x3e);
	LCD_WR_DATA8(0x07);
	
	LCD_WR_REG(0x35);
	LCD_WR_REG(0x21);
	
	LCD_WR_REG(0x11);
	HAL_Delay(120);
	LCD_WR_REG(0x29);
	HAL_Delay(20);
	LCD_CS_Set();
}

#include "font.h"

#define LCD_swap(a, b) { int16_t t = a; a = b; b = t; }
int lcd_light=0;

void LCD_Fill(uint16_t color)
{
	uint16_t i,j;
    LCD_CS_Clr();
	LCD_Address_Set(0,0,LCD_W-1,LCD_H-1);
	LCD_WR_REG(0x2c);
	for(i=0;i<LCD_H;i++)
	{
		for(j=0;j<LCD_W;j++)
		{
			LCD_WR_DATA(color);
		}
	}
    LCD_CS_Set();
}
void LCD_image(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1 ,const short unsigned A[])
{
	uint16_t i,j;
	int k=0;
    LCD_CS_Clr();
	LCD_Address_Set(x0,y0,x1-1,y1-1);
	LCD_WR_REG(0x2c);
	for(i=x0;i<x1;i++)
	{
		for(j=y0;j<y1;j++)
		{
			//LCD_WR_DATA((word)pgm_read_word(A+k));
			k++;
		}
	}
    LCD_CS_Set();
}

void LCD_fill_Rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h,uint16_t color) 
{
    
	if((x >= LCD_W) || (y >= LCD_H)) return;
	if((x + w - 1) >= LCD_W)  w = LCD_W  - x;
	if((y + h - 1) >= LCD_H) h = LCD_H - y;
	LCD_CS_Clr();
	LCD_Address_Set(x, y, x+w-1, y+h-1);
	
	LCD_WR_REG(0x2C);
	for(y=h; y>0; y--) {
		for(x=w; x>0; x--) {
			LCD_WR_DATA(color);
		}
	}
    LCD_CS_Set();
}

void LCD_HLine(uint16_t x, uint16_t y, uint16_t w, uint16_t color) 
{
	if((x >= LCD_W) || (y >= LCD_H)) return;
	if((x+w-1) >= LCD_W)  w = LCD_W-x;
    LCD_CS_Clr();
	LCD_Address_Set(x, y, x+w-1, y);
	LCD_WR_REG(0x2C);
	while (w--) {
		LCD_WR_DATA(color);	
	}
    LCD_CS_Set();
}
void LCD_VLine(uint16_t x, uint16_t y, uint16_t h,uint16_t color) 
{
	// Rudimentary clipping
	if((x >= LCD_W) || (y >= LCD_H)) return;
	if((y+h-1) >= LCD_H)
	h = LCD_H-y;
    LCD_CS_Clr();
	LCD_Address_Set(x, y, x, y+h-1);
	LCD_WR_REG(0x2c);
	while (h--) {
		LCD_WR_DATA(color);
	}
    LCD_CS_Set();
}
void LCD_Pixel(uint16_t x, uint16_t y,uint16_t thin ,uint16_t color) 
{
	if((x < 0) ||(x >= LCD_W) || (y < 0) || (y >= LCD_H)) return;
    LCD_CS_Clr();
	LCD_Address_Set(x,y,x+thin-1,y+thin-1);
	LCD_WR_REG(0x2C);
	for(int a=0;a<(thin*thin);a++){
		LCD_WR_DATA(color);
	}
    LCD_CS_Set();
}


void drawCircleHelper( uint16_t x0, uint16_t y0,uint16_t r, uint8_t cornername,uint16_t thin, uint16_t color) {
	int16_t f     = 1 - r;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * r;
	int16_t x     = 0;
	int16_t y     = r;
	while (x<y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f     += ddF_y;
		}
		x++;
		ddF_x += 2;
		f     += ddF_x;
		if (cornername & 0x4) {
			LCD_Pixel(x0 + x, y0 + y,thin, color);
			LCD_Pixel(x0 + y, y0 + x,thin, color);
		}
		if (cornername & 0x2) {
			LCD_Pixel(x0 + x, y0 - y,thin, color);
			LCD_Pixel(x0 + y, y0 - x,thin, color);
		}
		if (cornername & 0x8) {
			LCD_Pixel(x0 - y, y0 + x,thin, color);
			LCD_Pixel(x0 - x, y0 + y,thin, color);
		}
		if (cornername & 0x1) {
			LCD_Pixel(x0 - y, y0 - x,thin, color);
			LCD_Pixel(x0 - x, y0 - y,thin, color);
		}
	}
}

void fillCircleHelper(uint16_t x0, uint16_t y0, uint16_t r,uint8_t cornername, uint16_t delta, uint16_t color)
{

	int16_t f     = 1 - r;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * r;
	int16_t x     = 0;
	int16_t y     = r;

	while (x<y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f     += ddF_y;
		}
		x++;
		ddF_x += 2;
		f     += ddF_x;

		if (cornername & 0x1) {
			LCD_VLine(x0+x, y0-y, 2*y+1+delta, color);
			LCD_VLine(x0+y, y0-x, 2*x+1+delta, color);
		}
		if (cornername & 0x2) {
			LCD_VLine(x0-x, y0-y, 2*y+1+delta, color);
			LCD_VLine(x0-y, y0-x, 2*x+1+delta, color);
		}
	}
    LCD_CS_Set();
}
void LCD_fill_Circle(int16_t x0, int16_t y0, int16_t r,int16_t color) 
{
	LCD_VLine(x0, y0-r, 2*r+1, color);
	fillCircleHelper(x0, y0, r, 3, 0, color);
}
void LCD_Circle(int16_t x0, int16_t y0, int16_t r,int16_t thin,int16_t color) 
{
	LCD_Pixel(x0,y0-r,thin,color);
	LCD_Pixel(x0,y0+r,thin,color);
	LCD_Pixel(x0-r,y0,thin,color);
	LCD_Pixel(x0+r,y0,thin,color);
	drawCircleHelper(x0,y0,r,15,thin,color);
}
void LCD_Rect(int16_t x, int16_t y,int16_t w, int16_t h,int16_t color) 
{
	LCD_HLine(x, y, w, color);
	LCD_HLine(x, y+h-1, w, color);
	LCD_VLine(x, y, h, color);
	LCD_VLine(x+w-1, y, h, color);
}
void LCD_Round_Rec(int16_t x, int16_t y, int16_t w,int16_t h, int16_t r, int16_t color) 
{
	// smarter version
	LCD_HLine(x+r  , y    , w-2*r, color); // Top
	LCD_HLine(x+r  , y+h-1, w-2*r, color); // Bottom
	LCD_VLine(x    , y+r  , h-2*r, color); // Left
	LCD_VLine(x+w-1, y+r  , h-2*r, color); // Right
	// draw four corners
	drawCircleHelper(x+r    , y+r    , r, 1,1, color);
	drawCircleHelper(x+w-r-1, y+r    , r, 2,1, color);
	drawCircleHelper(x+w-r-1, y+h-r-1, r, 4,1, color);
	drawCircleHelper(x+r    , y+h-r-1, r, 8,1, color);
}
void LCD_Line(int16_t x0, int16_t y0,int16_t x1, int16_t y1, int16_t thin, int16_t color) 
{
	uint16_t steep = abs(y1 - y0) > abs(x1 - x0);
	if (steep) {
		LCD_swap(x0, y0);
		LCD_swap(x1, y1);
	}

	if (x0 > x1) {
		LCD_swap(x0, x1);
		LCD_swap(y0, y1);
	}

	int16_t dx, dy;
	dx = x1 - x0;
	dy = abs(y1 - y0);

	int16_t err = dx / 2;
	int16_t ystep;

	if (y0 < y1) {
		ystep = 1;
		} else {
		ystep = -1;
	}

	for (; x0<=x1; x0++) {
		if (steep) {
			LCD_Pixel(y0, x0, thin, color);
			} else {
			LCD_Pixel(x0, y0, thin, color);
		}
		err -= dy;
		if (err < 0) {
			y0 += ystep;
			err += dx;
		}
	}
}
void LCD_Char_bg(int16_t x, int16_t y, unsigned c,int16_t color, int16_t bg, uint8_t size)
{

	if((x >= LCD_W)            || // Clip right
	(y >= LCD_H)           || // Clip bottom
	((x + 6 * size - 1) < 0) || // Clip left
	((y + 8 * size - 1) < 0))   // Clip top
	return;

	for (int8_t i=0; i<6; i++ ) {
		uint8_t line;
		if (i == 5)
		line = 0x0;
		//else
		//line = pgm_read_byte(font+(c*5)+i);
		for (int8_t j = 0; j<8; j++) {
			if (line & 0x1) {
				LCD_Pixel(x+i*size, y+j*size,size,color);
			} 
			else if (bg != color) {
				LCD_Pixel(x+i*size, y+j*size,size,bg);
			}
			line >>= 1;
		}
	}
}

void LCD_Char(int16_t x, int16_t y, unsigned c,int16_t color, uint8_t size) {

	if((x >= LCD_W)            || // Clip right
	(y >= LCD_H)           || // Clip bottom
	((x + 6 * size - 1) < 0) || // Clip left
	((y + 8 * size - 1) < 0))   // Clip top
	return;

	for (int8_t i=0; i<6; i++ ) {
		uint8_t line;
		if (i == 5)
		line = 0x0;
		//else
		//line = pgm_read_byte(font+(c*5)+i);
		for (int8_t j = 0; j<8; j++) {
			if (line & 0x1) {
				LCD_Pixel(x+i*size, y+j*size,size,color);
			}
			line >>= 1;
		}
	}
}

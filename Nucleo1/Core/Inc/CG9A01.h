#ifndef __CG9A01_H
#define __CG9A01_H
#ifdef __cplusplus
 extern "C" {
#endif

#define SPI_HANDLE      &hspi2

#define LCD_W   240
#define LCD_H   240

#define LCD_RES_Clr()   HAL_GPIO_WritePin(TFT_RST_GPIO_Port, TFT_RST_Pin, GPIO_PIN_RESET)
#define LCD_RES_Set()   HAL_GPIO_WritePin(TFT_RST_GPIO_Port, TFT_RST_Pin, GPIO_PIN_SET)

#define LCD_DC_Clr()    HAL_GPIO_WritePin(TFT_DC_GPIO_Port, TFT_DC_Pin, GPIO_PIN_RESET)
#define LCD_DC_Set()    HAL_GPIO_WritePin(TFT_DC_GPIO_Port, TFT_DC_Pin, GPIO_PIN_SET)

#define LCD_CS_Clr()    HAL_GPIO_WritePin(TFT_CS_GPIO_Port, TFT_CS_Pin, GPIO_PIN_RESET)
#define LCD_CS_Set()    HAL_GPIO_WritePin(TFT_CS_GPIO_Port, TFT_CS_Pin, GPIO_PIN_SET)

#define WHITE            0xFFFF
#define BLACK            0x0000
#define BLUE             0x001F
#define BRED             0XF81F
#define GRED             0XFFE0
#define GBLUE            0X07FF
#define RED              0xF800
#define MAGENTA          0xF81F
#define GREEN            0x07E0
#define CYAN             0x7FFF
#define YELLOW           0xFFE0
#define BROWN            0XBC40
#define BRRED            0XFC07
#define GRAY             0X8430
#define DARKBLUE         0X01CF
#define LIGHTBLUE        0X7D7C
#define GRAYBLUE         0X5458
#define LIGHTGREEN       0X841F
#define LGRAY            0XC618
#define LGRAYBLUE        0XA651
#define LBBLUE           0X2B12

#define LCD_swap(a, b) { uint16_t t = a; a = b; b = t; }

void LCD_WR_REG(uint8_t dat);
void LCD_WR_DATA(uint16_t dat);
void LCD_WR_DATA8(uint8_t dat);
void LCD_Address_Set(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void LCD_enter_sleep_mode(void);
void LCD_sleep_out(void);
void LCD_partial_mode_ON(void);
void LCD_display_inversion_ON(void);
void LCD_display_inversion_OFF(void);
void LCD_display_ON(void);
void LCD_display_OFF(void);
void LCD_memory_write(uint16_t data);
void LCD_tearing_effect_line_off(void);
void LCD_tearing_effect_line_on(void);
void LCD_Init(void);

void LCD_Fill(uint16_t color);
void LCD_image(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1 ,const short unsigned A[]);
void LCD_fill_Rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h,uint16_t color);
void LCD_HLine(uint16_t x, uint16_t y, uint16_t w, uint16_t color);
void LCD_VLine(uint16_t x, uint16_t y, uint16_t h,uint16_t color);
void LCD_Pixel(uint16_t x, uint16_t y,uint16_t thin ,uint16_t color);
void drawCircleHelper( uint16_t x0, uint16_t y0,uint16_t r, uint8_t cornername,uint16_t thin, uint16_t color);
void fillCircleHelper(uint16_t x0, uint16_t y0, uint16_t r,uint8_t cornername, uint16_t delta, uint16_t color);
void LCD_fill_Circle(int16_t x0, int16_t y0, int16_t r,int16_t color);
void LCD_Circle(int16_t x0, int16_t y0, int16_t r,int16_t thin,int16_t color);
void LCD_Rect(int16_t x, int16_t y,int16_t w, int16_t h,int16_t color);
void LCD_Round_Rec(int16_t x, int16_t y, int16_t w,int16_t h, int16_t r, int16_t color);
void LCD_Line(int16_t x0, int16_t y0,int16_t x1, int16_t y1, int16_t thin, int16_t color);
void LCD_Char_bg(int16_t x, int16_t y, unsigned c,int16_t color, int16_t bg, uint8_t size);
void LCD_Char(int16_t x, int16_t y, unsigned c,int16_t color, uint8_t size);

#ifdef __cplusplus
}
#endif

#endif
#ifndef __PCF8574_LCD__
#define __PCF8574_LCD__

#ifdef __KERNEL__
	
#include <linux/miscdevice.h>
#include <linux/ioctl.h>
#include <linux/types.h>

#define DRIVER_NAME 						"pcf8574_lcd"
#define LCD_CONTROLLER_NAME					"hd44780"
#define PCF8574_LCD_ADDR					0x27

#define PCF8574_LCD_BLINK_FLAG				(1 << 0x0)
#define PCF8574_LCD_CURSOR_FLAG				(1 << 0x1)
#define PCF8574_LCD_SHIFT_MODE				(1 << 0x2)
#define PCF8574_LCD_DISPLAY_FLAG			(1 << 0x3)

/* PCF8574 pin 3 is wired to a transistor to 
 * control the backlight 
 */
#define PCF8574_LCD_BACKLIGHT_FLAG			(1 << 0x3)


#define PCF8574_LCD_SHIFT_DIR				(1 << 0x3)


#define PCF8574_LCD_DISPLAY_CLEAR_CMD		(1 << 0x0)
#define PCF8574_LCD_RETURN_HOME_CMD			(1 << 0x1)
#define PCF8574_LCD_ENTRY_MODE_CMD			(1 << 0x2)
#define PCF8574_LCD_DISPLAY_CTRL_CMD		(1 << 0x3)
#define PCF8574_LCD_CURSOR_DISP_SHIFT_CMD	(1 << 0x4)
#define PCF8574_LCD_FUNCTION_SET_CMD		(1 << 0x5)
#define PCF8574_LCD_SET_CGRAM_ADDR_CMD		(1 << 0x6)
#define PCF8574_LCD_SET_DDRAM_ADDR_CMD		(1 << 0x7)
#define PCF8574_LCD_READ_BUSY_FLAG_CMD		(1 << 0x8)
#define PCF8574_LCD_RAM_WRITE_DATA			(1 << 0x9)
#define PCF8574_LCD_RAM_READ_DATA			(0x600)


#define PCF8574_LCD_ENABLE_CMD				(0x0C)
#define PCF8574_LCD_ENABLE_BIT				(1 << 2)
#define PCF8574_LCD_4BIT_MODE				(0x2)

#else
#include <sys/ioctl.h>
#include <stdint.h>

typedef uint8_t u8; 
#endif /* __KERNEL__ */

struct lcd_params {
	
	u8 lcd_display_lines;
	u8 lcd_font_size;
};

/* ioctl */
#define PCF8574_MAX_NR										32
#define PCF8574_LCD_MAGIC									'4'
#define PCF8574_LCD_DISPLAY_ON								_IO(PCF8574_LCD_MAGIC,0)
#define PCF8574_LCD_DISPLAY_OFF								_IO(PCF8574_LCD_MAGIC,1)
#define PCF8574_LCD_SET_BACKLIGHT_ON						_IO(PCF8574_LCD_MAGIC,2)
#define PCF8574_LCD_SET_BACKLIGHT_OFF						_IO(PCF8574_LCD_MAGIC,3)
#define PCF8574_LCD_CURSOR_BLINK_MODE_ON					_IO(PCF8574_LCD_MAGIC,4)
#define PCF8574_LCD_CURSOR_BLINK_MODE_OFF					_IO(PCF8574_LCD_MAGIC,6)
#define PCF8574_LCD_ADDR_INCREMENT_MODE_ON					_IO(PCF8574_LCD_MAGIC,7)
#define PCF8574_LCD_ADDR_INCREMENT_MODE_OFF					_IO(PCF8574_LCD_MAGIC,8)
#define PCF8574_LCD_CURSOR_SHIFT_MODE_ON					_IO(PCF8574_LCD_MAGIC,9)
#define PCF8574_LCD_CURSOR_SHIFT_MODE_OFF					_IO(PCF8574_LCD_MAGIC,10)
#define PCF8574_LCD_SET_CURSOR_ON							_IO(PCF8574_LCD_MAGIC,11)
#define PCF8574_LCD_SET_CURSOR_OFF							_IO(PCF8574_LCD_MAGIC,12)
#define PCF8574_LCD_CLEAR_DISPLAY							_IO(PCF8574_LCD_MAGIC,13)
#define PCF8574_LCD_RETURN_HOME								_IO(PCF8574_LCD_MAGIC,14)
#define PCF8574_LCD_CURSOR_SHIFT_ON							_IO(PCF8574_LCD_MAGIC,15)
#define PCF8574_LCD_DISPLAY_SHIFT_ON						_IO(PCF8574_LCD_MAGIC,16) /* this turns off cursor shift */
#define PCF8574_LCD_SET_SHIFT_RIGHT							_IO(PCF8574_LCD_MAGIC,17)
#define PCF8574_LCD_SET_SHIFT_LEFT							_IO(PCF8574_LCD_MAGIC,18)

#define PCF8574_LCD_INIT									_IOW(PCF8574_LCD_MAGIC,19,struct lcd_params*)
#define PCF8574_LCD_MOVE_CURSOR								_IOW(PCF8574_LCD_MAGIC,20,unsigned int)
#define PCF8574_LCD_WRITE_STRING							_IOW(PCF8574_LCD_MAGIC,21,const char*)


#endif /* __PCF8574_LCD__ */

// This header contains low level code to export from hd44780.c to "lower" HW
// implementation dependent files.

#ifndef HD_LOW_H
#define HD_LOW_H

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

# if TIME_WITH_SYS_TIME
#  include <sys/time.h>
#  include <time.h>
# else
#  if HAVE_SYS_TIME_H
#   include <sys/time.h>
#  else
#   include <time.h>
#  endif
# endif


//struct hwDependentFns;

// Maximum sizes of the keypad
// DO NOT CHANGE THESE 2 VALUES, unless you change the functions too
#define KEYPAD_MAXX 5
#define KEYPAD_MAXY 11

/* Constants for userdefchar_mode */
#define NUM_CCs 8 /* number of custom characters */
#define CCMODE_STANDARD 0 /* only char 0 is used for heartbeat */
#define CCMODE_VBAR 1
#define CCMODE_HBAR 2
#define CCMODE_BIGNUM 3
#define CCMODE_BIGCHAR 4

typedef struct ConnectionMapping {
	char *name;
	int (*init_fn) (Driver *drvthis);
	const char *helpMsg;
} ConnectionMapping;

typedef struct driver_private_data {

	unsigned int port;

	int fd; /* for picanlcd connection type */

	int width, height;
	int cellwidth, cellheight;

	// The framebuffer
	char *framebuf;

	// For incremental updates store last lcd contents
	char *lcd_contents;

	// The defineable characters
	char *cc_buf;
	char *cc_dirty;

	// Connection type data
	int connectiontype_index;
	struct hwDependentFns *hd44780_functions;

	// spanList[line number] = display line number is in
	int *spanList;
	int numLines;

	// dispVOffset is a cumulative sized array of line numbers for each display.
	// use this to determine the vertical positioning on a given display
	int *dispVOffset;
	int numDisplays;

	// dispSizes is the vertical size of each display. This is the same as the
	// input span list but is kept to save some cpu cycles.
	int *dispSizes;

	// Keypad, backlight extended interface and delay options
	char have_keypad;	 // off by default
	char have_backlight; // off by default
	char extIF;		 // off by default
	char have_output;	 // have extra output port (off by default)
	int delayMult;	 // Delay multiplier for slow displays
	char delayBus;	 // Delay if the computer can send data too fast over
				 // its bus to LPT port

	// keyMapDirect contains an array of the ascii-codes that should be generated
	// when a directly connected key is pressed (not in matrix).
	char *keyMapDirect[KEYPAD_MAXX];

	// keyMapMatrix contrains an array with arrays of the ascii-codes that should be generated
	// when a key in the matrix is pressed.
	char *keyMapMatrix[KEYPAD_MAXY][KEYPAD_MAXX];

	char *pressed_key;
	int pressed_key_repetitions;
	struct timeval pressed_key_time;

	int stuckinputs;

	int backlight_bit;

	int output_state;	// what was most recently output to the output port

	int ccmode;

} PrivateData;

// Structures holding pointers to HD44780 specific functions
typedef struct hwDependentFns {
	// microsec pauses
	void (*uPause) (PrivateData *p, int usecs);

	// Senddata to the LCD
	// dispID     - display to send data to (0 = all displays)
	// flags      - data or instruction command (RS_DATA | RS_INSTR)
	// ch	      - character to display or instruction value
	void (*senddata) (PrivateData *p, unsigned char dispID, unsigned char flags, unsigned char ch);

	// Switch the backlight on or off
	// state      - to be or not to be on
	void (*backlight) (PrivateData *p, unsigned char state);

	// Read the keypad
	// Ydata      - the up to 11 bits that should be put on the Y side of the matrix
	// return     - the up to 5 bits that are read out on the X side of the matrix
	unsigned char (*readkeypad) (PrivateData *p, unsigned int Ydata);

	// Scan the keypad and return a scancode.
	// The code is the Yvalue in the high nibble and the Xvalue in the low nibble.
	// A subdriver should do only one of two things:
	// - set readkeypad; or
	// - override scankeypad.
	unsigned char (*scankeypad) (PrivateData *p);

	// Output "data" to output latch if there is one
	void (*output) (PrivateData *p, int data);

} HD44780_functions;				  /* for want of a better name :-) */


void common_init (PrivateData *p);


// commands for senddata
#define RS_DATA     0x00
#define RS_INSTR    0x01

#define CLEAR       0x01

#define HOMECURSOR  0x02

#define ENTRYMODE   0x04
#define E_MOVERIGHT 0x02
#define E_MOVELEFT  0x00
#define EDGESCROLL  0x01
#define NOSCROLL    0x00

#define ONOFFCTRL   0x08
#define DISPON      0x04
#define DISPOFF     0x00
#define CURSORON    0x02
#define CURSOROFF   0x00
#define CURSORBLINK 0x01
#define CURSORNOBLINK 0x00

#define CURSORSHIFT 0x10
#define SCROLLDISP  0x08
#define MOVECURSOR  0x00
#define MOVERIGHT   0x04
#define MOVELEFT    0x00

#define FUNCSET     0x20
#define IF_8BIT     0x10
#define IF_4BIT     0x00
#define TWOLINE     0x08
#define ONELINE     0x00
#define LARGECHAR   0x04		  /* 5x11 characters */
#define SMALLCHAR   0x00		  /* 5x8 characters */

#define SETCHAR     0x40

#define POSITION    0x80

#endif

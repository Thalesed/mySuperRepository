#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "types.h"

#define PORT_DATA      0x60
#define PORT_STATUS    0x64

#define SCAN_CODE_KEY_ESC         0x01
#define SCAN_CODE_KEY_1         0x02
#define SCAN_CODE_KEY_2         0x03
#define SCAN_CODE_KEY_3         0x04
#define SCAN_CODE_KEY_4         0x05
#define SCAN_CODE_KEY_5         0x06
#define SCAN_CODE_KEY_6         0x07
#define SCAN_CODE_KEY_7         0x08
#define SCAN_CODE_KEY_8         0x09
#define SCAN_CODE_KEY_9         0x0A
#define SCAN_CODE_KEY_0         0x0B
#define SCAN_CODE_KEY_MINUS         0x0C
#define SCAN_CODE_KEY_EQUAL         0x0D
#define SCAN_CODE_KEY_BACKSPACE         0x0E
#define SCAN_CODE_KEY_TAB         0x0F
#define SCAN_CODE_KEY_Q         0x10
#define SCAN_CODE_KEY_W         0x11
#define SCAN_CODE_KEY_E         0x12
#define SCAN_CODE_KEY_R         0x13
#define SCAN_CODE_KEY_T         0x14
#define SCAN_CODE_KEY_Y         0x15
#define SCAN_CODE_KEY_U         0x16
#define SCAN_CODE_KEY_I         0x17
#define SCAN_CODE_KEY_O         0x18
#define SCAN_CODE_KEY_P         0x19
#define SCAN_CODE_KEY_SQUARE_OPEN_BRACKET         0x1A
#define SCAN_CODE_KEY_SQUARE_CLOSE_BRACKET         0x1B
#define SCAN_CODE_KEY_ENTER         0x1C
#define SCAN_CODE_KEY_LEFT_CTRL         0x1D
#define SCAN_CODE_KEY_A         0x1E
#define SCAN_CODE_KEY_S         0x1F
#define SCAN_CODE_KEY_D         0x20
#define SCAN_CODE_KEY_F         0x21
#define SCAN_CODE_KEY_G         0x22
#define SCAN_CODE_KEY_H         0x23
#define SCAN_CODE_KEY_J         0x24
#define SCAN_CODE_KEY_K         0x25
#define SCAN_CODE_KEY_L         0x26
#define SCAN_CODE_KEY_SEMICOLON         0x27
#define SCAN_CODE_KEY_SINGLE_QUOTE         0x28
#define SCAN_CODE_KEY_ACUTE         0x29
#define SCAN_CODE_KEY_LEFT_SHIFT         0x2A
#define SCAN_CODE_KEY_BACKSLASH         0x2B
#define SCAN_CODE_KEY_Z         0x2C
#define SCAN_CODE_KEY_X         0x2D
#define SCAN_CODE_KEY_C         0x2E
#define SCAN_CODE_KEY_V         0x2F
#define SCAN_CODE_KEY_B         0x30
#define SCAN_CODE_KEY_N         0x31
#define SCAN_CODE_KEY_M         0x32
#define SCAN_CODE_KEY_COMMA         0x33
#define SCAN_CODE_KEY_DOT         0x34
#define SCAN_CODE_KEY_FORESLHASH         0x35
#define SCAN_CODE_KEY_RIGHT_SHIFT         0x36
#define SCAN_CODE_KEY_ASTERISK         0x37
#define SCAN_CODE_KEY_ALT         0x38
#define SCAN_CODE_KEY_SPACE         0x39
#define SCAN_CODE_KEY_CAPS_LOCK         0x3A
#define SCAN_CODE_KEY_F1         0x3B
#define SCAN_CODE_KEY_F2         0x3C
#define SCAN_CODE_KEY_F3         0x3D
#define SCAN_CODE_KEY_F4         0x3E
#define SCAN_CODE_KEY_F5         0x3F
#define SCAN_CODE_KEY_F6         0x40
#define SCAN_CODE_KEY_F7         0x41
#define SCAN_CODE_KEY_F8         0x42
#define SCAN_CODE_KEY_F9         0x43
#define SCAN_CODE_KEY_F10         0x44
#define SCAN_CODE_KEY_NUM_LOCK         0x45
#define SCAN_CODE_KEY_SCROLL_LOCK         0x46
#define SCAN_CODE_KEY_HOME         0x47
#define SCAN_CODE_KEY_UP         0x48
#define SCAN_CODE_KEY_PAGE_UP         0x49
#define SCAN_CODE_KEY_KEYPAD_MINUS         0x4A
#define SCAN_CODE_KEY_LEFT         0x4B
#define SCAN_CODE_KEY_KEYPAD_5         0x4C
#define SCAN_CODE_KEY_RIGHT         0x4D
#define SCAN_CODE_KEY_KEYPAD_PLUS         0x4E
#define SCAN_CODE_KEY_END         0x4F
#define SCAN_CODE_KEY_DOWN         0x50
#define SCAN_CODE_KEY_PAGE_DOWN         0x51
#define SCAN_CODE_KEY_INSERT         0x52
#define SCAN_CODE_KEY_DELETE         0x53
#define SCAN_CODE_KEY_F11         0x57
#define SCAN_CODE_KEY_F12         0x58

uint8 ctrl_pressed = false;

static inline uint8 inb(uint16 port) {
    uint8 val;
    __asm__ __volatile__ ("inb %1, %0"
                          : "=a"(val)
                          : "Nd"(port));
    return val;
}

static inline void outb(uint16 port, uint8 val) {
    __asm__ __volatile__ ("outb %0, %1"
                          :
                          : "a"(val), "Nd"(port));
}


void outw(uint16 port, uint16 val) {
    __asm__ __volatile__ ("outw %0, %1" : : "a"(val), "Nd"(port));
}

static inline uint8 keyboard_data_ready() {
    return inb(PORT_STATUS) & 0x01;
}

static char codeToChar(uint8 scancode) {
    switch (scancode) {
	case SCAN_CODE_KEY_LEFT_CTRL:
            ctrl_pressed = true;
	    return NULL;
        case SCAN_CODE_KEY_LEFT_CTRL + 0x80:
            ctrl_pressed = false;
            return NULL;
        case SCAN_CODE_KEY_1: return '1';
        case SCAN_CODE_KEY_2: return '2';
        case SCAN_CODE_KEY_3: return '3';
        case SCAN_CODE_KEY_4: return '4';
        case SCAN_CODE_KEY_5: return '5';
        case SCAN_CODE_KEY_6: return '6';
        case SCAN_CODE_KEY_7: return '7';
        case SCAN_CODE_KEY_8: return '8';
        case SCAN_CODE_KEY_9: return '9';
        case SCAN_CODE_KEY_0: return '0';
        case SCAN_CODE_KEY_Q: return 'q';
        case SCAN_CODE_KEY_W: return 'w';
        case SCAN_CODE_KEY_E: return 'e';
        case SCAN_CODE_KEY_R: return 'r';
        case SCAN_CODE_KEY_T: return 't';
        case SCAN_CODE_KEY_Y: return 'y';
        case SCAN_CODE_KEY_U: return 'u';
        case SCAN_CODE_KEY_I: return 'i';
        case SCAN_CODE_KEY_O: return 'o';
        case SCAN_CODE_KEY_P: return 'p';
        case SCAN_CODE_KEY_A: return 'a';
        case SCAN_CODE_KEY_S: return 's';
        case SCAN_CODE_KEY_D: return 'd';
        case SCAN_CODE_KEY_F: return 'f';
        case SCAN_CODE_KEY_G: return 'g';
        case SCAN_CODE_KEY_H: return 'h';
        case SCAN_CODE_KEY_J: return 'j';
        case SCAN_CODE_KEY_K: return 'k';
        case SCAN_CODE_KEY_L: return 'l';
        case SCAN_CODE_KEY_Z: return 'z';
        case SCAN_CODE_KEY_X: return 'x';
        case SCAN_CODE_KEY_C: return 'c';
        case SCAN_CODE_KEY_V: return 'v';
        case SCAN_CODE_KEY_B: return 'b';
        case SCAN_CODE_KEY_N: return 'n';
        case SCAN_CODE_KEY_M: return 'm';
        case SCAN_CODE_KEY_SPACE: return ' ';
	case SCAN_CODE_KEY_ENTER: return '\n';
	case SCAN_CODE_KEY_BACKSPACE: return '\b';
	case SCAN_CODE_KEY_TAB: return '\t';
	case SCAN_CODE_KEY_ESC: return '\0';
        default: return NULL;
    }
}

char getchar() {
    while (!keyboard_data_ready());
    return codeToChar(inb(PORT_DATA));
}


#endif

#ifndef VGA_H
#define VGA_H

#include "types.h"

#define VGA_WIDTH  80
#define VGA_HEIGHT 100

#define VGA_POINTER 0xB8000
#define BUFFER_SIZE (VGA_WIDTH * VGA_HEIGHT) +1

#define INDEX_LIMIT 11
uint16* vga_buffer;
uint16 vga_index = INDEX_LIMIT;

#define MAX_CHAR 0xFFF

enum vga_color {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE,
};

uint8 lineIndex = 0;

uint16 vga_add(unsigned char ch, uint8 proxCor, uint8 corAnt){
	uint16 reg;
	uint8 regChar, regCor;

	regCor = corAnt;
	regCor <<= 4;
	regCor |= proxCor;

	reg = regCor;
	reg <<= 8;

	regChar = ch;
	
	reg |= regChar;

	return reg;
}

void vga_clear(uint16** buffer, uint8 proxCor, uint8 corAnt){
	uint32 i;
	for(i=0;i<BUFFER_SIZE;i++){
		(*buffer)[i] = vga_add(NULL, proxCor, corAnt);
	}
	vga_index = 0;
}

void cursor_goto(uint16 pos) {
    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8)(pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8)((pos >> 8) & 0xFF));
}

void vga_start(uint8 proxCor, uint8 corAnt){
	vga_buffer = (uint16 *)VGA_POINTER;
	vga_clear(&vga_buffer, proxCor, corAnt);
	cursor_goto(vga_index);
}

void newLine(){
	uint8 line = vga_index / VGA_WIDTH;
	uint8 col = vga_index - (line * VGA_WIDTH);
	
	vga_index += VGA_WIDTH - col;
}


char vga_get(uint16 val){
	uint8 ch = 0;
	ch |= val;

	return (char)ch;	
}

void unsafe_putchar(uint16 code){
	vga_buffer[vga_index] = code;
	vga_index++;
}

uint8 putchar(unsigned char ch){
	uint8 valido = false;
	if(ch == '\n'){
		newLine();
	}
	else if( ch =='\b' && ( (vga_index - ((vga_index /(VGA_WIDTH)) * VGA_WIDTH)) > 10 ) ){
		if(vga_buffer[vga_index-1] != MAX_CHAR /*&& vga_buffer[vga_index] != MAX_CHAR*/){
			vga_index--;
			vga_buffer[vga_index] = vga_add(' ', WHITE, BLACK);
			valido = true;
		}else{
			return valido;
		}
	}else if(ch == '\t'){
		vga_index+=4;

	}else if(vga_index < BUFFER_SIZE){
		if( (vga_buffer[vga_index - 1] & 0x80) != ch){
			vga_buffer[vga_index] = vga_add(ch, WHITE, BLACK);
			vga_index++;
			valido = true;
		}
	}
	cursor_goto(vga_index);
	return valido;
	
}


void vga_print(char * str){
	uint8 count = 0;
	unsigned char ch = str[count];
	while(ch != '\0'){
		putchar(ch);
		count ++;
		ch = str[count];
	}
}


 


#endif

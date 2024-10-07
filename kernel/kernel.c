#include "kernel.h"
#include "keyboard.h"
#include "types.h"
#include "vga.h"

uint8* ram;

#include <stdint.h>

extern void* multiboot_info;

#define MULTIBOOT_INFO_MEM_MAP 0x0000000000000010

typedef struct {
    uint32_t size;
    uint32_t base_addr_low;
    uint32_t base_addr_high;
    uint32_t length_low;
    uint32_t length_high;
    uint32_t type;
} __attribute__((packed)) multiboot_memory_map_t;

uint64* ram_start = 0;

void kernel_start(uint32 magic, uint32* mbi_ptr){
	MULTIBOOT_INFO * mboot_info = (MULTIBOOT_INFO *)mbi_ptr;
	vga_start(WHITE, BLACK);
	vga_print(intToStr( (mboot_info->mem_low)));
	vga_print("\n");
	vga_print(intToStr( (mboot_info->mem_high)));
	vga_print("\n");

	//init_memory();
	uint64 teste = detect_memory();
	ram_start = (void*)teste;

	char key = '\n';
	
	char* cmd_buffer = (char*)(ram_start);	
	uint8 cmd_i = 0;
	//cmd_buffer[cmd_i] = '\0';
	while(1){
		if(key == '\n'){
			cmd_buffer[cmd_i] = '\0';
			vga_print(cmd_buffer);
			vga_print("\nSWAN-OS >>");
			//sendCmd(cmd_buffer);
			cmd_i = 0;
			cmd_buffer[cmd_i] = '\0';
		}else if(key == '\0'){
			//die();
		}
		else if(ctrl_pressed){
			if(key == 'l'){
				vga_clear(&vga_buffer, WHITE, BLACK);
				vga_print("SWAN-OS >>");
				unsafe_putchar(MAX_CHAR);
			}else if(key == 'm'){
				vga_print(intToStr( (mboot_info->mem_low)));
				vga_print(intToStr( (mboot_info->mem_high)));
				vga_clear(&vga_buffer, WHITE, BLACK);
				show_mbi();
			}else if(key == 'd'){
				die();
			}
		}
		key = getchar();
		if(putchar(key)){
			if(key == '\b'){
				if(cmd_i > 0){
					//vga_print("BackSpace");
					cmd_buffer[cmd_i] = ' ';
					cmd_i--;
				}
			}else{
				cmd_buffer[cmd_i] = key;
				cmd_i++;
				cmd_buffer[cmd_i] = '\0';
				//vga_print(intToStr(cmd_i));
			}
		}
	}
	return;
}

uint8 test_memory(uint64 * addr) {
    volatile uint8 * ptr = (volatile uint8*)addr;
    *ptr = 0x55;
    return *ptr == 0x55; 
}

uint64 detect_memory() {
	uint64 start = 0x00100000;
	uint64 end = 0x00F00000;

	for(uint64 i = start; i < end; i += 0x1000){
		if(test_memory((uint64*)i)){
			return i;
		}
	}

}

void init_memory(){
	ram = (uint8*)(RAM_POINTER);
	uint64 i;

	vga_print("Carregando . ");

	uint64 total = 1024 * 1024 * 2;


	for(i=0;i<total;i++){
		ram[i] = 2;
		if(i % (1024 * 1024) == 0){
			if(ram[i] != 2){
				vga_print("END");
			}
			vga_print(". ");
		}
	}
	vga_clear(&vga_buffer, WHITE, BLACK);
}

void sendCmd(char* cmd){
	vga_print(cmd);
	if(str_cmp(cmd, "cl")){
		vga_clear(&vga_buffer, WHITE, BLACK);
	}

	for(int i=0;cmd[i] != 2;i++){
		cmd[i] = 2;
	}
}

void show_mbi(){
	uint8* bt = ram;
       	uint8 vazio = false;
	uint64 i = 1;	

	uint64 total = 1024 * 1024 * 1024;
	uint8 numCod = 12;
	
	uint8 tmp;
	
	vga_print(intToStr(bt[i]));
	while(!vazio && i < total){
		vga_print(intToStr(bt[i]));
		if(bt[i] != 2){
			//vga_print(intToStr(i));
			vazio = true;
		}
		i++;
	}
	//vga_print(intToStr(i));
	
}

void die(){
	outw(0x604, 0x2000);
	uint16* teste = (uint16*)0x00000;
	uint32 i, count =1;

	for(i=0;count!=0;i++){
		teste[i] = NULL;
		count++;
	}
	outw(0x604, 0x2000);
}

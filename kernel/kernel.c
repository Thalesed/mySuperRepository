#include "kernel.h"
#include "keyboard.h"
#include "types.h"
#include "vga.h"

uint8* ram;

void kernel_start(uint32 magic, uint32* mbi_ptr){
	MULTIBOOT_INFO * mboot_info = (MULTIBOOT_INFO *)mbi_ptr;
	vga_start(WHITE, BLACK);
	vga_print(intToStr( (mboot_info->mem_low)));
	vga_print("\n");
	vga_print(intToStr( (mboot_info->mem_high)));
	vga_print("\n");

	init_memory();

	char key = '\n';

	char* cmd_buffer = (char*)(ram + 16); 
	uint8 cmd_i = 0;
	while(1){
		if(key == '\n'){
			vga_print("SWAN-OS >>");
			unsafe_putchar(MAX_CHAR);
			cmd_buffer[cmd_i] = '\0';
			//vga_print(cmd_buffer);
			sendCmd(cmd_buffer);
			cmd_buffer[cmd_i] = NULL;
			cmd_i = 0;
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
					cmd_buffer[cmd_i-1] = NULL;
					cmd_i--;
				}
			}else{
				cmd_buffer[cmd_i] = key;
				cmd_i++;
				//vga_print("Added");
			}
			vga_print(cmd_buffer);
		}
	}
	return;
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

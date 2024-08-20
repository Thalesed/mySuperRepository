#ifndef TYPES_H
#define TYPES_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;

#define NULL 0
#define false (1==0)
#define true (1==1)

int pow(int base,int  exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}


char* intToStr(signed int number) {
    char* str = (char*)0x21001;
    int i = 0;
    unsigned int temp = number;
    int count = 0;

    while (temp != 0) {
        count++;
        temp /= 10;
    }

    if (number < 0) {
        str[i++] = '-';
        number = -number;
    }

    for (int j = count - 1; j >= 0; j--) {
        str[i++] = '0' + (number / (int)pow(10, j)) % 10;
    }

    str[i] = '\0';
    return str;
}

uint8 str_cmp(char* str1, char* str2) {
    if (str1 == NULL || str2 == NULL) {
        return false;
    }

    uint8 i = 0;
    while ( i < 10) {
        if (str1[i] != str2[i]) {
            return false; 
        }
	i++;
    }
	

    return true;
}

#endif

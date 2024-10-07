#ifndef MEMORY_H
#define MEMORY_H

#include "types.h"

#define E820_MAX_ENTRIES 128

struct e820_entry {
    uint64 base_addr;
    uint64 length;
    uint32 type;
} __attribute__((packed));

struct e820_entry e820_map[E820_MAX_ENTRIES];
unsigned int e820_entries_count = 0;

uint64 detect_memory();

void analyze_memory() {
    for (unsigned int i = 0; i < e820_entries_count; ++i) {
        if (e820_entries[i].type == 1) {  // Memória disponível
            uint64_t base = e820_entries[i].base_addr;
            uint64_t length = e820_entries[i].length;

            for (uint64_t addr = base; addr < base + length; addr += sizeof(uint32_t)) {
                volatile uint32_t *ptr = (uint32_t *)addr;
                // Operações com a memória
                *ptr = 0xDEADBEEF;
                uint32_t value = *ptr;
                if (value != 0xDEADBEEF) {
                    // Tratamento de erro
                }
            }
        }
    }
}

#endif

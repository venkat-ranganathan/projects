#include <stdint.h>
#include <stdio.h>

void print_hex(uint8_t num_digits, uint32_t value) {
    for (int i = num_digits - 1; i >= 0; i--) {
        uint8_t nibble = (value >> (i * 4)) & 0xF;
        if (nibble < 10) {
            putchar('0' + nibble);
        } else {
            putchar('A' + (nibble - 10));
        }
    }
}

void dump_memory(uint32_t address, uint32_t byte_size) {
    for (uint32_t i = 0; i < byte_size; i++) {
        if (i % 16 == 0) {
            if (i != 0) {
                printf("\n");
            }
            printf("%08X: ", address + i);
        }

        uint8_t byte = *((uint8_t*)(address + i));
        print_hex(2, byte);
        putchar(' ');
    }
    printf("\n");
}

int main() {
    uint32_t memory_address = 0x20000000;  // Example memory address
    uint32_t byte_size = 32;               // Example byte size

    dump_memory(memory_address, byte_size);

    return 0;
}

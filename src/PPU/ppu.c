#include <stdint.h>
#include <stdlib.h>

#include "../CARTUCHO/cartucho.h"

uint8_t *vNameTable;

uint8_t *vPalettes;

void ppuStart(){
    vNameTable = (uint8_t*)calloc(4096, sizeof(uint8_t));
    vPalettes = (uint8_t*)calloc(32, sizeof(uint8_t));
}

uint8_t ppuRead();

uint8_t ppuWrite();
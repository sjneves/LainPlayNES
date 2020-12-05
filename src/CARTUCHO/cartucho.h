#ifndef _H_CARTUCHO
#define _H_CARTUCHO
#include <stdint.h>

struct {
    char name[4];
    uint8_t nPRG;
    uint8_t nCHR;
    uint8_t flag6;
    uint8_t flag7;
    uint8_t flag8;
    uint8_t flag9;
    uint8_t flag10;
    uint8_t paraNome[5];
}typedef header;

struct {
    uint16_t (*mapper)(uint16_t, uint16_t);
}typedef Mapper;

uint8_t inserirCartucho(char*);

uint8_t CPUromRead(uint16_t addrs);

uint8_t PPUromRead(uint16_t addrs);

void pointMapper(uint8_t);

#endif
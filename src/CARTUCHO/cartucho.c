#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "cartucho.h"
#include "mappers.h"


Cartucho *inserirCartucho(char *arquivo){
    FILE *rom;
    printf("Abrindo Arquivo: %s\n", arquivo);
    rom = fopen(arquivo, "rb");

    if(rom == 0){
        printf("Erro ao abrir o arquivo!!\n");
        exit(1);
    }

    Cartucho *c = (Cartucho*)calloc(1, sizeof(Cartucho));

    fread(&c->myHeader, sizeof(header), 1, rom);

    printf("CPU banks: %d\nPPU banks: %d\n", c->myHeader.nPRG, c->myHeader.nCHR);

    char lixo[512];
    if(c->myHeader.flag6 & 0x04)
        fread(&lixo, sizeof(uint8_t) * 512, 1, rom);
    
    uint8_t lowMapper;
    uint8_t highMapper;

    lowMapper = ((c->myHeader.flag6 & 0xF0) >> 4);
    highMapper = (c->myHeader.flag7 & 0xF0);

    uint8_t numMapper = lowMapper | highMapper;
    pointMapper(numMapper, c);

    c->mPRG = calloc(16384, c->myHeader.nPRG);
    c->mCHR = calloc(8192, c->myHeader.nCHR);

    fread(c->mPRG, 16384 * c->myHeader.nPRG, 1, rom);
    fread(c->mCHR, 8192 * c->myHeader.nCHR, 1, rom);
    fclose(rom);
    return 0;
}

void closeCartucho(Cartucho *c){
    free(c);
}

void pointMapper(uint8_t map, Cartucho *c){
    Mapper LM[256];

    LM[0x00].mapper = NROM;     LM[0x01].mapper = mXX; LM[0x02].mapper = mXX; LM[0x03].mapper = mXX; LM[0x04].mapper = mXX; LM[0x05].mapper = mXX; LM[0x06].mapper = mXX; LM[0x07].mapper = mXX; LM[0x08].mapper = mXX; LM[0x09].mapper = mXX; LM[0x0A].mapper = mXX; LM[0x0B].mapper = mXX; LM[0x0C].mapper = mXX; LM[0x0D].mapper = mXX; LM[0x0E].mapper = mXX; LM[0x0F].mapper = mXX;
    LM[0x10].mapper = mXX;      LM[0x11].mapper = mXX; LM[0x12].mapper = mXX; LM[0x13].mapper = mXX; LM[0x14].mapper = mXX; LM[0x15].mapper = mXX; LM[0x16].mapper = mXX; LM[0x17].mapper = mXX; LM[0x18].mapper = mXX; LM[0x19].mapper = mXX; LM[0x1A].mapper = mXX; LM[0x1B].mapper = mXX; LM[0x1C].mapper = mXX; LM[0x1D].mapper = mXX; LM[0x1E].mapper = mXX; LM[0x1F].mapper = mXX;
    LM[0x20].mapper = mXX;      LM[0x21].mapper = mXX; LM[0x22].mapper = mXX; LM[0x23].mapper = mXX; LM[0x24].mapper = mXX; LM[0x25].mapper = mXX; LM[0x26].mapper = mXX; LM[0x27].mapper = mXX; LM[0x28].mapper = mXX; LM[0x29].mapper = mXX; LM[0x2A].mapper = mXX; LM[0x2B].mapper = mXX; LM[0x2C].mapper = mXX; LM[0x2D].mapper = mXX; LM[0x2E].mapper = mXX; LM[0x2F].mapper = mXX;
    LM[0x30].mapper = mXX;      LM[0x31].mapper = mXX; LM[0x32].mapper = mXX; LM[0x33].mapper = mXX; LM[0x34].mapper = mXX; LM[0x35].mapper = mXX; LM[0x36].mapper = mXX; LM[0x37].mapper = mXX; LM[0x38].mapper = mXX; LM[0x39].mapper = mXX; LM[0x3A].mapper = mXX; LM[0x3B].mapper = mXX; LM[0x3C].mapper = mXX; LM[0x3D].mapper = mXX; LM[0x3E].mapper = mXX; LM[0x3F].mapper = mXX;
    LM[0x40].mapper = mXX;      LM[0x41].mapper = mXX; LM[0x42].mapper = mXX; LM[0x43].mapper = mXX; LM[0x44].mapper = mXX; LM[0x45].mapper = mXX; LM[0x46].mapper = mXX; LM[0x47].mapper = mXX; LM[0x48].mapper = mXX; LM[0x49].mapper = mXX; LM[0x4A].mapper = mXX; LM[0x4B].mapper = mXX; LM[0x4C].mapper = mXX; LM[0x4D].mapper = mXX; LM[0x4E].mapper = mXX; LM[0x4F].mapper = mXX;
    LM[0x50].mapper = mXX;      LM[0x51].mapper = mXX; LM[0x52].mapper = mXX; LM[0x53].mapper = mXX; LM[0x54].mapper = mXX; LM[0x55].mapper = mXX; LM[0x56].mapper = mXX; LM[0x57].mapper = mXX; LM[0x58].mapper = mXX; LM[0x59].mapper = mXX; LM[0x5A].mapper = mXX; LM[0x5B].mapper = mXX; LM[0x5C].mapper = mXX; LM[0x5D].mapper = mXX; LM[0x5E].mapper = mXX; LM[0x5F].mapper = mXX;
    LM[0x60].mapper = mXX;      LM[0x61].mapper = mXX; LM[0x62].mapper = mXX; LM[0x63].mapper = mXX; LM[0x64].mapper = mXX; LM[0x65].mapper = mXX; LM[0x66].mapper = mXX; LM[0x67].mapper = mXX; LM[0x68].mapper = mXX; LM[0x69].mapper = mXX; LM[0x6A].mapper = mXX; LM[0x6B].mapper = mXX; LM[0x6C].mapper = mXX; LM[0x6D].mapper = mXX; LM[0x6E].mapper = mXX; LM[0x6F].mapper = mXX;
    LM[0x70].mapper = mXX;      LM[0x71].mapper = mXX; LM[0x72].mapper = mXX; LM[0x73].mapper = mXX; LM[0x74].mapper = mXX; LM[0x75].mapper = mXX; LM[0x76].mapper = mXX; LM[0x77].mapper = mXX; LM[0x78].mapper = mXX; LM[0x79].mapper = mXX; LM[0x7A].mapper = mXX; LM[0x7B].mapper = mXX; LM[0x7C].mapper = mXX; LM[0x7D].mapper = mXX; LM[0x7E].mapper = mXX; LM[0x7F].mapper = mXX;
    LM[0x80].mapper = mXX;      LM[0x81].mapper = mXX; LM[0x82].mapper = mXX; LM[0x83].mapper = mXX; LM[0x84].mapper = mXX; LM[0x85].mapper = mXX; LM[0x86].mapper = mXX; LM[0x87].mapper = mXX; LM[0x88].mapper = mXX; LM[0x89].mapper = mXX; LM[0x8A].mapper = mXX; LM[0x8B].mapper = mXX; LM[0x8C].mapper = mXX; LM[0x8D].mapper = mXX; LM[0x8E].mapper = mXX; LM[0x8F].mapper = mXX;
    LM[0x90].mapper = mXX;      LM[0x91].mapper = mXX; LM[0x92].mapper = mXX; LM[0x93].mapper = mXX; LM[0x94].mapper = mXX; LM[0x95].mapper = mXX; LM[0x96].mapper = mXX; LM[0x97].mapper = mXX; LM[0x98].mapper = mXX; LM[0x99].mapper = mXX; LM[0x9A].mapper = mXX; LM[0x9B].mapper = mXX; LM[0x9C].mapper = mXX; LM[0x9D].mapper = mXX; LM[0x9E].mapper = mXX; LM[0x9F].mapper = mXX;
    LM[0xA0].mapper = mXX;      LM[0xA1].mapper = mXX; LM[0xA2].mapper = mXX; LM[0xA3].mapper = mXX; LM[0xA4].mapper = mXX; LM[0xA5].mapper = mXX; LM[0xA6].mapper = mXX; LM[0xA7].mapper = mXX; LM[0xA8].mapper = mXX; LM[0xA9].mapper = mXX; LM[0xAA].mapper = mXX; LM[0xAB].mapper = mXX; LM[0xAC].mapper = mXX; LM[0xAD].mapper = mXX; LM[0xAE].mapper = mXX; LM[0xAF].mapper = mXX;
    LM[0xB0].mapper = mXX;      LM[0xB1].mapper = mXX; LM[0xB2].mapper = mXX; LM[0xB3].mapper = mXX; LM[0xB4].mapper = mXX; LM[0xB5].mapper = mXX; LM[0xB6].mapper = mXX; LM[0xB7].mapper = mXX; LM[0xB8].mapper = mXX; LM[0xB9].mapper = mXX; LM[0xBA].mapper = mXX; LM[0xBB].mapper = mXX; LM[0xBC].mapper = mXX; LM[0xBD].mapper = mXX; LM[0xBE].mapper = mXX; LM[0xBF].mapper = mXX;
    LM[0xC0].mapper = mXX;      LM[0xC1].mapper = mXX; LM[0xC2].mapper = mXX; LM[0xC3].mapper = mXX; LM[0xC4].mapper = mXX; LM[0xC5].mapper = mXX; LM[0xC6].mapper = mXX; LM[0xC7].mapper = mXX; LM[0xC8].mapper = mXX; LM[0xC9].mapper = mXX; LM[0xCA].mapper = mXX; LM[0xCB].mapper = mXX; LM[0xCC].mapper = mXX; LM[0xCD].mapper = mXX; LM[0xCE].mapper = mXX; LM[0xCF].mapper = mXX;
    LM[0xD0].mapper = mXX;      LM[0xD1].mapper = mXX; LM[0xD2].mapper = mXX; LM[0xD3].mapper = mXX; LM[0xD4].mapper = mXX; LM[0xD5].mapper = mXX; LM[0xD6].mapper = mXX; LM[0xD7].mapper = mXX; LM[0xD8].mapper = mXX; LM[0xD9].mapper = mXX; LM[0xDA].mapper = mXX; LM[0xDB].mapper = mXX; LM[0xDC].mapper = mXX; LM[0xDD].mapper = mXX; LM[0xDE].mapper = mXX; LM[0xDF].mapper = mXX;
    LM[0xE0].mapper = mXX;      LM[0xE1].mapper = mXX; LM[0xE2].mapper = mXX; LM[0xE3].mapper = mXX; LM[0xE4].mapper = mXX; LM[0xE5].mapper = mXX; LM[0xE6].mapper = mXX; LM[0xE7].mapper = mXX; LM[0xE8].mapper = mXX; LM[0xE9].mapper = mXX; LM[0xEA].mapper = mXX; LM[0xEB].mapper = mXX; LM[0xEC].mapper = mXX; LM[0xED].mapper = mXX; LM[0xEE].mapper = mXX; LM[0xEF].mapper = mXX;
    LM[0xF0].mapper = mXX;      LM[0xF1].mapper = mXX; LM[0xF2].mapper = mXX; LM[0xF3].mapper = mXX; LM[0xF4].mapper = mXX; LM[0xF5].mapper = mXX; LM[0xF6].mapper = mXX; LM[0xF7].mapper = mXX; LM[0xF8].mapper = mXX; LM[0xF9].mapper = mXX; LM[0xFA].mapper = mXX; LM[0xFB].mapper = mXX; LM[0xFC].mapper = mXX; LM[0xFD].mapper = mXX; LM[0xFE].mapper = mXX; LM[0xFF].mapper = mXX;

    c->mapper = LM[map].mapper;
}

uint8_t CPUromRead(uint16_t addrs, Cartucho *c){
    printf("Entrou no romRead\n");

    uint16_t info = 0x0F00;
    info += ((uint16_t)c->myHeader.nPRG & 0x00FF);

    uint16_t r_addrs = c->mapper(addrs, info);

    return c->mPRG[r_addrs];
}

uint8_t PPUromRead(uint16_t addrs, Cartucho *c){
    printf("Entrou no PPUromRead\n");

    uint16_t info = 0xF000;
    info += ((uint16_t)c->myHeader.nCHR & 0x00FF);

    uint16_t r_addrs = c->mapper(addrs, info);

    return c->mCHR[r_addrs];
}
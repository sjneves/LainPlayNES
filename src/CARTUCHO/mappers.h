#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Apenas o Mapper000
uint16_t NROM(uint16_t addrs, uint16_t sw){
    if((sw & 0xFF00) == 0x0F00){
        // CPU
        printf("Entrou na CPU ROM\n");
        printf("nº bancos %d\n", sw & 0x00FF);
        if((sw & 0x00FF) == 1){
            return addrs;
        }else if((sw & 0x00FF) == 2){
            return addrs%16384;
        }else{
            printf("Erro no mapper da CPU - NROM\n");
            exit(1);
        }
    }else if((sw & 0xFF00) == 0xF000){
        // PPU
        printf("Entrou na PPU ROM\n");
        printf("nº bancos %d\n", sw & 0x00FF);
        return addrs;
    }else{
        exit(1);
    }
    return 0;
}

uint16_t mXX(uint16_t addrs, uint16_t sw){
    printf("Mapper ainda não criado!!\n");

    return 0;
}
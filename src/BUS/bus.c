
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t* cpuRAM;

void busStart(){
    cpuRAM = (uint8_t*)calloc(2 * 1024, sizeof(uint8_t));
}

uint8_t bus_read(uint16_t mem){
    uint8_t dado = 0x00;

    if((mem >= 0x0000) && (mem <= 0x1FFF)){
        dado = cpuRAM[mem%2048];
    }else if((mem >= 0x2000) && (mem <= 0x3FFF)){
        dado = 0x00;
    }
    return dado;
}

int bus_write(uint16_t mem, uint8_t dado){

    if((mem >= 0x0000) && (mem <= 0x1FFF)){
        cpuRAM[mem%2048] = dado;
    }else if((mem >= 0x2000) && (mem <= 0x3FFF)){
        dado = 0x00;
    }

    return 0;
}

/*
 * Envia um pulso de clock para todos os dispositivos conectados no bus
 * 
 * Cada componente deverar ter uma função para interpretar esse pulso
 * de clock
 */
int bus_clock(){
    return 0;
}
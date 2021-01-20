/*
    Aqui as coisas ainda são bem teóricas

    Sei que vou precisar de uma função de leitura e escrita OK
    Essa função tera um mapa e de acordo com o endereço de memória informado ele vai acessar o dispositivo
    conectado ao BUS correspondente a esse endereço.

    Criar uma struct que aponta para uma função, tenha um valor para endereço de início e endereço final. E criar
    uma função que receba essa struct, e vai adicionando ela a uma lista dinâmica sequêncial de acordo com o endereço
    especificado na função.
    A ideia aqui é que o bus tenha uma função clock, que será ativada de tempos em tempos, essa função vai chamar a 
    função clock de cada dispositivo conectado ao bus, e aí a função clock do dispositivo vai executar a sua respectiva
    função.

    Pegar a tabela com os endereços do NES

    Address range 	Size 	Device
    $0000-$07FF 	$0800 	2KB internal RAM
    $0800-$0FFF 	$0800 	Mirrors of $0000-$07FF
    $1000-$17FF 	$0800   ||
    $1800-$1FFF 	$0800   ||
    $2000-$2007 	$0008 	NES PPU registers
    $2008-$3FFF 	$1FF8 	Mirrors of $2000-2007 (repeats every 8 bytes)
    $4000-$4017 	$0018 	NES APU and I/O registers
    $4018-$401F 	$0008 	APU and I/O functionality that is normally disabled. See CPU Test Mode.
    $4020-$FFFF 	$BFE0 	Cartridge space: PRG ROM, PRG RAM, and mapper registers (See Note) 

    Eu sei que tenho a CPU (vou ignorar a PPU no momento, até porque o plano é que o BUS correspondente a ela, seja incorporado nela mesma),
    e ela é a única que faz acesso a memória, os demais são dispositívos para leitura, e no caso da RAM, para escrita também. Então a ideia,
    é que o BUS tenha uma struct no formato de lista, onde a cabeça da lista é a CPU, seguida pela memória RAM, que são os únicos diferentes,
    e os demais serão objetos simples com um endereço de começo e outro de fim e uma função de leitura associada a ele.
*/
#ifndef _H_BUS
#define _H_BUS

#include <stdint.h>

#include "../CPU/cpu.h"
#include "../CARTUCHO/cartucho.h"

struct {
    CPU_6502 *CPU;
    uint8_t *cpuRAM;
    Cartucho *cartucho;
} typedef System;

/*
 * Function bus_read(uint16_t)
 * 
 * Recebe um endereço de memória e retorna o valor armazenado
 * naquele endereço.
*/
uint8_t busRead(uint16_t);

/*  
 *  Function bus_write(uint16 endereco, uint8_t informacao)
 *  
 *  Recebe um endereço de memória onde o dado será gravado
 *  e a informação a ser gravada
 * 
*/
uint8_t busWrite(uint16_t, uint8_t);

int bus_clock();

System* newNES();

void closeNES(System*);

uint8_t* fake_memoria();

#endif
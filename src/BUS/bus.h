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
*/
#ifndef _H_BUS
#define _H_BUS

#include <stdint.h>

uint8_t bus_read(uint16_t);

/*  
 *  Function bus_write(uint16 endereco, uint8_t informacao)
 *  
 *  Recebe um enderaço de memória onde o dado que será gravado
 *  e a informação a ser gravada
 * 
*/
uint8_t bus_write(uint16_t, uint8_t);

int bus_clock();

uint8_t* fake_memoria();

#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "cpu.h"
#include "../BUS/bus.h"
#include "cpu_operacoes.h"

#define debug

opcode *myOpList; // Tabela com as instruções da CPU

uint8_t clk;

CPU_6502* CPUStart(){
    CPU_6502 *my_cpu;
    my_cpu = (CPU_6502*)malloc(sizeof(CPU_6502));
    opcode my_opcodeList[256];

    criaOpcodeLista(my_opcodeList, &clk);

    reset(my_cpu);
    myOpList = my_opcodeList;
    my_cpu->clk = 0;

    return my_cpu;
}

int CPUStop(CPU_6502 *my_cpu){
    free(my_cpu);
    return 0;
}

int CPUClock(CPU_6502 *my_cpu){
    opcode operacao;
    
    if(clk == 0){
        uint16_t addrs;

        #ifdef debug
        printf("oi ----> %d\n", clk);
        printf("PC ----> %x\n", my_cpu->PC);
        #endif
        uint8_t instrucao = fetch(my_cpu->PC);
        my_cpu->opcode = instrucao;
        my_cpu->PC++;
        #ifdef debug
        printf("ints -> %x\n",instrucao);
        #endif
        operacao = myOpList[instrucao];
        clk = operacao.ck;

        uint16_t t1 = operacao.mF(my_cpu, &addrs);
        
        uint8_t t2 = operacao.oF(my_cpu, addrs);

        if((t1 + t2) > 1){
            clk++;
        }
    }
    clk--;
    return clk;
}

// Seta todos os parâmetros da CPU para o valor inicial
// O valor inicial depende da aplicação
// Por exemplo: o PC não começa em 0x0000, por que os endereços
// 0x00FF para baixo (eu acho que é isso) são utilizados para o
// stack pointer. E sendo assim o stack pointer começa com o valor
// 0x00FF
// [Atualizar essas informações conforme for avançando]
void reset(CPU_6502 *my_cpu){
    my_cpu->PC   = 0x0100;
    my_cpu->AC   = 0x00;
    my_cpu->X    = 0x00;
    my_cpu->Y    = 0x00;
    my_cpu->SR   = 0x00;
    my_cpu->SP   = 0xFF;
}

uint8_t SetFlag(enum FLAGSCPU flag, CPU_6502 *my_cpu, int v){
    if(v != 0){
        my_cpu->SR |= flag;
    }else{
        my_cpu->SR &= ~flag;
    }

    return my_cpu->SR;
}

uint8_t GetFlag(enum FLAGSCPU flag, CPU_6502 *my_cpu){
    return ((my_cpu->SR & flag) > 0) ? 1 : 0;
}

// Esta interrupção pode só é executada se a flog I = 0
// 
// Escreve no SP a informação em PC
// Seta a flag de interrupção break B = 0
// Seta a undefined _ = 1
// Seta interruption I = 1
// Estreve o SR no SP
// O PC novo sera o endereço no 0xFFFE
// Requer 7 ciclos para ser executada
void irq(CPU_6502 *my_cpu){
    if(GetFlag(I, my_cpu) == 0){
        bus_write(0x0100 + my_cpu->SP, (uint8_t)((my_cpu->PC >> 8) & 0x00FF));
        my_cpu->SP--;
        bus_write(0x0100 + my_cpu->SP, (uint8_t)(my_cpu->PC & 0x00FF));
        my_cpu->SP--;

        SetFlag(B, my_cpu, 0);
        SetFlag(_, my_cpu, 1);
        SetFlag(I, my_cpu, 1);

        bus_write(0x0100 + my_cpu->SP, my_cpu->SR);
        my_cpu->SP--;

        my_cpu->PC = ((uint16_t)bus_read(0xFFFE) & 0x00FF);
        my_cpu->PC += (((uint16_t)bus_read(0xFFFE + 1) << 8) & 0xFF00);

        clk = 7;
    }
}

// Mesma coisa que o anterior mas o I não precisa ser 0
void nmi(CPU_6502 *my_cpu){
    bus_write(0x0100 + my_cpu->SP, (uint8_t)((my_cpu->PC >> 8) & 0x00FF));
    my_cpu->SP--;
    bus_write(0x0100 + my_cpu->SP, (uint8_t)(my_cpu->PC & 0x00FF));
    my_cpu->SP--;

    SetFlag(B, my_cpu, 0);
    SetFlag(_, my_cpu, 1);
    SetFlag(I, my_cpu, 1);

    bus_write(0x0100 + my_cpu->SP, my_cpu->SR);
    my_cpu->SP--;

    my_cpu->PC = ((uint16_t)bus_read(0xFFFE) & 0x00FF);
    my_cpu->PC += (((uint16_t)bus_read(0xFFFE + 1) << 8) & 0xFF00);

    clk = 7;
}
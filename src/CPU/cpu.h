/*
 * Anotações para a elaboração da CPU
 * 
 * CPUStart() vai iniciar a CPU, criando a tabela e chamando o reset entre outras coisas
 * 
 * 
 * 
 */

#ifndef _H_CPU
#define _H_CPU
#include<stdint.h>


enum FLAGSCPU {
    N = (1 << 7),       // Negative
    V = (1 << 6),       //Overflow
    _ = (1 << 5),       //ignored
    B = (1 << 4),       //Break
    D = (1 << 3),       //Decimal (use BCD for arithmetics)
    I = (1 << 2),       //Interrupt (IRQ disable)
    Z = (1 << 1),       //Zero
    C = (1 << 0)       //Carry
};

enum ESTADO{
    PC,
    OP
};



struct {
    // Registradores existentes na própria CPU
    uint16_t PC;    // program counter	(16 bit)
    uint8_t AC;     // accumulator	(8 bit)
    uint8_t X;      // X register	(8 bit)
    uint8_t Y;      // Y register	(8 bit)
    uint8_t SR;     // status register [NV-BDIZC]	(8 bit)
    uint8_t SP;     // stack pointer	(8 bit)

    // Registradores utilizados para o funcionamento da emulação da CPU
    uint8_t clk;
    uint16_t addrs;         // Vou mudar a forma que a CPU usa o endereço
                            // Mas manter isso aqui apenas caso me arrependa
    uint8_t opcode;         // Para salvar qual é a instrução em execução
                            // pode ser útil na hora de programar instruções proibidas
}typedef CPU_6502;

CPU_6502* CPUStart();

int CPUStop(CPU_6502*);

int CPUClock(CPU_6502*);

void reset(CPU_6502*);
 
uint8_t SetFlag(enum FLAGSCPU, CPU_6502*, int);

uint8_t GetFlag(enum FLAGSCPU, CPU_6502*);

// Funções de interrupção

void irq(CPU_6502*);
void nmi(CPU_6502*);

#endif
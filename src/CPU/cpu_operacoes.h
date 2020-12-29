#ifndef CPU_OPERACOES
#define CPU_OPERACOES

#include <stdint.h>

#include "cpu.h"

struct opcode {
    uint8_t (*mF)(CPU_6502*, uint16_t*);
    uint8_t (*oF)(CPU_6502*, uint16_t);
    uint8_t ck;
}typedef opcode;

uint8_t fetch(uint16_t);

void criaOpcodeLista(opcode*);

// Funções para trabalhar com acesso a memória

uint8_t IMP(CPU_6502*, uint16_t*);	uint8_t IMM(CPU_6502*, uint16_t*);	
uint8_t ZP0(CPU_6502*, uint16_t*);	uint8_t ZPX(CPU_6502*, uint16_t*);	
uint8_t ZPY(CPU_6502*, uint16_t*);	uint8_t REL(CPU_6502*, uint16_t*);
uint8_t ABS(CPU_6502*, uint16_t*);	uint8_t ABX(CPU_6502*, uint16_t*);	
uint8_t ABY(CPU_6502*, uint16_t*);	uint8_t IND(CPU_6502*, uint16_t*);	
uint8_t IZX(CPU_6502*, uint16_t*);	uint8_t IZY(CPU_6502*, uint16_t*);

// Códigos de operações

uint8_t ADC(CPU_6502*, uint16_t);	uint8_t AND(CPU_6502*, uint16_t);	uint8_t ASL(CPU_6502*, uint16_t);	uint8_t BCC(CPU_6502*, uint16_t);
uint8_t BCS(CPU_6502*, uint16_t);	uint8_t BEQ(CPU_6502*, uint16_t);	uint8_t BIT(CPU_6502*, uint16_t);	uint8_t BMI(CPU_6502*, uint16_t);
uint8_t BNE(CPU_6502*, uint16_t);	uint8_t BPL(CPU_6502*, uint16_t);	uint8_t BRK(CPU_6502*, uint16_t);	uint8_t BVC(CPU_6502*, uint16_t);
uint8_t BVS(CPU_6502*, uint16_t);	uint8_t CLC(CPU_6502*, uint16_t);	uint8_t CLD(CPU_6502*, uint16_t);	uint8_t CLI(CPU_6502*, uint16_t);
uint8_t CLV(CPU_6502*, uint16_t);	uint8_t CMP(CPU_6502*, uint16_t);	uint8_t CPX(CPU_6502*, uint16_t);	uint8_t CPY(CPU_6502*, uint16_t);
uint8_t DEC(CPU_6502*, uint16_t);	uint8_t DEX(CPU_6502*, uint16_t);	uint8_t DEY(CPU_6502*, uint16_t);	uint8_t EOR(CPU_6502*, uint16_t);
uint8_t INC(CPU_6502*, uint16_t);	uint8_t INX(CPU_6502*, uint16_t);	uint8_t INY(CPU_6502*, uint16_t);	uint8_t JMP(CPU_6502*, uint16_t);
uint8_t JSR(CPU_6502*, uint16_t);	uint8_t LDA(CPU_6502*, uint16_t);	uint8_t LDX(CPU_6502*, uint16_t);	uint8_t LDY(CPU_6502*, uint16_t);
uint8_t LSR(CPU_6502*, uint16_t);	uint8_t NOP(CPU_6502*, uint16_t);	uint8_t ORA(CPU_6502*, uint16_t);	uint8_t PHA(CPU_6502*, uint16_t);
uint8_t PHP(CPU_6502*, uint16_t);	uint8_t PLA(CPU_6502*, uint16_t);	uint8_t PLP(CPU_6502*, uint16_t);	uint8_t ROL(CPU_6502*, uint16_t);
uint8_t ROR(CPU_6502*, uint16_t);	uint8_t RTI(CPU_6502*, uint16_t);	uint8_t RTS(CPU_6502*, uint16_t);	uint8_t SBC(CPU_6502*, uint16_t);
uint8_t SEC(CPU_6502*, uint16_t);	uint8_t SED(CPU_6502*, uint16_t);	uint8_t SEI(CPU_6502*, uint16_t);	uint8_t STA(CPU_6502*, uint16_t);
uint8_t STX(CPU_6502*, uint16_t);	uint8_t STY(CPU_6502*, uint16_t);	uint8_t TAX(CPU_6502*, uint16_t);	uint8_t TAY(CPU_6502*, uint16_t);
uint8_t TSX(CPU_6502*, uint16_t);	uint8_t TXA(CPU_6502*, uint16_t);	uint8_t TXS(CPU_6502*, uint16_t);	uint8_t TYA(CPU_6502*, uint16_t);

uint8_t XXX(CPU_6502*, uint16_t);

#endif
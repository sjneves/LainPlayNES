#include <stdio.h>
#include <stdint.h>

#include "CPU/cpu.h"
#include "BUS/bus.h"
#include "CARTUCHO/cartucho.h"

int main(int argv, char **args){
    CPU_6502 *cpu = CPUStart();

    if(argv>1){
        inserirCartucho(args[1]);
    }else{
        inserirCartucho("ROMs/Super-Mario-Bros.-World.nes");
        inserirCartucho("ROMs/Legend of Zelda, The (U) (PRG1) [!].nes");
        inserirCartucho("ROMs/Street Fighter 3.nes");
    }

    printf("1: Test Mapper CPU %x\n",CPUromRead(0x002A));
    printf("2: Test Mapper CPU %x\n",CPUromRead(0x402A));
    printf("1: Test Mapper PPU %x\n",PPUromRead(0x002A));

    CPUStop(cpu);
    return 0;
}

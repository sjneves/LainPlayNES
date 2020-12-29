#include <stdio.h>
#include <stdint.h>

#include "CPU/cpu.h"
#include "BUS/bus.h"
#include "CARTUCHO/cartucho.h"

int main(int argv, char **args){
    char *arquivo;
    if(argv>1){
        arquivo = args[1];
    }else{
        printf("Especificar o caminho até uma ROM! \n./exec [ROM]\n");
        return 1;
    }
    System *pNES = newNES();
    pNES->cartucho = inserirCartucho(arquivo);

    closeNES(pNES);
    return 0;
}

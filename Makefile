GCC = gcc
GCC-Flags = -Wall -g -c -o
GPP = g++

Libs = 	src/CPU/cpu.h	\
		src/CPU/cpu.c

main: cpu_operacoes.o cpu.o main.o bus.o ppu.o cartucho.o
	@ echo 'Linkando tudo'
	@ $(GCC) cpu_operacoes.o cpu.o main.o bus.o ppu.o cartucho.o -g -o exec
	@ rm -rf *.o

main.o : src/main.c
	@ echo 'Gerando o MAIN objeto'
	@ $(GCC) src/main.c $(GCC-Flags) main.o

cpu.o : src/CPU/cpu.c
	@ echo 'Construindo a CPU'
	@ $(GCC) src/CPU/cpu.c $(GCC-Flags) cpu.o 

bus.o : src/BUS/bus.c
	@ echo 'Gerando o BUS'
	@ $(GCC) $< $(GCC-Flags) $@

cpu_operacoes.o : src/CPU/cpu_operacoes.c
	@ echo 'Gerando cpu_operacoes'
	@ $(GCC) $< $(GCC-Flags) $@

ppu.o : src/PPU/ppu.c
	@ echo 'Gerando a PPU'
	@ $(GCC) $< $(GCC-Flags) $@

cartucho.o : src/CARTUCHO/cartucho.c
	@ echo 'Gerando o Cartucho'
	@ $(GCC) $< $(GCC-Flags) $@

clean:
	@ rm exec
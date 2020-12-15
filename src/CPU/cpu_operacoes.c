#include "cpu_operacoes.h"
#include "cpu.h"
#include "../BUS/bus.h"

uint8_t impFlag = 0;

uint8_t *ptr_clk;

uint8_t fetch(uint16_t addrs){
    uint8_t fetched = 0x00;
    // fetched = bus_read(addrs);
    impFlag = 0;
    return fetched;
}

void criaOpcodeLista(opcode *oL, uint8_t *rec_clk){
    ptr_clk = rec_clk;

    oL[0x00].oF = BRK; oL[0x00].mF = IMP; oL[0x00].ck = 7; oL[0x10].oF = ORA; oL[0x10].mF = IZX; oL[0x10].ck = 6; oL[0x20].oF = XXX; oL[0x20].mF = IMP; oL[0x20].ck = 2; oL[0x30].oF = XXX; oL[0x30].mF = IMP; oL[0x30].ck = 8;
    oL[0x01].oF = BPL; oL[0x01].mF = REL; oL[0x01].ck = 2; oL[0x11].oF = ORA; oL[0x11].mF = IZY; oL[0x11].ck = 5; oL[0x21].oF = XXX; oL[0x21].mF = IMP; oL[0x21].ck = 2; oL[0x31].oF = XXX; oL[0x31].mF = IMP; oL[0x31].ck = 8;
    oL[0x02].oF = JSR; oL[0x02].mF = ABS; oL[0x02].ck = 6; oL[0x12].oF = AND; oL[0x12].mF = IZX; oL[0x12].ck = 6; oL[0x22].oF = XXX; oL[0x22].mF = IMP; oL[0x22].ck = 2; oL[0x32].oF = XXX; oL[0x32].mF = IMP; oL[0x32].ck = 8;
    oL[0x03].oF = BMI; oL[0x03].mF = REL; oL[0x03].ck = 2; oL[0x13].oF = AND; oL[0x13].mF = IZY; oL[0x13].ck = 5; oL[0x23].oF = XXX; oL[0x23].mF = IMP; oL[0x23].ck = 2; oL[0x33].oF = XXX; oL[0x33].mF = IMP; oL[0x33].ck = 8;
    oL[0x04].oF = RTI; oL[0x04].mF = IMP; oL[0x04].ck = 6; oL[0x14].oF = EOR; oL[0x14].mF = IZX; oL[0x14].ck = 6; oL[0x24].oF = XXX; oL[0x24].mF = IMP; oL[0x24].ck = 2; oL[0x34].oF = XXX; oL[0x34].mF = IMP; oL[0x34].ck = 8;
    oL[0x05].oF = BVC; oL[0x05].mF = REL; oL[0x05].ck = 2; oL[0x15].oF = EOR; oL[0x15].mF = IZY; oL[0x15].ck = 5; oL[0x25].oF = XXX; oL[0x25].mF = IMP; oL[0x25].ck = 2; oL[0x35].oF = XXX; oL[0x35].mF = IMP; oL[0x35].ck = 8;
    oL[0x06].oF = RTS; oL[0x06].mF = IMP; oL[0x06].ck = 6; oL[0x16].oF = ADC; oL[0x16].mF = IZX; oL[0x16].ck = 6; oL[0x26].oF = XXX; oL[0x26].mF = IMP; oL[0x26].ck = 2; oL[0x36].oF = XXX; oL[0x36].mF = IMP; oL[0x36].ck = 8;
    oL[0x07].oF = BVS; oL[0x07].mF = REL; oL[0x07].ck = 2; oL[0x17].oF = ADC; oL[0x17].mF = IZY; oL[0x17].ck = 5; oL[0x27].oF = XXX; oL[0x27].mF = IMP; oL[0x27].ck = 2; oL[0x37].oF = XXX; oL[0x37].mF = IMP; oL[0x37].ck = 8;
    oL[0x08].oF = NOP; oL[0x08].mF = IMP; oL[0x08].ck = 2; oL[0x18].oF = STA; oL[0x18].mF = IZX; oL[0x18].ck = 6; oL[0x28].oF = NOP; oL[0x28].mF = IMP; oL[0x28].ck = 2; oL[0x38].oF = XXX; oL[0x38].mF = IMP; oL[0x38].ck = 6;
    oL[0x09].oF = BCC; oL[0x09].mF = REL; oL[0x09].ck = 2; oL[0x19].oF = STA; oL[0x19].mF = IZY; oL[0x19].ck = 6; oL[0x29].oF = XXX; oL[0x29].mF = IMP; oL[0x29].ck = 2; oL[0x39].oF = XXX; oL[0x39].mF = IMP; oL[0x39].ck = 6;
    oL[0x0A].oF = LDY; oL[0x0A].mF = IMM; oL[0x0A].ck = 2; oL[0x1A].oF = LDA; oL[0x1A].mF = IZX; oL[0x1A].ck = 6; oL[0x2A].oF = LDX; oL[0x2A].mF = IMM; oL[0x2A].ck = 2; oL[0x3A].oF = XXX; oL[0x3A].mF = IMP; oL[0x3A].ck = 6;
    oL[0x0B].oF = BCS; oL[0x0B].mF = REL; oL[0x0B].ck = 2; oL[0x1B].oF = LDA; oL[0x1B].mF = IZY; oL[0x1B].ck = 5; oL[0x2B].oF = XXX; oL[0x2B].mF = IMP; oL[0x2B].ck = 2; oL[0x3B].oF = XXX; oL[0x3B].mF = IMP; oL[0x3B].ck = 5;
    oL[0x0C].oF = CPY; oL[0x0C].mF = IMM; oL[0x0C].ck = 2; oL[0x1C].oF = CMP; oL[0x1C].mF = IZX; oL[0x1C].ck = 6; oL[0x2C].oF = NOP; oL[0x2C].mF = IMP; oL[0x2C].ck = 2; oL[0x3C].oF = XXX; oL[0x3C].mF = IMP; oL[0x3C].ck = 8;
    oL[0x0D].oF = BNE; oL[0x0D].mF = REL; oL[0x0D].ck = 2; oL[0x1D].oF = CMP; oL[0x1D].mF = IZY; oL[0x1D].ck = 5; oL[0x2D].oF = XXX; oL[0x2D].mF = IMP; oL[0x2D].ck = 2; oL[0x3D].oF = XXX; oL[0x3D].mF = IMP; oL[0x3D].ck = 8;
    oL[0x0E].oF = CPX; oL[0x0E].mF = IMM; oL[0x0E].ck = 2; oL[0x1E].oF = SBC; oL[0x1E].mF = IZX; oL[0x1E].ck = 6; oL[0x2E].oF = NOP; oL[0x2E].mF = IMP; oL[0x2E].ck = 2; oL[0x3E].oF = XXX; oL[0x3E].mF = IMP; oL[0x3E].ck = 8;
    oL[0x0F].oF = BEQ; oL[0x0F].mF = REL; oL[0x0F].ck = 2; oL[0x1F].oF = SBC; oL[0x1F].mF = IZY; oL[0x1F].ck = 5; oL[0x2F].oF = XXX; oL[0x2F].mF = IMP; oL[0x2F].ck = 2; oL[0x3F].oF = XXX; oL[0x3F].mF = IMP; oL[0x3F].ck = 8;
	
    //---------------------------------------------------------------------------------------------------------------------------------------------------------

    oL[0x40].oF = NOP; oL[0x40].mF = IMP; oL[0x40].ck = 3; oL[0x50].oF = ORA; oL[0x50].mF = ZP0; oL[0x50].ck = 3; oL[0x60].oF = ASL; oL[0x60].mF = ZP0; oL[0x60].ck = 5;
    oL[0x41].oF = NOP; oL[0x41].mF = IMP; oL[0x41].ck = 4; oL[0x51].oF = ORA; oL[0x51].mF = ZPX; oL[0x51].ck = 4; oL[0x61].oF = ASL; oL[0x61].mF = ZPX; oL[0x61].ck = 6;
    oL[0x42].oF = BIT; oL[0x42].mF = ZP0; oL[0x42].ck = 3; oL[0x52].oF = AND; oL[0x52].mF = ZP0; oL[0x52].ck = 3; oL[0x62].oF = ROL; oL[0x62].mF = ZP0; oL[0x62].ck = 5;
    oL[0x43].oF = NOP; oL[0x43].mF = IMP; oL[0x43].ck = 4; oL[0x53].oF = AND; oL[0x53].mF = ZPX; oL[0x53].ck = 4; oL[0x63].oF = ROL; oL[0x63].mF = ZPX; oL[0x63].ck = 6;
    oL[0x44].oF = NOP; oL[0x44].mF = IMP; oL[0x44].ck = 3; oL[0x54].oF = EOR; oL[0x54].mF = ZP0; oL[0x54].ck = 3; oL[0x64].oF = LSR; oL[0x64].mF = ZP0; oL[0x64].ck = 5;
    oL[0x45].oF = NOP; oL[0x45].mF = IMP; oL[0x45].ck = 4; oL[0x55].oF = EOR; oL[0x55].mF = ZPX; oL[0x55].ck = 4; oL[0x65].oF = LSR; oL[0x65].mF = ZPX; oL[0x65].ck = 6;
    oL[0x46].oF = NOP; oL[0x46].mF = IMP; oL[0x46].ck = 3; oL[0x56].oF = ADC; oL[0x56].mF = ZP0; oL[0x56].ck = 3; oL[0x66].oF = ROR; oL[0x66].mF = ZP0; oL[0x66].ck = 5;
    oL[0x47].oF = NOP; oL[0x47].mF = IMP; oL[0x47].ck = 4; oL[0x57].oF = ADC; oL[0x57].mF = ZPX; oL[0x57].ck = 4; oL[0x67].oF = ROR; oL[0x67].mF = ZPX; oL[0x67].ck = 6;
    oL[0x48].oF = STY; oL[0x48].mF = ZP0; oL[0x48].ck = 3; oL[0x58].oF = STA; oL[0x58].mF = ZP0; oL[0x58].ck = 3; oL[0x68].oF = STX; oL[0x68].mF = ZP0; oL[0x68].ck = 3;
    oL[0x49].oF = STY; oL[0x49].mF = ZPX; oL[0x49].ck = 4; oL[0x59].oF = STA; oL[0x59].mF = ZPX; oL[0x59].ck = 4; oL[0x69].oF = STX; oL[0x69].mF = ZPY; oL[0x69].ck = 4;
    oL[0x4A].oF = LDY; oL[0x4A].mF = ZP0; oL[0x4A].ck = 3; oL[0x5A].oF = LDA; oL[0x5A].mF = ZP0; oL[0x5A].ck = 3; oL[0x6A].oF = LDX; oL[0x6A].mF = ZP0; oL[0x6A].ck = 3;
    oL[0x4B].oF = LDY; oL[0x4B].mF = ZPX; oL[0x4B].ck = 4; oL[0x5B].oF = LDA; oL[0x5B].mF = ZPX; oL[0x5B].ck = 4; oL[0x6B].oF = LDX; oL[0x6B].mF = ZPY; oL[0x6B].ck = 4;
    oL[0x4C].oF = CPY; oL[0x4C].mF = ZP0; oL[0x4C].ck = 3; oL[0x5C].oF = CMP; oL[0x5C].mF = ZP0; oL[0x5C].ck = 3; oL[0x6C].oF = DEC; oL[0x6C].mF = ZP0; oL[0x6C].ck = 5;
    oL[0x4D].oF = NOP; oL[0x4D].mF = IMP; oL[0x4D].ck = 4; oL[0x5D].oF = CMP; oL[0x5D].mF = ZPX; oL[0x5D].ck = 4; oL[0x6D].oF = DEC; oL[0x6D].mF = ZPX; oL[0x6D].ck = 6;
    oL[0x4E].oF = CPX; oL[0x4E].mF = ZP0; oL[0x4E].ck = 3; oL[0x5E].oF = SBC; oL[0x5E].mF = ZP0; oL[0x5E].ck = 3; oL[0x6E].oF = INC; oL[0x6E].mF = ZP0; oL[0x6E].ck = 5;
    oL[0x4F].oF = NOP; oL[0x4F].mF = IMP; oL[0x4F].ck = 4; oL[0x5F].oF = SBC; oL[0x5F].mF = ZPX; oL[0x5F].ck = 4; oL[0x6F].oF = INC; oL[0x6F].mF = ZPX; oL[0x6F].ck = 6;

    //---------------------------------------------------------------------------------------------------------------------------------------------------------

    oL[0x70].oF = XXX; oL[0x70].mF = IMP; oL[0x70].ck = 5; oL[0x80].oF = PHP; oL[0x80].mF = IMP; oL[0x80].ck = 3; oL[0x90].oF = ORA; oL[0x90].mF = IMM; oL[0x90].ck = 2;
    oL[0x71].oF = XXX; oL[0x71].mF = IMP; oL[0x71].ck = 6; oL[0x81].oF = CLC; oL[0x81].mF = IMP; oL[0x81].ck = 2; oL[0x91].oF = ORA; oL[0x91].mF = ABY; oL[0x91].ck = 4;
    oL[0x72].oF = XXX; oL[0x72].mF = IMP; oL[0x72].ck = 5; oL[0x82].oF = PLP; oL[0x82].mF = IMP; oL[0x82].ck = 4; oL[0x92].oF = AND; oL[0x92].mF = IMM; oL[0x92].ck = 2;
    oL[0x73].oF = XXX; oL[0x73].mF = IMP; oL[0x73].ck = 6; oL[0x83].oF = SEC; oL[0x83].mF = IMP; oL[0x83].ck = 2; oL[0x93].oF = AND; oL[0x93].mF = ABY; oL[0x93].ck = 4;
    oL[0x74].oF = XXX; oL[0x74].mF = IMP; oL[0x74].ck = 5; oL[0x84].oF = PHA; oL[0x84].mF = IMP; oL[0x84].ck = 3; oL[0x94].oF = EOR; oL[0x94].mF = IMM; oL[0x94].ck = 2;
    oL[0x75].oF = XXX; oL[0x75].mF = IMP; oL[0x75].ck = 6; oL[0x85].oF = CLI; oL[0x85].mF = IMP; oL[0x85].ck = 2; oL[0x95].oF = EOR; oL[0x95].mF = ABY; oL[0x95].ck = 4;
    oL[0x76].oF = XXX; oL[0x76].mF = IMP; oL[0x76].ck = 5; oL[0x86].oF = PLA; oL[0x86].mF = IMP; oL[0x86].ck = 4; oL[0x96].oF = ADC; oL[0x96].mF = IMM; oL[0x96].ck = 2;
    oL[0x77].oF = XXX; oL[0x77].mF = IMP; oL[0x77].ck = 6; oL[0x87].oF = SEI; oL[0x87].mF = IMP; oL[0x87].ck = 2; oL[0x97].oF = ADC; oL[0x97].mF = ABY; oL[0x97].ck = 4;
    oL[0x78].oF = XXX; oL[0x78].mF = IMP; oL[0x78].ck = 3; oL[0x88].oF = DEY; oL[0x88].mF = IMP; oL[0x88].ck = 2; oL[0x98].oF = NOP; oL[0x98].mF = IMP; oL[0x98].ck = 2;
    oL[0x79].oF = XXX; oL[0x79].mF = IMP; oL[0x79].ck = 4; oL[0x89].oF = TYA; oL[0x89].mF = IMP; oL[0x89].ck = 2; oL[0x99].oF = STA; oL[0x99].mF = ABY; oL[0x99].ck = 5;
    oL[0x7A].oF = XXX; oL[0x7A].mF = IMP; oL[0x7A].ck = 3; oL[0x8A].oF = TAY; oL[0x8A].mF = IMP; oL[0x8A].ck = 2; oL[0x9A].oF = LDA; oL[0x9A].mF = IMM; oL[0x9A].ck = 2;
    oL[0x7B].oF = XXX; oL[0x7B].mF = IMP; oL[0x7B].ck = 4; oL[0x8B].oF = CLV; oL[0x8B].mF = IMP; oL[0x8B].ck = 2; oL[0x9B].oF = LDA; oL[0x9B].mF = ABY; oL[0x9B].ck = 4;
    oL[0x7C].oF = XXX; oL[0x7C].mF = IMP; oL[0x7C].ck = 5; oL[0x8C].oF = INY; oL[0x8C].mF = IMP; oL[0x8C].ck = 2; oL[0x9C].oF = CMP; oL[0x9C].mF = IMM; oL[0x9C].ck = 2;
    oL[0x7D].oF = XXX; oL[0x7D].mF = IMP; oL[0x7D].ck = 6; oL[0x8D].oF = CLD; oL[0x8D].mF = IMP; oL[0x8D].ck = 2; oL[0x9D].oF = CMP; oL[0x9D].mF = ABY; oL[0x9D].ck = 4;
    oL[0x7E].oF = XXX; oL[0x7E].mF = IMP; oL[0x7E].ck = 5; oL[0x8E].oF = INX; oL[0x8E].mF = IMP; oL[0x8E].ck = 2; oL[0x9E].oF = SBC; oL[0x9E].mF = IMM; oL[0x9E].ck = 2;
    oL[0x7F].oF = XXX; oL[0x7F].mF = IMP; oL[0x7F].ck = 6; oL[0x8F].oF = SED; oL[0x8F].mF = IMP; oL[0x8F].ck = 2; oL[0x9F].oF = SBC; oL[0x9F].mF = ABY; oL[0x9F].ck = 4;

    //---------------------------------------------------------------------------------------------------------------------------------------------------------

    oL[0xA0].oF = ASL; oL[0xA0].mF = IMP; oL[0xA0].ck = 2; oL[0xB0].oF = XXX; oL[0xB0].mF = IMP; oL[0xB0].ck = 2; oL[0xC0].oF = NOP; oL[0xC0].mF = IMP; oL[0xC0].ck = 4;
    oL[0xA1].oF = NOP; oL[0xA1].mF = IMP; oL[0xA1].ck = 2; oL[0xB1].oF = XXX; oL[0xB1].mF = IMP; oL[0xB1].ck = 7; oL[0xC1].oF = NOP; oL[0xC1].mF = IMP; oL[0xC1].ck = 4;
    oL[0xA2].oF = ROL; oL[0xA2].mF = IMP; oL[0xA2].ck = 2; oL[0xB2].oF = XXX; oL[0xB2].mF = IMP; oL[0xB2].ck = 2; oL[0xC2].oF = BIT; oL[0xC2].mF = ABS; oL[0xC2].ck = 4;
    oL[0xA3].oF = NOP; oL[0xA3].mF = IMP; oL[0xA3].ck = 2; oL[0xB3].oF = XXX; oL[0xB3].mF = IMP; oL[0xB3].ck = 7; oL[0xC3].oF = NOP; oL[0xC3].mF = IMP; oL[0xC3].ck = 4;
    oL[0xA4].oF = LSR; oL[0xA4].mF = IMP; oL[0xA4].ck = 2; oL[0xB4].oF = XXX; oL[0xB4].mF = IMP; oL[0xB4].ck = 2; oL[0xC4].oF = JMP; oL[0xC4].mF = ABS; oL[0xC4].ck = 3;
    oL[0xA5].oF = NOP; oL[0xA5].mF = IMP; oL[0xA5].ck = 2; oL[0xB5].oF = XXX; oL[0xB5].mF = IMP; oL[0xB5].ck = 7; oL[0xC5].oF = NOP; oL[0xC5].mF = IMP; oL[0xC5].ck = 4;
    oL[0xA6].oF = ROR; oL[0xA6].mF = IMP; oL[0xA6].ck = 2; oL[0xB6].oF = XXX; oL[0xB6].mF = IMP; oL[0xB6].ck = 2; oL[0xC6].oF = JMP; oL[0xC6].mF = IND; oL[0xC6].ck = 5;
    oL[0xA7].oF = NOP; oL[0xA7].mF = IMP; oL[0xA7].ck = 2; oL[0xB7].oF = XXX; oL[0xB7].mF = IMP; oL[0xB7].ck = 7; oL[0xC7].oF = NOP; oL[0xC7].mF = IMP; oL[0xC7].ck = 4;
    oL[0xA8].oF = TXA; oL[0xA8].mF = IMP; oL[0xA8].ck = 2; oL[0xB8].oF = XXX; oL[0xB8].mF = IMP; oL[0xB8].ck = 2; oL[0xC8].oF = STY; oL[0xC8].mF = ABS; oL[0xC8].ck = 4;
    oL[0xA9].oF = TXS; oL[0xA9].mF = IMP; oL[0xA9].ck = 2; oL[0xB9].oF = XXX; oL[0xB9].mF = IMP; oL[0xB9].ck = 5; oL[0xC9].oF = NOP; oL[0xC9].mF = IMP; oL[0xC9].ck = 5;
    oL[0xAA].oF = TAX; oL[0xAA].mF = IMP; oL[0xAA].ck = 2; oL[0xBA].oF = XXX; oL[0xBA].mF = IMP; oL[0xBA].ck = 2; oL[0xCA].oF = LDY; oL[0xCA].mF = ABS; oL[0xCA].ck = 4;
    oL[0xAB].oF = TSX; oL[0xAB].mF = IMP; oL[0xAB].ck = 2; oL[0xBB].oF = XXX; oL[0xBB].mF = IMP; oL[0xBB].ck = 4; oL[0xCB].oF = LDY; oL[0xCB].mF = ABX; oL[0xCB].ck = 4;
    oL[0xAC].oF = DEX; oL[0xAC].mF = IMP; oL[0xAC].ck = 2; oL[0xBC].oF = XXX; oL[0xBC].mF = IMP; oL[0xBC].ck = 2; oL[0xCC].oF = CPY; oL[0xCC].mF = ABS; oL[0xCC].ck = 4;
    oL[0xAD].oF = NOP; oL[0xAD].mF = IMP; oL[0xAD].ck = 2; oL[0xBD].oF = XXX; oL[0xBD].mF = IMP; oL[0xBD].ck = 7; oL[0xCD].oF = NOP; oL[0xCD].mF = IMP; oL[0xCD].ck = 4;
    oL[0xAE].oF = NOP; oL[0xAE].mF = IMP; oL[0xAE].ck = 2; oL[0xBE].oF = SBC; oL[0xBE].mF = IMP; oL[0xBE].ck = 2; oL[0xCE].oF = CPX; oL[0xCE].mF = ABS; oL[0xCE].ck = 4;
    oL[0xAF].oF = NOP; oL[0xAF].mF = IMP; oL[0xAF].ck = 2; oL[0xBF].oF = XXX; oL[0xBF].mF = IMP; oL[0xBF].ck = 7; oL[0xCF].oF = NOP; oL[0xCF].mF = IMP; oL[0xCF].ck = 4;

    //---------------------------------------------------------------------------------------------------------------------------------------------------------

    oL[0xD0].oF = ORA; oL[0xD0].mF = ABS; oL[0xD0].ck = 4; oL[0xE0].oF = ASL; oL[0xE0].mF = ABS; oL[0xE0].ck = 6; oL[0xF0].oF = XXX; oL[0xF0].mF = IMP; oL[0xF0].ck = 6;
    oL[0xD1].oF = ORA; oL[0xD1].mF = ABX; oL[0xD1].ck = 4; oL[0xE1].oF = ASL; oL[0xE1].mF = ABX; oL[0xE1].ck = 7; oL[0xF1].oF = XXX; oL[0xF1].mF = IMP; oL[0xF1].ck = 7;
    oL[0xD2].oF = AND; oL[0xD2].mF = ABS; oL[0xD2].ck = 4; oL[0xE2].oF = ROL; oL[0xE2].mF = ABS; oL[0xE2].ck = 6; oL[0xF2].oF = XXX; oL[0xF2].mF = IMP; oL[0xF2].ck = 6;
    oL[0xD3].oF = AND; oL[0xD3].mF = ABX; oL[0xD3].ck = 4; oL[0xE3].oF = ROL; oL[0xE3].mF = ABX; oL[0xE3].ck = 7; oL[0xF3].oF = XXX; oL[0xF3].mF = IMP; oL[0xF3].ck = 7;
    oL[0xD4].oF = EOR; oL[0xD4].mF = ABS; oL[0xD4].ck = 4; oL[0xE4].oF = LSR; oL[0xE4].mF = ABS; oL[0xE4].ck = 6; oL[0xF4].oF = XXX; oL[0xF4].mF = IMP; oL[0xF4].ck = 6;
    oL[0xD5].oF = EOR; oL[0xD5].mF = ABX; oL[0xD5].ck = 4; oL[0xE5].oF = LSR; oL[0xE5].mF = ABX; oL[0xE5].ck = 7; oL[0xF5].oF = XXX; oL[0xF5].mF = IMP; oL[0xF5].ck = 7;
    oL[0xD6].oF = ADC; oL[0xD6].mF = ABS; oL[0xD6].ck = 4; oL[0xE6].oF = ROR; oL[0xE6].mF = ABS; oL[0xE6].ck = 6; oL[0xF6].oF = XXX; oL[0xF6].mF = IMP; oL[0xF6].ck = 6;
    oL[0xD7].oF = ADC; oL[0xD7].mF = ABX; oL[0xD7].ck = 4; oL[0xE7].oF = ROR; oL[0xE7].mF = ABX; oL[0xE7].ck = 7; oL[0xF7].oF = XXX; oL[0xF7].mF = IMP; oL[0xF7].ck = 7;
    oL[0xD8].oF = STA; oL[0xD8].mF = ABS; oL[0xD8].ck = 5; oL[0xE8].oF = STX; oL[0xE8].mF = ABS; oL[0xE8].ck = 4; oL[0xF8].oF = XXX; oL[0xF8].mF = IMP; oL[0xF8].ck = 4;
    oL[0xD9].oF = STA; oL[0xD9].mF = ABX; oL[0xD9].ck = 4; oL[0xE9].oF = XXX; oL[0xE9].mF = IMP; oL[0xE9].ck = 5; oL[0xF9].oF = XXX; oL[0xF9].mF = IMP; oL[0xF9].ck = 5;
    oL[0xDA].oF = LDA; oL[0xDA].mF = ABS; oL[0xDA].ck = 4; oL[0xEA].oF = LDX; oL[0xEA].mF = ABS; oL[0xEA].ck = 4; oL[0xFA].oF = XXX; oL[0xFA].mF = IMP; oL[0xFA].ck = 4;
    oL[0xDB].oF = LDA; oL[0xDB].mF = ABX; oL[0xDB].ck = 4; oL[0xEB].oF = LDX; oL[0xEB].mF = ABY; oL[0xEB].ck = 4; oL[0xFB].oF = XXX; oL[0xFB].mF = IMP; oL[0xFB].ck = 4;
    oL[0xDC].oF = CMP; oL[0xDC].mF = ABS; oL[0xDC].ck = 4; oL[0xEC].oF = DEC; oL[0xEC].mF = ABS; oL[0xEC].ck = 6; oL[0xFC].oF = XXX; oL[0xFC].mF = IMP; oL[0xFC].ck = 6;
    oL[0xDD].oF = CMP; oL[0xDD].mF = ABX; oL[0xDD].ck = 4; oL[0xED].oF = DEC; oL[0xED].mF = ABX; oL[0xED].ck = 7; oL[0xFD].oF = XXX; oL[0xFD].mF = IMP; oL[0xFD].ck = 7;
    oL[0xDE].oF = SBC; oL[0xDE].mF = ABS; oL[0xDE].ck = 4; oL[0xEE].oF = INC; oL[0xEE].mF = ABS; oL[0xEE].ck = 6; oL[0xFE].oF = XXX; oL[0xFE].mF = IMP; oL[0xFE].ck = 6;
    oL[0xDF].oF = SBC; oL[0xDF].mF = ABX; oL[0xDF].ck = 4; oL[0xEF].oF = INC; oL[0xEF].mF = ABX; oL[0xEF].ck = 7; oL[0xFF].oF = XXX; oL[0xFF].mF = IMP; oL[0xFF].ck = 7;
}

// Acesso e da memória

// Não faz nada ??
// Sim ela não faz nada no sentido de transferência de dados,
// entretanto IMP tb significa uma operação com o acumulador
// então fetch = a ...
// Ainda tenho q pensar em como vou implementar isso, sem ter q
// sair fazendo um monte de gambs.
// Ela é usada quando a operação chamada não faz fatch da memória
uint8_t IMP(CPU_6502 *MyCPU, uint16_t *addrs){
    impFlag = 1;
    return 0;
}

// Significa que o meu endereço de memória de interesse é o
// proximo endereço de memória
// Ou sejá ele só lê o próximo endereço
uint8_t IMM(CPU_6502 *MyCPU, uint16_t *addrs){
    return ++MyCPU->PC;
}

// Significa que o meu endereço de memória de interesse está em
// algum lugar da página 0
// Conceito de página:
// O endereço é definido no seguinte formato 0xYY XX
// Neste caso o YY representa a página e o XX o endereço da 
// informação na página
// Na chamada do ZeroPage (é esse o nome), o endereço da informação
// é a página zero então começa com 0x00xx e o xx é definido pela 
// informação no PC
uint8_t ZP0(CPU_6502 *MyCPU, uint16_t *addrs){
    uint16_t addrs_abs;
    addrs_abs = bus_read(MyCPU->PC);
    MyCPU->PC++;

    addrs_abs &= 0x00FF;

    *addrs = addrs_abs;
    return 0;
}

// ZeroPage adressing with X offset
// Acho q foi assim q ele falou...
// Aqui o endereço de interesse está deslocado do PC o número que
// está armazenado no registrador X
// "É TIPO" eu tenho um array e quero acessar o elemento X dele
// então vou contar x posições a partir do primeiro endereço do 
// array
uint8_t ZPX(CPU_6502 *MyCPU, uint16_t *addrs){
    
    *addrs = bus_read(MyCPU->PC + MyCPU->X);
    MyCPU->PC++;

    *addrs &= 0x00FF;
    return 0;
}

// Da mesma forma que o anterior, mas agora com o registrador Y
uint8_t ZPY(CPU_6502 *MyCPU, uint16_t *addrs){
    
    *addrs = bus_read(MyCPU->PC + MyCPU->Y);
    MyCPU->PC++;

    *addrs &= 0x00FF;
    return 0;
}

// Não foi explicado no decorrer do vídeo
// É usado em funções de branch
uint8_t REL(CPU_6502 *MyCPU, uint16_t *addrs){
    
    // *addrs = bus_read(MyCPU->PC);
    MyCPU->PC++;

    if(*addrs & 0x80){
        *addrs |= 0xFF00;
    }

    return 0;
}

// Endereço absoluto, ou sejá vou passar os 2bytes do endereço
// Então vou ler a primeira parte do endereço (low nibble) está 
// no mesmo PC da instrução e a segunda parte está no endereço
// seguinte (high nibble)
uint8_t ABS(CPU_6502 *MyCPU, uint16_t *addrs){
    uint16_t lo = bus_read(MyCPU->PC);
    MyCPU->PC++;
    uint16_t hi =bus_read(MyCPU->PC);
    MyCPU->PC++;

    *addrs = (hi << 8) |  lo;
    return 0;
}

// Uma mistura do ZPX e ABS, ou seja vou ler dois endereços de 
// memória para ter um endereço completo, onde o low nibble é o
// endereço em PC e o high nibble é o próximo endereço, e aí com
// o endereço completo basta somar o que está em X para ter o
// deslocamento
// Um detalhe adicional ... lembra do rolê das páginas, então,
// após realizar o offset com X é necessário verificar se ouve
// uma mudança de página, caso isso tenha ocorrido será necessário
// mais um ciclo de clock, imagino que para simular essa mudança
uint8_t ABX(CPU_6502 *MyCPU, uint16_t *addrs){
    uint16_t lo = bus_read(MyCPU->PC);
    MyCPU->PC++;
    uint16_t hi = bus_read(MyCPU->PC);
    MyCPU->PC++;

    *addrs = (hi << 8) | lo;
    *addrs += MyCPU->X;
    
    if((*addrs & 0xFF00) != (hi << 8)){  // Estou verificando de a segunda
        return 1;                        // parte do endereço (a parte alta)
    }                                   // mudou, pq nesse caso mudou de página

    return 0;
}

// Mesma coisa que o anterior mas agora com o registrador Y
uint8_t ABY(CPU_6502 *MyCPU, uint16_t *addrs){
    uint16_t lo = bus_read(MyCPU->PC);
    MyCPU->PC++;
    uint16_t hi = bus_read(MyCPU->PC);
    MyCPU->PC++;

    *addrs = (hi << 8) | lo;
    *addrs += MyCPU->Y;


    if((*addrs & 0xFF00) != (hi << 8)){
        return 1;
    }

    return 0;
}

// É uma forma que ele usa para trabalhar com ponteiros
// Indrect adressing
// Vou ler os dois próximos endereços de memória e receber
// um endereço, que vou ler e aí obter o endereço que me 
// interessa
uint8_t IND(CPU_6502 *MyCPU, uint16_t *addrs){
	uint16_t ptr_lo = bus_read(MyCPU->PC);
	MyCPU->PC++;
	uint16_t ptr_hi = bus_read(MyCPU->PC);
	MyCPU->PC++;

	uint16_t ptr = (ptr_hi << 8) | ptr_lo;

	if (ptr_lo == 0x00FF) // Simulate page boundary hardware bug
	{
		*addrs = (bus_read(ptr & 0xFF00) << 8) | bus_read(ptr + 0);
	}
	else // Behave normally
	{
		*addrs = (bus_read(ptr + 1) << 8) | bus_read(ptr + 0);
	}

	return 0;
}

// Mesma coisa, mas agora o endereço está deslocado em X
// em relação ao meu PC. E aí segue como anteriormente,
// lendo os próximos 2 endereços para montar o endereço final
uint8_t IZX(CPU_6502 *MyCPU, uint16_t *addrs){
    uint16_t t = bus_read(MyCPU->PC);
	MyCPU->PC++;

	uint16_t lo = bus_read((t + MyCPU->X) & 0x00FF);
	uint16_t hi = bus_read((t + MyCPU->X + 1) & 0x00FF);

    *addrs = (hi << 8) | lo;
    return  1;
    
}

// Mesma coisa que o anterior mas agora para Y
uint8_t IZY(CPU_6502 *MyCPU, uint16_t *addrs){
    uint16_t t = bus_read(MyCPU->PC);
	MyCPU->PC++;

	uint16_t lo = bus_read((t + MyCPU->Y) & 0x00FF);
	uint16_t hi = bus_read((t + MyCPU->Y + 1) & 0x00FF);
    
    *addrs = (hi << 8) | lo;

    if((*addrs & 0xFF00) != (hi << 8)){
        return 1;
    }

    return  0;
}

// Operações

// 1) Fetch the data you are working with
// 2) Perform calculation
// 3) Store the result in desired place
// 4) Set Flags of the status register
// 5) Return if instruction has potential to require additional
//    clock cycle


// APPENDIX A: 6502 Instructions in Detail

// ADC  Add Memory to Accumulator with Carry
//
//      A + M + C -> A, C
//      N Z C I D V
//      + + + - - +
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      immidiate     ADC #oper     69    2     2
//      zeropage      ADC oper      65    2     3
//      zeropage,X    ADC oper,X    75    2     4
//      absolute      ADC oper      6D    3     4
//      absolute,X    ADC oper,X    7D    3     4*
//      absolute,Y    ADC oper,Y    79    3     4*
//      (indirect,X)  ADC (oper,X)  61    2     6
//      (indirect),Y  ADC (oper),Y  71    2     5*
uint8_t ADC(CPU_6502 *MyCPU, uint16_t addrs){
    uint16_t temp = fetch(addrs);

    temp += MyCPU->AC + GetFlag(C, MyCPU);

    SetFlag(C, MyCPU, temp > 255);

    SetFlag(Z, MyCPU, (temp & 0x00FF) == 0);

    SetFlag(V, MyCPU, ( (~((uint16_t)MyCPU->AC ^ (uint16_t)fetch(addrs)) & ( (uint16_t)MyCPU->AC ^ temp) & 0x0080) ));

    SetFlag(N, MyCPU, temp & 0x80);

    MyCPU->AC = temp & 0x00FF;

    return 1;
}

// AND  AND Memory with Accumulator
//
//      A AND M -> A
//      N Z C I D V
//      + + - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      immidiate     AND #oper     29    2     2
//      zeropage      AND oper      25    2     3
//      zeropage,X    AND oper,X    35    2     4
//      absolute      AND oper      2D    3     4
//      absolute,X    AND oper,X    3D    3     4*
//      absolute,Y    AND oper,Y    39    3     4*
//      (indirect,X)  AND (oper,X)  21    2     6
//      (indirect),Y  AND (oper),Y  31    2     5*
uint8_t AND(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->AC = MyCPU->AC & fetch(addrs);

    SetFlag(Z, MyCPU, MyCPU->AC == 0x00);
    SetFlag(N, MyCPU, MyCPU->AC & 0x80);

    return 1;
}

// ASL  Shift Left One Bit (Memory or Accumulator)
//
//      C <- [76543210] <- 0
//      N Z C I D V
//      + + + - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      accumulator   ASL A         0A    1     2
//      zeropage      ASL oper      06    2     5
//      zeropage,X    ASL oper,X    16    2     6
//      absolute      ASL oper      0E    3     6
//      absolute,X    ASL oper,X    1E    3     7
uint8_t ASL(CPU_6502 *MyCPU, uint16_t addrs){
    uint16_t temp = fetch(addrs) << 1;

    SetFlag(C, MyCPU, (temp & 0xFF00) > 0);
    SetFlag(Z, MyCPU, (temp & 0x00FF) == 0x00);
    SetFlag(N, MyCPU,temp & 0x80);
    // Tem uma questão aqui, se a func de memoria que foi chamada junto
    // com esta era IMP tenho q salvar a informação no acumulador
    // Como no cado coloquei o IMP para retornar sempre 0 meu addrs será 0

    if(addrs == 0){
        MyCPU->AC = (temp & 0x00FF);
    }else{
        bus_write(addrs, temp & 0x00FF);
    }
    
    return 0;
}


// BCC  Branch on Carry Clear
//
//      branch on C = 0
//      N Z C I D V
//      - - - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      relative      BCC oper      90    2     2**
uint8_t BCC(CPU_6502 *MyCPU, uint16_t addrs){

    if(GetFlag(C, MyCPU) == 0){
        (*ptr_clk)++;
        
        addrs += MyCPU->PC;

        if((addrs & 0xFF00) != (MyCPU->PC & 0xFF00)){
            (*ptr_clk)++;
        }
        MyCPU->PC = addrs;
    }
    return 0;
}

// BCS  Branch on Carry Set
//
//      branch on C = 1
//      N Z C I D V
//      - - - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      relative      BCS oper      B0    2     2**
uint8_t BCS(CPU_6502 *MyCPU, uint16_t addrs){
    if(GetFlag(C, MyCPU) == 1){
        (*ptr_clk)++;

        addrs += MyCPU->PC;

        if((addrs & 0xFF00) != (MyCPU->PC & 0xFF00)){
            (*ptr_clk)++;
        }
        MyCPU->PC = addrs;
    }
    return 0;
}

// BEQ  Branch on Result Zero
//
//      branch on Z = 1
//      N Z C I D V
//      - - - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      relative      BEQ oper      F0    2     2**
uint8_t BEQ(CPU_6502 *MyCPU, uint16_t addrs){
    if(GetFlag(Z, MyCPU) == 1){
        (*ptr_clk)++;

        addrs += MyCPU->PC;

        if((addrs & 0xFF00) != (MyCPU->PC & 0xFF00)){
            (*ptr_clk)++;
        }
        MyCPU->PC = addrs;
    }
    return 0;
}

// BIT  Test Bits in Memory with Accumulator
//
//      bits 7 and 6 of operand are transfered to bit 7 and 6 of SR (N,V);
//      the zeroflag is set to the result of operand AND accumulator.
//
//      A AND M, M7 -> N, M6 -> V        N Z C I D V
//                                      M7 + - - - M6
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      zeropage      BIT oper      24    2     3
//      absolute      BIT oper      2C    3     4
uint8_t BIT(CPU_6502 *MyCPU, uint16_t addrs){
    uint16_t temp = MyCPU->AC & fetch(addrs);
    SetFlag(Z, MyCPU, (temp & 0x00FF) == 0x00);
    SetFlag(N, MyCPU, fetch(addrs) & (1 << 7));
    SetFlag(V, MyCPU, fetch(addrs) & (1 << 6));

    return 0;
}

// BMI  Branch on Result Minus
//
//      branch on N = 1
//      N Z C I D V
//      - - - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      relative      BMI oper      30    2     2**
uint8_t BMI(CPU_6502 *MyCPU, uint16_t addrs){
    if(GetFlag(N, MyCPU) == 1){
        (*ptr_clk)++;

        addrs += MyCPU->PC;

        if((addrs & 0xFF00) != (MyCPU->PC & 0xFF00)){
            (*ptr_clk)++;
        }
        MyCPU->PC = addrs;
    }
    return 0;
}

// BNE  Branch on Result not Zero
//
//      branch on Z = 0
//      N Z C I D V
//      - - - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      relative      BNE oper      D0    2     2**
uint8_t BNE(CPU_6502 *MyCPU, uint16_t addrs){
    if(GetFlag(Z, MyCPU) == 0){
        (*ptr_clk)++;

        addrs += MyCPU->PC;

        if((addrs & 0xFF00) != (MyCPU->PC & 0xFF00)){
            (*ptr_clk)++;
        }
        MyCPU->PC = addrs;
    }
     return 0;
}


// BPL  Branch on Result Plus
//
//      branch on N = 0
//      N Z C I D V
//      - - - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      relative      BPL oper      10    2     2**
uint8_t BPL(CPU_6502 *MyCPU, uint16_t addrs){
    if(GetFlag(N, MyCPU) == 0){
        (*ptr_clk)++;

        addrs += MyCPU->PC;

        if((addrs & 0xFF00) != (MyCPU->PC & 0xFF00)){
            (*ptr_clk)++;
        }
        MyCPU->PC = addrs;
    }
    return 0;
}

// BRK  Force Break
//
//      interrupt,                       N Z C I D V
//      push PC+2, push SR               - - - 1 - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       BRK           00    1     7
uint8_t BRK(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->PC++;

    SetFlag(I, MyCPU, 1);
    bus_write(0x0100 + MyCPU->SP, (MyCPU->PC >> 8) & 0x00FF);
    MyCPU->SP--;
    bus_write(0x0100 + MyCPU->SP, MyCPU->PC & 0x00FF);
    MyCPU->SP--;

    SetFlag(B, MyCPU, 1);
    bus_write(0x0100 + MyCPU->SP, MyCPU->PC & 0x00FF);
    MyCPU->SP--;
    SetFlag(B, MyCPU, 0);

    MyCPU->PC = ((uint16_t)bus_read(0xFFFE) | (uint16_t)bus_read(0xFFFF) << 8);
    return 0;
}

// BVC  Branch on Overflow Clear
//
//      branch on V = 0
//      N Z C I D V
//      - - - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      relative      BVC oper      50    2     2**
uint8_t BVC(CPU_6502 *MyCPU, uint16_t addrs){
    if(GetFlag(V, MyCPU) == 0){
        (*ptr_clk)++;

        addrs += MyCPU->PC;

        if((addrs & 0xFF00) != (MyCPU->PC & 0xFF00)){
            (*ptr_clk)++;
        }
        MyCPU->PC = addrs;
    }    
    return 0;
}

// BVS  Branch on Overflow Set
//
//      branch on V = 1                  N Z C I D V
//                                       - - - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      relative      BVC oper      70    2     2**
uint8_t BVS(CPU_6502 *MyCPU, uint16_t addrs){
    if(GetFlag(V, MyCPU) == 1){
        (*ptr_clk)++;

        addrs += MyCPU->PC;

        if((addrs & 0xFF00) != (MyCPU->PC & 0xFF00)){
            (*ptr_clk)++;
        }
        MyCPU->PC = addrs;
    }
    return 0; }

// CLC  Clear Carry Flag
//
//      0 -> C                           N Z C I D V
//                                       - - 0 - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       CLC           18    1     2
uint8_t CLC(CPU_6502 *MyCPU, uint16_t addrs){
    SetFlag(C, MyCPU, 0);

    return 0; 
}

// CLD  Clear Decimal Mode
//
//      0 -> D                           N Z C I D V
//                                       - - - - 0 -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       CLD           D8    1     2
uint8_t CLD(CPU_6502 *MyCPU, uint16_t addrs){
    SetFlag(D, MyCPU, 0);

    return 0;
}

// CLI  Clear Interrupt Disable Bit
//
//      0 -> I                           N Z C I D V
//                                       - - - 0 - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       CLI           58    1     2
uint8_t CLI(CPU_6502 *MyCPU, uint16_t addrs){
    SetFlag(I, MyCPU, 0);
    return 0; 
}

// CLV  Clear Overflow Flag
//
//      0 -> V                           N Z C I D V
//                                       - - - - - 0
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       CLV           B8    1     2
uint8_t CLV(CPU_6502 *MyCPU, uint16_t addrs){
    SetFlag(V, MyCPU, 0);
    return 0; 
}

// CMP  Compare Memory with Accumulator
//
//      A - M                            N Z C I D V
//                                     + + + - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      immidiate     CMP #oper     C9    2     2
//      zeropage      CMP oper      C5    2     3
//      zeropage,X    CMP oper,X    D5    2     4
//      absolute      CMP oper      CD    3     4
//      absolute,X    CMP oper,X    DD    3     4*
//      absolute,Y    CMP oper,Y    D9    3     4*
//      (indirect,X)  CMP (oper,X)  C1    2     6
//      (indirect),Y  CMP (oper),Y  D1    2     5*
uint8_t CMP(CPU_6502 *MyCPU, uint16_t addrs){
    uint16_t temp = (uint16_t)MyCPU->AC - (uint16_t)fetch(addrs);
    SetFlag(C, MyCPU, MyCPU->AC >= fetch(addrs));
    SetFlag(Z, MyCPU, (temp & 0x00FF) == 0x0000);
    SetFlag(N, MyCPU, temp & 0x0080);
    return 1;

}

// CPX  Compare Memory and Index X
//
//      X - M                            N Z C I D V
//                                       + + + - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      immidiate     CPX #oper     E0    2     2
//      zeropage      CPX oper      E4    2     3
//      absolute      CPX oper      EC    3     4
uint8_t CPX(CPU_6502 *MyCPU, uint16_t addrs){
    uint16_t temp = (uint16_t)MyCPU->X - (uint16_t)fetch(addrs);
    SetFlag(C, MyCPU, MyCPU->X >= fetch(addrs));
    SetFlag(Z, MyCPU, (temp & 0x00FF) == 0x0000);
    SetFlag(N, MyCPU, temp & 0x0080);
    return 0;
}

// CPY  Compare Memory and Index Y
//
//      Y - M                            N Z C I D V
//                                       + + + - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      immidiate     CPY #oper     C0    2     2
//      zeropage      CPY oper      C4    2     3
//      absolute      CPY oper      CC    3     4
uint8_t CPY(CPU_6502 *MyCPU, uint16_t addrs){
    uint16_t temp = (uint16_t)MyCPU->Y - (uint16_t)fetch(addrs);
    SetFlag(C, MyCPU, MyCPU->Y >= fetch(addrs));
    SetFlag(Z, MyCPU, (temp & 0x00FF) == 0x0000);
    SetFlag(N, MyCPU, temp & 0x0080);
    return 0;
}

// DEC  Decrement Memory by One
//
//      M - 1 -> M                       N Z C I D V
//                                       + + - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      zeropage      DEC oper      C6    2     5
//      zeropage,X    DEC oper,X    D6    2     6
//      absolute      DEC oper      CE    3     6
//      absolute,X    DEC oper,X    DE    3     7
uint8_t DEC(CPU_6502 *MyCPU, uint16_t addrs){
    uint16_t temp = fetch(addrs) - 1;
    bus_write(addrs, temp & 0x00FF);
    SetFlag(Z, MyCPU, (temp & 0x00FF) == 0x0000);
    SetFlag(N, MyCPU, temp & 0x0080);
    return 0;
}

// DEX  Decrement Index X by One
//
//      X - 1 -> X                       N Z C I D V
//                                       + + - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       DEC           CA    1     2
uint8_t DEX(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->X--;
    SetFlag(Z, MyCPU, MyCPU->X == 0x00);
    SetFlag(N, MyCPU, MyCPU->X == 0x80);
    return 0;
}

// DEY  Decrement Index Y by One
//
//      Y - 1 -> Y                       N Z C I D V
//                                       + + - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       DEC           88    1     2
uint8_t DEY(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->Y--;
    SetFlag(Z, MyCPU, MyCPU->Y == 0x00);
    SetFlag(N, MyCPU, MyCPU->Y == 0x80);
    return 0;
}

// EOR  Exclusive-OR Memory with Accumulator
//
//      A EOR M -> A                     N Z C I D V
//                                       + + - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      immidiate     EOR #oper     49    2     2
//      zeropage      EOR oper      45    2     3
//      zeropage,X    EOR oper,X    55    2     4
//      absolute      EOR oper      4D    3     4
//      absolute,X    EOR oper,X    5D    3     4*
//      absolute,Y    EOR oper,Y    59    3     4*
//      (indirect,X)  EOR (oper,X)  41    2     6
//      (indirect),Y  EOR (oper),Y  51    2     5*
uint8_t EOR(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->AC = MyCPU->AC ^ fetch(addrs);
    SetFlag(Z, MyCPU, MyCPU->AC == 0x00);
    SetFlag(N, MyCPU, MyCPU->AC & 0x80);
    return 1;
}

// INC  Increment Memory by One
//
//      M + 1 -> M                       N Z C I D V
//                                       + + - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      zeropage      INC oper      E6    2     5
//      zeropage,X    INC oper,X    F6    2     6
//      absolute      INC oper      EE    3     6
//      absolute,X    INC oper,X    FE    3     7
uint8_t INC(CPU_6502 *MyCPU, uint16_t addrs){
    uint8_t temp = fetch(addrs) + 1;
    bus_write(addrs, temp);
    SetFlag(Z, MyCPU, temp == 0x00);
    SetFlag(N, MyCPU, temp & 0x80);
    return 0;
}

// INX  Increment Index X by One
//
//      X + 1 -> X                       N Z C I D V
//                                       + + - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       INX           E8    1     2
uint8_t INX(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->X++;
    SetFlag(Z, MyCPU, MyCPU->X == 0x00);
    SetFlag(N, MyCPU, MyCPU->X == 0x80);
    return 0;
}

// INY  Increment Index Y by One
//
//      Y + 1 -> Y                       N Z C I D V
//                                       + + - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       INY           C8    1     2
uint8_t INY(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->Y++;
    SetFlag(Z, MyCPU, MyCPU->Y == 0x00);
    SetFlag(N, MyCPU, MyCPU->Y == 0x80);
    return 0;
}

// JMP  Jump to New Location
//
//      (PC+1) -> PCL                    N Z C I D V
//      (PC+2) -> PCH                    - - - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      absolute      JMP oper      4C    3     3
//      indirect      JMP (oper)    6C    3     5
uint8_t JMP(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->PC = addrs;
    return 0;
}

// JSR  Jump to New Location Saving Return Address
//
//      push (PC+2),                     N Z C I D V
//      (PC+1) -> PCL                    - - - - - -
//      (PC+2) -> PCH
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      absolute      JSR oper      20    3     6
uint8_t JSR(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->PC--;

    bus_write(0x0100 + MyCPU->SP, (MyCPU->PC >> 8) & 0x00FF);
    MyCPU->SP--;
    bus_write(0x0100 + MyCPU->SP, MyCPU->PC & 0x00FF);
    MyCPU->SP--;

    MyCPU->PC = addrs;
    return 0;
}

// LDA  Load Accumulator with Memory
//
//      M -> A                           N Z C I D V
//                                       + + - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      immidiate     LDA #oper     A9    2     2
//      zeropage      LDA oper      A5    2     3
//      zeropage,X    LDA oper,X    B5    2     4
//      absolute      LDA oper      AD    3     4
//      absolute,X    LDA oper,X    BD    3     4*
//      absolute,Y    LDA oper,Y    B9    3     4*
//      (indirect,X)  LDA (oper,X)  A1    2     6
//      (indirect),Y  LDA (oper),Y  B1    2     5*
uint8_t LDA(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->AC = fetch(addrs);
    SetFlag(Z, MyCPU, MyCPU->AC == 0x00);
    SetFlag(N, MyCPU, MyCPU->AC & 0x80);
    return 1;
}

// LDX  Load Index X with Memory
//
//      M -> X                           N Z C I D V
//                                       + + - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      immidiate     LDX #oper     A2    2     2
//      zeropage      LDX oper      A6    2     3
//      zeropage,Y    LDX oper,Y    B6    2     4
//      absolute      LDX oper      AE    3     4
//      absolute,Y    LDX oper,Y    BE    3     4*
uint8_t LDX(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->X = fetch(addrs);
    SetFlag(Z, MyCPU, MyCPU->X == 0x00);
    SetFlag(N, MyCPU, MyCPU->X & 0x80);
    return 1;
}

// LDY  Load Index Y with Memory
//
//      M -> Y                           N Z C I D V
//                                       + + - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      immidiate     LDY #oper     A0    2     2
//      zeropage      LDY oper      A4    2     3
//      zeropage,X    LDY oper,X    B4    2     4
//      absolute      LDY oper      AC    3     4
//      absolute,X    LDY oper,X    BC    3     4*
uint8_t LDY(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->Y = fetch(addrs);
    SetFlag(Z, MyCPU, MyCPU->Y == 0x00);
    SetFlag(N, MyCPU, MyCPU->Y & 0x80);
    return 1;
}

// LSR  Shift One Bit Right (Memory or Accumulator)
//
//      0 -> [76543210] -> C             N Z C I D V
//                                       0 + + - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      accumulator   LSR A         4A    1     2
//      zeropage      LSR oper      46    2     5
//      zeropage,X    LSR oper,X    56    2     6
//      absolute      LSR oper      4E    3     6
//      absolute,X    LSR oper,X    5E    3     7
uint8_t LSR(CPU_6502 *MyCPU, uint16_t addrs){
    uint8_t temp = fetch(addrs);

    SetFlag(C, MyCPU, temp & 0x01);
    temp = temp >> 1;
    SetFlag(Z, MyCPU, (temp == 0x00));
    SetFlag(N, MyCPU, temp & 0x80);

    if(impFlag != 0){
        MyCPU->AC = temp;
        impFlag = 0;
    }else{
        bus_write(addrs, temp);
    }
    return 0;
}

// NOP  No Operation
//
//      ---                              N Z C I D V
//                                       - - - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       NOP           EA    1     2
uint8_t NOP(CPU_6502 *MyCPU, uint16_t addrs){ return 0; }

// ORA  OR Memory with Accumulator
//
//      A OR M -> A                      N Z C I D V
//                                       + + - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      immidiate     ORA #oper     09    2     2
//      zeropage      ORA oper      05    2     3
//      zeropage,X    ORA oper,X    15    2     4
//      absolute      ORA oper      0D    3     4
//      absolute,X    ORA oper,X    1D    3     4*
//      absolute,Y    ORA oper,Y    19    3     4*
//      (indirect,X)  ORA (oper,X)  01    2     6
//      (indirect),Y  ORA (oper),Y  11    2     5*
uint8_t ORA(CPU_6502 *MyCPU, uint16_t addrs){
    uint8_t temp = fetch(addrs);
    MyCPU->AC = MyCPU->AC | temp;

    SetFlag(Z, MyCPU, MyCPU->AC == 0x00);
    SetFlag(N, MyCPU, MyCPU->AC & 0x80);

    return 1;
}

// PHA  Push Accumulator on Stack
//
//      push A                           N Z C I D V
//                                       - - - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       PHA           48    1     3
uint8_t PHA(CPU_6502 *MyCPU, uint16_t addrs){
    bus_write(0x0100 + MyCPU->SP, MyCPU->AC);
    MyCPU->SP--;
    return 0;
}

// PHP  Push Processor Status on Stack
//
//      push SR                          N Z C I D V
//                                       - - - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       PHP           08    1     3
uint8_t PHP(CPU_6502 *MyCPU, uint16_t addrs){
    bus_write(0x0100 + MyCPU->SP, MyCPU->SR | B | _);
    SetFlag(B, MyCPU, 0);
    SetFlag(_, MyCPU, 0);
    return 0;
}

// PLA  Pull Accumulator from Stack
//
//      pull A                           N Z C I D V
//                                       + + - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       PLA           68    1     4
uint8_t PLA(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->SP++;
    MyCPU->AC = bus_read(0x0100 + MyCPU->SP);
    SetFlag(Z, MyCPU, MyCPU->AC == 0x00);
    SetFlag(N, MyCPU, MyCPU->AC & 0x80);
    return 0;
}

// PLP  Pull Processor Status from Stack
//
//      pull SR                          N Z C I D V
//                                       from stack
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       PLP           28    1     4
uint8_t PLP(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->SP++;
    MyCPU->SR = bus_read(0x0100 + MyCPU->SP);
    SetFlag(_, MyCPU, 1);
    return 0;
}

// ROL  Rotate One Bit Left (Memory or Accumulator)
//
//      C <- [76543210] <- C             N Z C I D V
//                                       + + + - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      accumulator   ROL A         2A    1     2
//      zeropage      ROL oper      26    2     5
//      zeropage,X    ROL oper,X    36    2     6
//      absolute      ROL oper      2E    3     6
//      absolute,X    ROL oper,X    3E    3     7
uint8_t ROL(CPU_6502 *MyCPU, uint16_t addrs){
    uint8_t fetched;
    if(impFlag==0)
        fetched = fetch(addrs);
    else
        fetched = MyCPU->AC;

    
    
    uint16_t temp = (uint16_t)(fetched << 1) | GetFlag(C, MyCPU);
    SetFlag(C, MyCPU, (temp & 0xFF00));
    SetFlag(N, MyCPU, (temp & 0x0080));
    SetFlag(Z, MyCPU, ((temp & 0x00FF) == 0x0000));

    // Agora preciso saber se vou salvar na memoria ou no acumulador
    if(impFlag!=0){
        MyCPU->AC = (temp & 0x00FF);
        impFlag = 0;
    }else{
        bus_write(addrs, (temp & 0x00FF));
    }

    return 0;
}

// ROR  Rotate One Bit Right (Memory or Accumulator)
//
//      C -> [76543210] -> C             N Z C I D V
//                                       + + + - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      accumulator   ROR A         6A    1     2
//      zeropage      ROR oper      66    2     5
//      zeropage,X    ROR oper,X    76    2     6
//      absolute      ROR oper      6E    3     6
//      absolute,X    ROR oper,X    7E    3     7
uint8_t ROR(CPU_6502 *MyCPU, uint16_t addrs){
    uint8_t fetched;
    if(impFlag == 0){
        fetched = fetch(addrs);
    }else{
        fetched = MyCPU->AC;
    }

    uint16_t temp = (uint16_t)(fetched >> 1) | (GetFlag(C, MyCPU) << 7);
    SetFlag(C, MyCPU, (temp & 0x0001));
    SetFlag(N, MyCPU, (temp & 0x0080));
    SetFlag(Z, MyCPU, ((temp & 0x00FF) == 0x0000));

    if(impFlag!=0){
        MyCPU->AC = (temp & 0x00FF);
        impFlag = 0;
    }else{
        bus_write(addrs, (temp & 0x00FF));
    }

    return 0;
}

// RTI  Return from Interrupt
//
//      pull SR, pull PC                 N Z C I D V
//                                       from stack
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       RTI           40    1     6
uint8_t RTI(CPU_6502 *MyCPU, uint16_t addrs){

    // Aqui eu estou recuperando o estado das flags
    // antes da interrupção
    MyCPU->SP++;
    MyCPU->SR = bus_read(0x0100 + MyCPU->SP);
    SetFlag(B, MyCPU, 0);
    SetFlag(_, MyCPU, 0);

    // Agora recuperar o valor do PC
    MyCPU->SP++;
    MyCPU->PC = (uint16_t)bus_read(0x0100 + MyCPU->SP);
    MyCPU->SP++;
    MyCPU->PC |= ((uint16_t)bus_read(0x0100 + MyCPU->SP) << 8);

    return 0;
}

// RTS  Return from Subroutine
//
//      pull PC, PC+1 -> PC              N Z C I D V
//                                       - - - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       RTS           60    1     6
uint8_t RTS(CPU_6502 *MyCPU, uint16_t addrs){
    
    MyCPU->SP++;
    MyCPU->PC = (uint16_t)bus_read(0x0100 + MyCPU->SP);
    MyCPU->SP++;
    MyCPU->PC |= ((uint16_t)bus_read(0x0100 + MyCPU->SP) << 8);

    MyCPU->PC++;

    return 0; }

// SBC  Subtract Memory from Accumulator with Borrow
//
//      A - M - C -> A                   N Z C I D V
//                                       + + + - - +
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      immidiate     SBC #oper     E9    2     2
//      zeropage      SBC oper      E5    2     3
//      zeropage,X    SBC oper,X    F5    2     4
//      absolute      SBC oper      ED    3     4
//      absolute,X    SBC oper,X    FD    3     4*
//      absolute,Y    SBC oper,Y    F9    3     4*
//      (indirect,X)  SBC (oper,X)  E1    2     6
//      (indirect),Y  SBC (oper),Y  F1    2     5*
uint8_t SBC(CPU_6502 *MyCPU, uint16_t addrs){
    uint16_t temp = (uint16_t)MyCPU->AC + 1 + (uint16_t)GetFlag(C, MyCPU) + (uint16_t)(~fetch(addrs));

    MyCPU->AC = (temp & 0x00FF);
    
    SetFlag(N, MyCPU, (temp & 0x0080));
    SetFlag(C, MyCPU, (temp & 0x0100));
    SetFlag(Z, MyCPU, ((temp & 0x00FF) == 0x00));
    SetFlag(V, MyCPU, temp); // Ainda fazer

    return 1;
}

// SEC  Set Carry Flag
//
//      1 -> C                           N Z C I D V
//                                       - - 1 - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       SEC           38    1     2
uint8_t SEC(CPU_6502 *MyCPU, uint16_t addrs){
    SetFlag(C, MyCPU, 1);
    return 0;
}

// SED  Set Decimal Flag
//
//      1 -> D                           N Z C I D V
//                                       - - - - 1 -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       SED           F8    1     2
uint8_t SED(CPU_6502 *MyCPU, uint16_t addrs){
    SetFlag(D, MyCPU, 1);
    return 0;
}

// SEI  Set Interrupt Disable Status
//
//      1 -> I                           N Z C I D V
//                                       - - - 1 - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       SEI           78    1     2
uint8_t SEI(CPU_6502 *MyCPU, uint16_t addrs){
    SetFlag(I, MyCPU, 1);
    return 0;
}

// STA  Store Accumulator in Memory
//
//      A -> M                           N Z C I D V
//                                       - - - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      zeropage      STA oper      85    2     3
//      zeropage,X    STA oper,X    95    2     4
//      absolute      STA oper      8D    3     4
//      absolute,X    STA oper,X    9D    3     5
//      absolute,Y    STA oper,Y    99    3     5
//      (indirect,X)  STA (oper,X)  81    2     6
//      (indirect),Y  STA (oper),Y  91    2     6
uint8_t STA(CPU_6502 *MyCPU, uint16_t addrs){
    bus_write(addrs, MyCPU->AC);
    return 0;
}

// STX  Store Index X in Memory
//
//      X -> M                           N Z C I D V
//                                       - - - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      zeropage      STX oper      86    2     3
//      zeropage,Y    STX oper,Y    96    2     4
//      absolute      STX oper      8E    3     4
uint8_t STX(CPU_6502 *MyCPU, uint16_t addrs){
    bus_write(addrs, MyCPU->X);
    return 0;
}

// STY  Sore Index Y in Memory
//
//      Y -> M                           N Z C I D V
//                                       - - - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      zeropage      STY oper      84    2     3
//      zeropage,X    STY oper,X    94    2     4
//      absolute      STY oper      8C    3     4
uint8_t STY(CPU_6502 *MyCPU, uint16_t addrs){
    bus_write(addrs, MyCPU->Y);
    return 0;
}

// TAX  Transfer Accumulator to Index X
//
//      A -> X                           N Z C I D V
//                                       + + - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       TAX           AA    1     2
uint8_t TAX(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->X = MyCPU->AC;
    SetFlag(Z, MyCPU, (MyCPU->X == 0x00));
    SetFlag(N, MyCPU, (MyCPU->X & 0x80));
    return 0; }

// TAY  Transfer Accumulator to Index Y
//
//      A -> Y                           N Z C I D V
//                                       + + - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       TAY           A8    1     2
uint8_t TAY(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->Y = MyCPU->AC;
    SetFlag(Z, MyCPU, (MyCPU->Y == 0x00));
    SetFlag(N, MyCPU, (MyCPU->Y & 0x80));
    return 0; }

// TSX  Transfer Stack Pointer to Index X
//
//      SP -> X                          N Z C I D V
//                                       + + - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       TSX           BA    1     2
uint8_t TSX(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->X = MyCPU->SP;
    SetFlag(Z, MyCPU, (MyCPU->X == 0x00));
    SetFlag(N, MyCPU, (MyCPU->X & 0x80));
    return 0;
}

// TXA  Transfer Index X to Accumulator
//
//      X -> A                           N Z C I D V
//                                       + + - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       TXA           8A    1     2
uint8_t TXA(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->AC = MyCPU->X;
    SetFlag(Z, MyCPU, (MyCPU->AC == 0x00));
    SetFlag(N, MyCPU, (MyCPU->AC & 0x80));
    return 0;
}

// TXS  Transfer Index X to Stack Register
//
//      X -> SP                          N Z C I D V
//                                       - - - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       TXS           9A    1     2
uint8_t TXS(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->SP = MyCPU->X;
    return 0;
}

// TYA  Transfer Index Y to Accumulator
//
//      Y -> A                           N Z C I D V
//                                       + + - - - -
//
//      addressing    assembler    opc  bytes  cyles
//      --------------------------------------------
//      implied       TYA           98    1     2
uint8_t TYA(CPU_6502 *MyCPU, uint16_t addrs){
    MyCPU->AC = MyCPU->Y;
    SetFlag(Z, MyCPU, (MyCPU->AC == 0x00));
    SetFlag(N, MyCPU, (MyCPU->AC & 0x80));
    return 0;
}

/*
  *  add 1 to cycles if page boundery is crossed

  ** add 1 to cycles if branch occurs on same page
     add 2 to cycles if branch occurs to different page


     Legend to Flags:  + .... modified
                       - .... not modified
                       1 .... set
                       0 .... cleared
                      M6 .... memory bit 6
                      M7 .... memory bit 7


Note on assembler syntax:
Most assemblers employ "OPC *oper" for forced zeropage addressing.
*/


uint8_t XXX(CPU_6502 *MyCPU, uint16_t addrs){ return 0; }

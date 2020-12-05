#include <stdio.h>

#include "display.h"

void displayInfo(){
    char mold[] =   "    #00 #01 #02 #03 #04 #05 #06 #07 #08 #09 #0A #0B #0C #0D #0E #0F #10 #11 #12 #13 #14 #15 #16 #17 #18 #19 #1A #1B #1C #1D #1E #1F      |\n"
                    "#x0 000 001 002 003 004 005 006 007 008 009 00A 00B 00C 00D 00E 00F 010 011 012 013 014 015 016 017 018 019 01A 01B 01C 01D 01E 01F      |\n"
                    "#x1>100<101 102 103 104 105 106 107 108 109 10A 10B 10C 10D 10E 10F 110 111 112 113 114 115 116 117 118 119 11A 11B 11C 11D 11E 11F      |\n"
                    "#x2 200 201 202 203 204 205 206 207 208 209 20A 20B 20C 20D 20E 20F 210 211 212 213 214 215 216 217 218 219 21A 21B 21C 21D 21E 21F      |\n"
                    "#x3 300 301 302 303 304 305 306 307 308 309 30A 30B 30C 30D 30E 30F 310 311 312 313 314 315 316 317 318 319 31A 31B 31C 31D 31E 31F      |\n"
                    "#x4 400 401 402 403 404 405 406 407 408 409 40A 40B 40C 40D 40E 40F 410 411 412 413 414 415 416 417 418 419 41A 41B 41C 41D 41E 41F      |\n"
                    "#x5 500 501 502 503 504 505 506 507 508 509 50A 50B 50C 50D 50E 50F 510 511 512 513 514 515 516 517 518 519 51A 51B 51C 51D 51E 51F      |\n"
                    "#x6 600 601 602 603 604 605 606 607 608 609 60A 60B 60C 60D 60E 60F 610 611 612 613 614 615 616 617 618 619 61A 61B 61C 61D 61E 61F      |\n"
                    "#x7 700 701 702 703 704 705 706 707 708 709 70A 70B 70C 70D 70E 70F 710 711 712 713 714 715 716 717 718 719 71A 71B 71C 71D 71E 71F      |\n"
                    "#x8 800 801 802 803 804 805 806 807 808 809 80A 80B 80C 80D 80E 80F 810 811 812 813 814 815 816 817 818 819 81A 81B 81C 81D 81E 81F      |\n"
                    "#x9 900 901 902 903 904 905 906 907 908 909 90A 90B 90C 90D 90E 90F 910 911 912 913 914 915 916 917 918 919 91A 91B 91C 91D 91E 91F      |\n"
                    "#xA A00 A01 A02 A03 A04 A05 A06 A07 A08 A09 A0A A0B A0C A0D A0E A0F A10 A11 A12 A13 A14 A15 A16 A17 A18 A19 A1A A1B A1C A1D A1E A1F      |\n"
                    "#xB B00 B01 B02 B03 B04 B05 B06 B07 B08 B09 B0A B0B B0C B0D B0E B0F B10 B11 B12 B13 B14 B15 B16 B17 B18 B19 B1A B1B B1C B1D B1E B1F      |\n"
                    "#xC C00 C01 C02 C03 C04 C05 C06 C07 C08 C09 C0A C0B C0C C0D C0E C0F C10 C11 C12 C13 C14 C15 C16 C17 C18 C19 C1A C1B C1C C1D C1E C1F      |\n"
                    "#xD D00 D01 D02 D03 D04 D05 D06 D07 D08 D09 D0A D0B D0C D0D D0E D0F D10 D11 D12 D13 D14 D15 D16 D17 D18 D19 D1A D1B D1C D1D D1E D1F      |\n"
                    "#xE E00 E01 E02 E03 E04 E05 E06 E07 E08 E09 E0A E0B E0C E0D E0E E0F E10 E11 E12 E13 E14 E15 E16 E17 E18 E19 E1A E1B E1C E1D E1E E1F      |\n"
                    "#xF F00 F01 F02 F03 F04 F05 F06 F07 F08 F09 F0A F0B F0C F0D F0E F0F F10 F11 F12 F13 F14 F15 F16 F17 F18 F19 F1A F1B F1C F1D F1E F1F      |\n"
                    "\n"
                    "---------------PC   #P     Program Counter (16 bit)                #N Negative\n"
                    "---------------AC   #A     Accumulator (8 bit)                     #V Overflow\n"
                    "---------------X    #X     X register (8 bit)                      #_ Ignored\n"
                    "---------------Y    #Y     Y register (8 bit)                      #B Break\n"
                    "---------------SR   #R     Status Register [NV-BDIZC] (8 bit)      #D Decimal (ñ usado)\n"
                    "---------------SP   #S     Stack Pointer (8 bit)                   #I Interrupt (IRQ disable)\n"
                    "                                                                   #Z Zero\n"
                    "                                                                   #C Carry                                                           xxx\n";

                    char carro[] = "oi";
                    int i = 0;
                    printf("Compare---> %d\n", compare(mold, "   "));
                    while( compare(mold+i, "xxx")==0 && i<10000){
                        if(compare(mold+i, "#P")){
                            mold[i-1] = "0x" + (char)PC;
                        }
                        i += 1;
                    }
    
    printf("%s\n", mold);
    printf("%d\n", i);
}

int compare(char* str, char* valor){
    int i = 0;
    while(valor[i] != 0 && i<10){
        if(valor[i]!=str[i]){
            return 0;
        }
        i++;
    }

    return i;
}
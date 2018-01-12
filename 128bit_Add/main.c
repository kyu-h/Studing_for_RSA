#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
//    unsigned long long IN1 = 0xDA C1 A3 A4 13 05 DC 93 45 08 61 19 D6 6A 3A 39;
//    unsigned long long IN2 = 0xD9 4B 0D CB 81 89 6E 34 C6 49 CE F6 5D BD D5 71;
    unsigned int IN1[4] = {0xDAC1A3A4, 0x1305DC93, 0x45086119, 0xD66A3A39};
    unsigned int IN2[4] = {0xD94B0DCB, 0x81896E34, 0xC649CEF6, 0x5DBDD571};
    unsigned int OUT[4];
    //unsigned int carry[4];

    for(int i=0; i<4; i++){

        if(IN1[i] >= IN2[i]){
            OUT[i] = IN1[i] - IN2[i];
        }else if(IN1[i] < IN2[i]){
            if(i>0){
                OUT[i] = IN1[i] + (0x100000000 - IN2[i]);
                OUT[i-1] = OUT[i-1] - 1;
            }
        }
    }

    for(int i=0; i<4; i++){
        printf("%X ", OUT[i]);
    }
    return 0;
}

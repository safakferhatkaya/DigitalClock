#define _CRT_SECURE_NO_WARNINGS
#include "../include/segment.h"
#include "../include/date.h"
int main() {
    
    while(true){
        Sleep(1000);
        doubleDot();
        timeHand();
        updateScreen();
        clearScreen();
    }
    return 0;
}
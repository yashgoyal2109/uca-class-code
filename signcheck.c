#include <stdio.h>

int bitFunc1(int num) {
    int signBit = num >> 31;
    int bitMask = ((num | ~num + 1) >> 31) & 1;
    return signBit | bitMask;
}

int bitFunc2(int num) {
    return num >> 31 | !!num;
}

int main() {
    int negValue = -5, zeroValue = 0, posValue = 5;
    printf("%d %d %d\n", bitFunc1(negValue), bitFunc1(zeroValue), bitFunc1(posValue));
    return 0;
}
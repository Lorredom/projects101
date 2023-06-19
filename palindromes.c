#include <stdio.h>
#include <math.h>

void recursivePrinting(int length, int lengthIsOdd, int power) {
    int numOfPalindroms = pow(2, power);
    int halfLength = length/2;
    //printf("halfLength is %d\n", halfLength);
    //printf("length is %d\n", length);

    int sameDigitCols, divider;
    for (int i=0; i<numOfPalindroms; i++) {
        //printf("i is %d\n", i);
        for (int j=0; j<length+1; j++) {
            if (j<halfLength) {
                divider = pow(2, (j+1));
                sameDigitCols = numOfPalindroms/divider;
                if ((i/sameDigitCols)%2 != 0) {
                    printf("0");
                } else {
                    printf("1");
                }
            } else if (lengthIsOdd == 1 && j==(halfLength+1)) {
                if (i%2 != 0) {
                    printf("0");
                } else {
                    printf("1");
                }
            } else if (j>halfLength) {
                divider = pow(2, (length+1-j));
                //printf("\ndivider is %d\n", divider);
                sameDigitCols = numOfPalindroms/divider;
                //printf("sameDigitCols is %d\n", sameDigitCols);
                if ((i/sameDigitCols)%2 != 0) {
                    printf("0");
                } else {
                    printf("1");
                }
            }
        }
        //printf("\n");
    }   
}


int main() {
    int length, lengthIsOdd, power;
    length = 30;
    if (length%2==0) { 
        power = length/2;
        lengthIsOdd = 0;
    } else if (length%2==1) {
        power = ((length+1)/2);
        lengthIsOdd = 1;
    }
    //printf("power is %d\n", power);
    recursivePrinting(length, lengthIsOdd, power);

    return 0;
}



/*
111
110
101
100
011
010
001
000



8/ 16p=2^4
11111111
11100111
11011011
11000011
10111101
10100101
10011001
10000001
01111110
01100110
01011010
01000010
00111100
00100100
00011000
00000000

7/ 16p=2^4
1111111
1110111
1101011
1100011
1011101
1010101
1001001
1000001
0111110
0110110
0101010
0100010
0011100
0010100
0001000
0000000


6/ 8p=2^3
111111
110011
101101
100001
011110
010010
001100
000000


5/ 8p=2^3
11111
11011
10101
10001
01110
01010
00100
00000

4/ 4p=2^2
1111
1001
0110
0000

3/ 4p=2^2
111
101
010
000

2/ 2p=2^1
11
00

1/ 2p=2^1
1
0

*/
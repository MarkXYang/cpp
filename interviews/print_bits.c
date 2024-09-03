#include <stdio.h>
void print_bits(int num) {
    unsigned int check_bit = 1 << (sizeof(num)*8 - 1);

    while(check_bit != 0) {
        int r = num & check_bit;
        if(r == check_bit) {
            printf("%d ", 1);
        }
        else {
            printf("%d ", 0);
        }

        check_bit >>= 1;
    }
    printf("\n");
}

int count_bits(int num) {
    int count = 0;
    while(num != 0) {
        num = num & (num-1);
        count++;
    }
    return count;
}

char reverse_bits(char num) {
    char r = 0;
    int len = sizeof(num)*8;
    while(len-1) {
        r |= (num & 0x1);
        r <<= 1;
        num >>= 1;
        /*
        printf("---------------------\n");
        print_bits(num);
        print_bits(r);
        */
        len--;
    }
    r |= (num & 0x1);
    return r;
}

char reverse_bits2(char num) {
    char r = 0;
    int len = sizeof(num)*8;
    for(int i = 0; i< len/2; ++i) {
        int low = num >> i & 0x1;
        int high = (num & 1 << (len-i-1)) >> (len-i-1);
        r |= low << (len-i-1);
        r |= high << i;
    }
    return r;
}

int main()
{
    /*
    int x = 0x7A;
    print_bits(x);
    printf("bit 1 count of 0x%X is %d\n", x, count_bits(x));
    
    x = 0x85df;
    print_bits(x);
    printf("bit 1 count of 0x%X is %d\n", x, count_bits(x));

    */
    char c = 0xA7;
    printf("The reverse of 0x%X is 0x%X\n", c, reverse_bits2(c));
    return 0;
}
#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int* a, int size)
{
    for (int i=0; i<size; ++i) {
        bool bSwapped = false;
        for(int j=size-1; j>i; --j) {
            if (a[j-1] > a[j]) {
                // swap a[j-1] and a[j]
                a[j-1] = a[j-1] ^ a[j];
                a[j] = a[j-1] ^ a[j];
                a[j-1] = a[j-1] ^ a[j];
                bSwapped = true;
            }
        }
        if (bSwapped == false)
            break;
    }
}

void print_array(int* a, int size){
    for(int i = 0; i< size; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[] = {8,2,5,1,4,9,11,3,7,12};
    bubble_sort(a, sizeof(a)/sizeof(a[0]));
    print_array(a, sizeof(a)/sizeof(a[0]));
}
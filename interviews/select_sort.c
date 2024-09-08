#include <stdio.h>
void select_sort(int* arr, int size)
{
    for (int i = 0; i< size; ++i) {
        for(int j=i; j< size; ++j) {
            if (arr[i] > arr[j]) {
                /* swap a[i] and a[j]*/
                arr[i] ^=arr[j];
                arr[j] ^=arr[i];
                arr[i] ^=arr[j];
            }
        }
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
    select_sort(a, sizeof(a)/sizeof(a[0]));
    print_array(a, sizeof(a)/sizeof(a[0]));
    return 0;
}
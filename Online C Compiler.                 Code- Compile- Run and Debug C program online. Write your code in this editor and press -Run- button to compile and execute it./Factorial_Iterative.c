/******************************************************************************



*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = (int*) malloc(sizeof(int)*5);
    factorial(arr, 5);
    
    printf("%d\n", arr[4]);
    
    free(arr);
    return 0;
}
void factorial(int* arr, int limit){
    int x;
    *(arr) = 1;
    for( x = 1; x < limit; x++){
        *(arr+x) = *(arr+(x-1)) * (x+1);
    }
}

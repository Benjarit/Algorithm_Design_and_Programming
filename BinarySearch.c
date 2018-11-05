/******************************************************************************


*******************************************************************************/

#include <stdio.h>

typedef struct s{
    int value;
} Node; 

void* binarySearch(void*, int, int, void*);
int compare(void*, void*);

int main()
{
    Node arr[10]; 
    int a;
 
    for(a = 0; a < 10; a++)
    {
        arr[a].value = a+1; 
    }
    
    for(a = 0; a < 10; a++)
    {
        printf("%d ", arr[a].value);
    }
    
    int n = sizeof(arr)/ sizeof(arr[0]); 
    
    
    Node target;
    target.value = 11;
    printf("\nThe target number is %d\n\n", target.value);
    
    void* result = binarySearch(arr, 0, n-1, &target); 
    
    if(result != NULL){
        printf("\nThe result is: %d\n",((Node*)result)->value);
        printf("The result is: %p\n",((Node*)result));
    }else{
        printf("\nThe target is not in the array!!\n");
    }
    
    return 0;
}
void* binarySearch(void* arr, int first, int last, void* query){
    
    
    if(last >= 1 && first <= 9){
        int midIndex = first + (last - first)/2; 
        printf("The mid index is %d\n", midIndex);
        //printf("\n\nThe mid index is %d\n", midIndex);
        //printf("The value at mid index is %d\n\n",((Node*)arr+midIndex)->value);
        
        if(compare(query,((Node*)arr+midIndex)) < 0){

            return binarySearch(arr, first, midIndex-1, query);

        }else if(compare(query,((Node*)arr+midIndex)) > 0){
            
            //printf("The target is greater than the value of mid index!\n");
            return binarySearch(arr, midIndex+1, last, query); 
            
        }else if(compare(query,((Node*)arr+midIndex)) == 0) {
            
            //printf("The target is equal the value of mid index!\n");
            return ((Node*)arr+midIndex);
        }
    }
    return NULL;
}
int compare(void* obj1, void* obj2){
    // printf("Object 1 is %d\n", ((Node*)obj1)->value);
    // printf("Object 2 is %d\n\n", ((Node*)obj2)->value);
    
    if( ((Node*)obj1)->value < ((Node*)obj2)->value )
    {
        return -1;
    }
    else if( ((Node*)obj1)->value > ((Node*)obj2)->value) 
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

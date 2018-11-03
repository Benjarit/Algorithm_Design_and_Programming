/******************************************************************************



*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct s{
    int value;
    struct s* next;
}Node;

typedef struct s2{
    struct s* top;
}Stack;

Stack* push(Node*);
void popAll(Stack*);

int main()
{
    Node* head= NULL;
    Stack *s = NULL;
    
    s = push(head);
    popAll(s);
    
    return 0;
}
Stack* push(Node* head){
    int x;
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    Node* temp= NULL;
    Stack *s = (Stack*)malloc(sizeof(Stack));
    
    for( x =0; x < 10; x++){
        temp = (Node*)malloc(sizeof(Node));
        temp->value = array[x];
        if(head != NULL){
            temp->next = head;
        }
        head = temp;
        s->top = head;
        
        // ============ print ================= //
        Node* temp2 = head;
        while(temp2 != NULL){
            printf("%d ", temp2->value);
            temp2 = temp2->next;
        }
        printf("\n");
    }
    return s;
}
void popAll(Stack* stack){
    Node* temp3 = stack->top;
    while(temp3 != NULL){
        stack->top = temp3->next;
        free(temp3);// temp3 = NULL
        temp3 = stack->top;
        
        Node* temp4 = temp3;
        while(temp4 != NULL){
            printf("%d ", temp4->value);
            temp4 = temp4->next;
        }
        printf("\n");
    }
}

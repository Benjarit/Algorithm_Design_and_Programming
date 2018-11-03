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
void printList(Node* list);

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
        temp->next = NULL;
        temp->value = array[x];
        if(head != NULL){
            temp->next = head;
        }
        head = temp;
        s->top = head;
        // ============ print ================= //
        printList(head);
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
        printList(temp3);
        printf("\n");
    }
}
void printList(Node* list){
    while(list != NULL){
        printf("%d ", list->value);
        list = list->next;
    }
}

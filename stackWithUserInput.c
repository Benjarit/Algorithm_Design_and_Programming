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


void printList(Node* list);
Node* push(int,Node*);
Stack* pop(Stack*);

int main()
{
    Node* head= NULL;
    Stack *s = NULL;
    s = (Stack*)malloc(sizeof(Stack)); 
    int number;
    int x;
    char input;
    for(x = 0; x < 4; x++){
        printf("Enter a number to push to the stack: ");
        scanf("%d",&number);
        head = push(number,head);
        printList(head);
    }
    s->top = head;
    getchar();
    printf("\n\nWould you like to pop a latest Node? y/n\n");
    scanf("%c",&input);
    getchar();
    if(input == 'y'){
        s = pop(s);
        head =  s->top;
        printf("After pop: =====================\n");
        printList(head);
    }
    return 0;
}
Node* push(int number, Node* head){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->next = NULL;
    temp->value = number;
    
    if(head != NULL){
        (temp->next = head);
    }
    head = temp;
    return head;
}
Stack* pop(Stack* s){
    Node* temp = s->top;
    s->top = temp->next;
    free(temp);
    return s;
}
void printList(Node* list){
    while(list != NULL){
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

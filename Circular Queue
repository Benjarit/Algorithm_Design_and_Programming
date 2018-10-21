/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct x{
    int value;
    struct x* next;
} Node;

typedef struct y{
    Node* rear;
} Queue;

int main()
{
    srand(time(NULL));
    
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->rear = NULL;
    
    int counter;
    Node* temp;
    Node* head;
    for(counter = 0; counter < 10; counter++)
    {
        temp = (Node*)malloc(sizeof(Node));
        temp->value = (rand()%10 + 1);
        if(q->rear == NULL)
        {
            q->rear = temp;
        }
        if( head != NULL){
          temp->next = head; 
        }
        head = temp;
    }
    q->rear->next = head;
    
    printQueue(q);
    
    printf("\n");

    enqueue(q,(rand()%10+1));
    printQueue(q);
    
    printf("\n");
    dequeue(q);
    printQueue(q);
    
    return 0;
}
void printQueue(Queue* q)
{
    Node* temp2 = q->rear->next;
    printf("--------------------------------------------\n");
    while(temp2 != q->rear)
    {
        printf("%d ", temp2->value);
        temp2 = temp2->next;
    }
    printf("%d ", temp2->value);
    printf("\n--------------------------------------------");
    printFrontRear(q);
}
void enqueue(Queue* q, int number)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->value = number;
    Node* tempHead = q->rear->next;
    q->rear->next = temp;
    q->rear = temp;
    q->rear->next = tempHead;
}
void printFrontRear(Queue* q)
{
    printf("\nThe front value is %d\n", q->rear->next->value);
    printf("The rear value is %d\n", q->rear->value);
}
void dequeue(Queue* q)
{
    Node* temp = q->rear->next->next;
    free(q->rear->next);
    q->rear = temp;
}

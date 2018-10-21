/******************************************************************************

                 Benjarit Prelab for Queue Abstract Data Structure
                           Opeartion 1. Enqueue O(1)
                           Operation 2. Dequque O(1)
                           Operation 3. Print Queue O(n)

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct x{
    int value;
    struct x* next;
} Node;

typedef struct y{
    Node* front;
    Node* rear;
} Queue;

int main()
{
    srand(time(NULL));
    
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    
    int counter;
    Node* temp;
    for(counter = 0; counter < 10; counter++)
    {
        temp = (Node*)malloc(sizeof(Node));
        temp->value = (rand()%10 + 1);
        if(q->rear == NULL)
        {
            q->rear = temp;
        }
        if( q->front != NULL){
          temp->next = q->front; 
        }
        q->front = temp;
    }
    
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
    Node* temp2 = q->front;
    printf("--------------------------------------------\n");
    while(temp2 != NULL)
    {
        printf("%d ", temp2->value);
        temp2 = temp2->next;
    }
    printf("\n--------------------------------------------");
    printFrontRear(q);
}
void enqueue(Queue* q, int number)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->value = number;
    q->rear->next = temp;
    q->rear = temp;
}
void printFrontRear(Queue* q)
{
    printf("\nThe front value is %d\n", q->front->value);
    printf("The rear value is %d\n", q->rear->value);
}
void dequeue(Queue* q)
{
    Node* temp = q->front->next;
    free(q->front);
    q->front = temp;
}

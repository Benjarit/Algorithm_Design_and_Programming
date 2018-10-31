/****************************************************************************** 

                           Reverse Linked list by Benjarit Hotra

*******************************************************************************/
#include <iostream> 
#include <stack> 
#include <stdlib.h> 
#include <time.h> 
using namespace std;
typedef struct s
{ 
    int val; 
    struct s* next; 
    
}
Node; 
void initializeList(Node** head); 
void reverseLinkedList(Node** head); 
void printList(Node* head); 
int main() { 
    srand (time(NULL)); 
    Node* head = NULL; 
    initializeList(&head); 
    printList(head); 
    reverseLinkedList(&head);
    printList(head);
    return 0; 
} 
void initializeList(Node** head){ 
    for(int x = 0; x < 5; x++){ 
        Node* temp = new Node; 
        temp->val = rand() % 10 + 1; 
        if (*head != NULL){
            temp->next = *head; 
        } 
            *head = temp; 
    } 
} 
void printList(Node* head){ 
    while(head != NULL){ 
        printf("%d ", head->val); 
        head = head->next; 
    } 
    
} 
void reverseLinkedList(Node** head){ 
    stack<Node*> s; 
    Node* temp = *head; 
    while(temp != NULL){ 
        s.push(temp); 
        temp = temp->next; 
    } 
    printf("\n");
    while(!s.empty()){ 
        if(temp == NULL){
            *head = temp = s.top();
        }else{
            temp = temp->next = s.top();
        }
        s.pop();
    } 
    temp->next = NULL;
}

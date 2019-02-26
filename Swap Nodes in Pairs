
/*

Given a linked list, swap every two adjacent nodes and return its head.

Note: You may not modify the values in the list's nodes, only nodes itself may be changed.

Given 1->2->3->4, you should return the list as 2->1->4->3.

Accepted: 279,941
Submissions: 650,063
*/

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        else if( head->next == NULL){
            return head;
        }else{
            ListNode* temp = head;
            ListNode* temp2 = head->next->next;
            temp->next->next = head;
            head = temp->next;
            temp->next = swapPairs(temp2);
            return head;
        }
    }
};

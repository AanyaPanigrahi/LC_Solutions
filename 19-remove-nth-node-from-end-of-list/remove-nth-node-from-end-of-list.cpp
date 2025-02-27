/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return NULL;
        }
        int size=0;
        ListNode* temp=head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }

        if(n==size){
            return head->next;
        }

        int idx=size-n;
        ListNode* prev=head;
        int a=1;
        while(a<idx){
            prev=prev->next;
            a++;
        }
        prev->next=prev->next->next;
        return head;
    }
};
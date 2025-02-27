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
        if(head->next==NULL){
            return NULL;
        }
        ListNode* t1=head;
        ListNode* t2=head;
        int i=0;
        while(i<=n){
            if(t1==NULL) return head->next;
            t1=t1->next;
            i++;
        }
        while(t1){
            t1=t1->next;
            t2=t2->next;
        }

        t2->next=t2->next->next;
        return head;
    }
};
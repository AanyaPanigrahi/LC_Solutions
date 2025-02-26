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
    void rotate(ListNode* &head){
        ListNode* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        
        temp->next->next=head;
        head=temp->next;
        temp->next=NULL;
        
        
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int n=0;

        ListNode* temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        k=k%n;


        for(int i=1;i<=k;i++){
            rotate(head);
        }

        return head;
    }
};
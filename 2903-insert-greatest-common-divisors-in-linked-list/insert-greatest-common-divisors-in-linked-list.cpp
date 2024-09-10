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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=prev->next;
        while(curr!=NULL){
            ListNode* newNode=new ListNode(gcdEuclid(prev->val,curr->val));
            prev->next=newNode;
            newNode->next=curr;
            prev=curr;
            curr=curr->next;
        }
        return head;
    }
    int gcdEuclid(int a, int b){
        while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;}
        return a;
    }

};
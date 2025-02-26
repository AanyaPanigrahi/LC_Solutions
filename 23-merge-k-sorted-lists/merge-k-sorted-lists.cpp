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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n=lists.size();
        if(n==0){
            return NULL;
        }
        bool flag=false;
        for(ListNode* i:lists){
            if(i!=NULL){
                flag=true;
                break;
            }
        }
        if(flag==false){
            return NULL;
        }

        vector<int> ans;
        for(int i=0;i<lists.size();i++){
            ListNode* temp=lists[i];
            while(temp!=NULL){
                ans.push_back(temp->val);
                temp=temp->next;
            }
        }
        sort(ans.begin(),ans.end());
       
        ListNode* head2=new ListNode(ans[0]);
        ListNode* curr=head2;

        for(int i=1;i<ans.size();i++){
            ListNode* temp=new ListNode(ans[i]);
            curr->next=temp;
            curr=curr->next;

        }
        return head2;
    }
};
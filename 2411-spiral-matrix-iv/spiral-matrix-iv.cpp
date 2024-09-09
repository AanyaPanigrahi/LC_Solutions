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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int left=0,right=n-1,top=0,bottom=m-1;
        vector<vector<int>> ans(m,vector<int>(n,-1));

        ListNode* curr=head;
        while(curr!=NULL){
            
            //right
            for(int i=left;i<=right && curr;i++){
                ans[top][i]=curr->val;
                curr=curr->next;
            }
            top++;

            //down
            for(int j=top;j<=bottom && curr;j++){
                ans[j][right]=curr->val;
                curr=curr->next;
            }
            right--;

            //left
            for(int k=right;k>=left && curr;k--){
                ans[bottom][k]=curr->val;
                curr=curr->next;
            }
            bottom--;

            //upward
            for(int n=bottom;n>=top && curr;n--){
                ans[n][left]=curr->val;
                curr=curr->next;
            }
            left++;

        }
        return ans;
    }
};
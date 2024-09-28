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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* oddList = new ListNode(-1);
        ListNode* oddPtr = oddList;
        ListNode* evenList = new ListNode(-1);
        ListNode* evenPtr = evenList;
        ListNode* current = head;
        int index = 1;

        while (current) {
            if (index % 2 != 0) {
                oddPtr->next = current;
                oddPtr = oddPtr->next;
            } else {
                evenPtr->next = current;
                evenPtr = evenPtr->next;
            }
            current = current->next;
            index++;
        }

        oddPtr->next = evenList->next;
        evenPtr->next = NULL;

        return oddList->next;
    }
};
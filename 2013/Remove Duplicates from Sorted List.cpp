/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *cur = head, *pre = NULL;
        while(cur)
        {
            pre = cur;
            cur = cur->next;
            while(cur && cur->val == pre->val) cur = cur->next;
            pre->next = cur; 
        }
        return head;
    }
};
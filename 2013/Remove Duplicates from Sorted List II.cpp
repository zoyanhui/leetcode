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
            ListNode *sCur = cur;
            cur = cur->next;
            if(!cur) return head;
            if(cur->val != sCur->val)
            {
                 pre = sCur;
                 continue;
                 
            }
            while(cur && cur->val == sCur->val) cur = cur->next;
            if(!pre)
            {
                 head = cur;
            }   
            else
            {
                pre->next = cur;
            }
                
        }
        return head;
    }
};
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *head = NULL;
        ListNode *cur1 = l1, *cur2 = l2, *pre=NULL;
        while(cur1 && cur2)
        {
            if(cur1->val < cur2->val)
            {
                if(!head)
                {
                    head = cur1;
                    pre = head;
                } 
                else 
                {
                    pre->next = cur1;
                    pre = cur1;
                }
                cur1 = cur1->next;
            }
            else
            {
                if(!head)
                {
                    head = cur2;
                    pre = head;
                } 
                else 
                {
                    pre->next = cur2;
                    pre = cur2;
                }
                cur2 = cur2->next;
            }
        }
        if(!cur1 && pre)  pre->next = cur2;
        else if(!cur2 && pre) pre->next = cur1;
        return head;
    }
};
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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *pre = head, *less = NULL;
        if(pre)
        {
            while(pre && pre->val < x)
            {
                less = pre;
                pre = pre->next;
            }
            if(pre)
            {
                ListNode *cur = pre->next;
                ListNode *greater = pre;
                while(cur)
                {
                    if(cur->val < x)
                    {
                        if(less)
                        {
                            less->next = cur;
                            less = cur;
                        }
                        else
                        {
                            less = cur;
                            head = less;
                        }
                        
                    }
                    else
                    {
                        greater->next = cur;
                        greater = cur;
                    }
                    cur = cur->next;
                }
                greater->next = NULL;
            }
            if(less)
                less->next = pre;
            
        }
        return head;
    }
};
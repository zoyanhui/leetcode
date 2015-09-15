//no change to l1,l2

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (l1 == NULL && l2 == NULL)
            return NULL;
            
        ListNode *head = NULL;
        ListNode *pre = NULL;
        int flag = 0;
        
        while(l1 && l2)
        {
            ListNode *node = new ListNode(l1->val + l2->val + flag);
            flag = node->val / 10;
            node->val %= 10;
            
            if (head == NULL)
                head = node;
            else
                pre->next = node;
                
            pre = node;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1)
        {
            ListNode *node = new ListNode(l1->val + flag);
            flag = node->val / 10;
            node->val %= 10;
            
            if (head == NULL)
                head = node;
            else
                pre->next = node;
                
            pre = node;
            
            l1 = l1->next;
        }
        
        while(l2)
        {
            ListNode *node = new ListNode(l2->val + flag);
            flag = node->val / 10;
            node->val %= 10;
            
            if (head == NULL)
                head = node;
            else
                pre->next = node;
                
            pre = node;
            
            l2 = l2->next;
        }
        
        if (flag > 0)
        {
            ListNode *node = new ListNode(flag);
            pre->next = node;
        }
        
        return head;
    }
};
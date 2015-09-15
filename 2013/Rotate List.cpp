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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head) return NULL;
        int len = 0;
        ListNode *cur = head;
        while(cur)
        {
            len++; 
            cur = cur->next;
        }
        k %= len;
        if(k == 0) return head;
        ListNode *linkR = head;
        cur = head;   
        for(int i=1; i < len-k; i++)
        {
            cur = cur->next;
        }
        head = cur->next; 
        cur->next = NULL;
        cur = head;
        while(cur->next) cur = cur->next;
        cur->next = linkR;
        return head;        
    }
};
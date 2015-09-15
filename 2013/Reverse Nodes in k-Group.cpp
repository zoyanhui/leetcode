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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(k <=1) return head;
        int num = 0;
        ListNode *cur= head, *pre =NULL, *tail = NULL;
        head = NULL;
        ListNode *bTail = NULL;
        while(cur)
        {
            bTail = tail;
            tail =NULL;
            num = 0; 
            pre = NULL;
            while(num < k && cur)
            {
                ListNode *temp = cur->next;
                cur->next = pre;
                pre = cur;
                if(!tail) tail = cur;
                cur = temp;
                num++;
            }            
            if(bTail) bTail->next = pre;
            
            if(!head && num == k) head = pre;
        }
        
        if(num < k)
        {
            cur = pre; pre = NULL;
            while(num)
            {
                ListNode *temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
                num--;
            }
            if(bTail) bTail->next = pre;
            if(!head) head = pre;
        }
        return head;
    }
};
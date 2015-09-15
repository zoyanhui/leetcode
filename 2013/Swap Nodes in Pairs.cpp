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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head) return NULL;
        ListNode *cur = head, *pre = NULL, *tail = NULL, *con = NULL;
        head = NULL;
        while(cur)
        {
            int k = 2;
            con = tail;
            tail = NULL; pre = NULL;
            while(k-- && cur)
            {
                ListNode* temp = cur->next;
                cur->next = pre;
                pre = cur;
                if(!tail) tail = cur;
                cur = temp;
            }
            
            if(!head) head = pre;
            if(con) con->next = pre;
        }
        return head;
    }
};
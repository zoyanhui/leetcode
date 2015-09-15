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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m >=n) return head;
        if(!head) return NULL;
        if(m<1) n =1;
        ListNode *node = head;
        ListNode *pre = NULL;
        for(int i=1;i<m;i++)
        {
            pre = node;
            node = node->next;
        }
        ListNode *subtail = node;
        ListNode *conSub = pre;
        for(int i = m; i <= n; i++)
        {
            if(!node) break;
            ListNode *next = node->next;
            node->next = pre;
            pre = node;
            node = next;
        }
        if(conSub)
            conSub->next = pre;
        else
            head = pre;
        subtail->next = node;
        return head;
    }
};
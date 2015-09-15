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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) return head;
        
        ListNode *pre = head, *del = head, *delpre = NULL;
        int k = n;
        while(k && pre)
        {
            pre = pre->next;
            k--;
        }
        if(k > 0) return NULL;  // n is not valid, that bigger than length of list
        while(pre)
        {
            pre = pre->next;
            delpre = del;
            del = del->next;
        }
        if(!delpre) return del->next;
        delpre->next = del->next;
        del = NULL;
        return head;
    }
};
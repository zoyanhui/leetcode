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
        if(!l1) return l2;
        if(!l2) return l1;
        int temp = 0;
        ListNode *ll1 = l1,*ll2 = l2;
        
        while((ll1->next) && (ll2->next))
        {
            temp += ll1->val + ll2->val;
            ll1->val = temp%10;
            temp/=10;
            ll1 = ll1->next;
            ll2 = ll2->next;
        }
        temp += ll1->val + ll2->val;
        ll1->val = temp%10;
        temp/=10;
        
        if(!(ll1->next))
        {
            ll1->next = ll2->next;
            ll2 = ll2 ->next;
            while(ll2)
            {
                temp += ll2->val;
                ll2->val = temp%10;
                temp /= 10;
                ll1 = ll2;
                ll2 = ll2->next;
            }
            if(temp!=0)
            {
                ListNode* newNode; newNode = new ListNode(temp);
                ll1->next = newNode;
            }
            
        }
        else
        {
            ll1 = ll1 ->next;
            while(ll1)
            {
                temp += ll1->val;
                ll1->val = temp%10;
                temp /= 10;
                ll2 = ll1;
                ll1 = ll1->next;
            }
           if(temp!=0)
            {
                ListNode* newNode; newNode = new ListNode(temp);
                ll2->next = newNode;
            }
        }
        
        return l1;
    }
};
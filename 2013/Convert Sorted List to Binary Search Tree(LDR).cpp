//// recursion, divide and conquer algorithm
// LDR

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p = head;
        int len = 0;
        while(p)
        {
            len ++; 
            p = p->next;
        }
        return toBST(head, len);
    }
private:
    TreeNode *toBST(ListNode *&cur, int n)
    {
        if(n == 0) return NULL;
        int mid = n >> 1; //mid = n/2
        TreeNode *left = toBST(cur, mid);  //suppose left has been completed, just is a mid-order traversal
        TreeNode *parent = new TreeNode(cur->val);
        parent->left = left;
        cur = cur->next;
        parent->right = toBST(cur, n-1 - mid);
        return parent;
    }
};
//LDR, mid-order traversal, find the two elements of swapped, and then swap them
//O(1)extral sapce

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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return;
        TreeNode *pre = NULL;
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        warlkTree(root, pre, first, second);
        if(first && second)
        {
            int temp = first->val;
            first->val = second->val;
            second->val= temp;
        }
    }

private:
    void warlkTree(TreeNode *node, TreeNode *&pre,TreeNode *&first,TreeNode *&second)
    {
        if(!node) return;
        warlkTree(node->left, pre, first, second);
        if(pre && pre->val >= node->val) 
        {
            if(!first)
                first = pre;
            second = node;
        }
        pre = node;
        warlkTree(node->right, pre, first, second);
    }
};

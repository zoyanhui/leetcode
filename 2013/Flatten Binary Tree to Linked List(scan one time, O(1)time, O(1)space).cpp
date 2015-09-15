//scan one time, O(1)time, O(1)space
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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       if(!root) return;
       TreeNode *pre = NULL;
       pushVector(root, pre);
       
    }
private:
    void pushVector(TreeNode *node, TreeNode *&pre)
    {
        if(pre)
        {
            pre->left =NULL;
            pre->right = node;
        }        
        if(!node)   return;
        pre = node;
        TreeNode *left = node->left, *right = node->right;
        if(left)
            pushVector(left, pre);
        if(right)
            pushVector(right, pre);
        return;
    }
};
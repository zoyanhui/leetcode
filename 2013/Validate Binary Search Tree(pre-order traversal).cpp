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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return validation(root, INT_MIN, INT_MAX);
    }
private:
    bool validation(TreeNode *node, int left, int right)
    {
        if(!node) return true;
        return (node->val > left) && (node->val < right) && validation(node->left, left, node->val) && validation(node->right, node->val, right);   // node->val is greater than left, smaller than right. then recurse left and right, just a DLR
        
    }
};
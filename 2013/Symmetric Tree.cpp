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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;
        else if(root->left && root->right) return isSymetric(root->left,root->right);
        else if(!root->left && !root->right) return true;
        else return false;
    }
private:
    bool isSymetric(TreeNode *left, TreeNode *right)
    {
        if(left->val != right->val) return false;
        bool l,r;
        if(!left->left && !right->right) l = true;
        else if(left->left && right->right) l = isSymetric(left->left, right->right);
        else return false;
        
        if(!left->right && !right->left) r = true;
        else if(left->right && right->left) r = isSymetric(left->right, right->left);
        else return false;
        return l & r;
    }
};
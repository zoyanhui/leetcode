//LDR, mid-order traversal
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
        if(!root) return true;
        TreeNode *pre = NULL;
        return validation(root, pre);
    }
private:
    bool validation(TreeNode *node, TreeNode *&pre)
    {
        if(!node) return true;
        bool ans = validation(node->left,pre);
        if(pre && pre->val >= node->val) 
        {
            return false;
        }
        pre = node;
        return  ans &= validation(node->right, pre);
    }
};


// reduce above code statement as below:
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
        if(!root) return true;
        TreeNode *pre = NULL;
        return validation(root, pre);
    }
private:
    bool validation(TreeNode *node, TreeNode *&pre)
    {
        if(!node) return true;
       
        return validation(node->left,pre) && !(pre && pre->val >= node->val) && validation(node->right, pre=node);
    }
};
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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool isB = true;
        walkTree(root, isB);
        return isB;
    }
private:
    int walkTree(TreeNode *node, bool &isB)
    {
        if(!isB || !node) return 0;
        if(!node->left && !node->right) return 1;
        int dl = 1, dr = 1;
        if(isB && node->left)
            dl += walkTree(node->left, isB) ;
        if(isB && node->right)
            dr += walkTree(node->right, isB) ;
        if(!isB) return 0;
        if(dl > dr)
        {
            if(dl > dr +1) isB = false;
            return dl;
        }
        else
        {
            if(dr > dl +1) isB = false;
            return dr;
        }
    }
};
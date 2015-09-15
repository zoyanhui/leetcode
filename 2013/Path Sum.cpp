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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return false;
        int now = 0;
        return getPathSum(root, sum, now);
    }
private:
    bool getPathSum(TreeNode *node, const int sum, int &nowSum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!node) return false;
        nowSum += node->val;
        if(!node->left && !node->right)
        {
            
            if(nowSum == sum)
                return true;
            else 
            {
                nowSum -= node->val;
                return false;
            }
        }
        bool hasSum = false;
        if(node->left)
        {
            hasSum |= getPathSum(node->left,sum,nowSum);
        }
        if(node->right)
        {
            hasSum |= getPathSum(node->right, sum ,nowSum);
        }
        nowSum -= node->val;
        return hasSum;
    }
};
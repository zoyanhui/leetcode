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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0;
        getDegree(root,sum);
    return sum;
    }
    int getDegree(TreeNode *node,int &sum)
    {
        if(node == NULL)
          return 0;
        int degree = 0;
        if(!node->left && !node->right)
       {
           sum += node->val;
           
           return 1;
        }
	if(node->left)
        {
	    
            degree += getDegree(node->left,sum);
        }
        if(node->right)
        {
            degree += getDegree(node->right,sum);
        }
        degree *= 10;
        sum += node->val * degree;
        return degree;
    }
};
//method 1: count at top
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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return 0;
        int left = 1 + maxDepth(root->left);
        int right = 1 + maxDepth(root->right);
        return left > right ? left : right;
    }
};


//method 2: count at bottom
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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max = 0;
        findMaxDepth(root, 0, max);
        return max;
    }
private:
    void findMaxDepth(TreeNode *node,int cur, int &max)
    {
        if(!node) return;
        cur++;
        if(!node->left && !node->right)
        {
            max = cur > max ? cur : max;
        }
        findMaxDepth(node->left, cur, max);
        findMaxDepth(node->right, cur, max);
    }
};
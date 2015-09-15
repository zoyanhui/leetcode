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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return 0;
        long long min = INT_MAX;
        pruningTree(root, 0, min);
        return min;
    }
private:
    void pruningTree(TreeNode *node, long long nowMin, long long &min)
    {
        if(!node) return;
        if(nowMin + 1 >= min) return; 
        if(!node->left && !node->right) min = nowMin +1;;
        if(node->left)
            pruningTree(node->left, nowMin +1, min);
        if(node->right)
            pruningTree(node->right, nowMin +1, min);
        
    }
};
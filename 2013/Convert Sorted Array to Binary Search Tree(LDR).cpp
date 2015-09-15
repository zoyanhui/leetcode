// recursion, divide and conquer algorithm
// LDR

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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = num.size();
        int key = 0;
        return toBST(num, len, key);
    }
private:
    TreeNode *toBST(vector<int> &num, int n, int &key)
    {
        if(!n) return NULL;
        int mid = n>>1;   
        TreeNode *left = toBST(num, mid, key);
        TreeNode *root = new TreeNode(num[key]);
        root->left = left;
        key++;
        TreeNode *right = toBST(num, n-mid-1, key);        
        root->right = right;        
        return root;
    }
};
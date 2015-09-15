//recursion, divide and conquer algorithm
// DLR
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
        return toBST(num, 0, len-1);
    }
private:
    TreeNode *toBST(vector<int> &num, int begin, int end)
    {
        if(begin > end) return NULL;
        int mid = (begin + end)/ 2;   //find mid to be root
        TreeNode *root = new TreeNode(num[mid]);
        TreeNode *left = toBST(num, begin, mid -1);
        TreeNode *right = toBST(num, mid +1, end);
        root->left = left;
        root->right = right;        
        return root;
    }
};
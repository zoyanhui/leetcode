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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int pre=0;
        lenp = preorder.size();
        leni = inorder.size();
        if(lenp != leni)
            return NULL;
        return build(preorder, inorder, pre, 0, lenp-1);
    }
private:
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &pre, int inb, int ine)
    {
        if(inb > ine  || pre == lenp) return NULL;
        int root = indexof(inorder, preorder[pre], inb, ine);
        if(root >= 0)
            pre++;
        else
            return NULL;
        TreeNode *left = build(preorder, inorder, pre, inb, root-1);
        TreeNode *rootT = new TreeNode(inorder[root]);
        rootT->left = left;
        rootT->right = build(preorder,inorder, pre, root+1, ine);
        return rootT;
        
    }
    int indexof(vector<int> &inorder, int value, int begin, int end)
    {
        for(int i=begin; i <=end; i++)
            if(inorder[i] == value)
                return i;
        return -1;
    }
    int lenp = 0, leni = 1;
};
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        lenp = postorder.size();
        leni = inorder.size();
        if(lenp != leni)
            return NULL;
        int pre = lenp -1;
        return build(inorder, postorder, pre, 0, lenp-1);
    }
private:
    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int &pre, int inb, int ine)
    {
        if(inb > ine  || pre == lenp) return NULL;
        int root = indexof(inorder, postorder[pre], inb, ine);
        if(root >= 0)
            pre--;
        else
            return NULL;
        TreeNode *right = build(inorder, postorder, pre, root+1, ine);
        TreeNode *rootT = new TreeNode(inorder[root]);
        rootT->right = right;
        rootT->left = build(inorder,postorder, pre, inb, root-1);
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
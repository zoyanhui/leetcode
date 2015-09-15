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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!p&&!q) return true;
        else if(p&&q)
        {
            if(p->val != q->val) return false;
            else
            {
                bool res = true;
                if(p->left && q->left) res &= isSameTree(p->left,q->left);
                else if(!p->left && !q->left) res &=true;
                else return false;
                
                if(p->right && q->right) res &= isSameTree(p->right,q->right);
                else if(!p->right && !q->right) res &=true;
                else return false;
                return res;
            }
        }
        else
            return false;
    }
};
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return;
        root->next = NULL;
        TreeLinkNode *nextLayer = root->left, *preLayer = root, *left = NULL, *right = NULL;
        while(nextLayer)
        {
            TreeLinkNode *preNear = preLayer->next;
            left = preLayer->left; right = preLayer->right;
            nextLayer = left->left;
            preLayer = left;
            while(left)
            {
                left->next = right;
                if(preNear)
                {
                    right->next = preNear->left;
                    left = preNear->left; right = preNear->right;
                    preNear = preNear->next;
                }
                else 
                {
                    right->next = NULL;
                    left = right = NULL;
                }               
            }
            
            
        }
    }
};
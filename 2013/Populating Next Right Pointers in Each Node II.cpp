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
        TreeLinkNode *nowN = NULL, *preN = NULL, *nextLayer = root;
        while(nextLayer)
        {
            preN = nextLayer;
            nextLayer = NULL;
            nowN = NULL;
            while(preN)
            {
                if(preN->left)
                {
                    if(nowN)
                        nowN->next = preN->left;
                    nowN = preN->left;
                    if(!nextLayer)
                        nextLayer = nowN;
                }
                if(preN->right)
                {
                    if(nowN)
                        nowN->next = preN->right;
                    nowN = preN->right;
                    if(!nextLayer)
                        nextLayer = nowN;
                }
                preN = preN->next;    
            }
            
        }
        
    }
};
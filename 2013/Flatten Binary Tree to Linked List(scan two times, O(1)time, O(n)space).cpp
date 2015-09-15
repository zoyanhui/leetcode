//DLR, O(n)
//extra memory space: vector<*>
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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       if(!root) return;
       st.clear();
       pushVector(root);
       int i;
       for(i=0; i<st.size()-1; i++)
       {
           st[i]->right = st[i+1];
           st[i]->left = NULL;
       }
       if(i>0 && i<st.size())
       {
           st[i]->left = NULL; st[i]->right = NULL;
       }
    }
private:
    vector<TreeNode*> st;
    void pushVector(TreeNode *node)
    {
        if(!node) return;
        st.push_back(node);
        pushVector(node->left);
        pushVector(node->right);
    }
};
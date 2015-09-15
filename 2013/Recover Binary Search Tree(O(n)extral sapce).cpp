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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return;
        value.clear();
        nodes.clear();
        warlkTree(root);
        sort(value.begin(),value.end());
        for(int i=0;i<value.size();i++)
        {
            nodes[i]->val = value[i];
        }
    }

private:
    void warlkTree(TreeNode *node)
    {
        if(!node) return;
        warlkTree(node->left);
        value.push_back(node->val);
        nodes.push_back(node);
        warlkTree(node->right);
    }
    
     vector<int> value;
     vector<TreeNode*> nodes;
};

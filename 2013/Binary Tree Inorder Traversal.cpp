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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        ans.clear();
       // recursionTraversal(root,ans);  // recursion method
       iterationTraversal(root, ans); // iteration method
        return ans;
    }
private:
    void recursionTraversal(TreeNode* node, vector<int> &v)  // recursion method
    {
        if(!node) return;
        recursionTraversal(node->left,v);
        v.push_back(node->val);
        recursionTraversal(node->right,v);
    }
    void iterationTraversal(TreeNode* node, vector<int> &v)  // iteration method
    {
        if(!node) return;
        stack<TreeNode*> s;
        
        while(true)
        {
            if(node)
            {
                s.push(node);
                node = node->left;
            }
            else
            {
                if(s.empty())
                   break;
                node = s.top();
                s.pop();
                v.push_back(node->val);
                node = node->right;
            }
               
            
        }
    }
};
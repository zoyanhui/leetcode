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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        int nowSum = 0;
        vector<int> v;
        findPath(root, sum, nowSum, v);
        return ans;
    }
private:
    void findPath(TreeNode *node, int sum, int &nowSum, vector<int> &v)
    {
        if(!node) return;
        v.push_back(node->val);
        nowSum += node->val;
        if(!node->left && !node->right)
        {
            if(nowSum == sum)
                ans.push_back(v);          
        }
        if(node->left)
            findPath(node->left, sum, nowSum, v);
        if(node->right)
            findPath(node->right, sum, nowSum, v);
        v.pop_back();
        nowSum -= node->val;
        
    }
    vector<vector<int>> ans;
};
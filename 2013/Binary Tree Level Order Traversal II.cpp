// walk tree from up to down, get a u2b vector for every layer,
// while finished reverse it to get answer
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        u2b.clear();
        maxlayer = -1; // first layer is b2u[0], begin at zero, -1 presents no layer
        getLayerElements(root, 0);
        vector<vector<int> > b2u;
        for(int i=u2b.size()-1; i>=0; i--)
            b2u.push_back(u2b[i]);
        return b2u;
    }
private:
    void getLayerElements(TreeNode *node, int layer)
    {
        if(!node) return;
        
        if(layer > maxlayer)
        {
            vector<int> v(1,node->val);
            maxlayer ++;
            u2b.push_back(v);
        }
        else
        {
            u2b[layer].push_back(node->val);
        }
        if(node->left)
            getLayerElements(node->left, layer+1);
        if(node->right)
            getLayerElements(node->right, layer+1);
    }
    vector<vector<int> > u2b;
    int maxlayer;
};
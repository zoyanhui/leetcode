 // walk tree from up to down, get a u2b vector for every layer,
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        u2bZigzag.clear();
        maxlayer = -1; // first layer is b2u[0], begin at zero, -1 presents no layer
        getLayerElements(root, 0);
        return u2bZigzag;
    }
private:
    void getLayerElements(TreeNode *node, int layer)
    {
        if(!node) return;
        
        if(layer > maxlayer)
        {
            vector<int> v(1,node->val);
            maxlayer ++;
            //if(layer%2)
            //    reverse(v);    //new vector has only one element, don't need to reverse
            u2bZigzag.push_back(v);
        }
        else
        {
            if(layer%2)
            {
                reverse(u2bZigzag[layer]);
                u2bZigzag[layer].push_back(node->val);
                reverse(u2bZigzag[layer]);
            }    
            else
                u2bZigzag[layer].push_back(node->val);        
            
        }
        if(node->left)
            getLayerElements(node->left, layer+1);
        if(node->right)
            getLayerElements(node->right, layer+1);
    }
    void reverse(vector<int> &v)
    {
        int len = v.size();
        int head = 0, tail = len-1;
        while(head < tail)
        {
            int temp = v[head];
            v[head] = v[tail];
            v[tail] = temp;
            head++; tail--;
        }
    }
    vector<vector<int> > u2bZigzag;
    int maxlayer;
};

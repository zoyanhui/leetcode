class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        if(n == 0) return ret;
        ret = generateParenthesis(n, n, 0, 0, 2*n);
        return ret;
    }
private:
    vector<string> generateParenthesis(int l, int r, int lQ, int rQ, int len) 
    {
        vector<string> ret;
        if(len == 0) return ret;
        
        if(lQ > rQ && r > 0)
        {
            vector<string> v = generateParenthesis(l, r-1, lQ, rQ+1, len-1);
            string s = ")";
            int i;
            for(i=0; i< v.size(); i++)
            {
                
                ret.push_back(s + v[i]);
            }
            if(i == 0)
                ret.push_back(s);
                
        }
        if(l > 0)
        {
            vector<string> v = generateParenthesis(l-1, r, lQ+1, rQ, len-1);
            string s = "(";
            int i;
            for(i=0; i< v.size(); i++)
            {
                     
                ret.push_back(s+ v[i]);
            } 
            if(i == 0)
                ret.push_back(s);
        }
        return ret;
    }
};
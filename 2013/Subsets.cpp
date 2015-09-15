class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = S.size();
        vector<int> nullV;
        vector<vector<int> > ret;
        ret.push_back(nullV);
        if(len <=0) return ret;
        sort(S.begin(), S.end()); // sort S to non-descending order
        
        for(int i =0; i< len; i++)
        {
            int rlen = ret.size();            
            for(int j=1; j<rlen; j++)
            {
                vector<int> temp = ret[j];
                temp.push_back(S[i]);
                ret.push_back(temp);
            }
            ret.push_back(vector<int>(1, S[i]));
        }
        return ret;
    }
};
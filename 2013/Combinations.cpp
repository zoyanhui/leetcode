class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        int cur = 0;
	//#region 
	//this region can be replaced by:
		//vector<int> v;
		//combine(v, ret, 1, n, k, cur);
	//but there will be some unnecessary iteration at i=(n-k+2 : n)
        for(int i=1; i<=n-k+1; i++)
        {
            vector<int> v;
            v.push_back(i);
            cur = 1;
            combine(v, ret, i+1, n, k, cur);
        }
	//#end region
        return ret;
    }
private:
    void combine(vector<int> &v, vector<vector<int> > &ret, int begin, const int n, const int k, int &cur)
    {        
        if(cur == k)
        {
            ret.push_back(v);
            return;
        }
        if(begin >n) return;
        for(int i=begin; i<=n; i++)
        {
            v.push_back(i);
            cur++;
            combine(v, ret, i+1, n, k, cur);
            v.pop_back();
            cur--;
        }
        
    }
};
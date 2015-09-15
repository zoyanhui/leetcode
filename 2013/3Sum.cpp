class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        int len = num.size();
        if(len < 3) return ret;
        
        sort(num.begin(), num.end());
        for(int i =0; i<= len-3; i++)
        {
            if(i!=0 && num[i] == num[i-1]) continue;
            int m = i+1, n = len-1;
            while(m < n)
            {
                int sum = num[i] + num[m] + num[n];
                if(sum < 0) m++;
                else if(sum > 0) n--;
                else
                {
                    vector<int> v;
                    v.push_back(num[i]); v.push_back(num[m]); v.push_back(num[n]);
                    ret.push_back(v);
                    m++; n--;
                    while(m<n && num[m] == num[m-1]) m++;
                    while(m<n && num[n] == num[n+1]) n--;
                }
            }
        }
        return ret;
    }
};
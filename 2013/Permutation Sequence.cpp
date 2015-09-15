class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int deg = 1, d = 1;
        while(d < n)
        {
            d++;
            deg *= d;
        }
       
        deg /= d;  d--;
        
       
        string ret(n,'0');
        vector<int> leaving(n, 0);
        for(int j =0; j < n; j++)
            leaving[j] = j + 1;
        int retIndex = 0;
        while(k && d)
        {
            int nd = k/deg;
            k %= deg;
            
            if(k == 0)
            {
                k = deg;
                ret[retIndex++] += leaving[nd-1];
                leaving.erase(leaving.begin()+nd-1);
            }
            else
            {
                ret[retIndex++] += leaving[nd];
                leaving.erase(leaving.begin()+nd);
            }
                
            deg /= d;  d--;
        }
        ret[retIndex++] += leaving[0];
        
        
        return ret;
    }
};
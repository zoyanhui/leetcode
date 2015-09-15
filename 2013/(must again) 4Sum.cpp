class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        
        int len = num.size();
        if(len < 4) return ret;
        sort(num.begin(), num.end());
        int a = 0, b = len-1, c, d;
        for(int a=0; a <len-3; a++)
        {
            if(a!= 0 && num[a] == num[a-1]) continue;
            for(int b = len-1; b>=a+3; b--)
            {
                if(b!= len-1 && num[b] == num[b+1]) continue;
                c = a+1;  d = b-1;
                while(c < d)
                {
                    int sum = num[a] + num[b] + num[c] + num[d];
                    if(sum == target)
                    {
                        vector<int> v;  
                        v.push_back(num[a]); v.push_back(num[c]);
                        v.push_back(num[d]); v.push_back(num[b]);
                        ret.push_back(v);
                        c++;  d--;
                        while (c < d && num[c] == num[c - 1]) {  
                            c++;  
                        }  
                        while (c < d && num[d] == num[d + 1]) {  
                            d--;  
                        }  
                    }
                    else if(sum < target)
                        c++;
                    else
                        d--;
                    
                }
            }
        }
        return ret;
    }
};
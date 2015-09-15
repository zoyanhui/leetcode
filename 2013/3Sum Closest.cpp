class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int minD = INT_MAX;
        int ret;
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
                int d = abs(sum - target);
                if(d < minD)
                {
                    minD = d;
                    ret = sum;
                } 
                if(sum < target) m++;
                else if(sum > target) n--;
                else
                {
                    return target;
                }
            }
        }
        return ret;
    }
};
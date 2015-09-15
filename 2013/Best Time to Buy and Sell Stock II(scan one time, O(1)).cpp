class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = prices.size();
        if(len <= 1) return 0;
        int sum = 0, cur = 0;
        for(int i=1;i <len; i++)
        {
            int temp = prices[i] - prices[i-1];
            if(temp > 0)
                cur += temp;
            else
            {
                sum += cur;
                cur = 0;
            }
        }
        if(cur > 0) sum += cur;
        return sum;
    }
};
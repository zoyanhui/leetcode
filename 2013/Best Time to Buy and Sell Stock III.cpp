class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = prices.size();
        if(len<2) return 0;
        int min = prices[0]; 
        vector<int> frontMax(len, 0);
        for(int i =1;i < len;i++)
        {
            if(prices[i] < min)
                min = prices[i];
            int temp = prices[i] - min;
            frontMax[i] = temp >frontMax[i-1] ? temp : frontMax[i-1];
        }
        int max = prices[len-1]; 
        vector<int> behindMax(len, 0);
        for(int i =len -2;i >= 0; i--)
        {
            if(prices[i] > max)
                max = prices[i];
            int temp = max - prices[i];
            behindMax[i] = temp >behindMax[i+1] ? temp : behindMax[i+1];
        }
        int sum = 0;
        for(int i =0; i<len; i++)
        {
            int temp = frontMax[i] + behindMax[i];
            if(temp > sum) sum = temp;
        }
        return sum;
    }
};
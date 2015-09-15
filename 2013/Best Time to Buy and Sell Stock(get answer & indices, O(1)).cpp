//scan one time of the array
class Solution {
public:
    int maxProfit(vector<int> &prices) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = prices.size();
        if(len <= 1) return 0;
        int buy = 0, sell = 0; //indicate the day of buy or sell
        int maxdiff = 0;// indicate the max profit can be got nowtime
        int min = 0; // indicate the indices of min element
        for(int i=0;i <len; i++)
        {
            if(prices[i] < prices[min])
                min = i;
            int diff = prices[i] - prices[min]; // a temp diff(profits)
            if(diff > maxdiff)
            {
                maxdiff = diff;
                buy = min;
                sell = i;
            }
	            
        }
        return maxdiff;
    }
};
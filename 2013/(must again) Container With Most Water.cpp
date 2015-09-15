class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = height.size();
        if(len <= 1) return 0;
        
        int i = 0, j= len-1;
        
        int sum = 0;
        while(i <= j)
        {
            int temp;
            if(height[j] > height[i])
            {
                temp = height[i]* (j-i);
                if(temp >sum) sum = temp;
                i++;
            }
            else 
            {
                temp = height[j]*(j-i);
                if(temp > sum) sum = temp;
                j--;
                
            }
        }
        return sum;
    }
};
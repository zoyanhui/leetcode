class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = digits.size();
        vector<int> ans(len,0);
        int i = len-1, j = 0, plus = 1;
        while(i>=0 && digits[i])
        {
            int temp = digits[i] + plus;
            ans[j++] = temp % degree;
            plus = temp /10;
            i--;
        }
            
        if(i >= 0)
        {
            ans[j++] = digits[i] + plus;
            for(i--; i >=0; i--)
                ans[j++] = digits[i];
        }
            
        else if(plus)
        {
            ans.push_back(plus);
            j++;
        }
            
        for(int i =0, k = (j >= len ? j : len) - 1; i < k; i++, k--)
        {
            int temp = ans[i];
            ans[i] = ans[k];
            ans[k] = temp;
        }
        return ans;
    }
private:
    const int degree = 10;
};
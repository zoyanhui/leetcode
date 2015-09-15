class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = num1.length(), len2 = num2.length();
        reverse(num1, len1); reverse(num2, len2);
       
        for(int i=0; i<len1; i++)
            num1[i] -= '0';
        for(int i=0; i<len2; i++)
            num2[i] -= '0';
        int k =0;
        
        int carry = 0, totalDigit = len1+len2-1;
        vector<int> ret(totalDigit+1, -1);
        while(k < totalDigit)
        {
            int sum = carry;
            for(int i=0; i<=k; i++)
            {
                if(i >= len1 || k-i >= len2) continue;
                sum += num1[i] * num2[k-i];
            }
            ret[k] = sum%10;
            carry = sum/10;
            k++;
        }
        while(carry >0)
        {
            ret[k++] = carry%10;
            carry /= 10;
        }
        
        k=0;
        int i=ret.size()-1;
        while(i >=0 && ret[i] <=0) i--;
        if(i < 0) return "0";
        string result(i+1, '0');
        for(; i>=0 && ret[i] >= 0; i--)
        {
            result[k++] += ret[i];
        }
        return result;
    }
    
private:
    void reverse(string &s, int len = 0)
    {
        if(len == 0) len = s.length();
        int left = 0, right = len-1;
        while(left < right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left ++;  right --;
        }
    }
    
};
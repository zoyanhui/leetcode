class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        reverse(a);  reverse(b);
        char carry = '0';
        int lena = a.length(), lenb = b.length();
        
        if(lena < lenb)
        {
            int temp = lena;  lena = lenb;  lenb = temp;
            string tmp = b;  b = a;  a = tmp;
        }
        string ret(a);   
        int i;
        for(i=0; i < lenb; i++)
        {
            ret[i] = a[i] ^ b[i] ^ carry;
            carry = '0' + (a[i] + b[i] + carry) / ('0' + '1' + '1');
        }
        for(i = lenb; i <lena; i++)
        {
            ret[i] = (a[i] ^ carry) ? '1' : '0';
            carry = '0' + (a[i] + carry) / ('1' + '1');
        }
        if(carry == '1')
            ret += "1";
        reverse(ret);
        return ret;
    }
private:
    void reverse(string &s)
    {
        int left =0, right = s.length()-1;
        while(left < right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left ++; right--;
        }
    }
    
};
typedef unsigned int BYTE;
class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bits = sizeof(BYTE) *8;
        int len = n /bits, tlen = n%bits;
        //if(n%bits)  len += 1;
        vector<BYTE> bytes(len+1, 0);
        ret.clear();
        ret.push_back(0);
        
        
        for(int i=1; i <= n; i++)
        {
            changeCode(bytes,i);
           
        }
        
        return ret;
        
    }
private:
    int bits;
    vector<int> ret;
    void changeCode(vector<BYTE> &bytes, int n)
    {
        if(n <=0) return;
        int len = n /bits, tlen = n%(bits +1);
        BYTE each = 1;
        bytes[len] ^= each << (tlen-1);
        ret.push_back(getValue<int>(bytes));
        for(int i=1; i <= n-1; i++)
        {
            changeCode(bytes, i);         
        }        
    }
    template<typename T>
    T getValue(vector<BYTE> &v)
    {
        int len = v.size();
        T ans = 0;
        int bits = sizeof(BYTE) *8;
        for(int i =0; i<len; i++)
        {
            ans <<= bits;
            ans += v[i];
        }
        return ans;
    }
};
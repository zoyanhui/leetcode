//three layers of iteration

class Solution {
public:
    bool check(string &s, int beg, int end)
     {
         string ip(s, beg, end - beg + 1);
         if (ip.size() == 1)
             return "0" <= ip && ip <= "9";
         else if (ip.size() == 2)
             return "10" <= ip && ip <= "99";
         else if (ip.size() == 3)
             return "100" <= ip && ip <= "255";
         else
             return false;
     }
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        int i1 = 1, i2 = 2, i3 = 3;  // three dot position, 0<i1<i2<i3<len
        vector<string> ans;
        ans.clear();
        //while(i1 < i2 && i2 < i3 && i3 < len)
        for(i1=1; i1<=3 && i1 < len-2; i1++)
        {
            for(i2 = i1+1; i2<=i1+3 && i2 < len -1; i2++)
            {
                for(i3 = i2+1; i3<=i2+3 && i3 < len; i3++)
                {
                    if(len - i3 > 3) continue;
                    
                    if(!check(s,0,i1-1))  continue;
                    if(!check(s,i1,i2-1))  continue;
                    if(!check(s,i2,i3-1))  continue;
                    if(!check(s,i3,len-1))  continue;
                    string temp = s;
                    temp.insert(i1,1,'.'); temp.insert(i2+1,1,'.'); temp.insert(i3+2,1,'.');
                    ans.push_back(temp);
                }
            }
        }
            
        return ans;
    }
};
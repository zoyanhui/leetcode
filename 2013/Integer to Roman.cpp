class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string ret = "";
        int k = 0;
        int deg[4] = {1000, 100, 10, 1}; 
        while(num)
        {
            int value = num / deg[k];
            switch(k)
            {
                case 0:
                    for(int i = 0; i < value; i++)
                        ret += 'M';
                    break;
                case 1:
                    if(value == 9)
                    {
                        ret += "CM";
                    }
                    else if(value >= 5) 
                    {
                        ret += 'D';
                        for(int i = 5; i <value; i++) ret += 'C';
                    }
                    else if(value == 4)
                        ret += "CD";
                    else
                    {
                        for(int i = 0; i <value; i++) ret += 'C';
                    }
                    break;
                case 2:
                    if(value == 9)
                    {
                        ret += "XC";
                    }
                    else if(value >= 5) 
                    {
                        ret += 'L';
                        for(int i = 5; i <value; i++) ret += 'X';
                    }
                    else if(value == 4)
                        ret += "XL";
                    else
                    {
                        for(int i = 0; i <value; i++) ret += 'X';
                    }
                    break;

                case 3:
                    if(value == 9)
                    {
                        ret += "IX";
                    }
                    else if(value >= 5) 
                    {
                        ret += 'V';
                        for(int i = 5; i <value; i++) ret += 'I';
                    }
                    else if(value == 4)
                        ret += "IV";
                    else
                    {
                        for(int i = 0; i <value; i++) ret += 'I';
                    }
                    break;
            }
            num %= deg[k];
            k++;
        }
        return ret;
    }
};
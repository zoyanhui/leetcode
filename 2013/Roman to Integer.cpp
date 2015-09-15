class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0;
        int i =0;
        char pre = '0';
        int preN = 0;
        while(s[i] != '\0')
        {
            if(pre == '0') pre = s[i];
            int m;
            switch(s[i])
            {
                case 'M':
                    m = 0;
                    while(s[i] == 'M'){m++; i++;}
                    if(pre != '\0' && pre != 'M')  sum += m*1000 - 2*preN;
                    else    sum += m * 1000;
                    pre = 'M'; preN =0;
                    break;
                case 'D':
                    m = 0;
                    while(s[i] == 'D'){m++; i++;}
                    if(compareRoman('D', pre))  {sum += m*500 - 2*preN; preN =0;}
                    else    { sum += m*500; preN =m*500;}
                    pre = 'D'; 
                    break;
                case 'C':
                    m = 0;
                    while(s[i] == 'C'){m++; i++;}
                    if(compareRoman('C', pre))  {sum += m*100 - 2*preN; preN =0;}
                    else    { sum += m*100; preN =m*100;}
                    pre = 'C'; 
                    break;
                case 'L':
                    m = 0;
                    while(s[i] == 'L'){m++; i++;}
                    if(compareRoman('L', pre))  {sum += m*50 - 2*preN; preN =0;}
                    else    { sum += m*50; preN =m*50;}
                    pre = 'L'; 
                    break;
                case 'X':
                    m = 0;
                    while(s[i] == 'X'){m++; i++;}
                    if(compareRoman('X', pre))  {sum += m*10 - 2*preN; preN =0;}
                    else    { sum += m*10; preN =m*10;}
                    pre = 'X'; 
                    break;
                case 'V':
                    m = 0;
                    while(s[i] == 'V'){m++; i++;}
                    if(compareRoman('V', pre))  {sum += m*5 - 2*preN; preN =0;}
                    else    { sum += m*5; preN =m*5;}
                    pre = 'V';                 
                    break;
                case 'I':
                    m = 0;
                    while(s[i] == 'I'){m++; i++;}                    
                    sum += m; preN = m;
                    pre = 'I'; 
                    break;
                default:
                    return -1;
            }
        }
        return sum;
    }
private:
    bool compareRoman(char l, char r)  // l> r : true ; else false
    {
        if(l == r) return false;
        if(l == 'M') return true;
        if(l == 'D' && r != 'M') return true;
        if(l == 'C' && r != 'M' && r!= 'D') return true;
        if(l == 'L' && (r == 'X' || r == 'V' || r == 'I')) return true;
        if(l == 'X' && (r == 'V' || r == 'I')) return true;
        if(l == 'V' && r == 'I') return true;
        return false;
    }
};
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int i =0, j = s.length()-1;
        while(i<j){              
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++; j--;
        }
        return s;
    }
};


int main(){
    Solution solution;
    cout<<solution.reverseString("hello")<<endl;
}
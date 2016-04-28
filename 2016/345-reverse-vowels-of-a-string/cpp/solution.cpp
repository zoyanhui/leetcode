#include <iostream>
using namespace std;

class Solution {
private:
    static const char vowels[11];
public:
    string reverseVowels(string s) {
        int i =0, j = s.length()-1;
        while(i<j){
            for(;i<j&&strchr(vowels,s[i]) == NULL;i++);
            for(;i<j&&strchr(vowels,s[j]) == NULL;j--);   
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++; j--;
        }
        return s;
    }
};

const char Solution::vowels[11] = {'a','i','u','e','o','A','I','U','E','O','\0'};


int main(){
    Solution solution;
    cout<<solution.reverseVowels("hello")<<endl;
}
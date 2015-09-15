class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long left = 0, right = x , mid;
        while(left <= right)
        {
            mid = (right + left) /2;
            long long temp = mid * mid;
            if(temp <= x && (temp+2*mid+1) > x) return mid;
            else if(temp > x) right = mid -1;
            else left = mid + 1;
        }
        return -1;
    }
};
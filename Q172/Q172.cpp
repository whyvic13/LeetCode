//https://en.wikipedia.org/wiki/Trailing_zero

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n /= 5){
            ans += n;
        }
        return ans;
    }
};

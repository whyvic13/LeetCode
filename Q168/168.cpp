class Solution {
public:
    string convertToTitle(int n) {
        string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ans;
        while(n){
            ans = s[(n-1)%26] + ans; // 这样写可以在string头部加char
            n = (n-1)/26;
        }
        return ans;
    }
};

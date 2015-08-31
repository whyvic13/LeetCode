class Solution {
public:
    string convertToTitle(int n) {
        string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ans;
        while(n){
            ans = s[(n-1)%26] + ans;
            n = (n-1)/26;
        }
        return ans;
    }
};

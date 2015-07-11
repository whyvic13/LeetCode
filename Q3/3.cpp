class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for(int i=0;i<s.length();i++){
            int map[128] = {0};
            int length = 0;
            for(int j=i;j<s.length();j++){//begin from i
                if(map[s[j]]) break;
                map[s[j]] = 1;
                length++;
            }
            ans = max(ans,length);
        }
        return ans;
    }
};

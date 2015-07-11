class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int map_s[128] = {0};
        int map_t[128] = {0};
        for(int i=0;i<s.length();i++){
            if(map_s[s[i]] != map_t[t[i]]) return false;
            map_s[s[i]] = i+1;
            map_t[t[i]] = i+1;
        }
        return true;
    }
};

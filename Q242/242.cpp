class Solution {
public:
    bool isAnagram(string s, string t) {
        int map[26]={0};
        int slen = s.size();
        int tlen = t.size();
        if(slen != tlen) return false;
        for(int i=0;i<slen;i++){
            map[s[i]-'a']++;
            map[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(map[i]<0) return false;
        }
        return true;
    }
};

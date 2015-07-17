class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        int count[26] = {0};
        int len = s1.size();
        for(int i=0;i<s1.size();i++){
            count[s1[i]-'a'] ++;//attention - 'a'
            count[s2[i]-'a'] --;
        }
        for(int i=0;i<26;i++){
            if(count[i] != 0) return false;
        }
        
        for(int i=1;i<len;i++){
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i))) return true;
            if(isScramble(s1.substr(0,i),s2.substr(len-i)) && isScramble(s1.substr(i),s2.substr(0,len-i))) return true;
        }
        return false;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        string ans; 
        if(s.empty()) return ans;
        if(s.size() == 1) return s;
        int maxlen = 0;
        for(int i=0;i<s.size();){
            if(s.size()-i <= maxlen/2) break;
            int j=i,k=i;
            while(k<s.size()-1 && s[k+1] == s[k]) k++;
            i = k+1;
            for(;j>0 && k<s.size()-1 && s[j-1] == s[k+1];) {j--; k++;}
            int len = k-j+1;
            if(len > maxlen){
                maxlen = len;
                ans = s.substr(j,maxlen);
            }
        }
        return ans;
    }
};

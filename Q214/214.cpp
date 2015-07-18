//use the same method as longest palindrome, but change it with longest prelix palindrome
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.empty()) return s;
        int maxL = 0;
        for(int i=0;i<=s.size()/2;){
            int j=i,k=i;
            while(k<s.size()-1 && s[k+1] == s[k]) k++;
            i = k+1;// attention
            while(j>0 && k<s.size()-1 && s[j-1] == s[k+1]){k++; j--;}
            if(j==0){
                maxL = max(maxL,k-j+1);
            }
        }
        string tmp = s.substr(maxL,s.size()-maxL);
        reverse(tmp.begin(),tmp.end());
        tmp += s;
        return tmp;
    }
};

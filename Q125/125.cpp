class Solution {
public:
    bool isPalindrome(string s) {
        if(!s.size()) return true;
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z') s[i] += 'a'-'A';
            else if(s[i]>='a' && s[i]<='z') ;
            else if(s[i]>='0' && s[i]<='9') ;
            else {
                s.erase(i,1);
                i--;//attention this
            }        
        }
        string tmp = s;
        reverse(tmp.begin(),tmp.end());
        if(tmp == s) return true;
        else return false;
        
    }
};

//solution 2
//Use two pointers. One from the beginning of the string, another from the ending of the string. 
//Skip those non-alphanumeric characters
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int i = 0, j = s.length() - 1;
        while (i < j){
            while (i < j && !isalnum(s[i])){i++;}
            while (i < j && !isalnum(s[j])){j--;}
            if (tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};

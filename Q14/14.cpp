class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(!strs.size()) return res;
        int min = INT_MAX;
        for(auto s:strs){
            min = (min>s.size())? s.size():min;
        }
        for(int i=0;i<min;i++){
            char tmp = strs[0][i];
            bool flag = true;
            for(auto s:strs){
                if(s[i] != tmp){
                    flag = false;
                    break;
                }
            }
            if(!flag) return res;
            res += tmp;
        }
        return res;
    }
};

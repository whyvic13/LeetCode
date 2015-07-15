class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string s1,s2,s3,s4;
        //s1,s2,s3,s4 length : i,j,k,size()-i-j-k
        for(int i=1;i<4&&i<s.size()-2;i++){
            for(int j=1;j<4&&i+j<s.size()-1;j++){
                for(int k=1;k<4&&i+j+k<s.size();k++){
                    s1 = s.substr(0,i);
                    s2 = s.substr(i,j);
                    s3 = s.substr(i+j,k);
                    s4 = s.substr(i+j+k,s.size()-i-j-k);
                    if(isValid(s1)&&isValid(s2)&&isValid(s3)&&isValid(s4)){
                        ans.push_back(s1+"."+s2+"."+s3+"."+s4);
                    }
                }
            }
        }
        return ans;
    }
    
    int string2int(string s){
        int tmp = 0;
        for(auto i:s){
            tmp = tmp*10 + i - '0';
        }
        return tmp;
    }
    
    bool isValid(string s){
        if(s.size()>3 || (s[0] == '0' && s.size()>1) || string2int(s)>255) return false;
        return true;
    }
};

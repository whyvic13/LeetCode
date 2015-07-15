class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string res;
        bool isAdd = false;
        int i,j;
        for(i=0,j=0;i<a.size() && j<b.size();i++,j++){
            if(isAdd == false && a[i]=='1' && b[j]=='1'){
                isAdd = true;
                res += '0';
            }
            else if(isAdd == true && a[i]=='1' && b[j] == '1'){
                isAdd = true;
                res += '1';
            }
            else if(isAdd == true && (a[i]-'0')^(b[j]-'0') == 1){
                isAdd = true;
                res += '0';
            }
            else if(isAdd == true && a[i] == '0' && b[j] == '0'){
                isAdd = false;
                res += '1';
            }
            else if(isAdd == false && (a[i]-'0')^(b[j]-'0') == 1){
                isAdd = false;
                res += '1';
            }
            else if(isAdd == false && a[i] == '0' && b[j] == '0'){
                isAdd = false;
                res += '0';
            }
        }
        if(i == a.size() && j==b.size()){
            if(isAdd) res += '1';
        }
        else{
            if(i == a.size()){
                for(;j<b.size();j++){
                    if(isAdd && b[j] == '1'){
                        res += '0';
                        isAdd = true;
                    }
                    else if(isAdd && b[j] == '0'){
                        res += '1';
                        isAdd = false;
                    }
                    else if(!isAdd && b[j]=='1'){
                        res += '1';
                        isAdd = false;
                    }
                    else if(!isAdd && b[j] == '0'){
                        res += '0';
                        isAdd = false;
                    }
                }
            }
            else if(j == b.size()){
                for(;i<a.size();i++){
                    if(isAdd && a[i] == '1'){
                        res += '0';
                        isAdd = true;
                    }
                    else if(isAdd && a[i] == '0'){
                        res += '1';
                        isAdd = false;
                    }
                    else if(!isAdd && a[i]=='1'){
                        res += '1';
                        isAdd = false;
                    }
                    else if(!isAdd && a[i] == '0'){
                        res += '0';
                        isAdd = false;
                    }
                }
            }
            if(isAdd) res += '1';
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

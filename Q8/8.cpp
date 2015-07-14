class Solution {
public:
    int myAtoi(string str) {
        if(!str.size()) return 0;
        long res=0;
        int i = str.find_first_not_of(' ');
        int flag = 1;
        if(str[i] == '+' || str[i] == '-'){
            flag = (str[i++] == '+')?1:-1;
        }
        while(str[i]>='0' && str[i]<='9'){
            res = res*10 + str[i++]-'0';
            if(res*flag >= INT_MAX) return INT_MAX;
            if(res*flag <= INT_MIN) return INT_MIN;
        }
        return res*flag;
    }
};

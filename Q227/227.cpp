//converse the expression to Suffix expression, and then use suffix expression to calculate
class Solution {
public:
    stack<string> num;
    stack<char> mark;
    int calculate(string s) {
        stack<int> calc;
        stack<string> rev;//reverse the stack num;
        convert_MtoB(s);
        while(!num.empty()){
            rev.push(num.top());
            num.pop();
        }
        while(!rev.empty()){
            string s = rev.top();
            rev.pop();
            if(s!="+" && s!="-" && s!="*" && s!="/"){
                 calc.push(string2int(s));
            }
            else{
                int b = calc.top();
                calc.pop();
                int a = calc.top();
                calc.pop();
                if(s=="+") calc.push(a+b);
                else if(s=="-") calc.push(a-b);
                else if(s=="*") calc.push(a*b);
                else if(s=="/") calc.push(a/b);
            }
            
        }
        return calc.top();
        
    }
    
    void convert_MtoB(string s){
        s += '#';
        mark.push('#');
        for(int i=0;i<s.size() && !mark.empty();i++){
            if(s[i] == ' ') ;
            else if(s[i] <= '9' && s[i] >= '0'){
                string tmp = "";
                while(i<s.size() && s[i] <= '9' && s[i] >= '0'){
                    tmp += s[i++];
                }
                i--;
                num.push(tmp);
            }
            else{
                char top = mark.top();
                if(compare(top,s[i]) < 0) mark.push(s[i]);
                else if(compare(top,s[i]) == 0) mark.pop();
                else{
                    while(compare(top,s[i]) > 0){
                        string stmp = "";
                        num.push(stmp+mark.top());
                        mark.pop();
                        top = mark.top();
                    }
                    if(compare(top,s[i]) == 0) mark.pop();
                    else mark.push(s[i]);
                }
            }

        }
    }
    
    int compare(char top, char c){
        if(top == '+' || top == '-'){
            if(c == '*' || c=='/' || c=='(') return -1;
            else return 1;
        }
        else if(top == '*' || top == '/'){
            if(c=='(') return -1;
            else return 1;
        }
        else if(top == '('){
            if(c==')') return 0;
            else return -1;
        }
        else if(top == '#'){
            if(c=='#') return 0;
            else return -1;
        }
    }
    
    int string2int(string s){
        int tmp = 0;
        for(auto i:s){
            tmp = tmp * 10 + i-'0';
        }
        return tmp;
    }
};

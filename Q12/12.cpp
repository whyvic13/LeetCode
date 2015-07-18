class Solution {
public:
    string intToRoman(int num) {
        string THOUS[]  = {"","M","MM","MMM"};
        string HUNDS[]  = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string TENS[]   = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string ONES[]   = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string sum;
        sum += THOUS[(num/1000)%10];
        sum += HUNDS[(num/100)%10];
        sum += TENS[(num/10)%10];
        sum += ONES[num%10];
        return sum;
    }
};

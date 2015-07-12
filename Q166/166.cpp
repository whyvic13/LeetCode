class Solution {
public:
    string fractionToDecimal(int64_t numerator, int64_t denominator) {
        if(numerator == 0) return "0";
        string res;
        if((numerator>0)^(denominator>0))  res += '-';
        int64_t n = abs(numerator);
        int64_t d = abs(denominator);
        res += to_string(n/d);
        if(!(n % d)) return res;
        res += '.';
        unordered_map<int,int> map;
        for(int64_t r = n%d ; r!=0 ; r %= d){
            // meet a known remainder
            // so we reach the end of the repeating part
            if(map[r] > 0){
                res.insert(map[r],1,'(');
                res += ')';
                break;
            }
            // the remainder is first seen
            // remember the current position for it
            map[r] = res.size();
            
            r *= 10;
            res += to_string(r/d);
        }
        return res;
    }
};

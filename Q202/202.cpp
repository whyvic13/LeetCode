//use hash table to check whether get into a dead loop
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> mp;
        while (mp[n] == 0){
            mp[n]++;
            n = sqrSum(n);
            if (1 == n)
                return true;
        }
        return false;
    }
    
    int sqrSum(int n){
        int tmp, sum = 0;
        while (n){
            tmp = n %10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }
};

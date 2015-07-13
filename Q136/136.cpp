//use trick: a^b^a = b
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            ans ^= nums[i];
        }
        return ans;
    }
};

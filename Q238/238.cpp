//Use tmp to store temporary multiply result by two directions. Then fill it into result. Bingo!
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        for(int i=0,tmp=1;i<nums.size();i++){
            ans[i] = tmp;
            tmp *= nums[i];
        }
        for(int i=nums.size()-1,tmp=1;i>=0;i--){
            ans[i] *= tmp;
            tmp *= nums[i];
        }
        return ans;
    }
};


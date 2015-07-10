class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long long max = LLONG_MAX;
        long long min = LLONG_MIN;
        return isValid(root,min,max);
    }
    bool isValid(TreeNode* root,long long min,long long max){
        if(!root) return true;
        if(root->val <= min || root->val >= max)
            return false;
        return isValid(root->left,min,root->val) && isValid(root->right,root->val,max);
    }
};

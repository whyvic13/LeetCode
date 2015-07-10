class Solution {
public:
    int cur = 0;
    vector<int> path;
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if(!root) return sum;
        dfs(root);
        for(auto i:path){
            sum += i;
        }
        return sum;
    }
    
    void dfs(TreeNode* root){
        cur = cur*10 + root->val;
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
        if(!root->left && !root->right) path.push_back(cur);
        cur /= 10;
    }
};

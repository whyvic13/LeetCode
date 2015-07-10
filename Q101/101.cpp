//use the same way as Q100
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return check(root->left,root->right);
    }
    
    bool check(TreeNode* p,TreeNode* q){
        if(!p || !q) return p? false : !q;
        return p->val == q->val && check(p->left,q->right) && check(p->right,q->left);
    }
};

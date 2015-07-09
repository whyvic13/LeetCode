class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        int cnt = 1;
        queue<TreeLinkNode*> node;
        TreeLinkNode *pre=NULL,*now=NULL;
        node.push(root);
        while(!node.empty()){
            int tcnt = 0;
            for(int i=0;i<cnt;){
                if(!pre){
                    pre = node.front();
                    node.pop();
                    if(pre->left){ node.push(pre->left); tcnt++;}
                    if(pre->right){ node.push(pre->right); tcnt++;}
                    i++;
                }
                if(i>=cnt) break;
                else{
                    now = node.front();
                    node.pop();
                    if(now->left){ node.push(now->left); tcnt++;}
                    if(now->right){ node.push(now->right); tcnt++;}
                    i++;
                }
                pre->next = now;
                pre = now;
            }
            pre->next = NULL; 
            pre = NULL;
            cnt = tcnt;
        }
    }
};

//from the rightest node, renew the node[layer] value
 //every layer,from right to left,renew the next pointer
class Solution {
public:
    vector<TreeLinkNode *> node;
    void connect(TreeLinkNode *root) {
        if(!root) return;
        
        TreeLinkNode *tmp = root;
        while(tmp){
            node.push_back(NULL);
            tmp = tmp->right;
        }
        DFS(root,1);//layer start from 0, to make conference with node[layer],node counts from zero
    }
    
    void DFS(TreeLinkNode *root,int layer){
        if(!root) return;
        DFS(root->right,layer+1);
        DFS(root->left,layer+1);
        while(layer > node.size()) node.push_back(NULL);//supplement right subtree
        root->next = node[layer-1];
        node[layer-1] = root;
        
    }
};

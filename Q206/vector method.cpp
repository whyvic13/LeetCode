//use vector to reverse the values of nodes
//reassign the link with reversed value
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        vector<int> node;
        ListNode *tp = head;
        while(tp){
            node.push_back(tp->val);
            tp = tp->next;
        }
        tp = head;
        reverse(node.begin(),node.end());
        for(auto i:node){
            tp->val = i;
            tp = tp->next;
        }
        return head;
    }
};

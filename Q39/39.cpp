class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int n = candidates.size();
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        vector<int> cur_vec;
        helper(candidates, n, 0, target, cur_vec, result);
        return result;
    }

    void helper(vector<int> &a, int n, int pos, int target, vector<int>& cur_vec, vector<vector<int> >& result) {
        if (target == 0 && cur_vec.size() > 0) {
            result.push_back(cur_vec);
            return;
        }

        for (int i = pos; i < n; i++) {
            if (target < a[i]) {
                break;
            } 
            if (i > 0 && a[i] == a[i-1]) continue;
            cur_vec.push_back(a[i]);
            helper(a,n, i, target-a[i], cur_vec, result);//attention:i
            cur_vec.pop_back();
        }

    }
};

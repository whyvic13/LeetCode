//SOULTION 1
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        for(int i=0;i<input.length();i++){
            char c = input[i];
            if(c == '-' || c == '+' || c == '*'){
                vector<int> lval = diffWaysToCompute(input.substr(0,i));
                vector<int> rval = diffWaysToCompute(input.substr(i+1));
                for(auto l:lval){
                    for(auto r:rval){
                        if(c == '-') ans.push_back(l-r);
                        else if(c == '+') ans.push_back(l+r);
                        else ans.push_back(l*r);
                    }
                }
            }
        }
        if(ans.empty()){
            ans.push_back(stoi(input));
        }
        return ans;
    }
};

//There are many repeating subquestions in this recursive method, therefore, 
//we could use dynamic programming to avoid this situation by saving the results for subquestions. 
//Here is the DP solution.
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> dpMap;
        return computeWithDP(input, dpMap);
    }

    vector<int> computeWithDP(string input, unordered_map<string, vector<int>> &dpMap) {
        vector<int> result;
        int size = input.size();
        for (int i = 0; i < size; i++) {
            char cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*') {
                // Split input string into two parts and solve them recursively
                vector<int> result1, result2;
                string substr = input.substr(0, i);
                // check if dpMap has the result for substr
                if (dpMap.find(substr) != dpMap.end())
                    result1 = dpMap[substr];
                else
                    result1 = computeWithDP(substr, dpMap);

                substr = input.substr(i + 1);
                if (dpMap.find(substr) != dpMap.end())
                    result2 = dpMap[substr];
                else
                    result2 = computeWithDP(substr, dpMap);

                for (auto n1 : result1) {
                    for (auto n2 : result2) {
                        if (cur == '+')
                            result.push_back(n1 + n2);
                        else if (cur == '-')
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2);
                    }
                }
            }
        }
        // if the input string contains only number
        if (result.empty())
            result.push_back(atoi(input.c_str()));
        // save to dpMap
        dpMap[input] = result;
        return result;
    }
};

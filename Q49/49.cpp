//first solution
class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        unordered_map<string,int> map;
        vector<string> res;
        for(int i=0;i<strs.size();i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            auto got = map.find(str);
            if(got == map.end()){
                map[str] = i;
            }
            else{
                res.push_back(strs[i]);
                if(got->second != -1){//put the first anagram into result
                    res.push_back(strs[got->second]);
                    got->second = -1;
                }
            }
        }
        return res;
    }
};

//second solution
/*Here is basic idea for this problem.
First, get a copy of "strs". Let's name this copy "sortedStrs".
Second, sort all strings in "sortedStrs".
And we have a hash map unordered_map<string, vector<int>> map.
Every string in "sortedStrs" will be recorded in this hash map with its position.
In the second loop, we traverse this hash map. And find each value of which size is larger than 1. Then find the original string in "strs".
Done.
*/
class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> map;
        vector<string> res;
        for(int i=0;i<strs.size();i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            map[str].push_back(i);
        }
        for(auto i=map.begin(); i!=map.end();i++){
            if(i->second.size() > 1){//not 0
                for(auto j:i->second){
                    res.push_back(strs[j]);
                }
            }
        }
        return res;
    }
};

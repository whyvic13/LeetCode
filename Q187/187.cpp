//use hash to produce unique key for unique string,and the same key for the same string
//theoretically, no hash function could guarantee completely "unique". 
//What a hash function try to guarantee is that "it's extremely hard to find a collision"
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<size_t,int> map;//size_t,	The type of the hash values produced.
        hash<string> fn;
        vector<string> res;
        for(int i=0;i<int(s.size())-9;i++){//if without int(), when s="", runtime error
            if(map[fn(s.substr(i,10))]++ == 1){
                res.push_back(s.substr(i,10));
            }
        }
        return res;
    }
};

//A straightforward method. Just check every word.
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> map,tmp;
        vector<int> ans;
        for(auto i:words) map[i]++;
        int len = words[0].size() * words.size();
        for(int i=0,j;i<=(int)s.size() - len; i++){
            tmp = map;
            string str = s.substr(i,len);
            for(j=0;j<=len-words[0].size();j+= words[0].size()){
                string tstr = str.substr(j,words[0].size());
                if(tmp[tstr] == 0) break;
                tmp[tstr]--;
            }
            if(j==len) ans.push_back(i);
        }
        return ans;
    }
};

/*There are three key variables in my solution:

unordered_map <char, int> map; unordered_map<char, int> window; int letterCounter;
variable "map" is used to indicate what characters and how many characters are in T.

variable "window" is to indicate what characters and how many characters are between pointer "slow" and pointer "fast".

Now let's start.

The first For loop is used to construct variable "map".

The second For loop is used to find the minimum window.

The first thing we should do in the second For loop is to find a window which can cover T. 
I use "letterCounter" to be a monitor. If "letterCounter" is equal to T.length(), then we find this window. 
Before that, only the first If clause can be executed. 
However, after we find this window, the second If clause can also be executed.

In the second If clause, we move "slow" forward in order to shrink the window size. Every time finding a smaller window, I update the result.

At the end of program, I return result, which is the minimum window.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        if(s.empty() || t.empty())  return res;
        int map[256] ={0};
        int window[256] ={0};
        for(auto i:t) map[i]++;
        int count = 0, minLength = INT_MAX;
        for(int slow = 0, fast = 0; fast<s.length();fast++){
            if(map[s[fast]] > 0){
                window[s[fast]]++;
                if(window[s[fast]] <= map[s[fast]]) count ++;
            }
            if(count >= t.length()){
                while(map[s[slow]] <= 0 || window[s[slow]] > map[s[slow]]){
                    window[s[slow]]--;
                    slow++;
                }
                if(fast - slow + 1 < minLength){
                    minLength = fast - slow + 1;
                    res = s.substr(slow,minLength);
                }
                //letterCounter will never change after it equals to T.length(), 
                //but the truth is that if we shrink a certain char, letterCounter will less than T.length, 
                //Also by adding these sentence, code will run much faster because of the cut-down of meaningless check.
                window[s[slow]] --;
                slow++;
                count--;
            }
        }
        return res;
    }
};

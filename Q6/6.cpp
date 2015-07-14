class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        if(s.size()<=numRows || numRows == 1) return s;
        int gap = 2*numRows-2;
        // append result row by row
        for(int i=0;i<numRows;i++){
            // for each row, the first character is in the ith position of s;
            res += s[i];
            // 2*numRows - 2 is the increment amount between two straight columns
            // i is the current location in this column
            // so colIndex is now the position of character of the same position in the next "straight column"
            int colIndex = i+gap;
            // 2*numRows - 2 - i is the position of the character in the "tilted column" (P or S or I in the example)
            // use colIndex - 2 * i (same value) because we need to increment this value every time
            // while there is still character in the "tilted column":
            while(colIndex-2*i < s.size()){
                // if it is the first or the last row, tilted column overlaps the straight column, ignore!
                if(i!=0 && i!=numRows-1){
                    res += s[colIndex-2*i];
                }
                // second: append the character in the straight column in the same row only if this position exists
                if(colIndex < s.size()){
                    res += s[colIndex];
                }
                colIndex += gap;
            }
        }
        return res;
    }
};

/*First, let's talk about mathematics.
How to determine if three points are on the same line?
The answer is to see if slopes of arbitrary two pairs are the same.
Second, let's see what the minimum time complexity can be.
Definitely, O(n^2). It's because you have to calculate all slopes between any two points.
Then let's go back to the solution of this problem.
In order to make this discussion simpler, let's pick a random point A as an example.
Given point A, we need to calculate all slopes between A and other points. There will be three cases:
Some other point is the same as point A.
Some other point has the same x coordinate as point A, which will result to a positive infinite slope.
General case. We can calculate slope.
We can store all slopes in a hash table. And we find which slope shows up mostly. Then add the number of same points to it. Then we know the maximum number of points on the same line for point A.
We can do the same thing to point B, point C...
Finally, just return the maximum result among point A, point B, point C...*/

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int ans = 0;
        for(auto i:points){
            int samePoints = 0;  
            unordered_map<double,int> map;
            for(auto j:points){
                if(i.x == j.x && i.y == j.y) samePoints ++;
                else if(i.x == j.x) map[INT_MAX]++;
                else{
                    double slot = (i.x-j.x)*1.0 / (i.y-j.y);
                    map[slot]++;
                }
            }
            int localMax = 0;
            for(auto k=map.begin();k != map.end();k++){
                localMax = max(localMax, k->second);
            }
            ans = max(ans, localMax+samePoints);
        }
        return ans;
        
    }
};

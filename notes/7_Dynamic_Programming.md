## 7_Dynamic_Programming

[300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/description/)
Solution:
```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> a;
        a.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            int x = nums[i];
            int l=0,r=a.size()-1;
            if(a[r] < x){
                a.push_back(x);
            }else{
                while(l<r){
                    int t = (l+r)>>1;
                    if(a[t]>=x){
                        r = t;
                    }else{
                        l = t+1;
                    }
                }
                a[l] = min(x, a[l]);
            }
        }
        return a.size();
    }
};
```
note that `a[j]` represents that the minimum value at the last place of any `j`-length sub-sequenece selecting from `nums[1 to i]`. We can proof that `a` should be ascending strictly, and the length of `a` should be equal to the length of the longest increasing sub-sequenece in `nums[1 to *]`. Thus, given any `nums[1 to m]` and the corresponding `a`, we can update `a` according to `nums[1 to m+1]` accordingly. We can show that atmost 1 value would be replaced with `nums[m+1]`.


[63. Unique Paths II](https://leetcode.com/problems/unique-paths-ii/) solution:
```c++
class Solution {
public:
    void init(vector<int>& dp, int n) {
        dp.clear();
        dp.push_back(1);
        for(int i=1;i<n;i++){
            dp.push_back(0);
        }
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int> dp;

        int m = obstacleGrid.size(), n;
        for(int i=0;i<m;i++){
            n = obstacleGrid[i].size();
            if(i==0) {this->init(dp, n);}
            if(obstacleGrid[i][0]) {
                dp[0] = 0;
            }
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]){
                    dp[j] = 0;
                } else {
                    dp[j] = dp[j] + dp[j-1];
                }
                
            }
        }
        return dp[n-1];
    }
};
```

[32. Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/description/) Solution:
```c++
class Solution {
public:
    vector<int> a;
    int longestValidParentheses(string s) {
        a.clear();
        a.push_back(0);
        int ans=0;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(c=='('){
                a.push_back(i+1);
            }else{
                ans = a.size()>=2?max(ans, i-a[a.size()-2]+1):ans;
                a.pop_back();
                if(a.empty()){
                    a.push_back(i+1);
                }
            }
        }
        return ans;
    }
};
```
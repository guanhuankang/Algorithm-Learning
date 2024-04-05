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


## 8. Amortized Analysis

### 8.1 Two pointers method
[1. Two Sum](https://leetcode.com/problems/two-sum/description/)
solution:
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> a;
        for(int i=0;i<nums.size();i++){
            a.push_back(pair<int, int>{nums[i], i});
        }
        sort(a.begin(), a.end());

        int i=0, j=nums.size()-1;
        while(i<j){
            int tmp = a[i].first+a[j].first;
            if(tmp > target){
                j--;
            }else if(tmp < target){
                i++;
            }else{
                return vector<int>{a[i].second,a[j].second};
            }
        }
        return vector<int>();
    }
};
```

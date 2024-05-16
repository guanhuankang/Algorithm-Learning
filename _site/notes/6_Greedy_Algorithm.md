## 6. Greedy Algorithm
[Leetcode 11. Container With Most Water ](https://leetcode.com/problems/container-with-most-water/description/)[](https://leetcode.com/problems/container-with-most-water/description/)

Solution: 
```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int cap = 0, left=0, right=height.size()-1;
        while(left < right){
            if(height[left] < height[right]){
                cap = max(cap, height[left] * (right - left));
                left++;
            }else{
                cap = max(cap, height[right] * (right - left));
                right--;
            }
        }
        return cap;
    }
};
```
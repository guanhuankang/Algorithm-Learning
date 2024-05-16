## Binary Search

Search for an element in an sorted array, which contains n elements. The time complexity is O(log n):

```c++
int binary_search(vector<int> array, int target) {
    int a=0, b=array.size()-1, k;
    while(a<b){
        k = (a+b) / 2;
        if(array[k] >= target){
            b = k;
        }else{
            a = k+1;
        }
    }
    return a;
}
```
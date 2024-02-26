# C++ STL Cheat Sheet
C++ Reference Website: https://en.cppreference.com/w/cpp/17

## Sort
```C++
#include <bits/stdc++.h>
using namespace std;


bool compare(int a, int b) {
    return a>b;
}

int main() {
    int a[] = {2, 4, 3};
    sort(a, a+3, compare);
    
    for(int x: a){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}
```
 
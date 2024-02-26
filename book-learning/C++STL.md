# C++ STL Cheat Sheet
C++ Reference Website: https://en.cppreference.com/w/cpp/17
C++ Reference Website2: https://cplusplus.com/reference

## Sort
```c++
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(int a, int b) {
    return a>b;
}

int main() {
    int a[] = {2, 4, 3};
    sort(a, a+3, compare);
    return 0;
}
```

## Vector
```c++
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
    vector<string> strings;
    string s{"def"};
    strings.push_back("abc");
    strings.push_back(s);

    for(vector<string>::iterator it=strings.begin(); it!=strings.end(); ++it){
        cout<<*it<<"#";
    }
    cout<<endl;
    return 0;
}
```
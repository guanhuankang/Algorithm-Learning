# C++ STL Cheat Sheet
C++ Reference Website: https://en.cppreference.com/w/cpp/17  
C++ Reference Website2: https://cplusplus.com/reference  
Antti Book: Chapter 4  

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
#include <iostream>
using namespace std;

int main() {
    // size 10, all are initialed as 1
    // vector<int> v(10, 1);

    // claim a vector of int, size 0
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}
```

## Set
```c++
#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> s;

    for(int i=0;i<10;i++){
        s.insert(i%5);
    }
    cout << s.size() << endl;
    for(set<int>::iterator it=s.begin(); it!=s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
```

Set also supports `s.count(1)`, `s.erase(1)` and `s.erase(s.find(1))` operation (see Chapter 4.2)

## Map
```c++
#include <iostream>
#include <map>
using namespace std;

int main(){
    map<char, char> m;
    for(int i=0;i<26;i++){
        m['a'+i] = 'A'+i;
    }
    // m.erase('b');

    for(auto x: m){
        cout<< x.first <<":"<< x.second << " ";
    }
    return 0;
}
```
Map also supports `m.count('a')` to check whether a key exists, and `m.erase('a')` to erase a key.

## Iterator and ranges
```c++
// vector
sort(v.begin(), v.end());
reverse(v.begin(), v.end());
random_shuffle(v.begin(), v.end());

//array
sort(a, a+n);
reverse(a, a+n);
random_shuffle(a, a+n);

//set
set<int>::iterator it = s.begin();
s.lower_bound(x);
```
In the set structure, the function `lower_bound(x)` returns an iterator to the smallest element in the set whose value is at least `x`, and the function `upper_bound(x)` returns an iterator to the smallest element in the set whose value is larger than `x`. In both functions, if such an element does not exist, the return value is end (See Chapter 4.4).

## Bitset
```c++
#include <iostream>
#include <bitset>
using namespace std;

int main(){
    bitset<8> s;
    int num, i=0, m=1;

    cin>>num;
    while(i<8){
        s[i] = num & m? 1:0;
        i++;
        m <<= 1;
    }
    cout<<s<<endl;
    return 0;
}
```

## Stack
```c++
#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    
    for(int i=0;i<3;i++){
        cout<< s.top() << endl;
        s.pop();
    }
    return 0;
}
```
Stack `stack<T> s` is a data struture that provides two O(1) time operations: adding an element `s.push(t)`, and removing an element from the top `s.pop()`.

## Queue
```c++
#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    
    for(int i=0;i<3;i++){
        cout<< s.front() << endl;
        s.pop();
    }
    return 0;
}
```
A queue `queue<T> q` is a FIFO queue.

## Priority Queue
```c++
#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(3);
    pq.push(5);
    pq.push(7);
    pq.push(2);
    
    while(!pq.empty()){
        cout << pq.top() <<endl;
        pq.pop();
    }
    return 0;
}
```
Priority Queue can be implemented using max-heap or min-heap. The base data type can be array or vector.

> More details:  
> C++ Reference Website: https://en.cppreference.com/w/cpp/17  
> C++ Reference Website2: https://cplusplus.com/reference  
> Antti Book: Chapter 4  

#include <algorithm>
#include <iostream>
using namespace std;

bool compare(int a, int b) {
    return a>b;
}

int main() {
    int a[] = {2, 4, 3};
    sort(a, a+3, compare);
    for(int x : a){
        cout<<x<<" ";
    }
    return 0;
}
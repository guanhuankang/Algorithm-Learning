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

    cout<< "lower_bound:" << *s.lower_bound(3) << 
        " upper_bound:" << *s.upper_bound(3) <<endl;
    return 0;
}
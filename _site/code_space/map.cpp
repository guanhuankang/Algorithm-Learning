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
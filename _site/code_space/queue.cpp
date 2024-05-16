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
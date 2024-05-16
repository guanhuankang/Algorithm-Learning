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
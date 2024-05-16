#include <vector>
#include <iostream>
using namespace std;

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    printVector(v);
    //v.clear(); // clear vector

    vector<int> v2 = {4, 5, 6};
    printVector(v2);

    // size 3, all are initialed as 7
    vector<int> v3(3, 7);
    printVector(v3);

    v2.pop_back();
    cout << "v2 back:" << v2.back() << " size:" << v2.size() <<endl;
    return 0;
}
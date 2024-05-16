#include <iostream>
#include <vector>
using namespace std;

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

int main() {
    // freopen("binary_search.txt", "r", stdin);
    int T;
    cin>>T;
    while (T--) {
        vector<int> array;
        int n, x, y;

        cin >> n >> y;
        for(int i=0;i<n;i++){
            cin >> x;
            array.push_back(x);
        }

        cout << binary_search(array, y) << endl;
    }
    return 0;
    /**
    3
    5 1
    1 2 3 3 4
    5 3
    1 2 3 3 4
    5 4
    1 2 3 3 4

    output:
    0
    2
    4
    **/
}
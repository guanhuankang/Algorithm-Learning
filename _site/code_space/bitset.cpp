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
// SPOJ https://www.spoj.com/submit/INTEST/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, t=0, x;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x;
        t = x%k==0? t+1 : t;
    }
    cout<<t<<endl;
    return 0; 
}
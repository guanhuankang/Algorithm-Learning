// https://codeforces.com/contest/1933/problem/D
#include <bits/stdc++.h>
using namespace std;

int a[102345];

bool solve(){
    int n, cnt=0, minval=1e9+7;
    cin >> n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        if(tmp < minval){
            minval = tmp;
            cnt = 1;
        }else if(tmp==minval){
            cnt++;
        }
        a[i] = tmp;
    }
    // cout << minval << " " << cnt <<endl;
    if(cnt==1){
        return true;
    }
    for(int i=0;i<n;i++){
        int tmp = a[i]%minval;
        if(tmp < minval && tmp>0){
            return true;
        }
    }
    return false;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        if(solve()){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}

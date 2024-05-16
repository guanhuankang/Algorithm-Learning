// https://www.spoj.com/problems/ELEVTRBL/
#include <bits/stdc++.h>
using namespace std;
#define N 1000123

int ans[N];

int main()
{
    // freopen("elevtrbl.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    
    queue<int> q;
    memset(ans, 127, sizeof(ans));
    ans[s] = 0;
    q.push(s);
    while(!q.empty()){
        int c = q.front();
        q.pop();
        int nxt_u = (u+c)>f?c:u+c;
        int nxt_d = c<d?c:c-d;
        if(ans[nxt_u] > (ans[c]+1)){
            ans[nxt_u] = ans[c] + 1;
            q.push(nxt_u);
        }
        if(ans[nxt_d] > (ans[c]+1)){
            ans[nxt_d] = ans[c] + 1;
            q.push(nxt_d);
        }
    }
    if(ans[g] > f){
        cout << "use the stairs" << endl;
    }else{
        cout << ans[g] << endl;
    }
    return 0; 
}

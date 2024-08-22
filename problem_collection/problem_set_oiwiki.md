`tree-centroid` https://codeforces.com/problemset/problem/685/B
```c++
#include <iostream>
#include <vector>
using namespace std;
#define N 300123

int n, q;
vector<int> G[N];
int s[N], w[N], ans[N], fa[N];
vector<int> path;

void dfs(int u)
{
    s[u] = 1;
    w[u] = 0;
    int a = -1, c=0;
    for (int v : G[u])
    {
        dfs(v);
        a = s[v]>=c? v : a;
        c = max(s[v], c);

        s[u] += s[v];
        w[u] = max(w[v], w[u]);
    }
    
    ans[u] = u;
    for(int c : G[u]){
        if (c != a) continue;

        int x = ans[c];
        while(x != u){
            if(s[u] >= 2*w[x] && s[u] <= 2*s[x]){
                ans[u] = x;
                break;
            }else{
                x = fa[x];
            }
        }
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; i++)
    {
        int v;
        scanf("%d", &v);
        G[v].push_back(i);
        fa[i] = v;
    }
    dfs(1);

    while (q--)
    {
        int v;
        scanf("%d", &v);
        printf("%d\n", ans[v]);
    }

    return 0;
}
```
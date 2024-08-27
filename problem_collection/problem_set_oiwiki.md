`树的中心`, `tree-centroid`, https://oi-wiki.org/graph/tree-centroid, https://codeforces.com/problemset/problem/685/B
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

`最小生成树`, `MST`, https://oi-wiki.org/graph/mst/, https://www.luogu.com.cn/problem/P2504
```c++
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int m, n;
int jump[1005], nodes[1005][2], vis[1005];
float d[1005];

float dist(int i, int j){
    int x=nodes[i][0], y=nodes[i][1];
    int x2=nodes[j][0], y2=nodes[j][1];
    float dx = x - x2;
    float dy = y - y2;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    // freopen("in.txt", "r", stdin);

    ios::sync_with_stdio(0);

    cin >> m;
    for(int i=1;i<=m;i++){
        cin >> jump[i];
    }

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> nodes[i][0] >> nodes[i][1];
    }

    int c = 1;
    float cur=0;
    d[c] = 0.0;
    vis[c] = 1;
    for(int i=2;i<=n;i++){
        d[i] = 1e9+7.0;
        vis[i] = 0;
    }

    for(int i=2;i<=n;i++){
        float tmp = 1e9+7.0;
        int idx=-1;
        for(int j=1;j<=n;j++){
            d[j] = min(d[j], dist(c, j));
            if(vis[j]==0 && d[j]<=tmp){
                tmp = d[j];
                idx = j;
            }
        }
        vis[idx] = 1;
        cur = max(cur, tmp);
        c = idx;
    }

    // cout << cur << endl;
    int ans = 0;
    for(int i=1;i<=m;i++){
        ans = (float) jump[i] >= cur ? ans + 1 : ans;
    }
    cout << ans << endl;

    return 0;
}

```

`最小生成树`, `MST`, https://oi-wiki.org/graph/mst/, https://loj.ac/p/2149
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, c;
    Edge(int x, int y, int z) : u(x), v(y), c(z) {};
    bool operator< (const Edge x) const {
        return this->c < x.c;
    };
};

int m, n;
int fa[500];
vector<Edge> edges;

int findfa(int x) {
    if (fa[x] == x)
        return x;

    fa[x] = findfa(fa[x]);
    return fa[x];
}

inline bool together(int u, int v) {
    return findfa(u) == findfa(v);
}

inline void link(int u, int v) {
    fa[findfa(u)] = findfa(v);
}

int main() {
    // freopen("in.txt", "r", stdin);

    ios::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back(Edge(u, v, c));
    }

    sort(edges.begin(), edges.end());

    int ans = -1e9 + 1;

    for (int i = 0; i <= 350; i++) {
        fa[i] = i;
    }

    for (int i = 0; i < m; i++) {
        if (!together(edges[i].u, edges[i].v)) {
            link(edges[i].u, edges[i].v);
            ans = max(ans, edges[i].c);
        }
    }

    cout << n - 1 << " " << ans << endl;

    return 0;
}
```
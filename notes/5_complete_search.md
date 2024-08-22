## Complete Search

This note presents two complete search algorithms: Depth-First Search (DFS) and Breadth-First Search (BFS).

### Depth-First Search (DFS)
SPOJ-PT07Z: https://www.spoj.com/problems/PT07Z/ 
```c++
// https://www.spoj.com/problems/PT07Z/
#include <bits/stdc++.h>
using namespace std;
#define N 20005

struct {
    int v, nxt;
} egdes[N];
int head[N];
int ans[N];
int top;

void addEdge(int u, int v){
    egdes[top].v = v;
    egdes[top].nxt = head[u];
    head[u] = top++;
}

int dfs_leaf(int u, int fa){
    int longest = 0, second_longest = 0;
    for(int i=head[u];i!=-1;i=egdes[i].nxt){
        int v = egdes[i].v;
        if(v!=fa) {
            int a = dfs_leaf(v, u) + 1;
            second_longest = max(a, second_longest);
            if(longest < second_longest){
                swap(longest, second_longest);
            }
        }
    }
    ans[u] = longest + second_longest;
    return longest;
}

int main()
{
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, u, v;
    
    top = 0;
    memset(head, -1, sizeof(head));
    cin >> n;

    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    memset(ans, 0, sizeof(ans));
    dfs_leaf(1, -1);

    int printans = 0;
    for(int i=1;i<=n;i++){
        printans = max(ans[i], printans);
    }
    cout<<printans<<endl;
    return 0; 
}
```

How to build graph: 
```c++
struct Graph {
    int top;
    int head[N];
    struct {
        int v, nxt;
    } edges[N];

    Graph(){
        this->top=0;
        memset(this->head, -1, sizeof(this->head));
    }

    void addEdge(int u, int v){
        edges[top].v = v;
        edges[top].nxt = head[u];
        head[u] = top++;
    }
} G;

//visit all childrens of node u
for(int i=G.head[u];i!=-1;i=G.edges[i].nxt){
    int child = G.edges[i].v;
    // continue
}
```

### Breadth-First Search (BFS)
SPOJ-ELEVTRBL: https://www.spoj.com/problems/ELEVTRBL/ 

Use Queue<T> to handle the to-be-visted nodes. In SPOJ-ELEVTRBL, each floor will be visited at most once to reach the target, or he will never reach the target floor. Also, the answer should be smaller than f or "impossible".

```c++
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

```
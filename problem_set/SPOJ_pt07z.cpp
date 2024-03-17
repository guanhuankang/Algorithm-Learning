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

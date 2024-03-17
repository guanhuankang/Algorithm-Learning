## Complete Search

This note presents two complete search algorithms: Depth-First Search (DFS) and Breadth-First Search (BFS).

### Depth-First Search (DFS)
SPOJ-PT07Z: https://www.spoj.com/problems/PT07Z/ 
CPP: [Solution](../problem_set/SPOJ_pt07z.cpp)

How to build graph: 
```
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
CPP: [Solution](../problem_set/elevtrbl.cpp) 

Use Queue<T> to handle the to-be-visted nodes. In SPOJ-ELEVTRBL, each floor will be visited at most once to reach the target, or he will never reach the target floor. Also, the answer should be smaller than f or "impossible".
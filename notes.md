# Notes for Competitive Programming

>for interactive qs : use ```cout<<flush``` after every cout

## Bitwise Operations Properties

```cpp
a|b = a⊕b + a&b
a⊕(a&b) = (a|b)⊕b
b⊕(a&b) = (a|b)⊕a
(a&b)⊕(a|b) = a⊕b
```

### Addition

```cpp
a+b = a|b + a&b
a+b = a⊕b + 2(a&b)
```

### Subtraction

```cpp
a-b = (a⊕(a&b))-((a|b)⊕a)
a-b = ((a|b)⊕b)-((a|b)⊕a)
a-b = (a⊕(a&b))-(b⊕(a&b))
a-b = ((a|b)⊕b)-(b⊕(a&b))
```

## Binary Exponentation: a^b%m

```cpp
ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
```

## Quicksort

### Partition function when pivot is randomized

- Swap pivot posn with first element for ease
- Have two pointer ```left``` and ```right```
- Increase ```left``` until you find an element greater than ```pivot```
- Decrease ```right``` until you find an element smaller than ```pivot```
- Exchange them and continue this
- Stop when ```right < left```
- Position of ```pivot``` is at index of ```right```

### Inline Partition Functioon

```cpp
auto partition = [&](int left, int right) -> int{
    int pivot = nums[right], index = left - 1;
    for(int i = left; i < right; i++){
        if(nums[i] < pivot){
            index++;
            swap(nums[i], nums[index]);
        }
    }
    index++;
    swap(nums[index], nums[right]);
    return index;
};
```

### Pseudocode for Random Pivot

```cpp
quicksort(l, r){
    if(l < r){
        int p = rand()%(r - l + 1) + l;
        swap(p, r);
        m = partition(l, r)
        quicksort(l, m)
        quicksort(m+1, r)
    }
}
```

## MSB of a number

```1<<(31 - __builtin_clz(n)) ```
```__builtin_clz``` counts number of leading zeros.

## Min Heap Priority Queue

```priority_queue <T, vector<T>, greater<T>> pq```

### Custom Comparator

```cpp
struct cmp{
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        if(p1.second == p2.second) return p1.first < p2.first;
        return p1.second > p2.second;
    }
};
```

### Logic

```p1.second > p2.second``` makes the priority queue a min heap priority queue, i.e top element is min
normal priority queue is max heap.
>For typical min heap priority queue use ```greater<int>``` as comparator

## Dynamic Programming (DP)

- Recursive soln mostly use top down, iterative uses bottom up  
- Pull DP: "pull" ans from prev dp soln  
- Push DP: "push" ans to next dp soln  
- Recursive can only be pull dp  
- Order of iteration doesn't matter in recursive as we compute the ans we want, but matters in iterative  

### Solving approach

- Solve it brute force/recursively, break it into bits
- States are the variables used in the dp/recursive function
- Store the states, so a 2d dp has 2 states
- Transition is the dp/recursive function that finds a value using diff states
- If recursive soln is not obv: pull the state/transitions out of problem statement
- Every 2d dp problem can be thought of as a grid problem, easier to visualize

>Trick to find 4-adjacent elements using a loop
```cpp
int df[] = {0, 1, 0, -1, 0}
int nx = x + df[i], ny = y + df[i+1] 
//loop from i = 0 to i = 3;
```

## Set Operations

- Adding elements: ```s.insert(key);```  
- Find: ```s.find(key);```  
- Iterating through elements: ```for(auto i : s) cout<<i<<endl;```  
- Upper & Lower bound: ```set.upper_bound```, ```set.lower_bound```

## Finding Prime Numbers till n

### 1. Sieve of Eratosthenes

```cpp
int n;
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
```
O(n*loglogn) tc, O(n) mc

#### Optimisations

1. Run outer loop till root ```n``` only i.e. ```i = 2; i*i <= n```
same tc(O(n*loglog(rt(n)))), but less operations
2. Memory optimisations: only store odd numbers as 2 is the only even prime

### 2 Using Bitset

```cpp
bitset<SIZE> p;
void pre() {
    for (int i = 2; i < SIZE; i++) {
        if (!p[i]) {
            for (int j = i + i; j < SIZE; j += i) p[j] = 1;
        }
    }
    p[1] = 1;
}
```

## iota

- Used to fill a range of elements with increasing values starting from the given initial value
- ```iota(v.begin(), v.end(), 1)```  
- Only works for those STL containers that support random access using index numbers such as vector, dequeu, etc.

## Knapsack DP: 0/1 or choose not choose  

### Bottom-Up Manner 

O(n*w) mc  
```cpp
for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= W; j++) {
        // If there is no item or the knapsack's capacity is 0, dp[i][j] = 0 if i = 0 or j = 0
        int pick = 0;
        // Pick ith item if it does not exceed the capacity of knapsack
        if(wt[i - 1] <= j)
            pick = val[i - 1] + dp[i - 1][j - wt[i - 1]];
        // Don't pick the ith item
        int notPick = dp[i - 1][j];
        dp[i][j] = max(pick, notPick);
    }
}
return dp[n][W];
```

### Memory optimisation

Taking first i elements, O(n*w) time but O(w) space  
```cpp
for (int i = 1; i <= wt.size(); i++) {
 // Starting from back, so that we also have data of previous computation of i-1 items
 for (int j = W; j >= wt[i - 1]; j--) {
     dp[j] = max(dp[j], dp[j - wt[i - 1]] + val[i - 1]);
 }
}
return dp[W];
```

## Inbuilt binary search functions STL

- ```lower_bound(all(vector), val)```: returns iterator of element with value not less than ```val```, returns equal ```val```  
- ```upper_bound```: returns iterator of the min element greater than the the ```val```

## Meet in the Middle

```O((2^n/2)*log(2^n/2)) = O(n*2^n/2)```

### 3 steps: 
1. Partition the array into two
2. Find the sum(or other variable) from all subsets of ```n/2``` -> ```2^n/2```
can do this by bitmask or dfs(recursion with choose not choose)
3. Binary search on the ```2^n/2``` to make it log

```cpp
vector<ll> getsum(vector<int>& a){
    int n = a.size();
    vector<ll> ans;
    for(int i = 0; i < 1<<n; i++){
        ll curr = 0;
        for(int j = 0; j < n; j++) if(i & (1<<j)) curr += a[j];
        ans.push_back(curr);
    }
    return ans;
}

int meetInMiddle(vector<int> arr, int maxCapacity){
    int n = arr.size();
    vector<int> l(arr.begin(), arr.begin() + n/2), r(arr.begin() + n/2, arr.end());
    vector<ll> lsum = getsum(l), rsum = getsum(r);
    sort(lsum.begin(), lsum.end());
    sort(rsum.begin(), rsum.end());
    ll ans = 0;
    for(ll i: lsum){
        if(i > maxCapacity) break;
        auto it = lower_bound(rsum.begin(), rsum.end(), maxCapacity - i);
        if(it == rsum.end()) it--;
        ans = max(ans, i + *it);
    }
    return ans;
}
```

## Policy Based Data Structure (PBDS)

PBDS is an ordered set with access to the indices of the element.
```
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
```

This multiset implementation is used so as to not get errors in find. put index at second value.  
To:
- find lower bound search for ```({val, 0})```
- find the element search for ```({val, index})```
- find upper bound search for ```({val, INT_MAX})``` 

Functions of PBDS:  
- ```*p.find_by_order(i)```: shows value at ```ith``` index
- ```*p.order_of_key(i)```: shows index number of ```i```, even if it is not in the set  

## Kadane's Algorithm: Max Subarray Sum

- ```t = max(t + arr[i], arr[i]);```  
- Either choose ```prev_max_sum + arr[i]```, or start a new subarray from ```i```  
- Store result separately  
- ```ans = max(t, ans);```  
- O(n) tc, O(1) mc

## Minimising Sum of Maximum Subarray splitting into k Subarrays

- Do binary search on the maximum sum  
- Find the number of subarrays less than the sum  
- check if that number <= ```k```  

https://leetcode.com/problems/split-array-largest-sum/

## Sliding Window for exactly k Subarrays of something

### Approach

- Find number of subarrays with at most ```k```  
- Subtract it with number of subarrays with at most ```k - 1```
- The sliding window will expand rightwards

To find the number of subarrays with atmost k:
1. Start with ```l = r = 0```
2. Let r expand till the condition lets it to
3. Add ```r - l``` to the ans then increment ```l```

### Why does this work?

- We are counting number of valid subarrays starting from the ```lth``` posn
- So ```r - l``` gives the exact number of distinct subarrays starting from ```l``` which satsify the condition
of atmost ```k``` something.
- Repeat this for ```k - 1```

https://leetcode.com/problems/binary-subarrays-with-sum/

## Merge Sort

Divide, Conquer then Merge  
1. Divide: until it cannot be divided no more
2. Conquer: each subarray is sorted(as initially they are individual elements, when merging we sort them)
3. Merge: merge subarrays in sorted order

```
//merging vectors into arr[l...r]
while(i < n1 && j < n2){
    if(L[i] <= R[j]) arr[k] = L[i], i++;
    else arr[k] = R[j], j++;
    k++;
}
//copy remaining elements of L[] if there are any
while(i < n1) arr[k] = L[i], k++, i++;
while(j < n2) arr[k] = R[j], k++, j++;
```

## Tortoise-Hare Method

One pointer goes slow(Tortoise), another fast(Hare)  
eg: Finding middle element of linked list  
https://leetcode.com/problems/middle-of-the-linked-list/

## Breadth-First Search (BFS)

```
auto bfs = [&](int t)->bool{
    queue<pair<int, int>> q;
    q.push({0, 0});
    int df[] = {0, -1, 0, 1, 0}; //when traversing 4 adj 
    vector<vector<bool>> marked(n, vector<bool>(n, 0));
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        for(int i = 0; i < 4; i++){
            int nx = x + df[i], ny = y + df[i+1];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n || marked[nx][ny]) continue;
            if(grid[nx][ny] <= t){ //condition change acc to ques
                q.push({nx, ny});
                marked[nx][ny] = 1;
            }
        }
        q.pop();
    }
    return marked[n-1][n-1];
};
```

O(V+E) tc, O(V) mc

## Djikstra's Algorithm 

### Implementation using set

Doesn't require visited array

```
vector<int> dist(n, INT_MAX);
dist[src] = 0;
set<pair<int, int>> s;
s.insert({0, src});
while(!s.empty()){
    int x = (*s.begin()).first;
    int node = (*s.begin()).second;
    s.erase(s.begin());         //if you give address to red black tree(set) then it is o(1), therefore it is faster than pq.pop()
    for(auto it : adj[node]){
        int ad = it.first, wt = it.second; //assuming adj is a vector of pair with element as first and weight as second
        if(dist[ad] > dist[x] + wt){
            s.erase({dist[ad], ad});    //might be optional, can remove but will require another if checking if curDist > dist[node]
            dist[ad] = dist[x] + wt;
            s.insert({dist[ad], ad});
        }
    }
}
```

O(e*logv) tc as we go around all edges and need logV to process, O(v) mc  

> When using ```set<vector\<int\>>``` use ```(*s.begin).first```

Typical questions has multiple states in Djikstra(refer algo_mashup g) so make multiple dimension dist array

## Depth-First Search

### Recursive Lambda Function

```
function<void(int)> dfs = [&](int t)->void{
    // dbg(t);
    marked[t] = 1;
    curr.pb(t);
    for(auto it: adj[t]){
        if(!marked[it]) dfs(it);
    }
};
```
O(V+E) tc, O(V) mc

## Topological Sort/Topo Sort

Puts the vertexes in order of level, i.e. topo sort  
DFS doesn't care about the level, it just goes along a path

```
void topo(int t, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st){
    vis[t] = 1;
    for(auto i: adj) if(!vis[i]) topo(i, adj, vis, st);
    st.push(t);
}
```

O(V+E) tc, O(V) mc due to creation of stack

### Using Kahn's algorithm/the indegree method

Repeatedly finds vertices with no incoming edges and adds them to queue, basically BFS

```
vector<int> topo(vector<int>& adj){
    int n = adj.size();
    vector<int> ind(n);
    for(int i = 0; i < n; i++){
        for(auto it: adj[i]) ind[it]++;
    }
    queue<int> q;
    for(int i = 0; i < n; i++) if(!ind[i]) q.push(i);
    vector<int> ans;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        ans.push_back(t);
        for(auto i: adj[t]){
            ind[i]--;
            if(!ind[i]) q.push(i);
        }
    }
    if(ans.size() != n) return -1; //graph contains cycle
    return ans;
}
```

O(V+E) tc, O(V) mc  

> Topo sort is only valid for directed acyclic graph as undirected graph doesn't have any levels  
> Acyclic is necessary otherwise we will get stack overflow, hence used in cycle detection

## Cycle Detection

### Undirected Graph

Simple BFS or DFS

### Directed Graph

1. Topo sort using Kahn's as above == BFS using Kahn's
2. using DFS

```
bool dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& cur){
    if(cur[u]) return 1; //1 signifies contains cycle
    if(vis[u]) return 0;
    vis[u] = cur[u] = 1;
    for(auto i: adj[u]) if(dfs(i, adj, vis, cur)) return 1;
    cur[u] = 0;
    return 0;
}
```

Can also be done using ```colour``` instead of ```vis```

```
bool dfs(int t, vector<vector<int>>& adj, vector<short>& colour){
    if(colour[t] == 1) return false; //here false indicates cycle is present
    if(colour[t] == 2) return true;
    colour[t]++;
    for(auto i: adj[t]) if(!dfs(i, adj, colour)) return false;
    colour[t]++;
    return true;
}
```

## Bellman-Ford Algorithm

- Shortest Path Algorithm for graphs with negative weights edges
- Djikstra doesn't work on that as -ve weights makes the algorithm run in an infinite loop
- Applicable only for directed graphs, but can be used in undirected by making edge ```(1-2) to (1->2, 2->1)```
- Also used to detect negative weight cycles, but cannot give ans in -ve weight cycle

### Logic
- Works on relaxation of ```edges(dist[adj] > dist[curr] + weight)```
- Only need to do relaxation ```n - 1``` times in worst case
- Stop the loop once there are no more relaxations
- If relaxations occur after ```n - 1``` iteration i.e. on nth iteration then -ve weight cycle is present

### Implementation using edges

```
vector<int> d(n, INF);
d[v] = 0;
//p is used to retrieve path
vector<int> p(n, -1);
int x;
//basic of bellman ford
for (int i = 0; i < n; ++i){
    x = -1;
    for (Edge e : edges)
        if (d[e.a] < INF && d[e.b] > d[e.a] + e.cost){
            d[e.b] = max(-INF, d[e.a] + e.cost);
            p[e.b] = e.a;
            x = e.b;
        }
}
if (x == -1){
    // no negative cycle
    //retrieiving shortest path
    vector<int> path;
        for (int cur = t; cur != -1; cur = p[cur])
            path.push_back(cur);
        reverse(path.begin(), path.end());
        cout << "Path from " << v << " to " << t << ": ";
        for (int u : path)
            cout << u << ' ';
}
else {
    //retrieving -ve cycle
    int y = x;
    for (int i = 0; i < n; ++i)
        y = p[y];
    vector<int> path;
    for (int cur = y;; cur = p[cur]) {
        path.push_back(cur);
        if (cur == y && path.size() > 1)
            break;
    }
    reverse(path.begin(), path.end());
    cout << "Negative cycle: ";
    for (int u : path)
        cout << u << ' ';
}
```

### Implementation using adj

```
int n = adj.size();
d.assign(n, INF);
vector<int> cnt(n, 0);
vector<bool> inqueue(n, false);
queue<int> q;
d[s] = 0;
q.push(s);
inqueue[s] = true;
while (!q.empty()) {
    int v = q.front();
    q.pop();
    inqueue[v] = false;
    for (auto edge: adj[v]) {
        int to = edge.first;
        int len = edge.second;
        if (d[v] + len < d[to]) {
            d[to] = d[v] + len;
            if (!inqueue[to]) {
                q.push(to);
                inqueue[to] = true;
                cnt[to]++;
                if (cnt[to] > n)
                    return false;  // negative cycle
            }
        }
    }
}
return true;
```

O(E*V) tc, O(v) mc

## Floyd-Warshall

Multi-Source Shortest Path Finding Algorithm, i.e., finds shortest path between each pair of vertices

### Logic

1. ```d[i][j]``` in the kth phase stores the shortest dist from a path that has internal vertices
only from 1...k-1. so for ```k = 0, d[i][j] = weight(i, j) = inf``` if there is no edge bw them
2. Run this for n phases

```
for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][k] < INF && d[k][j] < INF)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}
```

O(n^3) tc, O(n^2) mc

## Minimum Spanning Tree Path (MSTP)

Spanning Tree: Tree which covers all nodes in a graph 

### Prim's Algorithm

Choose a vertex and choose the minimum edge from any of the vertexes already chosen, similar to BFS

```
while(!pq.empty()){
    vector<int> t = *pq.top();
    pq.pop();
    ans += t[0];
    for(auto i: adj[t[1]]){
        if(!vis[i[0]]) pq.push({i[1], i[0]});
    }
}
```

O((E+V)logV) tc, O(V) mc

### Kruskal's Algorithm

Always choosing the min edge not already in the set

```
sort(edges.begin(), edges.end());
for (Edge e : edges) {
    if (find_set(e.u) != find_set(e.v)) {
        cost += e.weight;
        result.push_back(e);
        union_sets(e.u, e.v);
    }
}
```

O(ElogV) tc, O(E+V) mc

## Disjoint Set Union (DSU)

Store set in form of trees and root of tree is the leader of set  
Merging has two approaches: union by rank or by size

### Union by rank

```
struct dsu{
    int n;
    vi p;
    vi rank;

    dsu(int n){
        this.n = n;
        p.resize(n+1, 0);
        lopp(i, n+1) p[i] = i;
        rank.resize(n+1, 0);
    }

    int find(int x){
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    //union by rank
    void merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(rank[x] > rank[y])
            p[y] = x, rank[x]++;
        else p[x] = y, rank[y]++;
    }
};
```

### Union by size, other way to write rest of the struct

```
struct dsu{
    vector<int> data;
    int components;

    dsu(int n){
        data.assign(n, -1);
        components = -1;
    }

    int find(int x){
        return data[x] < 0 ? x : data[x] = find(data[x]); 
    }

    int getsize(int x){
        return -data[find(x)];
    }

    int getcomponents(){
        return components;
    }

    bool merge(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return 0;
        if(-data[x] < -data[y]) swap(x, y);
        //union by size
        data[x] += data[y], data[y] = x;
        components--;
        return 1;
    }
};
```

## Printing Cycles in Graph

- Do DFS, when you encounter node in the current stack i.e. cycle node
- Store that node as start of cycle and parent node as end of cycle

```
bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u)) return true;
        } 
        else if (color[u] == 1){
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}
```

Calling the above function in parent function: ```for() if(!colour[i] && dfs) cycle.store(cyclestart, cycleend);```  
Function returns true when it finds a cycle.

## Finding Bridges in Graph: Tarjan's Algorithm

Bridge is the edge which when removed breaks the connectivity of graph, i.e., makes the graph unconnected.  

### Logic

- Using DFS with timer to find these edges
- Two arrays, one stores discovery/in time for the vertice (```tin```)
- Second stores the lowest possible time to reach the vertex (```low```)
- If ```u``` is a parent of ```v``` and ```low[v] > tin[u]``` then there is no other way to reach ```v``` other than ```u```

### Why does this work?

- Lets say 2-3 is bridge where ```tin[2] = 2, low[3] = 3```
- If 1-2 and lets say for arguments sake 1-3 is possible
- Where ```tin[1] = 1```, then we cannot say 2-3 is a bridge
- Why? Because when we reach 3, ```low[3]``` will get updated to 1 as it is the lowest
- So if ```low[to] > tin[u]``` then there is no "back-edge" or path which can connect 'to' to ```u``` because if there had been one, the low[to] would have been updated to that

```cpp
void dfs(int v, int p = -1){
    visited[v] = true;
    tin[v] = low[v] = timer++;  //timer is a global variable
    for (int to: adj[v]){
        if (to == p) continue;
        if (visited[to]) low[v] = min(low[v], low[to]);
        else{
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) IS_BRIDGE(v, to);
        }
    }
}
```
O(V+E) tc, O(V) mc

## Articulation Point/Cut Vertices

Vertices which when removed makes the graph unconnected are called cut vertices.    
In bridges we check whether any alternative path existed from curr node to adj node, whereas here we check if any path exist from child to parent node.  

## Difference from Tarjan's

1. Min of all adj points except parent & visited (from visited it will only update low if ```low > tin[to]```)
2. If ```(low[to] >= tin[v] && parent != -1) low[to] == tin[v]``` then it is only reachable to curr node but it cannot reach its parent node, so v is an articulation point
3. If parent has multiple children then it is assumed to be articulation point

```cpp
void dfs(int node, int parent, vector<int> &vis, int tin[], int low[], vector<int> &mark, vector<int> adj[]) {
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    int child = 0;
    for (auto it: adj[node]){
        if (it == parent) continue;
        if (!vis[it]){
            dfs(it, node, vis, tin, low, mark, adj);
            low[node] = min(low[node], low[it]);
            if (low[it] >= tin[node] && parent != -1) mark[node] = 1;
            child++;
        }
        else low[node] = min(low[node], tin[it]);
    }
    if (child > 1 && parent == -1) mark[node] = 1;
}
```
O(V+E) tc, O(V) mc

## Strongly Connected Components (SCC)

Strongly connected components are components where every pair of vertices is mutually reachable i.e 1->2 and 2->1 happens in directed graph as in undirected graph all components are strongly connected.  
Two algorithms to find these: Kosaraju & Tarjan.

### Kosaraju

SCC have every pair of vertices to be mutually reachable so 
reversing the edges will not have effect on traversing in an scc
so components of scc are still reachable to each other even if edges are reversed
a: store all vertices in order of finishing time
b: reverse edges of graphs
c: do dfs again to get sccs

```cpp
void dfs(int u, vector<vector<int>>& adj, vector<int> v, vector<bool>& vis){
    vis[u] = 1;
    for(auto i: adj[u]){
        if(!vis[i]) dfs(u, adj, v, vis);
    }
    v.push_back(u);
}

vector<vector<int>> Kosaraju(vector<vector<int>> edges, int n){
    vector<vector<int>> adj(n), adjrev(n);
    for(auto i: edges){
        adj[i[0]].push_back(i[1]);
        adjrev[i[1]].push_back(i[0]);
    }
    vector<bool> vis(n, 0);
    vector<int> order;
    for(int i = 0; i < n; i++)
        if(!vis[i]) dfs(i, adj, order, vis);
    reverse(begin(order), end(order)); //need to reverse it as it stores the first vector to finish at first
    vis.clear();
    vector<vector<int>> ans;
    int cnt = 0;
    for(auto i: order){
        if(!vis[i]){
            cnt++;
            vector<int> component;
            dfs(i, adjrev, component, vis);
            ans.push_back(component);
        }
    }
    return ans;
}
```
O(V+E) tc, O(V) mc

## Binary Tree

### Data Structure
```cpp
struct Node{
    int value;
    struct Node* left, *right;
    Node(int val, Node* l, Node* r){
        value = val, left = l, right = r;
    }
    Node(int val){
        value = val, left = right = nullptr;
    }
}
```

### Preorder Traversal

Root then first left subtree then right.

#### Recursive

```cpp
vector<int> preorderTraversal(TreeNode* root) {
    if(!root) return {};
    vector<int> ans;
    ans.push_back(root->val);
    if(root->left){
        vector<int> l = preorderTraversal(root->left);
        ans.insert(ans.end(), l.begin(), l.end());
    }
    if(root->right){
        vector<int> l = preorderTraversal(root->right);
        ans.insert(ans.end(), l.begin(), l.end());
    }
    return ans;
}
```

#### Iterative

Using Stack, O(n) mc
```cpp
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode* t = s.top();
        s.pop();
        ans.push_back(t->val);
        if(t->right) s.push(t->right);
        if(t->left) s.push(t->left);
    }
    return ans;
}
```

#### Morris, O(1) mc

Connecting the rightmost node(i.e the last node) of the left subtree to right node of current node
```cpp
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    while(root){
        ans.push_back(root->val);
        if(!root->left) root = root->right;
        else{
            TreeNode* nx = root->left;
            while(nx->right) nx = nx->right;
            nx->right = root->right;
            root->right = nullptr;
            root = root->left;
        }
    }
    return ans;
}
```

### Inorder Traversal

From the left sbutree to root to right subtree.

#### Recursive

```cpp
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    if(root->left) ans = inorderTraversal(root->left);
    ans.push_back(root->val);
    vector<int> right;
    if(root->right) right = inorderTraversal(root->right);
    for(auto i: right) ans.push_back(i);
    return ans;
}
```

#### Iterative

Using Stack, O(n) mc
```cpp
vector<int> inorderTraversal(TreeNode* root){
    stack<TreeNode*> st;
    TreeNode* node = root;
    vector<int> inorder;
    while(1){
        if(node){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;
        }
    }
    return inorder;
}
```

#### Morris O(1) mc

- Connecting the rightmost node of left subtree to current node
- If it is already connected then we have already pushed the left subtree to ans
- Remove the connection
```cpp
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    while(root){
        if(!root->left){
            ans.push_back(root->val);
            root = root->right;
        }
        else{
            TreeNode* nx = root->left;
            while(nx->right && nx->right != root) nx = nx->right;
            if(!nx->right){
                nx->right = root;
                root = root->left;
            }
            else{
                nx->right = nullptr;
                ans.push_back(root->val);
                root = root->right;
            }
        }
    }
    return ans;
}
```

### Postorder Traversal

Left subtree then right then root.

#### Recursive

```cpp
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    if(root->left) ans = postorderTraversal(root->left);
    vector<int> right;
    if(root->right) right = postorderTraversal(root->right);
    ans.insert(ans.end(), right.begin(), right.end());
    ans.push_back(root->val);
    return ans;
}
```

#### Iterative

Push elements on ans in reverse, i.e. go right, then go left.
```cpp
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> s1;
    s1.push(root);
    while(!s1.empty()){
        TreeNode* t = s1.top();
        s1.pop();
        ans.push_back(t->val);
        if(t->left) s1.push(t->left);
        if(t->right) s1.push(t->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
```
> Appending another vector to a vector
> ```a.insert(a.end(), b.begin(), b.end());```

### Level Order Traversal

Left to right level by level.
```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    queue<TreeNode*> a;
    a.push(root);
    while (!a.empty()) {
        int levelSize = a.size();
        vector<int> currLevel;
        for (int k = 0; k < levelSize; ++k) {
            TreeNode* node = a.front(); a.pop();
            currLevel.push_back(node->val);
            if (node->left) a.push(node->left);
            if (node->right) a.push(node->right);
        }
        result.push_back(currLevel);
    }
    return result;
}
```

### Pre, Post and Inorder Traversal in only one traversal

Store ```pair<Node*, int>``` in stack where the value of int represents where to put node: 1 = pre, 2 = inorder, 3 = post, i.e if you encounter the node for the first time then preorder, second time then inorder, third time then post order an element is removed from the stack only when the int = 3 basically doing a preorder traversal
```cpp
vector<vector<int>> preInPostTraversal(Node* root) {
    // Vectors to store traversals
    if(!root) return {{}, {}, {}};
    vector<int> pre, in, post;
    stack<pair<Node*, int>> st;
    st.push({root, 1});
    while (!st.empty()) {
        auto it = st.top();
        st.pop();
        if (it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it); 
            if(it.first->left) st.push({it.first->left, 1});
        }
        else if (it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right) st.push({it.first->right, 1});
        }
        else  post.push_back(it.first->data);
    }
    return {pre, in, post};
}
```

> Two trees need not be same even if there pre/post/inorder traversals are same

### Constructing a Tree from any two traversals (Pre, In, Post)

```cpp
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        return build(postorder, 0, postorder.size()-1, 0, inorder.size()-1, mp);
    }

private:
    TreeNode* build(vector<int>& post, int postl, int postr, int inl, int inr, map<int, int>& mp){
        if(postl > postr || inl > inr) return nullptr;
        TreeNode* t = new TreeNode(post[postr]);
        int inroot = mp[post[postr]], l = inroot - inl;
        t->left = build(post, postl, postl + l - 1, inl, inroot - 1, mp);
        t->right = build(post, postl + l, postr - 1, inroot + 1, inr, mp);
        return t;
    }
};
```

### Lowest Common Ancestor (LCA) of two nodes in a Tree

- Recursive function which traverse through right & left subtree
- If ```root == either``` of them then return root
- If both side return a node then the current node is the LCA
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return nullptr;
    if(root == p || root == q) return root;
    TreeNode* l = lowestCommonAncestor(root->left, p, q), *r = lowestCommonAncestor(root->right, p, q);
    if(l && r) return root;
    return l?l:r;
}
```

## Binary Search Tree (BST)

Property: ```left->val < curr->val < right->val```

### Deletion

There are 3 cases in deletion:
1. Leaf node: trivial, point parent node to null
2. Single child, replace the node with the child node
3. Two children:
    1. find successor of node which is the smallest in the right subtree(leftmost)
    2. put its value in current node
    3. delete successor

#### Recursive

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* node = root, *parent = nullptr;
        while(node && node->val != key){
            parent = node;
            if(node->val > key) node = node->left;
            else if(node->val < key) node = node->right;
        }
        if(!node) return root;
        if(!node->left && !node->right){
            if(!parent) return parent;
            if(parent->left == node) parent->left = nullptr;
            else parent->right = nullptr;
        }
        else if(!node->right){
            if(!parent) return root->left;
            if(parent->left == node) parent->left = node->left;
            else parent->right = node->left;
        }
        else if(!node->left){
            if(!parent) return root->right;
            if(parent->left == node) parent->left = node->right;
            else parent->right = node->right;
        }
        else{
            //recursive
            TreeNode* t = node->right;
            while(t->left) t = t->left;
            int value = t->val;
            node = deleteNode(node, value);
            node->val = value;

            //iterative
            /*TreeNode* t = node->right, *pt = node;
            while(t->left){ pt = t, t = t->left; }
            if(pt == node) pt->right = t->right;
            else pt->left = t->right;
            node->val = t->val;*/
        }
        return root;
    }
};
```

#### Iterative 

Similar, just store the parent of the node to be deleted and point it to right of node replacing.

## NSE, NGE, PSE, PGE: Next/Previous Smaller/Greater Element

- Finding NGE: iterate from n-1 to 0 as we have to find next 
- Push elements onto stack
- Iterate to next, pop elements from stack till the element is smaller than the one on top of stack that element is NGE

```cpp
vector<int> nge(vector<int> arr, int n){
    stack<int> s;
    vector<int> result(n, -1);
    for(int i = n-1; i >= 0; i--){
        while(!s.empty() && arr[i] >= s.top()) s.pop();
        if(!s.empty) result[i] = s.top();
        s.push(arr[i]);
    }
}
```
- Similar for NSE (condition in while loop changes to ```arr[i] <= s.top()```)
- For PSE/PGE loop iterates from 0 to n-1

## String Functions

### String Hashing

```cpp
long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
```
- Use ```p = 31``` for lowercase letters only, and ```p =  53``` for both upper and lower case(as there are 52)
- ```hash(L, R) = (prefix[R] - prefix[L-1] * power(R - L + 1) + mod) % mod```

### Rabin-Karp

```cpp
vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurrences;
    for (int i = 0; i + S <= T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}
```

O(s + t), s is pattern, t is text in which we have to check

### Z-Function

Stores max substr from start which is equal to substr from that posn ```i```.
```cpp
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) z[i] = min(r - i, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
```
O(n) tc, O(n) mc  

#### Time Complexity Explanation

It will be O(n) as the inner loop will make ```r``` atmost ```n - 1```, so inner loop will run atmost ```n - 1``` times to find substring in string using this attach pattern to original string in the front then if ```z[i + length(p)] == length(p)``` -> substring occurs at that index.
```
"aaaaa" - [0, 4, 3, 2, 1]
"aaabaab" - [0, 2, 1, 0, 2, 1, 0]
"abacaba" - [0, 0, 1, 0, 3, 0, 1]
```

### Prefix Function: KMP

Similar to z function except here it ```substr``` from ```start = substr``` ending at ```i```.
```cpp
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
```
O(n) tc

## Designing Data Structures

### 1. Map: BST same for Set (Node doesn't have value)

```cpp
// Node structure for our map
template <typename K, typename V>
struct Node {
    K key;
    V value;
    Node* left;
    Node* right;
    Node(K k, V v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

// Map implementation using Binary Search Tree
template <typename K, typename V>
class MyMap {
private:
    Node<K,V>* root;
    // helper to insert key-value
    Node<K,V>* insert(Node<K,V>* node, K key, V value) {
        if (!node) return new Node<K,V>(key, value);
        if (key < node->key) node->left = insert(node->left, key, value);
        else if (key > node->key) node->right = insert(node->right, key, value);
        else node->value = value; // update value if key exists

        return node;
    }
    // helper to search key
    V* search(Node<K,V>* node, K key) {
        if (!node) return nullptr;

        if (key == node->key) return &node->value;
        else if (key < node->key) return search(node->left, key);
        else return search(node->right, key);
    }
    // inorder traversal (sorted keys)
    void inorder(Node<K,V>* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->key << " : " << node->value << "\n";
        inorder(node->right);
    }

public:
    MyMap() : root(nullptr) {}
    void insert(K key, V value) {
        root = insert(root, key, value);
    }
    V* get(K key) {
        return search(root, key);
    }
    void print() {
        inorder(root);
    }
};
```

### 2. Unordered Map: Hashing, same for Unordered Set (Node doesn't have value)

```cpp
template <typename K, typename V>
class MyHashMap {
private:
    // Node for chaining
    struct Node {
        K key;
        V value;
        Node* next;
        Node(K k, V v) : key(k), value(v), next(nullptr) {}
    };

    Node** table;       // array of linked lists (buckets)
    int capacity;       // number of buckets
    int size;           // number of elements

    // Simple hash function
    int hash(K key) {
        return key % capacity; // works for int keys, can extend with templates
    }

public:
    MyHashMap(int cap = 10) {
        capacity = cap;
        size = 0;
        table = new Node*[capacity];
        for (int i = 0; i < capacity; i++) table[i] = nullptr;
    }

    // Insert key-value
    void insert(K key, V value) {
        int idx = hash(key);
        Node* head = table[idx];

        // check if key exists → update value
        while (head) {
            if (head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }

        // insert at head of list
        Node* newNode = new Node(key, value);
        newNode->next = table[idx];
        table[idx] = newNode;
        size++;
    }

    // Get value by key
    V* get(K key) {
        int idx = hash(key);
        Node* head = table[idx];
        while (head) {
            if (head->key == key)
                return &head->value;
            head = head->next;
        }
        return nullptr; // not found
    }

    // Remove key
    void remove(K key) {
        int idx = hash(key);
        Node* head = table[idx];
        Node* prev = nullptr;

        while (head) {
            if (head->key == key) {
                if (prev) prev->next = head->next;
                else table[idx] = head->next;
                delete head;
                size--;
                return;
            }
            prev = head;
            head = head->next;
        }
    }

    // Print all key-values
    void print() {
        for (int i = 0; i < capacity; i++) {
            Node* head = table[i];
            if (head) cout << "Bucket " << i << ": ";
            while (head) {
                cout << "(" << head->key << " : " << head->value << ") ";
                head = head->next;
            }
            if (table[i]) cout << "\n";
        }
    }

    ~MyHashMap() {
        for (int i = 0; i < capacity; i++) {
            Node* head = table[i];
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
        delete[] table;
    }
};
```

### 3. Stack with maximum in O(1)

- Make class with stack and ```maxElement``` variable
- if ```x > maxElement```, store ```2*x - maxElement``` in stack
- Since we store ```x = 2*maxEle - prev```
- Then ```prev = 2*maxEle - x``` (which we are popping lets say)
```cpp
class MaxStack {
  private:
    stack<int> s;
    int maxEle;
  public:
    MaxStack() { 
        maxEle = -1; 
    }
    // Add an element to the top of Stack
    void push(int x) {
        if (s.empty()) {
            maxEle = x;
            s.push(x);
        }
        // If new number is greater than maxEle
        else if (x > maxEle) {
            s.push(2 * x - maxEle);
            maxEle = x;
        } 
        else s.push(x);
    }
    // Remove the top element from the Stack
    void pop() {
        if (s.empty()) return;
        int top = s.top();
        s.pop();
        // Maximum will change if the maximum element
        // of the stack is being removed.
        if (top > maxEle) maxEle = 2 * maxEle - top;
    }
    // Returns top element of the Stack
    int peek() {
        if (s.empty()) return -1;
        int top = s.top();
        // If maxEle < top means maxEle stores value of top.
        return (maxEle < top) ? maxEle : top;
    }
    // Finds maximum element of Stack
    int getMax() {
        if (s.empty()) return -1;
        // variable maxEle stores the maximum element
        // in the stack
        return maxEle;
    }
};
```
Similarly for getmin() in O(1), push ```minEle = 2*x - minEle```
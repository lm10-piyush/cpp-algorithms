#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)
 
 
/****************************** CODE IS HERE ***********************************/
 
const ll inf = 1e18;

//Solving : https://cses.fi/problemset/task/1672
//Here graph is undirected and edges are non-negative.

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
    int n, m, q; cin >> n >> m >> q;
    vector <vector<ll>> dist(n+2, vector<ll>(n+2, inf));
    for (int i = 1; i <= n; ++i) dist[i][i] = 0;
 
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w*1LL);  //there could be parallel edges, that's why min()
        dist[v][u] = min(dist[v][u], w*1LL);  //because of given graph is undirected
    }
 
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
            	if (dist[i][k] < inf and dist[k][j] < inf)  //helpful when: negative edges and directed graph.
                	dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    //query the distance between two nodes.
    while (q--) {
        int a, b; cin >> a >> b;
        if (dist[a][b] == inf) {
            cout << -1 << endl;
        } else cout << dist[a][b] << endl;
    }
 
    return 0;
}

/*
 * Resource: https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html
 * It will work for both directed and undirected graph.
 * It can detect the negative cyles with some modifications.
 * NOTE: Generally we try to avoid those graphs which are undirected and have negative edges, becuz these will cause the
   negative cycle(s) always. That's why when we have edges with negative weight, then actually we have directed graph. So, when
   we have undirected graph and negative edges then it always have negative cycles.     

 * In case of floating point edges values you should be careful such that there could be precision error, to fix it you should use EPS(epsilon): 
 	if (dist[i][k] + dist[k][j] < dist[i][j] - EPS)
    	dist[i][j] = dist[i][k] + dist[k][j];

https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/pilgrims-and-portals/description/
https://pastebin.com/rZJZf4Fd   (with MST (kruskal or Prims))

https://codeforces.com/contest/25/problem/C
https://codeforces.com/contest/25/submission/104764237

https://codeforces.com/contest/295/problem/B              (similiar problem to DSU)
https://codeforces.com/contest/295/submission/104766006 

*/
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
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
    int n, m, q; cin >> n >> m >> q;
    vector <vector<ll>> dist(n+2, vector<ll>(n+2, inf));
    for (int i = 1; i <= n; ++i) dist[i][i] = 0;
 
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w*1LL);  //there could be parallel edges
        dist[v][u] = min(dist[v][u], w*1LL);
    }
 
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
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
 * It will work for both directed and undirected graph.
 * It can detect the negative cyles with some modifications.
 * NOTE: Generally we try to avoid those graphs which are undirected and have negative edges, becuz these will cause the
   negative cycle(s) always. That why when we have edges with negative weight, then actually we have directed graph. So, when
   we have undirected graph and negative edges then it always have negative cycles.     

https://cses.fi/problemset/task/1672

https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/pilgrims-and-portals/description/
https://pastebin.com/rZJZf4Fd   (with MST (kruskal or Prims))

*/
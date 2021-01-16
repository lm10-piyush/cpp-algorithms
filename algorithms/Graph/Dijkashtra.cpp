#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)
    
//{weight, node}
#define NODE pair<ll, ll>
const ll inf = 1e18;
vector <vector<pair<int,int>>> graph;  //{weight, node}
vector<bool> used;
vector <ll> dist;

void dijsktra(int s) {
    priority_queue <NODE, vector<NODE>, greater<NODE>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (used[u]) continue;  //we dont need this becuz in line-31 we are doing same if we don't insert visited node.
        used[u] = true;
        for (auto i: graph[u]) {
            ll v = i.second;
            ll w = i.first;
            if (!used[v]) {
                if (dist[u] + w < dist[v]) { 
                    dist[v] = w + dist[u];
                    pq.push({dist[v], v});
                }
            }
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    graph.assign(n+1, {});
    used.assign(n+1, false);
    dist.assign(n+1, inf);

    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        graph[u].push_back({w, v});  //directed-edge
    }
    int s, d; cin >> s >> d;
    dijsktra(s);
    if (dist[d] == inf) cout << "NO\n";
    else cout << dist[d] << endl;
}


/*
 Proof for Dijkstra: divide the graph into two sets of nodes A and B. A => those nodes whose distance is already calculated
 and B => Whose distance is not calculated. Then if we are at current node 'u' whose distance is not calculated yet then we will get the
 minimum distance from those nodes whose distance is already calculated (that means from set-A) because other nodes from set-B won't give me
 the best result for current unvisited node 'u'.

 GREEDY.

 * Graph could be directed or undirected and only for +ve weight.
 * When I call Multiple source that mean during the initialization of Priority queue and 'dist' array, we assume those vertices
 as sources also, we put there meaningful values other than infinity, like in single source we put there 0.
 * Observation: shortest path of current node 'u' will always passes from other vextex v's shortest path. There is never going to happen that
 the shortest path of current node 'u' will ever going to a passes from non-shortest path. 

 Tip: In problems related the Dijkstra, it is beneficial to think from start node, because we are maintaning the shortest path for each
 node greedily, so jump to any node abruptly and think might be difficult. 

https://www.spoj.com/problems/EZDIJKST/

(on Matrix)
https://drive.google.com/file/d/13B-hxGLizYhJcndlJReAN7xGBPLKfb6B/view?usp=sharing  (On matrix, with struct Node, multiple source)
https://pastebin.com/2Zk9QLMq

(on Matrix)
https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-a-5th-september/challenges/noise-control  (kind of multple source dijsktra)
https://pastebin.com/CWadhYFW

https://codeforces.com/contest/938/problem/D     (A bit tricky ques, like mutliple source)
https://codeforces.com/contest/938/submission/95437028

https://codeforces.com/contest/545/problem/E    (Dijkstra's variation)
https://codeforces.com/contest/545/submission/104450165

https://codeforces.com/contest/1473/problem/E      (Dijsktra's variation with 4 possiblities)
https://codeforces.com/contest/1473/submission/104539605
*/
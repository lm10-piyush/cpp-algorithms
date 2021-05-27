#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

const ll inf = 1e18;

struct Edge {
    int a, b, w; //a->b, weight: w
    Edge() {}
    Edge(int x, int y, int z) : a(x), b(y), w(z) {}
};

vector <Edge> edges;
vector <ll> dist;



void bellmanFord(int s, int n, int m) {
    dist[s] = 0;
    for (int k = 0; k < n - 1; k++) {
        for (int i = 0; i < m; ++i) {
            if (dist[edges[i].a] < inf)
                dist[edges[i].b] = min(dist[edges[i].b], dist[edges[i].a] + edges[i].w);
        }
    }
}


//Bellmonford with negtive cycle finding
vector <int> negativeCycle(int s, int n, int m) {
    vector <int> cycle;
    dist.assign(n + 1, inf);
    vector <int> p(n + 1, -1); //parent of shortest path
    dist[s] = 0;
    int last = -1;
    for (int k = 0; k < n; ++k) {
        last = -1;
        for (auto e : edges) {
            if (dist[e.a] + e.w < dist[e.b]) {
                dist[e.b] = dist[e.a] + e.w;
                p[e.b] = e.a;
                last = e.b;
            }
        }
    }

    if (last == -1) { //No negative cycle found
        return cycle;
    }

    for (int i = 0; i < n; ++i) {
        last = p[last];
    }
    for (int v = last; ; v = p[v]) {
        cycle.push_back(v);
        if (sz(cycle) > 1 and v == last)
            break;
    }
    reverse(all(cycle));

    return cycle;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    edges.resize(m);
    dist.assign(n + 1, inf);

    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        edges[i] = Edge(u, v, w);
    }

    /*
        bellmanFord(1, n, m);

        if (dist[n] == inf) {
            cout << -1;
        }
        else {
            cout << dist[n];
        }

    */

    //====== With Negative cycle ============
    vector <int> cycle = negativeCycle(1, n, m);
    if (cycle.empty()) {
        cout << (dist[n] == inf ? -1 : dist[n]);
    } else {
        for (auto i : cycle)
            cout << i << ' ';
    }

    return 0;
}

/**
  * Resource : https://cp-algorithms.com/graph/bellman_ford.html
  * It will work for both directed and undirected graph.
  * It can detect the negative cyles with some modifications.
  * There could be negative cycles, we could detect them by detecting the nodes which are get relaxed at nth iteration in
    Bellman ford algorithm. Then to find those nodes which are get affected by the cycles, we need to run the DFS from those
    nodes.

  * NOTE: Generally we try to avoid those graphs which are undirected and have negative edges, becuz these will cause the
    negative cycle(s) always. That why when we have edges with negative weight, then actually we have directed graph. So, when
    we have undirected graph and negative edges then it always have negative cycles.
  * Resource: https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html  (negative cycles)

  * https://cses.fi/problemset/task/1673
  * SOLN: https://pastebin.com/ZShH0XRp
  * solN : https://pastebin.com/BKrDbXu6 (via negate the edges and find minimum, then negate the ans)

  * https://cses.fi/problemset/task/1197  (negative cycle finding)
*/
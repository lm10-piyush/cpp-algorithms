#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

struct Edge {
    int u, v, w;
    Edge(int a, int b, int c) {
        u = a, v = b, w = c;
    }
    bool operator<(Edge e) {
        return w < e.w;
    }
};

vector <Edge> graph;

struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n+1);
        size.assign(n+1, 1);
        iota(all(parent), 0);
    }
    int find(int a) {
        if (parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    int dsu_union(int u, int v) {
        int x = find(u);
        int y = find(v);
        if (x == y) return 0;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        return 1;
    }
};


ll kruskal(int n) {
    sort(all(graph));
    ll cost = 0;
    DSU dsu(n);

    for (auto i: graph) {
        if (dsu.dsu_union(i.u, i.v)) {
            cost += i.w;
        }
    }
    return cost;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        graph.push_back({u, v, w});
    }

    ll cost = kruskal(n);
    cout << cost;

    return 0;
}

/*
https://www.spoj.com/problems/MST/

*/
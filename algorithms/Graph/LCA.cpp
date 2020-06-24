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

const int Log = 20;
vector <vector<int>> tree;
vector<int> level;
vector <vector<int>> parent;

void dfs(int u, int p) {
    level[u] = level[p] + 1;
    parent[u][0] = p;
    for (int v: tree[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (level[u] < level[v]) swap(u, v);
    for (int i = Log; i >= 0; --i) {
        if (level[u] - (1 << i) >= level[v])
            u = parent[u][i];
    }
    if(u == v) return u;
    for (int i = Log; i >= 0; --i) {
        if (parent[u][i] != -1 and parent[u][i] != parent[v][i])
            u = parent[u][i], v = parent[v][i];
    }
    return parent[u][0];
}

void build(int n) {
    dfs(1, 0);
    for (int i = 1; i <= Log; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (parent[j][i-1] != -1)
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    tree.assign(n+1, {});
    level.assign(n+1, -1);
    parent.assign(n+1, vector<int>(Log+1, -1));

    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    build(n);

    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        int p = lca(u, v);
        int dist = level[v] + level[u] - 2*level[p];
        cout << "lca = " << p << " distance =  " << dist << endl;
    }

    return 0;
}

/* Recurrence: Based on sparse table
 * x = parent[u][i]
 * parent[u][i+1] = parent[x][i]
 * parent[u][i] => parent of u which is 2^i distance far from u. 
 * so, parent[u][0] => parent of u. 
 * One more place where LCA helps, suppose you want to traverse the path from a to b, then DFS will lead you even a long path 
 * becuz it tries all possiblites, but moving via parent[][] tables helps to move correctly, along the path.
 * ex: https://www.codechef.com/LTIME84B/problems/TREDIFF

https://www.spoj.com/problems/LCA/
https://pastebin.com/85jTDXy5

https://www.spoj.com/problems/QTREE2/
soln: https://pastebin.com/GZVk5GVg



*/
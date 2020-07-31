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

//NOTE: here we are talking in sense of DFS tree.

vector <vector<int>> g;
vector <bool> used, artPoint;
vector <int> tin, lo;
int id;
int artCnt; //count of art_points


void dfs(int u, int p) {
    used[u] = true;
    tin[u] = lo[u] = id++;
    int child = 0;  //or outedges of the node in DFS tree
    for (int v: g[u]) {
        if (v == p) continue;
        if (used[v]) {
            lo[u] = min(lo[u], tin[v]);
        }
        else {
            dfs(v, u);
            lo[u] = min(lo[u], lo[v]);
            //if it not root, then if discovery time of 'u' is less than or equal to its child's low time
            if (tin[u] <= lo[v] and p != -1) {
                if (!artPoint[u]) artCnt++;
                artPoint[u] = true;
            }
            child++;
        }
    }
    //when 'u' is the root ie., 'u' act as linking node between disjoint components
    if (child > 1 and p == -1) {
        if (!artPoint[u]) artCnt++;
        artPoint[u] = true;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    id = 0; artCnt = 0;
    g.assign(n+1, {});
    tin.resize(n+1);
    lo.resize(n+1);
    used.assign(n+1, false);
    artPoint.assign(n+1, false);

    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (!used[i])
            dfs(i, -1);
    }

    for (int i = 1; i <= n; ++i) {
        if (artPoint[i]) cout << i << ' ';
    }

    return 0;
}

/*
 * lo[u] => minimum time reachable by the desendants of 'u' in the DFS spanning tree.
 * 
 * https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/rhezo-and-destructive-mind/description/
 * https://pastebin.com/cpr6i65d   (graph restored after each deletion)

 *https://www.spoj.com/problems/SUBMERGE/

*/
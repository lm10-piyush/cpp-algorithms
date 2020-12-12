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

//Strongly Connected by Kosaraju.

vector <vector<int>> graph, revGraph;
vector <bool> used;
stack <int> nodes;  //to maintain order / direction

void dfs1(int u) {
    used[u] = true;
    for (int v: graph[u]) {
        if (!used[v]) dfs1(v);
    }
    nodes.push(u);
}

void dfs2(int u) {
    used[u] = true;
    for (int v: revGraph[u]) {
        if (!used[v]) dfs2(v);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    graph.assign(n+1, {});
    revGraph.assign(n+1, {});
    used.assign(n+1, false);
    nodes = stack<int>();

    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        revGraph[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) dfs1(i);        
    }

    fill(all(used), false);

    int components = 0;
    while (!nodes.empty()) {
        int u = nodes.top(); nodes.pop();
        if (!used[u]) {
            dfs2(u);
            components++;
        }
    }

    cout << components; //number of components

    return 0;
}

//https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/magical-islands/description/
//https://pastebin.com/EA3SeZUy

/*
https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/a-walk-to-remember-qualifier2/description/
https://pastebin.com/249ArebS

https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-a-10-october/challenges/2-directions
https://pastebin.com/KnethsHB
*/
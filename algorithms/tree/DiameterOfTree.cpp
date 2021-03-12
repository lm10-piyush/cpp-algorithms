#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)

const int N = 2e5 + 2;
vector <int> tree[N];

pair<int, int> dfs(int u, int p = -1) {
    int mx1 = -1, mx2 = -1, h, d, best = 0;
    for (int v: tree[u]) {
        if (v == p) continue;
        tie(d, h) = dfs(v, u);
        best = max(best, d);
        if (h >= mx1) mx2 = mx1, mx1 = h; //mx1, mx2 = largest two heights of the children
        else if (h > mx2) mx2 = h;
    }
    best = max(best, mx1 + mx2 + 2);
    return {best, mx1 + 1};
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int d = dfs(1).first;

    cout << d;


    return 0;
}


/*
 * We can find the diameter of tree using two BFS's also. Apply the 1st bfs from any node 'x' and get the node 'u' with the
  longest distance from 'x', that 'u' will be the one end point of the diamter. Now, apply bfs from 'u' now it will give you the
  another end point of the diamter. 


 * https://cses.fi/problemset/task/1131
  https://pastebin.com/rAj15r4v   (old way to calculate the diameter, approach is same but implementation is old)
 * https://codeforces.com/contest/1405/problem/D
 solN: https://codeforces.com/contest/1405/submission/92066680

 * https://codeforces.com/contest/1294/problem/F      (diameter, two bfs, diameter nodes)
 * https://codeforces.com/contest/1294/submission/105599159

*/
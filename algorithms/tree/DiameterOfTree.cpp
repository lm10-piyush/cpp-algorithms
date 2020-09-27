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

const int N = 2e5 + 2;
vector <int> tree[N], height(N);
int ans = 0;

void dfs(int u, int p = -1) {
    int mx1 = -1, mx2 = -1;
    for (int v: tree[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (height[v] >= mx1) mx2 = mx1, mx1 = height[v];
        else if (height[v] > mx2) mx2 = height[v];
    }
    ans = max(ans, mx2 + mx1 + 2);
    height[u] = mx1 + 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1);

    cout << ans;


    return 0;
}

/*
 * https://cses.fi/problemset/task/1131
 * https://codeforces.com/contest/1405/problem/D
 solN: https://codeforces.com/contest/1405/submission/92066680
*/
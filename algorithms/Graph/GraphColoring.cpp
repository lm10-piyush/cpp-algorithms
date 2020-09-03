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
 
const int N = 1e5 + 3;
 
vector <int> graph[N];
vector <int> color(N, -1);

//bipertite check, if yes then colors will be in the std::vector colors
bool bipertite(int s) {
    queue <int> q;
    q.push(s);
    color[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: graph[u]) {
            if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                q.push(v);
            }
            else if (color[v] == color[u]) {
                return false;
            }
        }
    }
    return true;
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
    int n, m; cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1) {
            if (!bipertite(i)) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
 
    for (int i = 1; i <= n; ++i) {
        cout << color[i] + 1 << ' ';
    }
 

 
    return 0;
}

//https://cses.fi/problemset/task/1668

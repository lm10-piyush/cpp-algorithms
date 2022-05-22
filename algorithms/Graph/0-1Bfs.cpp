#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

//0-1 BFS
const int inf = 1e9;

vector <vector<pair<int, int>>> g;
vector <int> dist;
vector <bool> used;

void bfs01(int s) {
    deque <int> dq;
    dq.push_back(s);
    dist[s] = 0;
    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        if (used[u]) continue; //we dont need this becuz in line-31 we are doing same if we don't insert visited node.
        used[u] = true;
        for (auto v : g[u]) { // adjacent nodes
            if (used[v.first]) continue;
            if (dist[v.first] > dist[u] + v.second) {
                dist[v.first] = dist[u] + v.second;
                if (v.second) dq.push_back(v.first); //weight-1
                else dq.push_front(v.first);  //weight-0
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    g.assign(n + 1, {});
    dist.assign(n + 1, inf);
    used.assign(n + 1, false);

    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    bfs01(1);
    for (int i = 1; i <= n; ++i)
        cout << dist[i] << ' ';

    return 0;
}

/* Only edge weights allowed: 0 or 1.
 * Resource: https://codeforces.com/blog/entry/22276
 * It is similiar to Dijkstra, but it is more efficient O(E).
 * Concept is same as Dijkstra by maintaining the queue in increasing order by inserting '0' at front  and '1' at back.
 * It will also work as 0-x BFS ie., only 0 or x.

https://www.spoj.com/problems/KATHTHI/
https://pastebin.com/Zkj6LwHL

0-1 BFS constest : https://www.e-olymp.com/en/contests/16775

https://www.e-olymp.com/en/contests/16775/problems/173742
https://pastebin.com/FeBMbW6U

https://www.e-olymp.com/en/contests/16775/problems/173743
https://pastebin.com/8Cja2FvD

https://atcoder.jp/contests/abc176/tasks/abc176_d  (0-1 BFS on matrix)
https://atcoder.jp/contests/abc176/submissions/16211169

*/
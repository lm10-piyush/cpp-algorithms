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

const ll inf = 1e12;
vector <vector<pair<int,int>>> graph;
vector<bool> used;
vector <ll> dist;

void dijsktra(int s) {
    priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty()) {
        pair <ll, ll> u = pq.top(); pq.pop();
        if (used[u.second]) continue;
        used[u.second] = true;
        for (auto i: graph[u.second]) {
            ll v = i.second;
            ll w = i.first;
            if (!used[i.second]) {
                if (u.first + w < dist[v]) {
                    dist[v] = w + u.first;
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
        graph[u].push_back({w, v});
    }
    int s, d; cin >> s >> d;
    dijsktra(s);
    if (dist[d] == inf) cout << "NO\n";
    else cout << dist[d] << endl;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--)
        solve();


    return 0;
}

/*
https://www.spoj.com/problems/EZDIJKST/

*/
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

const int N = 1e4 + 4;
vector <pair<int, int>> graph[N];
bitset<N> used;

ll prims(int s) {
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    ll cost = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        pair<int, int> u = pq.top(); pq.pop();
        if (used[u.second]) continue;
        used.set(u.second);
        cost += u.first;
        for (auto i: graph[u.second]) {
            if (!used[i.second])
                pq.push(i);
        }
    }
    return cost;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    for (int i = 0, v, u, w; i < m; ++i) {
        cin >> u >> v >> w;
        graph[u].push_back({w, v}); //weight, node
        graph[v].push_back({w, u});
    }

    ll cost = prims(1);
    cout << cost;

    return 0;
}

/*
https://www.spoj.com/problems/MST/

https://codeforces.com/contest/1243/problem/D   
(0-1 MSTm set trick, https://codeforces.com/contest/1243/submission/94438372)

https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/pilgrims-and-portals/description/
https://pastebin.com/rZJZf4Fd  (with floyd warshall)
*/
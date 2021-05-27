#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type >
ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)

//Solution of : https://cses.fi/problemset/task/1694

//Edmond's Karp algorithm: complexity: O(VE^2).

const ll INF = 1e18;

vector<vector<ll>> capacity; //stores residual capacity. Initial capacity of residual edges is '0'.
vector<vector<ll>> graph;

ll bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<ll, ll>> q;
    q.push({s, INF});

    while (!q.empty()) {
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (int next : graph[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

ll maxflow(int n, int s, int t) {
    ll flow = 0;
    vector<int> parent(n + 1);
    ll new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    graph.assign(n + 1, {});
    capacity.assign(n + 1, vector <ll> (n + 1));

    //Indexing is 1-based
    for (int i = 0; i < m; ++i) {
        ll a, b, c; cin >> a >> b >> c;
        graph[a].push_back(b);  //original edge
        graph[b].push_back(a);  //residual edge
        capacity[a][b] += c; // multiple edges are possible
    }

    cout << maxflow(n, 1, n);


    return 0;
}


/*
 * To calcuate the max flow we use Ford-Fulkerson algorithm: keep finding the augmenting paths and augment the flow in the residual graph
   until there is no augmenting path available.

   Augmenting path: That path which could increase the  flow in the residual graph.
   Residual graph: Same graph with same vertices and edges but instead of capacity we store residual capacity (remaining capacity: capacity - flow)
   and residual edge (edge opposite to original one and with negative flow). NOTE: residual capacity is always non-negative for both original edge and residual edge.

   Ford-fulkerson doesn't give any information about how to find the augmenting path, so now there is bunch of algorithms which finds the augmenting
   paths like DFS, Edmonds-karp, Dinic etc. They use the same idea of ford-fulkerson but only the difference is "How efficiently they find augmenting paths".

* There is concept of min-cut. We have to find the max-flow to calculate the min-cut.

* Resource: https://cp-algorithms.com/graph/edmonds_karp.html
* Link of the above problem: https://cses.fi/problemset/task/1694

*/
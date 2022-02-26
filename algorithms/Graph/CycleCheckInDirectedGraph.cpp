#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

//Cycle check in directed graph


/*
Doing it using the coloring:
unvisited nodes : 0
visited nodes but in recursion : 1
visited and completed from recursion: 2

Another way, we can also use SSC to check the directed cycles.
*/

const int N = 1e5 + 3;
vector <int> graph[N];
vector <int> used(N, 0);

int cycle = 0;
void dfs(int u) {
    used[u] = 1;
    for (int v : graph[u]) {
        if (used[v] == 1) {
            cycle = 1;
        }
        else if (!used[v])
            dfs(v);
    }
    used[u] = 2;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }
    cycle = 0;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) dfs(i);
    }

    cout << cycle;

    return 0;
}

/*
 We can also maintain the stack/vector to store the cycle itself.
 https://www.interviewbit.com/problems/cycle-in-directed-graph/


*/
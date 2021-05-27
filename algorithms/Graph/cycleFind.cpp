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

//Find the cycle in the given undirected graph

const int N = 1e5 + 3;
vector <int> graph[N];
vector <bool> used(N, false);
vector <int> cycle;
stack <int> s;

bool dfs(int u, int p = -1) {
    if (used[u]) {  //hit the visited node, that means cycle found
        cycle = {u};
        //unwind the cycle nodes
        while (s.top() != u) {
            cycle.push_back(s.top());
            s.pop();
        }
        cycle.push_back(u);
        return true;
    }

    s.push(u);
    used[u] = true;
    for (int v : graph[u]) {
        if (v != p and dfs(v, u)) return true;  //when you hit the cycle return back
    }
    s.pop();
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, -1);

    for (int i : cycle) cout << i << ' ';

    return 0;
}

/*
Find the cycle in the given undirected graph
This is for finding the 1-cycle only, if want to find more than just remove the return true, false statements and after the pop
operation from stack you have to also push it in the stack to find more cycles.
https://www.geeksforgeeks.org/print-all-the-cycles-in-an-undirected-graph/  (Same solution)

https://codeforces.com/contest/1454/problem/E
https://codeforces.com/contest/1454/submission/100904774
https://codeforces.com/contest/1454/submission/100904221   (Another way to find the cycle, but little tricky)

https://cses.fi/problemset/task/1669
https://pastebin.com/iv71xHik         (using stack)
https://pastebin.com/5QWZAbfh   (2nd way to find the cycle)


*/
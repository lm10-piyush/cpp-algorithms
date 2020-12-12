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

//Maximum Bitertite Matching: Hopcroft-karp
//complexity: O(E.sqrt(V))

class matching {
 public:
  vector<vector<int>> g;
  vector<int> pa;
  vector<int> pb;
  vector<int> was;
  int n, m;
  int res;
  int iter;

  matching(int _n, int _m) : n(_n), m(_m) {
    assert(0 <= n && 0 <= m);
    pa = vector<int>(n+1, -1);
    pb = vector<int>(m+1, -1);
    was = vector<int>(n+1, 0);
    g.resize(n+1);
    res = 0;
    iter = 0;
  }

  void add(int from, int to) {
    assert(0 < from && from <= n && 0 < to && to <= m);
    g[from].push_back(to);
  }

  bool dfs(int v) {
    was[v] = iter;
    for (int u : g[v]) {
      if (pb[u] == -1) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    for (int u : g[v]) {
      if (was[pb[u]] != iter && dfs(pb[u])) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    return false;
  }

  int solve() {
    while (true) {
      iter++;
      int add = 0;
      for (int i = 1; i <= n; i++) { //iterating overnodes
        if (pa[i] == -1 && dfs(i)) {
          add++;
        }
      }
      if (add == 0) {
        break;
      }
      res += add;
    }
    return res;
  }

  int run_one(int v) {
    if (pa[v] != -1) {
      return 0;
    }
    iter++;
    return (int) dfs(v);
  }
};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    matching mat(n, n); //initialize the graph

    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;  //1-based indexing
        mat.add(u, v); //add edges
    }

    int maxMatch = mat.solve();
    cout << maxMatch;

    return 0;
}

/*
3 5
1 2
2 3
2 1
2 2
3 3
3

https://codeforces.com/contest/1423/problem/B (with binary search)
https://codeforces.com/contest/1423/submission/94799753


*/
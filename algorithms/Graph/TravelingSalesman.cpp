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


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <vector<int>> graph(n, vector<int>(n)); //adjacency matrix with weights
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> graph[i][j];
      }
    }


    //************************ top-down approach *****************
    vector <vector<int>> dp(n, vector<int>(1 << n, -1));
    function<int(int, int)> go = [&](int pos, int mask) {
      if (mask == (1 << n)-1) {
        return graph[pos][1];
      }
      int &res = dp[pos][pos];
      if (res != -1) return res;
      int ans = 2e9;
      for (int i = 0; i < n; ++i) {
        if (mask >> i & 1) continue;
        ans = min(ans, go(i, mask | (1 << i))   + graph[pos][i]);
      }
      return res = ans;
    };
    int ans = go(0, 1);
    cout << ans << endl;
    //************** Top down end**************************************************
    
    //************************ Bottom-up approach *****************************
    vector <vector<int>> dp2(n, vector<int>(1 << n, 2e9));
    //base case
    for (int i = 0; i < n; ++i) {
      dp2[i][(1 << n)-1] = graph[i][0];
    }

    vector <int> all_masks(1 << n); //to iterate over masks properly, such that smaller problems => bigger problems
    iota(all(all_masks), 0);
    sort(all(all_masks), [&](int a, int b) {
      return __builtin_popcount(a) < __builtin_popcount(b);
    });

    reverse(all(all_masks));
    for (int m: all_masks) {
      int x = __builtin_popcount(m);
      for (int i = 0; i < n; ++i) {
        if (!(m >> i & 1)) continue;
        for (int j = 0; j < n; ++j) {
          if (m >> j & 1) continue;
          dp2[i][m] = min(dp2[i][m], graph[i][j] + dp2[j][m | (1 << j)]);
        }
      }
    }
    cout << dp2[0][1] << endl;

    //finding path using bottom up solution...
    vector <int> path{0};
    int curr = 0;
    int mask = 1;
    while (mask != (1 << n)-1) {
      int dist = 2e9, node = -1;
      for (int i = 0; i < n; ++i) {
        if (mask >> i & 1) continue;
        if (dist > graph[curr][i] + dp2[i][mask | (1 << i)]) {
          dist = graph[curr][i] + dp2[i][mask | (1 << i)];
          node = i;
        }
      }
      assert(node >= 0);
      path.push_back(node);
      mask |= (1 << node);
      curr = node;
    }
    for (int i: path) cout << i << ' ';

    return 0;
}

/*
 f(i, mask) = min(cost(i, k) + f(k, mask | (1 << k))); k=> connected unvisited node from i to k
 if base case mask == (1 << n)-1 then f(i, mask) = cost[i][0]
  
 start node doesn't matter

 4
 0 10 15 20
 5 0 9 10 
 6 13 0 12
 8 8 9 0

 ans = 35

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(x) (int)x.size()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ****************************************/
const int N = 2e5 + 7;
vector <int> tree[N];
vector<int> g[N];
vector <int> seq;
bitset<N> used;

//BFS2 for finding shortest distance + path
void bfs2() {
  //input graph
  int n, m, a, b; cin >> n >> m >> a >> b;
  for (int i = 0, x, y; i < m; ++i) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  //bfs starts here
  vector <int> dist(n + 1, INF);
  vector <int> path(n + 1);
  //initialize
  path[a] = a;
  queue<int> q;
  q.push(a);
  dist[a] = 0;
  //run loop queue is not empty
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : g[u]) {
      if (dist[v] == INF) {
        dist[v] = dist[u] + 1;
        q.push(v);
        path[v] = u;
      }
    }
  }
  //not reachable
  if (dist[b] == INF) {
    cout << -1;
    return 0;
  }
  //distance between a to b
  cout << dist[b] << endl;
  //for the path
  vector <int> ans;
  int curr = b;
  while (curr != a) {
    ans.push_back(curr);
    curr = path[curr];
  }
  ans.push_back(curr);
  reverse(all(ans));
  for (int i : ans)
    cout << i << ' ';

}

//bfs
void bfs() {
  //initialize
  queue <int> q;
  q.push(1); //source
  used[1] = true;  //we can use distance instead to calcuate distance or previous(parent) of current node
  //run loop till queue is not empty
  while (!q.empty()) {
    int u = q.front(); q.pop();
    seq.push_back(u);  //bfs order
    for (int v : tree[u]) {
      if (!used[v]) {
        used[v] = true;
        q.push(v);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int n; cin >> n;
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }

  bfs();
  for (int i : seq)
    cout << i << ' ';

  return 0;
}


/*
* Multiple source BFS means during initilization of queue and dist array or matrix, we put there some other value rather than
infinity and assuming those nodes as source also, so, there are multiple source nodes.

* We can find the diamter with two bfs also.

Basic problems: https://www.e-olymp.com/en/contests/16661
problem for bfs2: https://www.e-olymp.com/en/problems/4853

https://codeforces.com/contest/1106/problem/D
sol: https://codeforces.com/contest/1106/submission/82663168

https://www.codechef.com/ENJU2020/problems/ECJN205
https://www.codechef.com/viewsolution/34844619

https://leetcode.com/problems/rotting-oranges/  (Bfs on matrix, multiple source BFS)
soln: https://pastebin.com/UL22GYhW

https://codeforces.com/contest/986/problem/A    (multiple source BFS)
https://codeforces.com/contest/986/submission/89774954

https://codeforces.com/contest/1307/problem/D  (bfs with trick from 1 and from n and vice-versa)
https://codeforces.com/contest/1307/submission/91081205

https://pastebin.com/YP9JFmVm  (bfs on matrx, problem is in the link)

https://codeforces.com/contest/813/problem/C
https://codeforces.com/contest/813/submission/94873848

https://codeforces.com/contest/1176/problem/E
https://codeforces.com/contest/1176/submission/88618605

https://atcoder.jp/contests/abc184/tasks/abc184_e
(Third Avenue, BFS on Matrix, https://atcoder.jp/contests/abc184/submissions/18795775)

https://leetcode.com/problems/word-ladder/
Array to graph conversion, BFS, precomputing, optimization, maps, tradeoff between rows and columns, https://pastebin.com/n9DAP7A7


 * https://codeforces.com/contest/1294/problem/F      (diameter, two bfs, diameter nodes)
 * https://codeforces.com/contest/1294/submission/105599159


https://codeforces.com/contest/242/problem/C
(BFS, Graph, map of graph, https://codeforces.com/contest/242/submission/111546417)
*/
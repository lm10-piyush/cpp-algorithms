#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(x) (int)x.size() 
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ****************************************/
const int N = 2e5 + 7;
vector <int> tree[N];
vector<int> g[N];
vector <int> seq;
bitset<N> used;

void bfs2(){
    int n, m, a, b; cin >> n >> m >> a >> b;
    for (int i = 0,x,y; i < m; ++i){
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }

    vector <int> dist(n+1, INF);
    vector <int> path(n+1);
    path[a] = a;
    queue<int> q;
    q.push(a);
    dist[a] = 0;
    while(!q.empty()){
      int u = q.front(); q.pop();
      for (int v: g[u]){
        if(dist[v] == INF){
          dist[v] = dist[u] + 1;
          q.push(v);
          path[v] = u;
        }
      }
    }
    if(dist[b] == INF) {
      cout << -1;
      return 0;
    }
    cout << dist[b] << endl;
    //for the path
    vector <int> ans;
    int curr = b;
    while(curr != a){
      ans.push_back(curr);
      curr = path[curr];
    }
    ans.push_back(curr);
    reverse(all(ans));
    for (int i: ans)
      cout << i << ' ';

}

void bfs(){
  queue<int> q;
  q.push(1);
  while(!q.empty()){
    int u = q.front(); q.pop();
    used[u] = true;
    seq.push_back(u);
    for (int v: tree[u]){
      if(!used[v]) q.push(v);
    }
  }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 1, x, y; i < n; ++i){
      cin >> x >> y;
      tree[x].push_back(y);
      tree[y].push_back(x);
    }

    bfs();
    for (int i: seq)
      cout << i << ' ';

  return 0;
}


//https://codeforces.com/contest/1106/problem/D
//sol: https://codeforces.com/contest/1106/submission/82663168
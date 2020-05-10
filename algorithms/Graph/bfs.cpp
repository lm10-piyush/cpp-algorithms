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
vector <int> seq;
bitset<N> used;

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

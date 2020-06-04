#include<bits/stdc++.h>
using namespace std;
#define  pb push_back

/********* topological sort using dfs  **************/
const int maxn = 1e5;
vector<int> graph[maxn + 5];
bool visited[maxn + 5];

vector<int> topo_sort;


void dfs(int u) {
  visited[u] = true;
  for(auto i: graph[u]){
    if(!visited[i])
      dfs(i);
  }
  topo_sort.pb(u);
}

int main()
{
  memset(visited,false, sizeof(visited));
  int n, m;
  cin>>n>>m;

  int a,b;

  for(int i=0;i<m;i++)
  {
    cin>>a>>b;
    graph[a].pb(b);
  }

  for(int i=1;i<=n;i++)
  {
    if(!visited[i])
    dfs(i);
  }

  reverse(topo_sort.begin(), topo_sort.end());
  for(auto i: topo_sort) cout<<i<<' ';


}
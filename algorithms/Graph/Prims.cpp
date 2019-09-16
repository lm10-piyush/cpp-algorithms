#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define mp make_pair
#define endl "\n"
#define tab " "
#define pb push_back
#define ff first
#define ss second
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pll pair<ll,ll>
#define pi 3.141592653589793238460

using namespace std;


vector<pair<int,int> > graph[10000+5];     //graph of <weight, node number>

bool visited[10000+5];


ll prims(int u)
{
  priority_queue<pll, vector<pll>, greater<pll> > pq;

  ll mincost=0;
  pq.push({0,u});
  pll p;

  while(!pq.empty())
  {
    p = pq.top();
    pq.pop();
    int ele = p.ss;

    if(visited[ele]==true) continue;

    visited[ele]=true;
    mincost += p.ff;

    //to check all its adjacent

    for(int i=0;i<graph[ele].size();++i)
    {
      int x = graph[ele][i].ss;
      if(visited[x]==false)        //if not visited then insert in priority queue
        pq.push(graph[ele][i]);

    }
  }

  return mincost;


}


int main()
{
  int n,e;
  cin>>n>>e;

  int e1,e2,w;

  for(int i=1;i<=e;i++)
  {
    cin>>e1>>e2>>w;        // e1-->e2 with weight w
    graph[e1].push_back({w,e2});

     graph[e2].push_back({w,e1});  //in case of undirected graph
    
  }

  ll mincost=prims(1);
  cout<<"minimum cost: "<<mincost;

  return 0;
}
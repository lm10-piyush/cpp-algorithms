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


vector<pair<int,int> > graph[1000+1];     //graph of <weight, node number>

bool visited[1000+1];
int dist[1000+1];



void dijkastra(int n,int u)
{
  for(int i=0;i<=n;i++) dist[i]=mod; //initialize with infinity
  for(int i=0;i<n;i++) visited[i] = false;  //all visited false

  dist[u]=0;             //source vertex will be at distance 0
  
  multiset< pair<int,int> > s;   //it helps to maintain order of minimum weight first
  s.insert({0,u});                //Insert source vertex with 0 distance

  while(!s.empty())
  {
    pair<int,int> p = *s.begin();   //pick the first element
    s.erase(s.begin());            //remove that first element 'cuz it is processed now

    int ele = p.ss;               //select that element
    int w =  p.ff;


    if(visited[ele]==false)    //if not visited
    {
      visited[ele]=true;

      //now check for its adjacents
      for(int i=0;i<graph[ele].size();i++)
      {
        int adj_vertx = graph[ele][i].ss;
        int weigh = graph[ele][i].ff;

        if(dist[ele]+weigh < dist[adj_vertx])   
        {
          dist[adj_vertx] = dist[ele]+weigh;
          s.insert({dist[adj_vertx], adj_vertx});
        }



      }

    }
  }
  
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

    // graph[e2].push_back({w,e1});  //in case of undirected graph
    
  }

  dijkastra(n,1);
  cout<<"distance: ";

  for(int i=1;i<=n;i++) cout<<dist[i]<<" ";


  return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define mp make_pair
#define endl "\n"
#define tab " "
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pll pair<ll,ll>
#define pi 3.141592653589793238460
#define F(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define RF(i,a,b) for(int i=(int)a;i>=(int)b;i--)


using namespace std;


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
  int n;
  cin>>n;
  int capacity;
  cin>>capacity;

  int weight[n],value[n];

  for(auto &i: value)
    cin>>i;

  for(auto &i: weight)
    cin>>i;


  
  int knapsack[n+1][capacity+1];

  F(i,0,capacity)
  knapsack[0][i]=0;

  F(i,0,n)
  knapsack[i][0]=0;


  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=capacity;j++)
    {
      if(weight[i-1]<=j)
      {
        if(knapsack[i-1][j] >= value[i-1]+knapsack[i-1][j-weight[i-1]])
          knapsack[i][j]=knapsack[i-1][j];
        else
          knapsack[i][j] = value[i-1] + knapsack[i-1][j-weight[i-1]];
      }
      else
        knapsack[i][j]=knapsack[i-1][j];
    }
  
  }


  cout<<knapsack[n][capacity];

}
}

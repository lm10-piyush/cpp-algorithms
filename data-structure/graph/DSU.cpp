#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

const int N = 1e5 + 5;
vector <int> parent, size;
int components;

void init(int n){
  parent.resize(n+1);
  size.assign(n+1, 1);
  iota(all(parent), 0);
  components = n;
}

//get leader
int find(int a){
  if(parent[a] == a) return a;
  return parent[a] =  find(parent[a]);
}

void dsu_union(int a, int b){
  int x = find(a);
  int y = find(b);
  if(x == y) return;
  if(size[x] < size[y])
    swap(x, y);
  components--; //components decreases with union
  parent[y] = x;
  size[x] += size[y];
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    init(n);

    for (int i = 0, x, y; i < m; ++i){
      cin >> x >> y;
      dsu_union(x, y);
    }

    cout << components;

  return 0;
}


//problem: https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/submissions/
//solution: exactly same code
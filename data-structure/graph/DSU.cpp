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

struct DSU {
  vector <int> parent, size;
  int components;
  DSU(int n) {
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
};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    DSU dsu(n);

    for (int i = 0, x, y; i < m; ++i){
      cin >> x >> y;
      dsu.dsu_union(x, y);
    }

    cout << dsu.components;

  return 0;
}

/*
 * Problem: Find the minimum number of edges that should be removed so that there should be no cycle in the 
            given undirected graph.
  soln: By Dsu, same as Kruksal algo for spanning tree. Keep adding edges when cycle found do ans++, and don't
  add that edge to your Dsu.


*/

//problem: https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/submissions/
//solution: exactly same code

//https://codeforces.com/contest/1213/problem/G
// https://codeforces.com/contest/1213/submission/82253510

//https://www.codechef.com/ENJU2020/problems/ECJN206
//https://www.codechef.com/viewsolution/34856044

//https://atcoder.jp/contests/abc177/tasks/abc177_d
//https://atcoder.jp/contests/abc177/submissions/16636646  (soln: size of largest size group)

//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/still-maximum/
//solution: start you solution from very end ie., when every node is detached, then one by one add the edge and ans the query.

//https://codeforces.com/contest/500/problem/B
//https://codeforces.com/contest/500/submission/102869091

//https://atcoder.jp/contests/abc183/tasks/abc183_f      (DSU + map important ques)
//https://atcoder.jp/contests/abc183/submissions/19185421
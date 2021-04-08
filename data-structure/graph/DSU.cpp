#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

struct DSU {
  vector <int> parent, size;
  int components;
  DSU(int n) {
    parent.resize(n + 1);
    size.assign(n + 1, 1);
    iota(all(parent), 0);
    components = n;
  }

  //get leader
  int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
  }

  void unite(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return;
    if (size[x] < size[y]) swap(x, y);
    components--; //components decreases with union
    parent[y] = x;
    size[x] += size[y];
  }
};


int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n, m; cin >> n >> m;
  DSU dsu(n);

  for (int i = 0, x, y; i < m; ++i) {
    cin >> x >> y;
    dsu.unite(x, y);
  }

  cout << dsu.components;

  return 0;
}

/*
 * It is also helpful for those problems when we need to do some linking and getting some leader like linkedlist, but in linkedlist
   getting leader is a little bit slow, so you can see that whenever have to do linking like Tree or linkedlist and getting leader is
   is the main role it is super helpful to use DSU. Like this problem: https://codeforces.com/contest/371/problem/D (soln: https://codeforces.com/contest/371/submission/111206598)
    BTW we can use std::set also.

 * Problem: Find the minimum number of edges that should be removed so that there should be no cycle in the
            given undirected graph.
  soln: By Dsu, same as Kruksal algo for spanning tree. Keep adding edges when cycle found do ans++, and don't
  add that edge to your Dsu.

  Another important use of DSU is to compress the nodes into one component. This is useful trick mostly in bridge tree or
  (2-edge tree) where we have to consider a bunch of nodes as a single component.
  EX: https://codeforces.com/contest/1000/problem/E       (brideges, 2-edge component, diameter of Tree, DSU components)
  https://codeforces.com/contest/1000/submission/104892785

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

/*
https://atcoder.jp/contests/arc111/tasks/arc111_b
converting the given problem to a graph problem, then solve it: https://atcoder.jp/contests/arc111/submissions/19299363

https://www.codechef.com/LTIME94A/problems/UNICOLOR  (Combine the groups and then calculate answer)
https://www.codechef.com/viewsolution/44306667
*/
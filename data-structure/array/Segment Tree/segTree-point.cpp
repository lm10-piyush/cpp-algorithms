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

//Range min
template <typename T, typename X = int>
struct SegTree {
  vector <T> tree;
  int n;

  SegTree(vector<X> &A) {
    n = sz(A);
    tree.resize(4 * n);
    build(A, 0, n - 1, 1);
  }

  T merge(T a, T b) {  //merge Two segments
    return min(a, b);
  }

  void build(vector<X> &A, int lo, int hi, int node) {
    if (lo == hi) {
      tree[node] = T(A[lo]);
      return;
    }
    int mid = (lo + hi) / 2;
    build(A, lo, mid, 2 * node);
    build(A, mid + 1, hi, 2 * node + 1);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
  }

  void upd(int idx, X val, int lo, int hi, int node) {
    if (hi < idx or lo > idx) return; // no overlapp
    if (lo == hi and hi == idx) { //total overlapp
      tree[node] = T(val);
      return;
    }

    int mid = (lo + hi) / 2;
    upd(idx, val, lo, mid, 2 * node);
    upd(idx, val, mid + 1, hi, 2 * node + 1);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
  }

  void upd(int idx, X val) {  //update at value at index 'idx' to 'val'
    upd(idx, val, 0, n - 1, 1);
  }

  T qry(int l, int r, int lo, int hi, int node) {
    if (hi < l or lo > r) return 1e9; //No-overlapp
    if (l <= lo and hi <= r) {    //total overlap
      return tree[node];
    }
    int mid = (lo + hi) / 2;
    return merge(qry(l, r, lo, mid, 2 * node), qry(l, r, mid + 1, hi, 2 * node + 1));
  }

  T qry(int l, int r) { //query [l...r]
    return qry(l, r, 0, n - 1, 1);
  }
};



int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  vector <int> A = {3, 4, 1, 4, 6, 8, 9, 2, 1, 0, 4};
  SegTree <int> st(A);  //template
  cout << st.qry(0, sz(A) - 1) << endl;
  cout << st.qry(0, 3) << endl;
  cout << st.qry(3, 3) << endl;
  cout << st.qry(5, 5) << endl;
  cout << st.qry(4, 5) << endl;

  st.upd(9, 5);
  cout << st.qry(0, sz(A)) << endl;
  cout << st.qry(8, 9) << endl;

  return 0;
}

/*
 * It can calculate the values of the functions which are Associative, that means: a * (b * c) = (a*b)*c
 * Simple way to remember the Segtree is associating the indices and their corresponding segment (represented by 'node')
 * It is very common trick in Segtree or Fenwick trees to sort the query according to "Right pointer" of query (for offline queries)
 then update the answer and after that, calculate the answer for the query. This trick is majorly for offline queries.
 * We can prune or navigate the Query function in a way that it looks like Binary search.
 * We can calculate lengths, number of intersection of segments and many more.

 * There is another type of problems also: The update operation is something else and qry operation is something else. Ex: update operation
   is add 'v' in the range and qry operation is minimum in the range. Another example: update operation is multiplication of 'v' and qry operation is
   addition of the range. To solve these types of problems we can solve these problems using normal segment tree (without lazy propogation), but we have
   to make sure that both the operations must be Distributive. Source: https://codeforces.com/edu/course/2/lesson/5/2

 * https://www.youtube.com/watch?v=_zYMsx4iOSc        (must watch, Parvel marvin 2-D queries and Data structure).
 * Mostly we use Euler tour for subtree queries, and for heavylight / centroid decompo for path queries.

 * We can find MEX of whole using Segtree with updates, each query will be in O(log n) time? how by maintaining counts of each element in range.

 * Segtree: https://usaco.guide/plat/segtree-ext?lang=cpp
*/

//https://codeforces.com/blog/entry/57319 (Some trick)

//https://www.spoj.com/problems/RMQSQ/

//https://codeforces.com/contest/1691/problem/D                     (segtree, Next greater element, observational)
// https://codeforces.com/contest/1691/submission/159468637

//problem: https://codeforces.com/contest/339/problem/D
//soln: https://codeforces.com/contest/339/submission/78825205

//https://cses.fi/problemset/task/1649

//https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/0000000000337b4d (Seg Tree with arithmetics)
//https://pastebin.com/2ZafVfJ6

//https://cses.fi/problemset/task/1143  (hotels),(quering the left most and right most index)
//https://pastebin.com/g7UUTynJ

//https://www.codechef.com/ENJU2020/problems/ECJN208
//https://www.codechef.com/viewsolution/34856026

// https://www.spoj.com/problems/DQUERY/  (DQUERY USING BIT)
//https://pastebin.com/5QkP5KkC               (BIT solution)


// https://www.spoj.com/problems/KQUERY/            (BIT solution)
// https://pastebin.com/jNap9hvZ



//https://www.hackerearth.com/problem/algorithm/subtree-queries/description/  (Euler tour)
//https://pastebin.com/iMV9xNPx

//https://codeforces.com/problemset/problem/332/B
//https://codeforces.com/contest/332/submission/88007883
//easy solutin without seg tree just suffix: https://codeforces.com/contest/332/submission/88016080

//Euler tour + array to tree conversion + path sum query
//https://www.codechef.com/JULY20B/problems/DRGNDEN or https://www.codechef.com/problems/DRGNDEN/
//https://www.codechef.com/viewsolution/37019198

//https://codeforces.com/contest/1262/problem/D2         (Can be done with c++ pbds)
// https://codeforces.com/contest/1262/submission/109781843   (pbds solution)


//https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/C       (Intersecting intervals)
//https://pastebin.com/3BYAgxyL

//https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/D           (Nested intervals)
// https://pastebin.com/NmTfmJkB

/*
 * For path sum query in euler tour: just all values in the range of start of root and start of 's' node, and
   all the others will be cancelled out automatically. This technique is generally used when we have inverse of operation also.
 * https://cses.fi/problemset/task/1138  (euler tour, path sum query)
 * https://pastebin.com/Kdb74mwu   (using fenwick tree)


*/
/******************* segment tree***********/
/*
*Segment tree is a binary tree, each node stores the information of a particular segment of the original array
   of an array ranges, and we bulid this segment tree in another array, like we use heap to represent a tree.
*Complexity to bulid and search is O(n) and O(log n) respectively.
*Here I take starting index as 1 for segment tree.


blogs : https://codeforces.com/blog/entry/22616 (Problems)
    https://codeforces.com/blog/entry/15890  (Some theory)
Resource: https://cp-algorithms.com/data_structures/segment_tree.html
        : https://codeforces.com/edu/course/2/lesson/5/1

Problem: https://codeforces.com/contest/1208/problem/D (Restore permutation, https://codeforces.com/contest/1208/problem/D)
       :https://www.hackerrank.com/challenges/robot/problem (segTree with DP, sol: https://pastebin.com/q9jip5X0)

      https://codeforces.com/contest/52/problem/C  (circular RMq)
      https://codeforces.com/contest/52/submission/72788292

****************************************
steps:
1) progate the lazy
2) check for no overlap
3) check for total overlap
4) recursion for partial overlap
******************************************
segtree for
1) min/max
2) sum of elements
3) count of elements (2D segtree, eg. letters, count the number of letters between [l, r])
     https://codeforces.com/contest/558/problem/
     https://codeforces.com/contest/558/submission/79979941
4) xor
5) number of inversions, https://codeforces.com/contest/61/problem/E
6) Polynomial queries


*/
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
//range sum - query
//range update=> increase [l, r] by value 'val'
template <typename T, typename X = int>
struct SegTree {
  vector <T> tree;
  vector <T> lazy;
  int n;
  SegTree(vector <X>& A) {
    n = sz(A);
    tree.resize(4 * n);
    lazy.assign(4 * n, 0);
    build(A, 0, n - 1, 1);
  }

  T merge(T a, T b) {  //merge Two segments
    return min(a, b);
  }

  void build(vector<X> &A, int lo, int hi, int node) {
    if (lo == hi) {
      tree[node] = A[lo];
      return;
    }
    int mid = (lo + hi) >> 1LL;
    build(A, lo, mid, 2 * node);
    build(A, mid + 1, hi, 2 * node + 1);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
  }
  void propagate(int lo, int hi, int node) {
    if (lazy[node]) {
      tree[node] += lazy[node];
      if (lo != hi) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
      }
      lazy[node] = 0;
    }
  }

  void upd(X val, int l, int r, int lo, int hi, int node) {
    //push-changes
    propagate(lo, hi, node);
    //no-overlap
    if (hi < l or r < lo) return;
    //total-overlap
    if (l <= lo and hi <= r) {
      tree[node] += val;
      if (lo != hi) {
        lazy[2 * node] += val;
        lazy[2 * node + 1] += val;
      }
      return;
    }
    int mid = (lo + hi) >> 1;
    upd(val, l, r, lo, mid, 2 * node);
    upd(val, l, r, mid + 1, hi, 2 * node + 1);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);

  }

  T qry(int l, int r, int lo, int hi, int node) {
    //push changes
    propagate(lo, hi, node);

    if (hi < l or lo > r) return 1e9;

    if (l <= lo and hi <= r) {
      return tree[node];
    }
    int mid = (lo + hi) >> 1;
    return merge(qry(l, r, lo, mid, 2 * node), qry(l, r, mid + 1, hi, 2 * node + 1));
  }

  void upd(X val, int l, int r) { //upd by +val in [l..r]
    upd(val, l, r, 0, n - 1, 1);
  }
  T qry(int l, int r) {    //[l...r]
    return qry(l, r, 0, n - 1, 1);
  }

};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  vector <int> A = {3, 4, 1, 4, 6, 8, 9, 2, 1, 0, 4};
  SegTree <int> st(A);

  cout << st.qry(0, sz(A)) << endl;
  cout << st.qry(0, 3) << endl;
  cout << st.qry(3, 3) << endl;
  cout << st.qry(5, 5) << endl;
  cout << st.qry(4, 5) << endl;

  st.upd(-10, 4, 6);
  st.upd(-4, 1, 4);
  cout << st.qry(0, sz(A)) << endl;
  cout << st.qry(6, sz(A)) << endl;
  cout << st.qry(2, 4) << endl;



  return 0;
}

/*
 * Resource: https://codeforces.com/edu/course/2/lesson/5/1
 * To use lazy seg-tree; operations must be: Associative. If operations are not commuatative, then we have to do operations safely.
   The order should be maintained.


https://cses.fi/problemset/task/1651
https://codeforces.com/contest/877/problem/E (seg tree on tree with euler tour)
solution: https://codeforces.com/contest/877/submission/82785039


https://atcoder.jp/contests/abc187/tasks/abc187_e  (Euler tour, tree, subtree value sum)
https://atcoder.jp/contests/abc187/submissions/19168934 (solution using fenwick tree)

https://cses.fi/problemset/task/2166
https://pastebin.com/kD1uMGZz
*/
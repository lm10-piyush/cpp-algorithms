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

//Range Min
struct SegTree{
  vector <int> tree;
  int n; 

  SegTree(vector<int> &A){
    n = sz(A);
    tree.assign(4*n, 0);
    build(A, 0, n-1, 1);
  }

  void build(vector<int>&A, int lo, int hi, int node){
    if(lo == hi){
      tree[node] = A[lo];
      return;
    }
    int mid = (lo + hi) / 2;
    build(A, lo, mid, 2*node);
    build(A, mid+1, hi, 2*node+1);
    tree[node] = min(tree[2*node], tree[2*node+1]);
  }

  void upd(int idx, int val, int lo, int hi, int node){
    // no overlapp
    if(hi < idx or lo > idx) return;
    //total overlapp
    if(lo == hi and hi == idx){
      tree[node] = val;
      return;
    }

    int mid = (lo + hi) / 2;
    upd(idx, val, lo, mid, 2*node);
    upd(idx, val, mid+1, hi, 2*node+1);
    tree[node] = min(tree[2*node], tree[2*node+1]);
  }

  void upd(int idx, int val){
    upd(idx, val, 0, n-1, 1);
  }

  int qry(int l, int r, int lo, int hi, int node){
    //no overlapp
    if(hi < l or lo > r) return 1e9;
    //total overlapp
    if(l <= lo and hi <= r){
      return tree[node];
    }
    int mid = (lo + hi) / 2;
    return min(qry(l, r, lo, mid, 2*node), qry(l, r, mid+1, hi, 2*node+1));
  }

  int qry(int l, int r){
    return qry(l, r, 0, n-1, 1);
  }

};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vector <int> A = {3, 4, 1, 4, 6, 8, 9, 2, 1, 0, 4};
    SegTree st(A);

    cout << st.qry(0, sz(A)) << endl;
    cout << st.qry(0, 3) << endl;
    cout << st.qry(3, 3) << endl;
    cout << st.qry(5, 5) << endl;
    cout << st.qry(4, 5) << endl;

    st.upd(9, 5);
    cout << st.qry(0, sz(A)) << endl;
    cout << st.qry(8, 9) << endl;



  return 0;
}

//https://www.spoj.com/problems/RMQSQ/

//problem: https://codeforces.com/contest/339/problem/D
//soln: https://codeforces.com/contest/339/submission/78825205

//https://cses.fi/problemset/task/1649

//https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/0000000000337b4d (Seg Tree with arithmetics)
//https://pastebin.com/2ZafVfJ6

//https://cses.fi/problemset/task/1143  (hotels),(quering the left most and right most index)
//https://pastebin.com/g7UUTynJ
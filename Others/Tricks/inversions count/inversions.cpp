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
//https://www.spoj.com/problems/INVCNT/
//https://codeforces.com/contest/1042/problem/D
//https://codeforces.com/contest/61/problem/E


struct BIT{
  vector <ll> bit;
  int n; 
  BIT(int _n){
    n = _n;
    bit.assign(n+2, 0);
  }
  void upd(int id, int val){
    for (++id; id <= n; id += id&-id)
      bit[id] += val;
  }

  ll qry(int id){
    ll res = 0;
    for (++id; id > 0; id -= id&-id)
      res += bit[id];
    return res;
  }
};


void solve(){
    int n; cin >> n;
    vector <int> A(n), compress(n);
    for (int i = 0; i < n; ++i){
      cin >> A[i];
      compress[i] = A[i];
    }
    //compression
    sort(all(compress));
    compress.resize(unique(all(compress)) - compress.begin());
    for (int i = 0; i < n; ++i){
      A[i] = lower_bound(all(compress), A[i]) - compress.begin();
    }

    reverse(all(A));  //because we have move from backwards, i < j, A[i] > A[j]
    const int N = 2e5 + 2;
    BIT f(N);
    ll ans = 0;
    //A[i] > A[j], i < j
    //iterating over 'i', from backwards of original A, `cuz now A is reversed.
    //for each 'i', we count the inversions pair(finding j) for 'i', using BIT
    for (int &i: A){   
      ans += f.qry(i); //there should be f.qry(i-1) ??? here when integers are not distinct
      f.upd(i, 1);
    }

    cout << ans << endl;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
      solve();


  return 0;
}

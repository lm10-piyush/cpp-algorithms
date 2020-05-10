#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(x) (int)x.size() 
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ****************************************/

/*
  it gives: if exactly found: return index.
  otherwise: that index (lo), such that A[lo] < x; 
*/
int bi_search(vector<int> &v, int x){
    int lo = 0, hi = sz(v)-1;
    while(lo < hi){
      int mid = (lo + hi + 1) >> 1;  //ceil: it is really helpful when lo & hi are adjacent.
      if(v[mid] <= x)
        lo = mid;
      else hi = mid-1;  //also important
    }
    return lo;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vector <int> v = {3, 5, 7, 19, 20, 25, 30, 39, 50, 55};

    int x; cin >> x;
    cout << bi_search(v, x);

      


  return 0;
}

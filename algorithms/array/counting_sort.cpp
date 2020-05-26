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


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n; cin >> n;
    vector <int> A(n), res(n);
    for (int &i: A) cin >> i;
    vector <int> cnts(*max_element(all(A))+1, 0);

    for (int i : A){
      cnts[i]++;
    }

    int pos = 0;
    for (int i = 0; i < n; ++i){
      while(cnts[pos] == 0) pos++;
      res[i] = pos;
      cnts[pos]--;
    }
    for (int i: res)
      cout << i << ' ';

  return 0;
}

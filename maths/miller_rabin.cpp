#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

//problem: https://www.spoj.com/problems/PON/
//https://pastebin.com/XJVm7nhd
ll mul(ll a, ll b, ll mod){
  ll res = 0;
  while(b){
    if(b & 1) res = (res + a) % mod;
    a = (2 * a) % mod;
    b >>= 1;
  }
  return res;
}

ll power(ll a, ll b, ll mod){
    ll res = 1;
    while(b){
      if(b & 1)
        res = mul(res, a, mod);
      a = mul(a, a, mod);
      b >>= 1;
    }
    return res;
}

bool check_composite(ll n, ll a, ll d, int s){
  ll x = power(a, d, n);
  if(x == 1 || x == n-1)
    return false;
  for (int r = 1; r < s; ++r){
    x = mul(x, x, n);
    if(x == n-1)
      return false;
  }
  return true;
}



bool miller_rabin(ll n){
    if(n < 4)
      return (n == 2 || n == 3);
    int s = 0;
    ll d = n-1;
    while((d & 1) == 0){
      d >>= 1;
      s++;
    }

    //repeat the miller process untill
    vector <int> v = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}; //must be true for all the bases
    for (int a: v){
      if(n == a) return true;
      if(check_composite(n, a, d, s))
        return false;
    }
    return true;
}



int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--){
      ll n; cin >> n;
      if(miller_rabin(n))
        cout << "YES\n";
      else cout << "NO\n";
    }

  return 0;
}

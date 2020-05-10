#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define arr_watch(arr, n) for(int i=0;i<n;++i) cout<<arr[i]<<" \n"[i==n-1]
using namespace std;

//fac[i] => i! % mod (factorial of i)
//reFac[i] => 1/(i!) % mod => inverse(i!) % mod => power(i!, mod-2) (by fermat-little theorem) 

/*********************************** CODE IS HERE *******************************************/
const int N = 1e5 + 5;
const int mod = 998244353;
ll fac[N], reFac[N];

ll power(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1){
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    ll n, m, k; cin >> n >> m >> k;
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
        fac[i] = (fac[i-1] * i) % mod;

    reFac[n] = power(fac[n], mod-2);
    for (int i = n; i > 0; --i){
        reFac[i-1] = (reFac[i] * i) % mod;
    }

    //apply => nCr(n-1, k) * m * (m-1)^k;
    //https://codeforces.com/contest/1081/problem/C
    ll ans = (((fac[n-1]*reFac[k] % mod) * reFac[n-1-k] % mod) * m % mod)*power(m-1, k);
    ans %= mod;

    cout << ans;

    return 0;
}

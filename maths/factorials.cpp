#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define arr_watch(arr, n) for(int i=0;i<n;++i) cout<<arr[i]<<" \n"[i==n-1]
using namespace std;

//fac[i] => i! % mod (factorial of i)
//reFac[i] => 1/(i!) % mod => inverse(i!) % mod => power(i!, mod-2) (by fermat-little theorem) 

/*********************************** CODE IS HERE *******************************************/
const int N = 2e5 + 5;
const int mod = 998244353;
ll fac[N+3], reFac[N+3];

ll power(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1){
            (res *= a) %= mod;
        }
        (a *= a) %= mod;
        b >>= 1;
    }
    return res;
}

void calc() {
    fac[0] = 1;
    for (int i = 1; i <= N; ++i)
        fac[i] = (fac[i-1] * i) % mod;

    reFac[N] = power(fac[N], mod-2);
    for (int i = N; i > 0; --i){
        reFac[i-1] = (reFac[i] * i) % mod;
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    calc();  //build

    ll n, m, k; cin >> n >> m >> k;
    

    //apply => nCr(n-1, k) * m * (m-1)^k;
    //https://codeforces.com/contest/1081/problem/C
    ll ans = (((fac[n-1]*reFac[k] % mod) * reFac[n-1-k] % mod) * m % mod)*power(m-1, k);
    ans %= mod;

    cout << ans;

    return 0;
}


//https://cses.fi/problemset/task/1079

//https://www.hackerrank.com/contests/all-india-contest-by-coding-club-india-13-june/challenges/easy-counting-problem
// https://pastebin.com/PUjG17KD

//https://cses.fi/problemset/task/1716  (stars and bars)
//https://pastebin.com/Y9NBBszs

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
vector <ll> fac(N + 2), reFac(N + 2);

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
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
        fac[i] = (fac[i - 1] * i) % mod;

    reFac[N] = power(fac[N], mod - 2);
    for (int i = N; i > 0; --i) {
        reFac[i - 1] = (reFac[i] * i) % mod;
    }
}

ll modMul(ll a, ll b) {
    if (a >= mod) a %= mod;
    if (b >= mod) b %= mod;
    return (a * b) % mod;
}

ll nCr(ll a, ll b) {  //nCr => C(n, r)
    if (a < 0 or b < 0 or a < b) return 0LL;
    return modMul(fac[a], modMul(reFac[b], reFac[a - b]));
}


/*
    This way to calculate is useful when floating point numbers are allowed.
    n!/(r! * (n-r)!) => ((n-r+1) * (n-r+2)..n) / r!
    https://codeforces.com/contest/107/problem/B
    https://codeforces.com/contest/107/submission/103661808
*/
ll C(ll n, ll r) {
    ll ans = 1;
    for (int i = 0; i < r; ++i) {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    calc();  //build

    ll n, m, k; cin >> n >> m >> k;


    //apply => nCr(n-1, k) * m * (m-1)^k;
    //https://codeforces.com/contest/1081/problem/C
    ll ans = (((fac[n - 1] * reFac[k] % mod) * reFac[n - 1 - k] % mod) * m % mod) * power(m - 1, k);
    ans %= mod;

    cout << ans;

    return 0;
}

/*
 * Wilson theorem: (n - 1)! = -1 mod p, where p is prime.
   There is proof.

*/

//https://cses.fi/problemset/task/1079

//https://www.hackerrank.com/contests/all-india-contest-by-coding-club-india-13-june/challenges/easy-counting-problem
// https://pastebin.com/PUjG17KD

//https://cses.fi/problemset/task/1716  (stars and bars)
//https://pastebin.com/Y9NBBszs

//https://atcoder.jp/contests/abc178/tasks/abc178_c
//https://atcoder.jp/contests/abc178/submissions/16733179

//https://www.hackerrank.com/challenges/coinage/problem
//solution : smart brute force

//https://leetcode.com/problems/count-ways-to-make-array-with-product/
//(stars and bars, maths, counting, combinatorics, https://pastebin.com/4VETqNEE)

//https://codeforces.com/gym/102942/problem/E
//(maths, combinatorics, stars and bars, https://pastebin.com/pFJJTq9R)

/*
https://codeforces.com/contest/1288/problem/C
maths, combinatorics, https://codeforces.com/contest/1288/submission/88074818

https://atcoder.jp/contests/arc110/tasks/arc110_d     (Really Nice problem)
https://atcoder.jp/contests/arc110/submissions/18604093

https://atcoder.jp/contests/arc116/tasks/arc116_c        (combinatorics, Stars and Bars, Classic)
https://atcoder.jp/contests/arc116/submissions/21387350
*/
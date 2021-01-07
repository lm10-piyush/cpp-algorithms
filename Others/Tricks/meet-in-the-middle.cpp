#include <bits/stdc++.h>
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

    int n, m; cin >> n >> m;
    vector <int> A(n);
    for (int &i: A) cin >> i;
    int k1 = (n + 1) / 2, k2 = n / 2;
    
    vector <ll> X, Y;
    //Brute force on First part
    for (int i = 0; i < (1 << k1); ++i) {
        ll sum = 0;
        for (int j = 0; j < k1; ++j) {
            if (i >> j & 1) {
                sum += A[j];
            }
        }
        if (sum <= m) {
            X.push_back(sum);
        }
    }

    //brute force on Second part
    for (int i = 0; i < (1 << k2); ++i) {
        ll sum = 0;
        for (int j = 0; j < k2; ++j) {
            if (i >> j & 1) {
                sum += A[j + k1];
            }
        }
        if (sum <= m) {
            Y.push_back(sum);
        }
    }


    sort(all(Y));

    ll ans = 0;
    //Now apply binary search to find the best answer
    for (ll i: X) {
        int pos = lower_bound(all(Y), m - i) - Y.begin();
        if (pos >= sz(Y) or Y[pos] + i > m) pos--;
        ans = max(ans, i + Y[pos]);
    
    }

    cout << ans;

    return 0;
}

/*

--------- Meet in the middle Technique ---------------
Like brute force but here we divide the original array into two parts and apply the brute forces individually and merge them.

For more details.....
https://www.geeksforgeeks.org/meet-in-the-middle/

https://atcoder.jp/contests/abc184/tasks/abc184_f
Solution: just above code.

*/
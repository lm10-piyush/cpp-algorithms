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

const int mod = 1e9 + 7;

//matrix multiplication
vector<vector<ll>> mult(vector<vector<ll>> A, vector<vector<ll>> B) {
    int a = sz(A), b = sz(A[0]), c = sz(B[0]);

    vector<vector<ll>> ans(a, vector<ll> (c, 0)); //order:  a x c
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < c; ++j) {
            int res = 0;
            for (int k = 0; k < b; ++k) {
                res += (A[i][k] * B[k][j]) % mod;
                res %= mod;
            }
            ans[i][j] = res;
        }
    }
    return ans;
}

vector<vector<ll>> powerMatrix(vector<vector<ll>>A, ll n) {
    int a = sz(A);
    vector <vector<ll>> res(a, vector<ll>(a, 0));
    for (int i = 0; i < a; ++i)
        res[i][i] = 1;
    while (n) {
        if (n & 1) res = mult(res, A);
        A = mult(A, A);
        n >>= 1;
    }
    return res;
}

//fibonacci(n)
ll fibo(ll n) {
    if (n <= 1) return n;
    vector<vector<ll>> A = {{1, 1}, {1, 0}};
    vector<vector<ll>> B = {{1}, {0}};

    A = powerMatrix(A, n-1);  //matrix to the power zero is Identity matrix
    A = mult(A, B);
    return A[0][0];
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        if (n > m) swap(n, m);

        ll f1 = fibo(n+1); //fibonacci(n+1)
        ll f2 = fibo(m+2); //fibonacci(m+2)

        ll ans = (f2 - f1 + mod) % mod;
        cout << ans << endl;
    }

    return 0;
}

/*
 * Above one is solution of : https://www.spoj.com/problems/FIBOSUM/

 * https://www.spoj.com/problems/SEQ/

 * https://cses.fi/problemset/task/1722  (fibonacci simple problem)
*/
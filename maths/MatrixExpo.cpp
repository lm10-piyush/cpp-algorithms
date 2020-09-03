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

const int mod = 1e9;

//matrix multiplication
vector<vector<ll>> mult(vector<vector<ll>> A, vector<vector<ll>> B) {
    int a = sz(A), b = sz(A[0]), c = sz(B[0]);

    vector<vector<ll>> ans(a, vector<ll> (c, 0)); //order:  a x c
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < c; ++j) {
            int res = 0;
            for (int k = 0; k < b; ++k) {
                res += (A[i][k] * B[k][j]) % mod;
                if (res >= mod) res %= mod;
            }
            ans[i][j] = res;
        }
    }
    return ans;
}

//Matrix Exponentiation
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


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        vector <vector<ll>> A(k, vector<ll>(k, 0)); // K x K
        vector <vector<ll>> B(k, vector<ll>(1, 0));  // K x 1
        //Enter in Column wise
        for (int i = 0; i < k; ++i)
            cin >> B[k-i-1][0];

        //Enter in row
        for (int i = 0; i < k; ++i)
            cin >> A[0][i];
        
        int n; cin >> n;

        //first case
        if (n <= k) {
            cout << B[k - n][0] << endl;
            continue;
        }
        //Apply 1, in this fashion
        for (int i = 1; i < k; ++i) {
            A[i][i-1] = 1;
        }

        A = powerMatrix(A, n - k); //not to use n-k+1, becuz here the base starts from i = 1, not from i = 0
        A = mult(A, B);  //multiply the exponented matrix with the 'B'base condition matrix.

        cout << A[0][0] << endl;  //ans found at A[0][0]

    }

    return 0;
}

// https://www.spoj.com/problems/SEQ/
//lm10_piyush
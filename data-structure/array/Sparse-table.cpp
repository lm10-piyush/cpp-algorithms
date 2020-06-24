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

struct STable {
    const int Log = 20;
    vector <vector<int>> sparse;
    int n;

    STable(vector <int> &A) {
        n = sz(A);
        sparse.assign(n, vector<int>(Log+1, 0));
        build(A);
    }

    void build(vector <int>& A) {
        for (int i = 0; i < n; ++i) sparse[i][0] = A[i];
        for (int j = 1; j <= Log; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                sparse[i][j] = min(sparse[i][j-1], sparse[i+(1 << (j-1))][j-1]);
            }
        } 
    }

    int qry(int l, int r) {
        int ans = 1e9;
        for (int i = Log; i >= 0; --i) {
            if (l + (1 << i) - 1 <= r) {
                ans = min(ans, sparse[l][i]);
                l += 1 << i;
            }
        }
        return ans;
    }    

};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <int> A(n);
    for (int &i: A) cin >> i;

    STable st(A);

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << st.qry(l, r) << endl;
    }

    return 0;
}

/*
sparse[i][j] => f(i, i + 2^i - 1) or it contains the min() from i next 2^i elements including self so [i, i+2^i - 1]

https://www.spoj.com/problems/RMQSQ/


*/
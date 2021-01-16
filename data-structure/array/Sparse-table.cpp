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

template <typename T>
struct STable {
    const int Log = 20;
    vector <vector<T>> sparse;
    int n;

    STable(vector <T> &A) {
        n = sz(A);
        sparse.assign(n, vector<T>(Log+1, 0));
        build(A);
    }

    void build(vector <T>& A) {
        for (int i = 0; i < n; ++i) sparse[i][0] = A[i];
        for (int j = 1; j <= Log; ++j) {   
            for (int i = 0; i + (1 << j) <= n; ++i) {
                sparse[i][j] = min(sparse[i][j-1], sparse[i+(1 << (j-1))][j-1]);
            }
        } 
    }

    T qry(int l, int r) {
        T ans = 1e9;
        for (int i = Log; i >= 0; --i) {
            if (l + (1 << i) - 1 <= r) {
                ans = min(ans, sparse[l][i]);
                l += 1 << i;
            }
        }
        return ans;
    }  

    //only for idempotent operations like min, max, gcd etc 
    T qry1(int l, int r) {
        int len = r - l + 1;
        int k = log2(len);
        int x = len - (1 << k); //remaining
        T ans = min(sparse[l][k], sparse[l+x][k]);
        return ans;
    }  

};    


    


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <int> A(n);
    for (int &i: A) cin >> i;

    STable <int> st(A);

    int q; cin >> q;
    while (q--) {  
        int l, r; cin >> l >> r; //l, r => indices
        cout << st.qry(l, r) << endl;
        cout << st.qry1(l, r) << endl;
    }

    return 0;
}


/*
sparse[i][j] => f(i, i + 2ʲ - 1) or it contains the min() from i next 2ʲ elements including self so [i, i+2ʲ - 1]
f(i, i + 2ʲ - 1) => min(f(i, i + 2ʲ⁻¹-1), f(i+2ʲ⁻¹, i+2ʲ⁻¹ + 2ʲ⁻¹-1));

https://www.spoj.com/problems/RMQSQ/


https://codeforces.com/contest/91/problem/B
https://codeforces.com/contest/91/submission/90313176 (with binary search)
http://algoshots.herokuapp.com/problems/queue-91B/  (greedy solution also)


https://codeforces.com/contest/846/problem/D  O(1) query
https://codeforces.com/contest/846/submission/91562490

https://codeforces.com/contest/1454/problem/F  (+ binary search)
https://codeforces.com/contest/1454/submission/101060423
*/
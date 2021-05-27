#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

struct SegTree {
    vector <vector<int>> tree;
    int n;
    SegTree(vector<int>& A) {
        n = sz(A);
        tree.assign(4 * n, {});
        build(A, 0, n - 1, 1);
    }
    void build(vector <int>&A, int lo, int hi, int node) {
        if (lo == hi) {
            tree[node].push_back(A[lo]);
            return;
        }
        int mid = (lo + hi) / 2;
        build(A, lo, mid, 2 * node);
        build(A, mid + 1, hi, 2 * node + 1);
        tree[node].resize(hi - lo + 1);
        merge(all(tree[2 * node]), all(tree[2 * node + 1]), tree[node].begin());
    }

    int qry(int l, int r, int val, int lo, int hi, int node) {
        if (hi < l or lo > r) return 0;
        if (l <= lo and hi <= r) {
            int idx = upper_bound(all(tree[node]), val) - tree[node].begin();
            return ((hi - lo + 1) - idx);
        }

        int mid = (lo + hi) / 2;
        return qry(l, r, val, lo, mid, 2 * node) + qry(l, r, val, mid + 1, hi, 2 * node + 1);
    }

    //number of elements, greater than val in [l..r], complexity: O(log(n) * log(n))
    int qry(int l, int r, int val) {
        return qry(l, r, val, 0, n - 1, 1);
    }
};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <int> A(n);
    for (int &i : A) cin >> i;

    SegTree st(A);
    int q; cin >> q;

    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        l--, r--;
        cout << st.qry(l, r, k) << endl;
    }

    return 0;
}

//https://www.spoj.com/problems/KQUERY/
//To solve problem like Kquery, I used mergeSort approach with binary search.
//But here updates would be costly, becuz it is O(n.logn);

//https://atcoder.jp/contests/abc190/tasks/abc190_e
//https://atcoder.jp/contests/abc190/submissions/19819988

// https://codeforces.com/contest/1405/problem/E         (Not necessary to use but I've used it here)
// https://codeforces.com/contest/1405/submission/113355063

//https://atcoder.jp/contests/abc202/tasks/abc202_e
//Two ways to write euler tour:
//https://atcoder.jp/contests/abc202/submissions/22845140
//https://atcoder.jp/contests/abc202/submissions/22844995
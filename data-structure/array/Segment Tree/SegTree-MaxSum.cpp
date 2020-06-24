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

const ll inf = 1e18;

struct Node {
    ll pref, suff, sum, max_sum;
    Node(){}
    Node(ll a, ll b, ll c, ll d){
        pref = a, suff = b, sum = c, max_sum = d;
    }
};

struct SegTree {
    vector <Node> tree;
    int n; 
    SegTree(vector<int>& A) {
        n = sz(A);
        tree.resize(4*n);
        build(A, 0, n-1, 1);
    }
    Node merge(Node l, Node r) {
        Node res;
        res.sum = l.sum + r.sum;
        res.pref = max(l.pref, l.sum + r.pref);
        res.suff = max(r.suff, r.sum + l.suff);
        res.max_sum = max(max(l.max_sum, r.max_sum), l.suff + r.pref);  
        return res;
    }
    void build(vector<int>& A, int lo, int hi, int node) {
        if (lo == hi) {
            tree[node] = Node(A[lo], A[lo], A[lo], A[lo]);
            return;
        }
        int mid = (lo + hi) / 2;
        build(A, lo, mid, 2*node);
        build(A, mid+1, hi, 2*node + 1);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }
    Node qry(int l, int r, int lo, int hi, int node) {
        if (hi < l or lo > r) return {-inf, -inf, 0, -inf};
        if (l <= lo and hi <= r) {
            return tree[node];
        }
        int mid = (lo + hi) / 2;
        return merge(qry(l, r, lo, mid, 2*node), qry(l, r, mid+1, hi, 2*node+1));
    }
    void upd(int pos, int val, int lo, int hi, int node) {
        if (hi < pos or lo > pos) return;
        if (hi == lo and hi == pos) {
            tree[node] = {val, val, val, val};
            return;
        }
        int mid = (lo + hi) / 2;
        upd(pos, val, lo, mid, 2*node);
        upd(pos, val, mid+1, hi, 2*node+1);
        tree[node] = merge(tree[node*2], tree[2*node+1]);
    }

    void upd(int pos, int val) {
        upd(pos, val, 0, n-1, 1);
    }

    ll qry(int l, int r) {
        return qry(l, r, 0, n-1, 1).max_sum;
    }
};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> A(n);
    for (int &i: A) cin >> i;

    SegTree st(A);
    
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int pos, val; cin >> pos >> val;
            pos--;
            st.upd(pos, val);    
        }
        else {
            int l, r; cin >> l >> r; l--, r--;
            ll ans = st.qry(l, r);
            cout << ans << endl;
        }
    }

    return 0;
}

/*
Node contains: 
1) Maximum prefix sum of the segment
2) Maximum suffix sum of the segments
3) Sum of the whose segment [lo, hi]
4) Maximum sum of the segment [lo, hi]


https://www.spoj.com/problems/GSS1/   (there is no updates)
https://cses.fi/problemset/task/1190
*/
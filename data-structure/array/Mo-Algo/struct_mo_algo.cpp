#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type >
ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define LM10_Piyush
#ifdef LM10_Piyush
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)
#else
#define watch(...)
#endif


//number of unique elements
struct Mo_algo {
    vector <int> frq, A;
    const int N = 1000006;
    int blk, roll;

    struct Node {
        int i, l, r;
        Node() {}
        Node(int x, int y, int z) {
            l = x; r = y; i = z;
        }
    };

    Mo_algo(vector <int> X) {
        frq.assign(N + 1, 0);
        A = X;
        int n = sz(A);
        blk = ceil(sqrt(n));
        roll = 0;
    }
    void add(int x) {
        if (frq[x] == 0) roll++;
        frq[x]++;
    }

    void remove(int x) {
        frq[x]--;
        if (frq[x] <= 0) {
            roll--;
        }
    }

    //number of unique elements in range
    vector <int> process_qry(vector <pair<int, int>> queries) {
        int q = sz(queries);
        vector <Node> qry(q);
        vector <int> ans(q);
        for (int i = 0, l, r; i < q; ++i) {
            l = queries[i].first, r = queries[i].second;
            qry[i] = Node(l, r, i);
        }

        sort(all(qry), [&](Node x, Node y) {
            return make_tuple(x.l / blk, x.r) < make_tuple(y.l / blk, y.r);
        });

        int Mr = 0, Ml = 0; //inclusive [Ml, Mr]
        add(A[Mr]);

        for (int i = 0; i < q; ++i) {
            while (qry[i].l < Ml)
                add(A[--Ml]);

            while (qry[i].r > Mr)
                add(A[++Mr]);

            while (qry[i].l > Ml)
                remove(A[Ml++]);

            while (qry[i].r < Mr)
                remove(A[Mr--]);

            ans[qry[i].i] = roll;
        }
        return ans;
    }

};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <int> A(n);
    for (int &i : A)
        cin >> i;
    int q; cin >> q;
    vector <pair<int, int>> qry(q);
    for (int i = 0, l, r; i < q; ++i) {
        cin >> l >> r; l--; r--;
        qry[i] = {l, r};
    }
    Mo_algo mo(A);
    vector <int> ans = mo.process_qry(qry);
    for (int i : ans) {
        cout << i << endl;
    }



    return 0;
}


/*

//https://www.spoj.com/problems/DQUERY/     (number of distinct elements)
//same solution, given above


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


const int N = 1e6 + 5;
vector <int> frq(N); //we can use unordered_map(hash Map) to store keys when they are very large

int blk, roll; //roll => number of distinct elements

struct Node {
    int i, l, r;
    Node() {}
    Node(int x, int y, int z) {
        l = x; r = y; i = z;
    }
    bool operator<(Node x) {
        return make_tuple(l / blk, r) < make_tuple(x.l / blk, x.r);
    }

};

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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <int> A(n);
    for (int &i : A) cin >> i;
    int q; cin >> q;

    //============ Standard part of MO's algorithm ========
    blk = ceil(1.0 * sqrt(n));

    vector <Node> qry(q);
    vector <int> ans(q);
    for (int i = 0, l, r; i < q; ++i) {
        cin >> l >> r; l--, r--;
        qry[i] = Node(l, r, i);
    }

    sort(all(qry));

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

    //=========== MO's algo end ============

    for (int i = 0; i < q; ++i)
        cout << ans[i] << endl;


    return 0;
}

//https://www.spoj.com/problems/DQUERY/     (number of distinct elements)
//same solution, given above
//another solution by BIT, https://www.quora.com/What-is-an-approach-to-solve-the-problem-DQUERY-of-SPOJ-using-BIT-Segment-Tree

//https://www.spoj.com/problems/FREQ2/      (maximum frequency in range)
//https://pastebin.com/pD7XX8dW

//https://www.hackerearth.com/problem/algorithm/happy-segments-e290faa6/
//https://pastebin.com/jJrNiH1b

//https://codeforces.com/contest/220/problem/B
//https://codeforces.com/contest/220/submission/77406583

//https://codeforces.com/contest/1288/problem/E  (counting the number of unique elements in the range)
//https://codeforces.com/contest/1288/submission/120435890

/*
 Note: if you solve set(dfs and return the set) here to solve this problem, it will give TLE
 https://cses.fi/problemset/task/1139  (Mo on trees, using Euler tour)
 https://pastebin.com/HWjZyVhk   (it will give TLE because of collison in unordered_map)
 https://pastebin.com/rXCKz4Kw   (AC solution with vector and compression)

*/
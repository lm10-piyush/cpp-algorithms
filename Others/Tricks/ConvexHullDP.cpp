#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)

//https://atcoder.jp/contests/dp/tasks/dp_z

//line: y = mx + c represented by pair : {slope, intercept}

struct Li_Chao {    
    const int N = 1e6 + 2; //max value of 'x' substitute
    const ll INF = 1e17;

    vector <array <ll, 2>> tree;
    Li_Chao() {
        tree.assign(4*N, {0, INF}); //we want min thats why I put INF here otherwise put -INF
    }

    //calculating the value of y, in line at some point x
    ll fx(array <ll, 2> line, int x) {
        return line[0] * x + line[1]; 
    }

    void insert(array <ll, 2> line, int lo, int hi, int node) {
        int mid = (lo + hi) / 2;
        bool left = fx(line, lo) < fx(tree[node], lo);
        bool m = fx(line, mid) < fx(tree[node], mid);
        if (m) swap(tree[node], line);
        if (hi - lo == 1) return;
        if (left != m) insert(line, lo, mid, 2*node);
        else insert(line, mid, hi, 2*node + 1);
    }

    ll qry(int x, int lo, int hi, int node) {
        int mid = (lo + hi) / 2;
        ll curr = fx(tree[node], x);
        if (hi - lo == 1) return curr;
        if (x < mid) return min(curr, qry(x, lo, mid, 2*node));
        else return min(curr, qry(x, mid, hi, 2*node + 1));
    }
    void insert(array <ll, 2> line) {
        insert(line, 1, N, 1);
    }
    ll qry(ll x) {
        return qry(x, 1, N, 1);
    }
};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    ll C; cin >> C;
    vector <ll> H(n);
    for (ll &i: H) cin >> i;
    vector <ll> dp(n);
    Li_Chao ch;
    for (int i = 0; i < n; ++i) {
        //giving best result in log(n)
        if (i) dp[i] = ch.qry(H[i]) + H[i] * H[i] + C;
        //these will be useful for indices > i
        array <ll, 2> line = {-2*H[i], H[i]*H[i] + dp[i]}; //{slope, intercept} 
        ch.insert(line);
    }

    cout << dp[n-1];

    return 0;
}


/*
    dp[i] => minimum cost to reach at position.
    dp[i] = min{dp[j] + (h[i] - h[j])^2 + C}, j < i
    But the solution is O(n^2)
    =============================================
    We gonna optimize with Convex hull optimization with Lichao tree
    It is a way to optimizing the DP state update.
    The main idea is to represent the cost function as line and store the line some data structure so that we can query efficiently
    like Li Chao tree. Use that line which gives you the best result.
    like here : cost : dp[j] + (h[i] - h[j])^2 + C => (h[i]^2 + C) + h[j]^2 - 2h[i]*h[j] + dp[j]
    (h[i]^2 + C) => constant for current 'i'
    cost : h[j]^2 + dp[j] - 2*h[i]*h[j]
    Now, we are currently at ith
    you see cost equation as: y = mx + c, m = 2h[j], intercept = h[j]^2 + dp[j]
    then y = -2*h[j]* x + intercept
    If we put x = h[i]
    then we get y = -2 * h[j]*h[i] + intercept
    ==========================================
    This is the concept to put the lines in the data structure then for current 'i' with h[i] height find the best value you can get
    using one of those lines. For this task Li Chao tree is recommended, although you can tree deque also.
    
    article: https://cp-algorithms.com/geometry/convex_hull_trick.html
    complexiy: O(n log(n))

*/
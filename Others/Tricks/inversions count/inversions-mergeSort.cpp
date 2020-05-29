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

vector <int> A;

ll mergeInversion(int l1, int r1, int l2, int r2) {
    vector <int> aux;
    ll inv = 0;
    int i = l1, j = l2;
    while (i <= r1 and j <= r2) {
        if (A[i] > A[j]) {
            inv += r1 - i + 1;
            aux.push_back(A[j++]);
        } else {
            aux.push_back(A[i++]);
        }
    }
    while (i <= r1)
        aux.push_back(A[i++]);
    while (j <= r2)
        aux.push_back(A[j++]);
    for (int i = 0; i < sz(aux); ++i) {
        A[l1 + i] = aux[i];
    }

    return inv;
}

ll mergeSort(int lo, int hi) {
    if (lo == hi) return 0;

    int mid = (lo + hi) / 2;
    ll ans = 0;
    ans += mergeSort(lo, mid);
    ans += mergeSort(mid+1, hi);

    ans += mergeInversion(lo, mid, mid+1, hi);
    return ans;
}

void solve() {
    int n; cin >> n;
    A.resize(n);
    for (int &i: A) cin >> i;

    ll ans = mergeSort(0, n-1);
    cout << ans << endl;
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--)
        solve();


    return 0;
}

// https://www.spoj.com/problems/INVCNT/
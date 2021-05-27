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

struct Trie {
    Trie *bit[2];
    int cnt;
    Trie() {
        for (auto &i : bit) i = nullptr;
        cnt = 0;
    }

    void insert(int x) {
        Trie *curr = this;
        for (int i = 30; i >= 0; --i) {
            bool b = x >> i & 1;
            if (curr->bit[b] == nullptr)
                curr->bit[b] = new Trie();
            curr = curr->bit[b];
            curr->cnt++;
        }
    }

    ll cnt_min(int x) { //counting number of elements greater than 'x' in trie
        Trie *curr = this;
        ll ans = 0;
        for (int i = 30; i >= 0; --i) {
            bool b = x >> i & 1;
            if (b) {
                if (curr->bit[b] != nullptr)  //no need to check curr->bit[b]->cnt, becuz we didn't use remove opration
                    curr = curr->bit[b];
                else return ans;
            } else {
                if (curr->bit[!b] != nullptr)
                    ans += curr->bit[!b]->cnt;

                if (curr->bit[b] != nullptr)
                    curr = curr->bit[b];
                else return ans;
            }
        }

        return ans;
    }
};


void solve() {
    int n; cin >> n;
    vector <int> A(n);
    for (int &i : A) cin >> i;

    Trie t;
    ll ans = 0;
    for (int i : A) {
        ans += t.cnt_min(i);
        t.insert(i);
    }

    cout << ans << endl;
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--)
        solve();


    return 0;
}

//https://www.spoj.com/problems/INVCNT/

//https://codeforces.com/contest/1417/problem/E
// https://codeforces.com/contest/1417/submission/112307613
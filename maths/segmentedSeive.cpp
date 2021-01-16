#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)

const int N = 4e4;
vector <ll> primes;
bitset <N> is_prime;

void seive() {
    is_prime.set();
    is_prime.reset(0); is_prime.reset(1);
    for (ll i = 2; i < N; ++i) {
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for (ll j = i * i; j < N; j += i) {
            is_prime[j] = false;
        }
    }
}

void solve() {
    ll l, r; cin >> l >> r;
    vector <bool> segment(r - l + 1, true);
    if (l == 1) segment[0] = false;
    for (ll i: primes) {
        if (i * i > r) break;
        ll base = ((l + i - 1) / i) * i; //this will give a number which is >= l and multiple of i
        for (ll j = base; j <= r; j += i) segment[j-l] = false;
        segment[base - l] = (base == i);  
    }
    for (int i = 0; i < sz(segment); ++i) {
        if (segment[i])
            cout << l + i << endl; 
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    seive();    

    int t; cin >> t;
    while (t--) solve();


    return 0;
}


/*
https://www.spoj.com/problems/PRIME1/
*/
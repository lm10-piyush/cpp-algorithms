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
/*
Here, Double hashing is used, ie. first find the hash of original sequence using module m1 and find the hash of
original sequence using module m2.
m1 = 1e9 + 123.
m2 = 2^64 (using unsigned long long).
Base or Point(p) is choosed randomly between [256, mod].
Then find the prefix hash array of original sequence using both modules using one at a time.
To compare the hashes of two strings, we have to compare the both hashes of each string.
Source: https://codeforces.com/blog/entry/60445

Below code is implementation of https://acmp.ru/index.asp?main=task&id_task=202

*/


#include<chrono>
#define ull unsigned long long


//generating the base(p)
ll gen_base(int before, int after) {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt_rand(seed);
    ll base = uniform_int_distribution<ll>(before+1, after)(mt_rand);
    return (base % 2 == 0 ? base-1 : base);
}


struct PolyHash {
    static const int mod = 1e9 + 123;
    static vector<ll> pow1;  //powers of base under modulo (1e9 + 123), size of pow1 = maxpow + 1, these are static
    static vector<ull> pow2; //powers of base under modulo (2^64), size of pow2 = maxpow + 1, cuz these are static
    static ll base;
    vector<ll> pref1;    //prefix hash of sequence under modulo (1e9 + 123)
    vector<ull> pref2;   //prefix hash of sequence under modulo (2^64)
    
    //initializing the pow1, pow2, pref1, pref2
    PolyHash(string &s) : pref1(sz(s)+1, 0), pref2(sz(s)+1, 0) {
        assert(base < mod);
        const int n = sz(s);
        while (sz(pow1) <= n) {
            pow1.push_back(pow1.back() * base % mod);
            pow2.push_back(pow2.back() * base);
        }
        //1-based indexing used for pref1, pref2
        for (int i = 0; i < n; ++i) {
            assert(base > s[i]);
            pref1[i+1] = (pref1[i] + s[i] * pow1[i]) % mod;
            pref2[i+1] = (pref2[i] + s[i] * pow2[i]);
        }
    }

    //calculating the hash of segment [pos, pos+len) and returning hash by both modules
    pair<ll, ull> operator()(int pos, int len, int mxpow = 0) {
        ll hash1 = pref1[pos + len] - pref1[pos];
        ll hash2 = pref2[pos + len] - pref2[pos];
        if (hash1 < 0) hash1 += mod;
        if (mxpow) {
            hash1 = hash1 * pow1[mxpow - (pos+len-1)] % mod;
            hash2 *= pow2[mxpow-(pos+len-1)];
        }
        return {hash1, hash2};
    }

};

ll PolyHash::base = 1e9 + 7;
vector<ll> PolyHash::pow1{1};
vector<ull> PolyHash::pow2{1};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string s, t; cin >> s >> t;
    int mxpow = max(sz(s), sz(t)); //maximum length of compared sequences
    PolyHash::base = gen_base(256, PolyHash::mod); //generating hash
    PolyHash hash1(s), hash2(t);  //hash1 for s, hash2 for t
    auto needed = hash2(0, sz(t), mxpow);  //hash of t [0...m-1], m = sizeof(t)

    //hash of the segment [i, i+len-1]
    for (int i = 0; i + sz(t) <= sz(s); ++i) {
        if (hash1(i, sz(t), mxpow) == needed)  //comparing both hashes
            cout << i << ' ';
    }

    return 0;
}

/*
To implement hashing just copy the Polyhash, then create its instance and pass the string as constructor.

*/

/*
https://leetcode.com/problems/longest-duplicate-substring/ (binary search + hashing)
soln: https://pastebin.com/q7Yxiq4n         (store the hash into the vector then sort it, find the hash).

https://acm.timus.ru/problem.aspx?space=1&num=1517&locale=en  (binary search + hashing)
https://pastebin.com/gHP9PJ7Y


https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-a-25th-july/challenges/hard-1-cc
solution: just move over the multiple of n, so solutin will be O(n.sqrt(n))

https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-a-31-october/challenges/palindromic-query
https://pastebin.com/WmJ6SLVq
*/
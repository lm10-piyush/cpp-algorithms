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

//Substring Search using Single Hashing, Buggy but worked.

const int p = 101;
const int mod = 1e9 + 7;
ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) (res = res * a) %= mod;
        (a = a * a) %= mod;
        b >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll inv = power(p, mod-2);
    string s, t; cin >> s >> t;
    ll hash1 = 0;
    ll power = 1;
    //Creating hash of string 't'
    for (int i = 0; i < sz(t); ++i) {
        hash1 = (hash1 + (t[i]-'a'+1) * power) % mod;
        power = (power * p) % mod;
    }

    ll hash2 = 0;
    int n = sz(s), m = sz(t);
    if (n < m) return 0;
    power = 1;
    vector <int> ans;
    //Creating hash of segments of 's' [j...i]
    for (int i = 0, j = 0; i < n; ++i) {
        if (i - j + 1 <= m) {
            hash2 = (hash2 + power * (s[i] - 'a'+1)) % mod;
            if (i - j + 1 < m) power = (power * p) % mod;
            else if (hash2 == hash1) ans.push_back(j);
            continue;
        }
        hash2 = (((hash2 - (s[j++]-'a'+1)) * inv) % mod + (s[i]-'a'+1)*power) % mod; 
        if (hash2 == hash1) {
            ans.push_back(j);
        }
    }
    for (int i: ans) cout << i << " ";


    return 0;
}

/*
Blog: https://codeforces.com/blog/entry/60445

(left to right) method to create the hash: a, b, c, d, e => [a + b.p + c.p^2 + d.p^3], [j..i]=>[0..3] (Accoding to my code)
To make it rolling hash for 'e' => remove the A[j], then divide by p under mod, then include the 'e'.
                                then, [b + c.p + d.p^2 + e.p^3].

Note: To encode the alphabets don't do like this (A[i]-'a'), instead do this => (A[i]-'a'+1).


This is buggy, But got AC on https://acmp.ru/index.asp?main=task&id_task=202
To avoid collison you can use double hashing or match the whole substring to check(May get TLE)
https://pastebin.com/q1aUuh3P  (Another solution using the "substring match on collison" which causes the TLE)


https://leetcode.com/problems/longest-duplicate-substring/
https://pastebin.com/8f87L1nU   (Worked, Same Type of solution but here avoiding the collison using "substring match on collison").

problem : https://www.codechef.com/LTIME60A/problems/SHIFTPAL
https://www.codechef.com/viewsolution/32359239

*/

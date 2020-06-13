#include<bits/stdc++.h>
#include<chrono>
#define ll long long
#define mod 1000000007
#define mp make_pair
#define endl "\n"
#define tab " "
#define pb push_back
#define ff first
#define ss second
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pll pair<ll,ll>
#define pi 3.141592653589793238460
#define F(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define RF(i,a,b) for(int i=(int)a;i>=(int)b;i--)
using namespace std;
using namespace std::chrono;

//problem : https://www.codechef.com/LTIME60A/problems/SHIFTPAL
//https://www.codechef.com/viewsolution/32359239

bool rolling_hash(string &s, string &pattern) {
    ll hash1 = 0;
    ll p = 31;
    ll power = 1;
    int len = pattern.size(), n = s.size();
    for (int i = 0; i < len; ++i) {
        hash1 = (hash1 + power*(pattern[i]-'a')) % mod;
        power = (power*p) % mod;
    }

    ll curr = 0;
    power = 1;
    //just a sliding window for rolling hashes
    for (int i = 0, j = 0; i < n; ++i) {
        if (i - j + 1 <= len) {
            curr = (curr + power*(s[i] - 'a')) % mod;
            if (i - j + 1 < len) power = (power * p) % mod;
            else if (curr == hash1) return true;
            continue;
        }

        curr = (((curr - (s[j]-'a')) / p) + (s[i]-'a')*power) % mod;
        j++;
        if (curr == hash1) return true;
    }

    return false;
}



struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    size_t ans=0;
    for(int i=0;i<x.first;i++)
      ans+=x.second;
    return ans;
  }
};

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        // https://codeforces.com/blog/entry/62393
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    //key-type in parameter of operator() (....)
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

};

int main()
{
    unordered_map<pair<int,int> , int, HASH> mmp;
    unordered_map<int,int,custom_hash> mp;
    //to speed up
    mp.reserve(1024);
    mp.max_load_factor(0.25);
    mp[10]=30;
    mp[20]=40;
    mp[30]=50;

    for(auto i: mp)
        cout<<i.first<<tab;
}


//https://codeforces.com/blog/entry/60442  rolling hashes
//https://codeforces.com/blog/entry/60445 rolling hashes

//problem
//https://codeforces.com/contest/126/problem/B
//https://codeforces.com/contest/126/submission/1308932
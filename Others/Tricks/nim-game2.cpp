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


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int xorr = 0;
        for (int i = 0, a; i < n; ++i) {
            cin >> a;
            xorr ^= a;
        }
        string s = (xorr > 0? "First" : "Second");
        cout << s << endl;
    }

    return 0;
}

//https://www.hackerrank.com/challenges/nim-game-1/problem
//https://cses.fi/problemset/task/1098  (NIM-II) (given n piles, you can remove 1,2, or 3 objects from any pile)
//https://pastebin.com/csSk7vYd

/*
concept: A player wins the game who is able to maintain the non-zero xor of the whole array

        (INITIALLy) If cumulative xor of the whose array is positive then always 1st wins, because he can maintain the same 
        positive value for himself, zero for 2nd partner. 

        Here is main fight of making xor positive for himself or making zero xor for other.
        If initially xor is positive then it is very easy to first player to maintain it. 

*/
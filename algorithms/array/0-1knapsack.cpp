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

    int n, x; cin >> n >> x;
    vector <int> price(n+1), pages(n+1);
    for (int i = 1; i <= n; ++i) //cost/weight
        cin >> price[i];
    for (int i = 1; i <= n; ++i) 
        cin >> pages[i];  //value..

    vector <vector <int>> dp(n+1, vector <int> (x+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= x; ++j) {
            dp[i][j] = dp[i-1][j]; // not ith book
            int left = j - price[i];
            if (left >= 0)
                dp[i][j] = max(dp[i][j], pages[i] + dp[i-1][left]); //include the ith book
        }
    }

    cout << dp[n][x];


    return 0;
}

//https://cses.fi/problemset/task/1158

//Note: above algorithm assumes one item only once, not multiple occurence
// to allow multiple occurrence you just do, =>pages[i] + dp[i][left]
//problem: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0/

//https://atcoder.jp/contests/dp/tasks/dp_d
//sol: https://atcoder.jp/contests/dp/submissions/14115284